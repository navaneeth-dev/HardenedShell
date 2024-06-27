#include <windows.h>

BOOL CheckMonitorRes(HMONITOR hMonitor, HDC hdcMonitor, LPRECT rect,
		     LPARAM data)
{
	int x, y = { 0 };

	MONITORINFO MI = { .cbSize = sizeof(MONITORINFO) };

	if (!GetMonitorInfoW(hMonitor, &MI)) {
		return FALSE; // Return FALSE to stop the enumeration
	}

	x = MI.rcMonitor.right - MI.rcMonitor.left;
	y = MI.rcMonitor.bottom - MI.rcMonitor.top;

	if (x < 0)
		x = -x;
	if (y < 0)
		y = -y;

	if ((x != 1920 && x != 2560 && x != 1440) ||
	    (y != 1080 && y != 1200 && y != 1600 && y != 900))
		*((BOOL *)data) = TRUE;

	return TRUE;
}

BOOL IsSandbox()
{
	BOOL ret = FALSE;
	EnumDisplayMonitors(NULL, NULL, (MONITORENUMPROC)CheckMonitorRes,
			    (LPARAM)(&ret));
	if (ret)
		return TRUE;

	return FALSE;
}
