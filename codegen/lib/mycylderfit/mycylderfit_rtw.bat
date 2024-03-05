@echo off

set MATLAB=E:\SystemInstallation\Matlab

cd .

if "%1"=="" ("E:\SystemInstallation\Matlab\bin\win64\gmake"  -f mycylderfit_rtw.mk all) else ("E:\SystemInstallation\Matlab\bin\win64\gmake"  -f mycylderfit_rtw.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1