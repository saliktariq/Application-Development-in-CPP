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

void set_random_background_color() {
    srand(time(0)); // Seed the random number generator with the current time
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int random_color = (rand() % 8) + 1; // Generate a random number between 1 and 8
    random_color = random_color << 4; // Shift the bits to set the background color
    SetConsoleTextAttribute(hConsole, random_color);
}

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
    for (const auto& song : playlist) {
        std::cout << "\033[1;36m"; // Set text color to bright cyan
        std::cout << songIndex << " : ";
        std::cout << "\033[0;36m"; // Set text color to cyan
        std::cout << song << std::endl;
        std::cout << "\033[0m"; // Reset text color
        songIndex++;
    }

    int choice = 0;
    std::cout << "\033[1;33m"; // Set text color to bright yellow
    std::cout << "\nspace bar: \033[0;33mPause music\033[1;33m" << std::endl;
    std::cout << "\033[0m"; // Reset text color
    std::cout << "\033[1;36m"; // Set text color to bright cyan
    cout << "\nEnter the \033[0;36msong number\033[1;36m to play: " << endl;
    std::cout << "\033[0m"; // Reset text color

    cin >> choice;

    // Convert selected song name to wide string
    const std::string& selectedSong = playlist.at(choice - 1);
    int wideSize = MultiByteToWideChar(CP_UTF8, 0, selectedSong.c_str(), -1, nullptr, 0);
    std::vector<wchar_t> wideSelectedSong(wideSize);
    MultiByteToWideChar(CP_UTF8, 0, selectedSong.c_str(), -1, wideSelectedSong.data(), wideSize);

    // Open the file
    wchar_t command[256];
    wsprintf(command, L"open \"%s\" type mpegvideo alias MyMusic", wideSelectedSong.data());
    mciSendString(command, NULL, 0, NULL);

    // Play the file
    mciSendString(L"play MyMusic", NULL, 0, NULL);

   


    bool is_paused = false;
    while (is_playing) {
        Sleep(1000);
        
        wsprintf(command, L"status MyMusic length");
        mciSendString(command, NULL, 0, NULL);

        if (std::wcscmp(command, L"0") == 0) {
            is_playing = false;
            break;
        }

        // Check for spacebar key press to pause or resume playing
        if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
            if (!is_paused) {
                mciSendString(L"pause MyMusic", NULL, 0, NULL);
                is_paused = true;
            }
            else {
                mciSendString(L"resume MyMusic", NULL, 0, NULL);
                is_paused = false;
            }
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
        set_random_background_color();
        std::cout << "  __  __           _      " << std::endl;
        std::cout << " |  \\/  |_   _ ___(_) ___ " << std::endl;
        std::cout << " | |\\/| | | | / __| |/ __|" << std::endl;
        std::cout << " | |  | | |_| \\__ \\ | (__ " << std::endl;
        std::cout << " |_|  |_|\\__,_|___/_|\\___|" << std::endl;


        std::cout << "\n\n";

        std::cout << "\033[1;36m"; // Set text color to bright cyan
        std::cout << "  Menu:" << std::endl;
        std::cout << "\033[0;36m"; // Set text color to cyan
        std::cout << "  p: Play music" << std::endl;
        std::cout << "  s: Stop music" << std::endl;
        std::cout << "  q: Quit program" << std::endl;
        std::cout << "\033[1;33m"; // Set text color to bright yellow
        std::cout << "\nPress 'S' at any time to stop the music\n";
        std::cout << "\033[0m"; // Reset text color

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

            // Reset the console color to the default
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, 15);

            break;
        }
        case 'q': {
            exit_program = true;
            break;
        }
        default: {
            std::cout << "\033[1;31m"; // Set text color to bright red
            std::cout << "Invalid input!" << std::endl;
            std::cout << "\033[0m"; // Reset text color
            break;
        }
        }

        std::cout << std::endl;
    }

    return 0;
}

