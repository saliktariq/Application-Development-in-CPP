#include <Windows.h>
#include <mmsystem.h>
#include <thread>
#include <atomic>
#pragma comment(lib, "winmm.lib")
#include <string>
#include <vector>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;
using namespace std;

std::vector<std::string> getPlaylist(std::string directory) {

    std::vector<std::string> playlist;
    std::string path = directory; //For example: std::string path = ".\\music";

    for (const auto& entry : fs::directory_iterator(path))
    {
        playlist.push_back(entry.path().filename().string());
    }
    return playlist;
}


void PlayMusic(std::atomic<bool>& is_playing) {
    std::vector<std::string> playlist = getPlaylist(".\\music");
    int songIndex = 1;
    for (const auto &song : playlist) {       
        cout << songIndex << " : " << song << endl;
        songIndex++;
    }

    int choice = 0;
    cout << "Enter the song number to play: " << endl;
    cin >> choice;

    // Convert selected song name to wide string
    const std::string& selectedSong = playlist.at(choice - 1);
    int wideSize = MultiByteToWideChar(CP_UTF8, 0, selectedSong.c_str(), -1, nullptr, 0);
    std::vector<wchar_t> wideSelectedSong(wideSize);
    MultiByteToWideChar(CP_UTF8, 0, selectedSong.c_str(), -1, wideSelectedSong.data(), wideSize);

    // Open the file
    wchar_t command[256];
    wsprintf(command, L"open \"%s\" type mpegvideo alias MyMusic", wideSelectedSong.data());
   // const wchar_t file_name[] = L"BadaCopa.mp3";

    // Open the file
    //wchar_t command[256];
    //wsprintf(command, L"open \"%s\" type mpegvideo alias MyMusic", file_name);

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
        system("cls");
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
