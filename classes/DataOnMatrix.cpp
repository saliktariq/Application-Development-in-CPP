#include <conio.h>
#include <iostream>
#include <vector>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;

class DataOnMatrix {
public:
    DataOnMatrix(int xSize, int ySize, int initialData) :
        mXSize(xSize), mYSize(ySize), mMatrix(xSize, vector<int>(ySize, 0)) {
        mData = initialData;
        mXPos = mXSize / 2;
        mYPos = mYSize / 2;
        mMatrix[mXPos][mYPos] = mData;
    }

    void move(int direction) {
        switch (direction) {
        case KEY_UP:
            if (mXPos > 0) {
                mMatrix[mXPos][mYPos] = 0;
                mXPos--;
                mMatrix[mXPos][mYPos] = mData;
            }
            break;
        case KEY_DOWN:
            if (mXPos < mXSize - 1) {
                mMatrix[mXPos][mYPos] = 0;
                mXPos++;
                mMatrix[mXPos][mYPos] = mData;
            }
            break;
        case KEY_LEFT:
            if (mYPos > 0) {
                mMatrix[mXPos][mYPos] = 0;
                mYPos--;
                mMatrix[mXPos][mYPos] = mData;
            }
            break;
        case KEY_RIGHT:
            if (mYPos < mYSize - 1) {
                mMatrix[mXPos][mYPos] = 0;
                mYPos++;
                mMatrix[mXPos][mYPos] = mData;
            }
            break;
        default:
            break;
        }
    }

    void print() {
        for (int i = 0; i < mXSize; i++) {
            for (int j = 0; j < mYSize; j++) {
                cout << mMatrix[i][j] << "\t";
            }
            cout << endl;
        }
    }

private:
    int mXSize;
    int mYSize;
    int mData;
    int mXPos;
    int mYPos;
    vector<vector<int>> mMatrix;
};

int main() {
    DataOnMatrix dataOnMatrix(4, 4, 1);
    int input;
    do {
    	system("cls");
        dataOnMatrix.print();
        input = getch();
        dataOnMatrix.move(input);
    } while (input != 0);

    return 0;
}

