#include <Windows.h>
#include <tchar.h>

int _tmain(int argc, _TCHAR * argv[])
{
	DEVMODE devmode = {};
	devmode.dmSize = sizeof(devmode);

	BOOL fetch_result = EnumDisplaySettings(
		nullptr,
		ENUM_CURRENT_SETTINGS,
		&devmode);

	if (!fetch_result) return -1;

	DWORD temp = devmode.dmPelsWidth;
	devmode.dmPelsWidth = devmode.dmPelsHeight;
	devmode.dmPelsHeight = temp;

	devmode.dmDisplayOrientation = (devmode.dmDisplayOrientation) ? DMDO_DEFAULT : DMDO_270;

	if (ChangeDisplaySettings(&devmode, 0) != DISP_CHANGE_SUCCESSFUL) return -2;

	return 0;
}
