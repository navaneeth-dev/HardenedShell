#include "target.h"

#include <wininet.h>
#include <stdio.h>

BOOL IsTargetIP()
{
    HINTERNET hSession = InternetOpen(
		L"Mozilla/5.0", // User-Agent
		INTERNET_OPEN_TYPE_PRECONFIG,
		NULL,
		NULL,
		0);

	HINTERNET hConnect = InternetConnect(
		hSession,
		L"www.google.com", // HOST
		0,
		L"",
		L"",
		INTERNET_SERVICE_HTTP,
		0,
		0);

	HINTERNET hHttpFile = HttpOpenRequest(
		hConnect,
		L"GET", // METHOD
		L"/",   // URI
		NULL,
		NULL,
		NULL,
		0,
		0);

	while (!HttpSendRequest(hHttpFile, NULL, 0, 0, 0)) {
		printf("HttpSendRequest error : (%lu)\n", GetLastError());

		InternetErrorDlg(
			GetDesktopWindow(),
			hHttpFile,
			ERROR_INTERNET_CLIENT_AUTH_CERT_NEEDED,
			FLAGS_ERROR_UI_FILTER_FOR_ERRORS |
			FLAGS_ERROR_UI_FLAGS_GENERATE_DATA |
			FLAGS_ERROR_UI_FLAGS_CHANGE_OPTIONS,
			NULL);
	}

    DWORD dwFileSize;
	//dwFileSize = (DWORD)atol(bufQuery);
	dwFileSize = BUFSIZ;

	char* buffer;
	buffer = new char[dwFileSize + 1];

	while (true) {
		DWORD dwBytesRead;
		BOOL bRead;

		bRead = InternetReadFile(
			hHttpFile,
			buffer,
			dwFileSize + 1,
			&dwBytesRead);

		if (dwBytesRead == 0) break;

		if (!bRead) {
			printf("InternetReadFile error : <%lu>\n", GetLastError());
		} else {
			buffer[dwBytesRead] = 0;
			printf("Retrieved %lu data bytes: %s\n", dwBytesRead, buffer);
		}
	}

	InternetCloseHandle(hHttpFile);
	InternetCloseHandle(hConnect);
	InternetCloseHandle(hSession);

    return TRUE;
}

BOOL IsTarget()
{
    if (!IsTargetIP())
        return FALSE;

    return TRUE;
}
