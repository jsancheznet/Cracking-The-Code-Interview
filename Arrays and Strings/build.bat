@echo off


set IncludeDirectories=
set LibDirectories=

set CompilerFlags= /std:c++17 -nologo -W4 -Od -FS %IncludeDirectories% -Zi -EHsc -MD /D "_WINDOWS"
set LinkerFlags=-nologo -DEBUG %LibDirectories%

cl 1_1.cpp %CompilerFlags% /link %LinkerFlags% -SUBSYSTEM:CONSOLE
cl 1_2.cpp %CompilerFlags% /link %LinkerFlags% -SUBSYSTEM:CONSOLE
cl 1_3.cpp %CompilerFlags% /link %LinkerFlags% -SUBSYSTEM:CONSOLE
cl 1_4.cpp %CompilerFlags% /link %LinkerFlags% -SUBSYSTEM:CONSOLE
cl 1_5.cpp %CompilerFlags% /link %LinkerFlags% -SUBSYSTEM:CONSOLE
