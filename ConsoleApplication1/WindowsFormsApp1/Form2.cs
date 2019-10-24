using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form2 : Form
    {
        [DllImport("user32.dll", CharSet = CharSet.Unicode)]
        private static extern int GetWindowText(IntPtr hWnd, StringBuilder strText, int maxCount);

        [DllImport("user32.dll", CharSet = CharSet.Unicode)]
        private static extern int GetWindowTextLength(IntPtr hWnd);

        [DllImport("user32.dll")]
        private static extern bool EnumWindows(EnumWindowsProc enumProc, IntPtr lParam);

        [DllImport("user32.dll")]
        private static extern bool IsWindowVisible(IntPtr hWnd);

        [DllImport("User32.dll")]
        static extern IntPtr GetParent(IntPtr hwnd);

        [DllImport("user32.dll", SetLastError = true)]
        static extern uint GetWindowThreadProcessId(IntPtr hWnd, out uint lpdwProcessId);

        // Delegate to filter which windows to include 
        public delegate bool EnumWindowsProc(IntPtr hWnd, IntPtr lParam);

        public string selProcessPath;

        public static string GetWindowText(IntPtr hWnd)
        {
            int size = GetWindowTextLength(hWnd);
            if (size > 0)
            {
                var builder = new StringBuilder(size + 1);
                GetWindowText(hWnd, builder, builder.Capacity);
                return builder.ToString();
            }

            return String.Empty;
        }

        public Form2()
        {
            InitializeComponent();

            listView1.Columns.Add("PID", 80, HorizontalAlignment.Left);
            listView1.Columns.Add("Process Name", 200, HorizontalAlignment.Left);
            listView1.Columns.Add("Window Handle", 80, HorizontalAlignment.Left);
            listView1.Columns.Add("Window Name", 300, HorizontalAlignment.Left);
            listView1.Columns.Add("Process Path", 500, HorizontalAlignment.Left);
            
            EnumWindows(delegate (IntPtr wnd, IntPtr param)
            {
                if (IsWindowVisible(wnd) && GetParent(wnd) == IntPtr.Zero)
                {
                    uint processId = 0;
                    bool isAppstoreApp = false;
                    String path = WindowHelper.GetExecutablePath(wnd, out isAppstoreApp, out processId);
                    if (processId != 0 && !isAppstoreApp)
                    {
                        try
                        {
                            Process ownerProcess = Process.GetProcessById((int)processId);
                            bool isMainWindow = ownerProcess.MainWindowHandle.Equals(wnd);
                            if (isMainWindow)
                            {
                                String wndText = GetWindowText(wnd);
                                ListViewItem item = new ListViewItem();
                                item.Text = processId.ToString();
                                item.SubItems.Add(ownerProcess.ProcessName);
                                item.SubItems.Add(wnd.ToString("X8"));
                                item.SubItems.Add(wndText);
                                item.SubItems.Add(path);
                                listView1.Items.Add(item);
                            }
                        }
                        catch (Exception ex)
                        {
                          
                        }
                    }
                }
                return true;
            }, IntPtr.Zero);
        }

        private void listView1_ItemSelectionChanged(object sender, ListViewItemSelectionChangedEventArgs e)
        {
            if (listView1.SelectedItems.Count > 0)
            {
                label2.Text = listView1.SelectedItems[0].Text;
            } else
            {
                label2.Text = "";
            }
            selProcessPath = label2.Text;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void listView1_DoubleClick(object sender, EventArgs e)
        {
            if (listView1.SelectedItems.Count > 0)
            {
                label2.Text = listView1.SelectedItems[0].Text;
                selProcessPath = label2.Text;
                Close();
            }
        }
    }

    static class WindowHelper
    {
        const int BufferSize = 512;

        static readonly StringBuilder _Buffer = new StringBuilder(BufferSize);

        [DllImport("user32.dll")]
        static extern uint GetWindowThreadProcessId(IntPtr hWnd, out uint lpdwProcessId);

        [DllImport("kernel32.dll")]
        static extern IntPtr OpenProcess(ProcessAccessFlags dwDesiredAccess, [MarshalAs(UnmanagedType.Bool)] bool bInheritHandle, uint dwProcessId);

        [Flags]
        public enum ProcessAccessFlags : uint
        {
            Read = 0x10, // PROCESS_VM_READ
            QueryInformation = 0x400 // PROCESS_QUERY_INFORMATION
        }

        [DllImport("psapi.dll", CharSet = CharSet.Auto)]
        static extern uint GetModuleFileNameEx(IntPtr hProcess, IntPtr hModule, StringBuilder lpFilename, uint nSize);

        [DllImport("psapi.dll", CharSet = CharSet.Auto)]
        static extern uint GetProcessImageFileName(IntPtr hProcess, StringBuilder lpImageFileName, uint nSize);

        [DllImport("kernel32.dll", CharSet = CharSet.Auto)]
        [return: MarshalAs(UnmanagedType.Bool)]
        static extern bool QueryFullProcessImageName(IntPtr hProcess, uint dwFlags, StringBuilder lpExeName, ref uint lpdwSize);

        [DllImport("kernel32.dll", CharSet = CharSet.Auto)]
        static extern uint QueryDosDevice(string lpDeviceName, StringBuilder lpTargetPath, uint uuchMax);

        [DllImport("kernel32.dll")]
        [return: MarshalAs(UnmanagedType.Bool)]
        static extern bool CloseHandle(IntPtr hObject);

        [DllImport("user32.dll")]
        static extern bool IsImmersiveProcess(IntPtr hProcess);

        public static string GetExecutablePath(IntPtr hwnd, out bool isAppstoreApp, out uint processId)
        {
            isAppstoreApp = false;
            processId = 0;

            // Get the process id
            uint processid;
            if (GetWindowThreadProcessId(hwnd, out processid) != 0)
            {
                processId = processid;

                IntPtr hprocess = IntPtr.Zero;
                try
                {
                    // Try GetModuleFileName method first since it's the fastest. This may return ACCESS_DENIED (due to VM_READ flag) if the process is 
                    // not owned by the current user. It will also fail if we are compiled as x86 and we're trying to open a 64 bit process.
                    hprocess = OpenProcess(ProcessAccessFlags.QueryInformation | ProcessAccessFlags.Read, false, processid);
                    if (hprocess != IntPtr.Zero)
                    {
                        isAppstoreApp = IsImmersiveProcess(hprocess);
    
                        if (GetModuleFileNameEx(hprocess, IntPtr.Zero, _Buffer, BufferSize) > 0)
                        {
                            return _Buffer.ToString();
                        }
                    }
                    else
                    {
                        // Try to get a handle to the process without the VM_READ flag
                        hprocess = OpenProcess(ProcessAccessFlags.QueryInformation, false, processid);
                    }

                    if (hprocess != IntPtr.Zero)
                    {
                        isAppstoreApp = IsImmersiveProcess(hprocess);

                        // Try QueryFullProcessImageName on Vista or higher operating systems
                        uint size = BufferSize;
                        if ((Environment.OSVersion.Version.Major >= 6) &&
                         QueryFullProcessImageName(hprocess, 0, _Buffer, ref size) && (size > 0))
                        {
                            return _Buffer.ToString();
                        }

                        // Try GetProcessImageFileName as a last resort
                        if (GetProcessImageFileName(hprocess, _Buffer, BufferSize) > 0)
                        {
                            string dospath = _Buffer.ToString();
                            foreach (string drive in Environment.GetLogicalDrives())
                            {
                                if ((QueryDosDevice(drive.TrimEnd('\\'), _Buffer, BufferSize) > 0) &&
                                 dospath.StartsWith(_Buffer.ToString(), StringComparison.OrdinalIgnoreCase))
                                {
                                    return drive + dospath.Remove(0, _Buffer.Length);
                                }
                            }
                        }
                    }
                }
                finally
                {
                    if (hprocess != IntPtr.Zero)
                    {
                        CloseHandle(hprocess);
                    }
                }
            }
            return string.Empty;
        }
    }
}
