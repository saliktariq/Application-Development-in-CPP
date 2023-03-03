#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "ludo.h"

using namespace std;

static bool initialized = false;


int rollDice() {
    
    if (!initialized) {
        srand(time(NULL));
        initialized = true;
    }
    int randomNumber = rand() % 4 + 1;
    cout<< "\n\n You rolled a " << randomNumber << "\n\n"<< endl;
    return randomNumber;
}



int main(){
	
	colourMyConsole();
	
	
	//Setting up initial board
	setup();
	
	int choice;
	int currentPlayer = 1;
	int p1pos = 0;
	int p2pos = 0;
	int p3pos = 0;
	int p4pos = 0;
	Node *nodeAtCurrentPos;
	
	do {
		displayBoard(); //not implemented yet
		
		cout<< "Press 1 to roll the dice...\n";
		cin >> choice;
		
		switch(choice){
			case 1:
				{
					// Player's turn
					cout << "Player " << currentPlayer << "'s turn" << endl;
					int diceResult = rollDice();
					
					switch(currentPlayer){
						case 1:
							{
							if (p1pos+diceResult > 47){
								;
							} else {
								p1pos += diceResult;
							}
							
							

							nodeAtCurrentPos = getNodeAtPosition(p1pos);
							if(nodeAtCurrentPos->isSafe){
								nodeAtCurrentPos->playersAtThisPosition.push_back(currentPlayer);
								cout << "Player " << currentPlayer << " is now at position: " << p1pos;
							} else {
								if(nodeAtCurrentPos->playersAtThisPosition.empty()){
									nodeAtCurrentPos->playersAtThisPosition.push_back(currentPlayer);
									cout << "Player " << currentPlayer << " is now at position: " << p1pos;
								}else {
									int deadPlayer = nodeAtCurrentPos->playersAtThisPosition.back();
									nodeAtCurrentPos->playersAtThisPosition.clear();
									nodeAtCurrentPos->playersAtThisPosition.push_back(currentPlayer);
									cout << "Player " << currentPlayer << " is now at position: " << p1pos;
									
									switch(deadPlayer){
										case 1:
											p1pos = 0;
											cout << "\nPlayer " << deadPlayer << "is now going back to: " << p1pos;
											break;
										case 2:
											p2pos = 0;
											cout << "\nPlayer " << deadPlayer << "is now going back to: " << p2pos;
											break;
										case 3:
											p3pos = 0;
											cout << "\nPlayer " << deadPlayer << "is now going back to: " << p3pos;
											break;
										case 4:
											p4pos = 0;
											cout << "\nPlayer " << deadPlayer << "is now going back to: " << p4pos;
											break;
										default:
											break;
									}
									
								}
							}
						
							printPlayersAtThisPositionVector(nodeAtCurrentPos->playersAtThisPosition); 
							if (p1pos == 47) {
								cout << "Player 1 has won!" << endl;
								return 0;
							}
							break;
							}

							
						case 2:
							{
							if (p2pos+diceResult > 47){
								break;
							} else {
								p2pos += diceResult;
							}
							
							

							nodeAtCurrentPos = getNodeAtPosition(p2pos);
							if(nodeAtCurrentPos->isSafe){
								nodeAtCurrentPos->playersAtThisPosition.push_back(currentPlayer);
								cout << "Player " << currentPlayer << " is now at position: " << p2pos;
							} else {
								if(nodeAtCurrentPos->playersAtThisPosition.empty()){
									nodeAtCurrentPos->playersAtThisPosition.push_back(currentPlayer);
									cout << "Player " << currentPlayer << " is now at position: " << p2pos;
								}else {
									int deadPlayer = nodeAtCurrentPos->playersAtThisPosition.back();
									nodeAtCurrentPos->playersAtThisPosition.clear();
									nodeAtCurrentPos->playersAtThisPosition.push_back(currentPlayer);
									cout << "Player " << currentPlayer << " is now at position: " << p2pos;
									
									switch(deadPlayer){
										case 1:
											p1pos = 0;
											cout << "\nPlayer " << deadPlayer << " is now going back to: " << p1pos;
											break;
										case 2:
											p2pos = 0;
											cout << "\nPlayer " << deadPlayer << " is now going back to: " << p2pos;
											break;
										case 3:
											p3pos = 0;
											cout << "\nPlayer " << deadPlayer << " is now going back to: " << p3pos;
											break;
										case 4:
											p4pos = 0;
											cout << "\nPlayer " << deadPlayer << " is now going back to: " << p4pos;
											break;
										default:
											break;
									}
									
								}
							}
						
							printPlayersAtThisPositionVector(nodeAtCurrentPos->playersAtThisPosition); 
							if (p2pos == 47) {
								cout << "Player 2 has won!" << endl;
								return 0;
							}
							break;
							}

						case 3:
							{
							if (p3pos+diceResult > 47){
								break;
							} else {
								p3pos += diceResult;
							}
							
							

							nodeAtCurrentPos = getNodeAtPosition(p3pos);
							if(nodeAtCurrentPos->isSafe){
								nodeAtCurrentPos->playersAtThisPosition.push_back(currentPlayer);
								cout << "Player " << currentPlayer << " is now at position: " << p3pos;
							} else {
								if(nodeAtCurrentPos->playersAtThisPosition.empty()){
									nodeAtCurrentPos->playersAtThisPosition.push_back(currentPlayer);
									cout << "Player " << currentPlayer << " is now at position: " << p3pos;
								}else {
									int deadPlayer = nodeAtCurrentPos->playersAtThisPosition.back();
									nodeAtCurrentPos->playersAtThisPosition.clear();
									nodeAtCurrentPos->playersAtThisPosition.push_back(currentPlayer);
									cout << "Player " << currentPlayer << " is now at position: " << p3pos;
									
									switch(deadPlayer){
										case 1:
											p1pos = 0;
											cout << "\nPlayer " << deadPlayer << " is now going back to: " << p1pos;
											break;
										case 2:
											p2pos = 0;
											cout << "\nPlayer " << deadPlayer << " is now going back to: " << p2pos;
											break;
										case 3:
											p3pos = 0;
											cout << "\nPlayer " << deadPlayer << " is now going back to: " << p3pos;
											break;
										case 4:
											p4pos = 0;
											cout << "\nPlayer " << deadPlayer << " is now going back to: " << p4pos;
											break;
										default:
											break;
									}
									
								}
							}
						
							printPlayersAtThisPositionVector(nodeAtCurrentPos->playersAtThisPosition); 
							if (p3pos == 47) {
								cout << "Player 3 has won!" << endl;
								return 0;
							}
							break;
							}
							
						case 4:
							{
							if (p4pos+diceResult > 47){
								;
							} else {
								p4pos += diceResult;
							}
							
							

							nodeAtCurrentPos = getNodeAtPosition(p4pos);
							if(nodeAtCurrentPos->isSafe){
								nodeAtCurrentPos->playersAtThisPosition.push_back(currentPlayer);
								cout << "Player " << currentPlayer << " is now at position: " << p4pos;
							} else {
								if(nodeAtCurrentPos->playersAtThisPosition.empty()){
									nodeAtCurrentPos->playersAtThisPosition.push_back(currentPlayer);
									cout << "Player " << currentPlayer << " is now at position: " << p4pos;
								}else {
									int deadPlayer = nodeAtCurrentPos->playersAtThisPosition.back();
									nodeAtCurrentPos->playersAtThisPosition.clear();
									nodeAtCurrentPos->playersAtThisPosition.push_back(currentPlayer);
									cout << "Player " << currentPlayer << " is now at position: " << p4pos;
									
									switch(deadPlayer){
										case 1:
											p1pos = 0;
											cout << "\nPlayer " << deadPlayer << " is now going back to: " << p1pos;
											break;
										case 2:
											p2pos = 0;
											cout << "\nPlayer " << deadPlayer << " is now going back to: " << p2pos;
											break;
										case 3:
											p3pos = 0;
											cout << "\nPlayer " << deadPlayer << " is now going back to: " << p3pos;
											break;
										case 4:
											p4pos = 0;
											cout << "\nPlayer " << deadPlayer << " is now going back to: " << p4pos;
											break;
										default:
											break;
									}
									
								}
							}
						
							printPlayersAtThisPositionVector(nodeAtCurrentPos->playersAtThisPosition); 
							if (p4pos == 47) {
								cout << "Player 4 has won!" << endl;
								return 0;
							}
							break;
							}
					}
					
					// Update current player's turn
					currentPlayer = (currentPlayer % 4) + 1;
					
					break;
				}
				
			default:
				break;
		}

} while(choice!=0);

return 0;
}

