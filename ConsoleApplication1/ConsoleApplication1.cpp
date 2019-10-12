#include "pch.h"

using namespace System;
using System.Runtime.InteropServices;

[DllImport("Dll1.dll")]
public static extern void myFunc(int p1, string p2);

int main(array<System::String ^> ^args)
{
    return 0;
}
