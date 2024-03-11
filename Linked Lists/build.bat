@echo off


set IncludeDirectories=
set LibDirectories=

set CompilerFlags= /std:c++17 -nologo -W4 -Od -FS %IncludeDirectories% -Zi -EHsc -MD /D "_WINDOWS"
set LinkerFlags=-nologo -DEBUG %LibDirectories%

cl 2_1.cpp %CompilerFlags% /link %LinkerFlags% -SUBSYSTEM:CONSOLE
