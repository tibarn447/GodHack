@IF NOT EXIST ..\dep\ (
	@echo ../dep/ not found!
	@echo This folder must be kept in the same folder as dep!
	@pause
	@exit
)

@set DEVKITARM=%~dp0..\dep\devkitARM
@set PATH=%~dp0..\dep\PortableGit\usr\bin;%~dp0..\dep\PortableGit\mingw64\bin;%~dp0..\dep\PortableGit\cmd;%~dp0..\dep\rgbds
@for /f "tokens=*" %%g in ('nproc') do @(set nproc=%%g)
make -j%nproc%
@if %ERRORLEVEL% NEQ 0 pause
