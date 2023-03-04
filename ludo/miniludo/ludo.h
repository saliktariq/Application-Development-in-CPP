#include <list>
#include <iostream>
#include <iomanip>
#include <string>



struct Player {
	int startX, startY;
	int currentX, currentY;
	int initXDir, initYDir;
	int xDir, yDir;
	std::string name;
	Player(int startX, int startY, int nextX, int nextY)
		: startX(startX), startY(startY), currentX(startX), currentY(startY), 
		initXDir(nextX), initYDir(nextY), xDir(nextX), yDir(nextY) {}
	void setDir(bool left, bool right) {
		if (left) {
			int temp = xDir;
			xDir = yDir;
			yDir = -temp;
		}
		if (right) {
			int temp = xDir;
			xDir = -yDir;
			yDir = temp;
		}
	}
	void move() {
		currentX += xDir;
		currentY += yDir;
	}
	void reset() {
		currentX = startX;
		currentY = startY;
		xDir = initXDir;
		yDir = initYDir;
	}
	friend bool operator==(Player& p1, Player& p2) {
		return (p1.currentX == p2.currentX && p1.currentY == p2.currentY);
	}
};

struct Square {
	bool turnLeft;
	bool turnRight;
	bool safe;
	Square(bool safe = false, bool right = false, bool left = false) :
		turnLeft(left), turnRight(right), safe(safe) {}
};
void initBoard(std::list<Square>& board) {
	bool left = false, right = false, safe = false;
	for (int i = 0; i <= 21; ++i) {
		if (i % 3 == 0) safe = true;
		else safe = false;
		if (i % 3 == 0 && i % 2 != 0) left = true;
		else left = false;
		board.push_back(Square(safe, right, left));
	}
	board.push_back(Square(false, false, true)); //22
	board.push_back(Square(true, false, false));
	for (int i = 24; i <= 38; ++i) {
		if (i % 4 == 3) {
			safe = true;
			right = true;
		}
		else {
			safe = false;
			right = false;
		}
		board.push_back(Square(safe, right, false));
	}
	board.back().turnRight = true; //38
	board.push_back(Square());
	board.push_back(Square()); //40
	board.push_back(Square(false, true));
	board.push_back(Square());
	board.push_back(Square(false, true));
	board.push_back(Square());
	board.push_back(Square(false, true)); //45
	board.push_back(Square(false, true));
	board.push_back(Square(true));
}

void printBoard(Player players[4]) {
	for (int i = 0; i < 7; ++i) {
		std::cout << "\n\n";
		for (int j = 0; j < 7; ++j) {
			std::string toPrint = "";
			bool playerOnSquare = false;
			for (int k = 0; k < 4; ++k) {
				if (players[k].currentX != j || players[k].currentY != i) {
					continue;
				}
				playerOnSquare = true;
				char player = 'A' + k;
				toPrint += player;
				if (i == 3 && j == 3) continue;
				if (players[k].xDir == 1) toPrint += '>';
				if (players[k].xDir == -1) toPrint += '<';
				if (players[k].yDir == 1) toPrint += 'v';
				if (players[k].yDir == -1) toPrint += '^';
			}
			if (!playerOnSquare) {
				if (i % 3 == 0 && j % 3 == 0 || i == 1 && (j == 1 || j == 5) || i == 5 && (j == 1 || j == 5)) {
					toPrint = 'S';
				}
				else toPrint = '#';
			}
			std::cout << std::setw(6) << toPrint;
		}
	}
	std::cout << "\n";
}
void move(std::list<Square>::iterator& posInList, 
Player& player, std::list<Square>::iterator end, int dice, int turn) {
	auto currPos = posInList;
	auto currPlayerState = player;
	for (int i = 0; i < dice; ++i) {
		++posInList;

		if (posInList == end) {
			std::cout << player.name << " rolled too high!";
			posInList = currPos;
			player = currPlayerState;
			return;
		}
		player.move();
		player.setDir(posInList->turnLeft, posInList->turnRight);
	}
}


bool checkPwnage(Player moved, Player &waiting, bool safeSquare) {
	if (moved == waiting && !safeSquare) {
		return true;
	}
	else return false;
}




