#include <conio.h>
#include <iostream>
#include <windows.h>
/**
#defined header and key functionality applied following instructions from stackoverflow page:
https://stackoverflow.com/questions/24708700/c-detect-when-user-presses-arrow-key
**/

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

//end of definition

using namespace std;

	const int rows = 4;
	const int cols = 4;
	int color = 25;
    int matrix[rows][cols] = {}; // 0 initialization
    
    HANDLE  hConsole;
	int k=100;

	void print_matrix(int x, int y, int data) {
	//Setting some colours to terminal
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,k);
	k++;
	system("cls");	
	//End of styling

    matrix[x][y] = data; // putting data in correct x,y position

    // Print the state of the matrix
    for (auto& outer : matrix) {
        for (auto& inner : outer) {
            cout << inner << "\t";
        }
        cout << "\n";
    }
}

int main(){
	
	int x = 1; //initial position of x coordinate
	int y = 1; //initial position of y coordinate

	int data = 1; //data in the cell
	
	int keyboard_input; //up, down, left, right keys
	

	do{
		//system("cls");
		print_matrix(x,y,data);

		
		// Wait for keyboard input
		keyboard_input = getch();
		cout << "\n\n you pressed: "<< keyboard_input << endl;
		
		// Move the data point based on the arrow key pressed
		switch(keyboard_input) {
			case KEY_UP: // up arrow
				if(x > 0) {
					matrix[x][y] = 0; // remove the data from the current position
					x--;
					matrix[x][y] = data; // put the data in the new position
				} else {
					cout << "Error: Cannot move up. Already at the top." << endl;
				}
				break;
			case KEY_DOWN: // down arrow
				if(x < rows-1) {
					matrix[x][y] = 0; // remove the data from the current position
					x++;
					matrix[x][y] = data; // put the data in the new position
				} else {
					cout << "Error: Cannot move down. Already at the bottom." << endl;
				}
				break;
			case KEY_LEFT: // left arrow
				if(y > 0) {
					matrix[x][y] = 0; // remove the data from the current position
					y--;
					matrix[x][y] = data; // put the data in the new position
				} else {
					cout << "Error: Cannot move left. Already at the left edge." << endl;
				}
				break;
			case KEY_RIGHT: // right arrow
				if(y < cols-1) {
					matrix[x][y] = 0; // remove the data from the current position
					y++;
					matrix[x][y] = data; // put the data in the new position
				} else {
					cout << "Error: Cannot move right. Already at the right edge." << endl;
				}
				break;
			default:
				cout << "Invalid input. Please use arrow keys to move." << endl;
		}
		
	}while(keyboard_input!=0);

	
	
	
	return 0;
}

