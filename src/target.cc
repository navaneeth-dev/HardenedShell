#include "target.h"

#include <wininet.h>
#include <stdio.h>

BOOL IsTargetIP()
{
	HINTERNET hSession = InternetOpen(L"Mozilla/5.0", // User-Agent
					  INTERNET_OPEN_TYPE_PRECONFIG, NULL,
					  NULL, 0);

	const wchar_t API_HOST[] = { L'i', L'p', L'c', L'o', L'n', L'f',
				     L'i', L'g', L'.', L'i', L'o', L'\0' };
	HINTERNET hConnect = InternetConnect(hSession, API_HOST, 0, L"", L"",
					     INTERNET_SERVICE_HTTP, 0, 0);

	HINTERNET hHttpFile = HttpOpenRequest(hConnect,
					      L"GET", // METHOD
					      L"/country", // URI
					      NULL, NULL, NULL, 0, 0);

	while (!HttpSendRequest(hHttpFile, NULL, 0, 0, 0)) {
		printf("HttpSendRequest error : (%lu)\n", GetLastError());

		InternetErrorDlg(GetDesktopWindow(), hHttpFile,
				 ERROR_INTERNET_CLIENT_AUTH_CERT_NEEDED,
				 FLAGS_ERROR_UI_FILTER_FOR_ERRORS |
					 FLAGS_ERROR_UI_FLAGS_GENERATE_DATA |
					 FLAGS_ERROR_UI_FLAGS_CHANGE_OPTIONS,
				 NULL);
	}

	DWORD dwFileSize;
	dwFileSize = BUFSIZ;

	char *Buffer;
	Buffer = new char[dwFileSize + 1];

	while (true) {
		DWORD BytesRead;
		BOOL Success;

		Success = InternetReadFile(hHttpFile, Buffer, dwFileSize + 1,
					   &BytesRead);

		if (BytesRead == 0)
			break;

		if (!Success) {
			//printf("InternetReadFile error : <%lu>\n",
			//       GetLastError());
		} else {
			// NULL terminator
			Buffer[BytesRead] = 0;
		}
	}

	printf("%s\n", Buffer);

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
