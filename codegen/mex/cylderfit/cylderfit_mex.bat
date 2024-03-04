@echo off
set MATLAB=E:\SystemInstallation\Matlab
call "E:\SystemInstallation\Matlab\sys\lcc64\lcc64\mex\lcc64opts.bat"
"E:\SystemInstallation\Matlab\toolbox\shared\coder\ninja\win64\ninja.exe" -t compdb cc cxx cudac > compile_commands.json
"E:\SystemInstallation\Matlab\toolbox\shared\coder\ninja\win64\ninja.exe" -v %*
