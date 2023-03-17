#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

int main() {
    const wchar_t file_name[] = L"BadaCopa.mp3";

    // Open the file
    wchar_t command[256];
    wsprintf(command, L"open \"%s\" type mpegvideo alias MyMusic", file_name);
    mciSendString(command, NULL, 0, NULL);

    // Play the file
    mciSendString(L"play MyMusic", NULL, 0, NULL);

    // Wait for the file to finish playing
    do {
        Sleep(1000);
        wsprintf(command, L"status MyMusic length");
        mciSendString(command, NULL, 0, NULL);
        std::wcout << L"Playing..." << std::endl;
    } while (std::wcscmp(command, L"0") != 0);

    // Close the file
    mciSendString(L"close MyMusic", NULL, 0, NULL);

    return 0;
}