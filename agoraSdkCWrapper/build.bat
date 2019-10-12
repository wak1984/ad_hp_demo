

call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" x86

echo building----------------------------------
msbuild agoraSdkCWrapper.sln /t:Rebuild /p:Configuration=Release

