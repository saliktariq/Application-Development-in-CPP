#include <iostream>
#include <cstdlib>
#include <utility>
#include <vector>
#include <ctime>

using namespace std;

int main()
{
    const int BOARD_SIZE = 100;
    int diceRollResult;
    
    string board[BOARD_SIZE];


for (int i = 0; i < 100; i++) {
    board[i] = "[ ]";
}


board[5] = "LH";  // Ladder head at position 6
board[45] = "LT"; // Ladder tail at position 46
board[18] = "LH"; // Ladder head at position 19
board[42] = "LT"; // Ladder tail at position 43
board[51] = "LH"; // Ladder head at position 52
board[70] = "LT"; // Ladder tail at position 71
board[56] = "LH"; // Ladder head at position 57
board[97] = "LT"; // Ladder tail at position 98


board[46] = "SH"; // Snake head at position 47
board[8] = "ST";  // Snake tail at position 9
board[61] = "SH"; // Snake head at position 62
board[39] = "ST"; // Snake tail at position 40
board[95] = "SH"; // Snake head at position 96
board[74] = "ST"; // Snake tail at position 75

    	for (int i = 0; i < 100; i++) {
    cout << board[i] << " ";
    if ((i + 1) % 10 == 0) {
        std::cout << std::endl;
    }
}

    int option = 0;
    vector< pair<int, int> > ladder; 
    vector< pair<int, int> > snake;

    ladder.push_back(std::make_pair(6,46));
    ladder.push_back(std::make_pair(19,43));
    ladder.push_back(std::make_pair(52,71));
    ladder.push_back(std::make_pair(57,98));

    snake.push_back(std::make_pair(47,9));
    snake.push_back(std::make_pair(62,40));
    snake.push_back(std::make_pair(96,75));

    unsigned int ladderSize = ladder.size();
    unsigned int snakeSize = snake.size();

    int player1Pos = 0;
    int player2Pos = 0;
    int currentPlayer = 1;

    do {
    	


cout <<"\n\n\n";
        cout << "Player " << currentPlayer << ", press 1 to roll the dice" << endl;
        cin >> option;
        srand(time(NULL));
        diceRollResult = rand() % 6 + 1;

        if (currentPlayer == 1) {
            player1Pos += diceRollResult;
        } else {
            player2Pos += diceRollResult;
        }

        bool ladderOrSnake = false;
        for(int i = 0; i < ladderSize; i++) {
            int firstValue = ladder[i].first;
            int secondValue = ladder[i].second;

            if (currentPlayer == 1 && player1Pos == firstValue) {
                player1Pos = secondValue;
                cout << "Cool! You are going up to " << secondValue << endl;
                ladderOrSnake = true;
                break;
            } else if (currentPlayer == 2 && player2Pos == firstValue) {
                player2Pos = secondValue;
                
                cout << "Cool! You are going up to " << secondValue << endl;
                ladderOrSnake = true;
                break;
            }
        }

        if (currentPlayer == 1 && player1Pos >= BOARD_SIZE) {
            cout << "Congratulations! Player 1 is the winner." << endl;
            break;
        } else if (currentPlayer == 2 && player2Pos >= BOARD_SIZE) {
            cout << "Congratulations! Player 2 is the winner." << endl;
            break;
        }

        if (!ladderOrSnake) {
            for(int i = 0; i < snakeSize; i++) {
                int firstValue = snake[i].first;
                int secondValue = snake[i].second;

                if (currentPlayer == 1 && player1Pos == firstValue) {
                    player1Pos = secondValue;
                    cout << "Oops! a snake bit you, you are going down to " << secondValue << endl;

                    break;
                } else if (currentPlayer == 2 && player2Pos == firstValue) {
                    player2Pos = secondValue;
                    cout << "Oops! a snake bit you, you are going down to " << secondValue << endl;

                    break;
                }
            }
        }

        cout << "Player 1 position: " << player1Pos << endl;
        cout << "Player 2 position: " << player2Pos << endl;
        for (int i = 0; i < 100; i++) {
    if (i == player1Pos -1 ) {
        cout << "P1 ";
    } else if (i == player2Pos -1 ) {
        cout << "P2 ";
    } else {
        cout << board[i] << " ";
    }
    if ((i + 1) % 10 == 0) {
        std::cout << std::endl;
    }
}





        if (option == 1) {
            if (currentPlayer == 1) {
                currentPlayer = 2;
            } else {
                currentPlayer = 1;
            }
        }
    } while (option == 1);

    return 0;
}

