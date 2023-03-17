#include <Windows.h>
#include <mmsystem.h>
#include <thread>
#include <atomic>
#pragma comment(lib, "winmm.lib")
#include <string>
#include <vector>
#include <iostream>


void PlayMusic(std::atomic<bool>& is_playing) {
    const wchar_t file_name[] = L"BadaCopa.mp3";

    // Open the file
    wchar_t command[256];
    wsprintf(command, L"open \"%s\" type mpegvideo alias MyMusic", file_name);

    mciSendString(command, NULL, 0, NULL);

    // Play the file
    mciSendString(L"play MyMusic", NULL, 0, NULL);

    // Wait for the file to finish playing or for the thread to be stopped
    while (is_playing) {
        Sleep(1000);
        wsprintf(command, L"status MyMusic length");
        mciSendString(command, NULL, 0, NULL);
        if (std::wcscmp(command, L"0") == 0) {
            is_playing = false;
        }
    }

    // Stop the music and close the file
    mciSendString(L"stop MyMusic", NULL, 0, NULL);
    mciSendString(L"close MyMusic", NULL, 0, NULL);
}

int main() {
    bool exit_program = false;

    while (!exit_program) {
        std::cout << "Menu:" << std::endl;
        std::cout << "  p: Play music" << std::endl;
        std::cout << "  s: Stop music" << std::endl;
        std::cout << "  q: Quit program" << std::endl;

        char input;
        std::cin >> input;

        switch (input) {
        case 'p': {
            std::atomic<bool> is_playing(true);
            std::thread music_thread(PlayMusic, std::ref(is_playing));

            while (true) {
                if (GetAsyncKeyState('S') & 0x8000) {
                    is_playing = false;
                    break;
                }
            }

            music_thread.join();
            break;
        }
        case 's': {
            std::cout << "Stopping music..." << std::endl;
            mciSendString(L"stop MyMusic", NULL, 0, NULL);
            mciSendString(L"close MyMusic", NULL, 0, NULL);
            break;
        }
        case 'q': {
            exit_program = true;
            break;
        }
        default: {
            std::cout << "Invalid input!" << std::endl;
            break;
        }
        }

        std::cout << std::endl;
    }

    return 0;
}
