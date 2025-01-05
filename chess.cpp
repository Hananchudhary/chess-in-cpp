#include <iostream>
#include <fstream>
#include<windows.h>
using namespace std;
const int s = 9;
const int rows = 8;
const int cols = 8;
struct abc
{
    char** parent;
    char*** child;
    int size;
    float* score;
    float realscore;
};
void setColor(int foreground, int background = 0) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int colorAttribute = (background << 4) | foreground; // Combine foreground and background
    SetConsoleTextAttribute(hConsole, colorAttribute);
}
void getRowColbyLeftClick(int& rpos, int& cpos)
{
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD Events;
    INPUT_RECORD InputRecord;
    SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT |
        ENABLE_EXTENDED_FLAGS);
    do
    {
        ReadConsoleInput(hInput, &InputRecord, 1, &Events);
        if (InputRecord.Event.MouseEvent.dwButtonState ==

            FROM_LEFT_1ST_BUTTON_PRESSED)

        {
            cpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
            rpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
            break;
        }
    } while (true);
}
void gotoRowCol(int rpos, int cpos)
{
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = rpos;
    scrn.Y = cpos;
    SetConsoleCursorPosition(hOuput, scrn);
}
void printCell(int h, int k, int color) {
    char ch = 255;
    setColor(color, color);
    for (int i = 0;i < 16;i++) {
        gotoRowCol(40 * (k + 4), i + (h * 16));
        for (int j = 0;j < 40;j++) {
            cout << ch;
        }
        cout << endl;
    }
}
void printpawn(int h, int k, int bclor, int pclor) {
    for (int i = 0;i < 16;i++) {
        gotoRowCol(40 * (k + 4), i + (h * 16));
        for (int j = 0;j < 40;j++) {
            if (i < 2 || i>13) {
                setColor(bclor, bclor);
                cout << " ";
            }
            else if (i < 4) {
                if (j < 17) {
                    setColor(bclor, bclor);
                    cout << " ";
                }
                else if (j < 23) {
                    setColor(pclor, pclor);
                    cout << "*";
                }
                else {
                    setColor(bclor, bclor);
                    cout << " ";
                }
            }
            else if (i < 6) {
                if (j < 13 + i) {
                    setColor(bclor, bclor);
                    cout << " ";
                }
                else if (j < 27 - i) {
                    setColor(pclor, pclor);
                    cout << "*";
                }
                else {
                    setColor(bclor, bclor);
                    cout << " ";
                }
            }
            else if (i < 8) {
                if (j < 18) {
                    setColor(bclor, bclor);
                    cout << " ";
                }
                else if (j < 22) {
                    setColor(pclor, pclor);
                    cout << "*";
                }
                else {
                    setColor(bclor, bclor);
                    cout << " ";
                }
            }
            else if (i < 11) {
                if (j < 25 - i) {
                    setColor(bclor, bclor);
                    cout << " ";
                }
                else if (j < 15 + i) {
                    setColor(pclor, pclor);
                    cout << "*";
                }
                else {
                    setColor(bclor, bclor);
                    cout << " ";
                }
            }
            else {
                if (j < 14) {
                    setColor(bclor, bclor);
                    cout << " ";
                }
                else if (j < 26) {
                    setColor(pclor, pclor);
                    cout << "*";
                }
                else {
                    setColor(bclor, bclor);
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
}
void printrook(int h, int k, int bclor, int pclor) {
    for (int i = 0;i < 16;i++) {
        gotoRowCol(40 * (k + 4), i + (h * 16));
        for (int j = 0;j < 40;j++) {
            if (i < 2) {
                setColor(bclor, bclor);
                cout << " ";
            }
            else if (i < 4) {
                if (((j + 1) % 4) == 0) {
                    setColor(bclor, bclor);
                    cout << " ";
                }
                else {
                    if (j < 10) {
                        setColor(bclor, bclor);
                        cout << " ";
                    }
                    else if (j < 29) {
                        setColor(pclor, pclor);
                        cout << "*";
                    }
                    else {
                        setColor(bclor, bclor);
                        cout << " ";
                    }
                }
            }
            else if (i < 5) {
                if (j < 10) {
                    setColor(bclor, bclor);
                    cout << " ";
                }
                else if (j < 29) {
                    setColor(pclor, pclor);
                    cout << "*";
                }
                else {
                    setColor(bclor, bclor);
                    cout << " ";
                }
            }
            else if (i < 7) {
                if (j < 8 + i) {
                    setColor(bclor, bclor);
                    cout << " ";
                }
                else if (j < 31 - i) {
                    setColor(pclor, pclor);
                    cout << " ";
                }
                else {
                    setColor(bclor, bclor);
                    cout << " ";
                }
            }
            else if (i < 9) {
                if (j < 14) {
                    setColor(bclor, bclor);
                    cout << " ";
                }
                else if (j < 25) {
                    setColor(pclor, pclor);
                    cout << " ";
                }
                else {
                    setColor(bclor, bclor);
                    cout << " ";
                }
            }
            else if (i < 11) {
                if (j < 22 - i) {
                    setColor(bclor, bclor);
                    cout << " ";
                }
                else if (j < 17 + i) {
                    setColor(pclor, pclor);
                    cout << " ";
                }
                else {
                    setColor(bclor, bclor);
                    cout << " ";
                }
            }
            else if (i < 13) {
                if (j < 10) {
                    setColor(bclor, bclor);
                    cout << " ";
                }
                else if (j < 29) {
                    setColor(pclor, pclor);
                    cout << "*";
                }
                else {
                    setColor(bclor, bclor);
                    cout << " ";
                }
            }
            else {
                setColor(bclor, bclor);
                cout << " ";
            }
        }
        cout << endl;
    }
}
void printknight(int h, int k, int bclor, int pclor) {
    for (int i = 0;i < 16;i++) {
        gotoRowCol(40 * (k + 4), i + (h * 16));
        for (int j = 0;j < 40;j++) {
            if (i < 2) {
                setColor(bclor, bclor);
                cout << " ";
            }
            else if (i < 3) {
                if (j < 20) {
                    setColor(bclor, bclor);
                    cout << " ";
                }
                else if (j < 24) {
                    setColor(pclor, pclor);
                    cout << "*";
                }
                else {
                    setColor(bclor, bclor);
                    cout << " ";
                }
            }
            else if (i < 6) {
                if (j < 21 - (3 * i)) {
                    setColor(bclor, bclor);
                    cout << " ";
                }
                else if (i == 4 && (j == 18 || j == 19)) {
                    setColor(4, 4);
                    cout << " ";
                }
                else if (j < 24 + i) {
                    setColor(pclor, pclor);
                    cout << "*";
                }
                else {
                    setColor(bclor, bclor);
                    cout << " ";
                }
            }
            else if (i < 7) {
                if (j < 6) {
                    setColor(bclor, bclor);
                    cout << " ";
                }
                else if (j < 29) {
                    setColor(pclor, pclor);
                    cout << "*";
                }
                else {
                    setColor(bclor, bclor);
                    cout << " ";
                }
            }
            else if (i < 9) {
                if (j < -17 + (i * 4)) {
                    setColor(bclor, bclor);
                    cout << " ";
                }
                else if (j < 29) {
                    setColor(pclor, pclor);
                    cout << "*";
                }
                else {
                    setColor(bclor, bclor);
                    cout << " ";
                }
            }
            else if (i < 10) {
                if (j < 15) {
                    setColor(bclor, bclor);
                    cout << " ";
                }
                else if (j < 29) {
                    setColor(pclor, pclor);
                    cout << "*";
                }
                else {
                    setColor(bclor, bclor);
                    cout << " ";
                }
            }
            else if (i < 12) {
                if (j < (20 - i)) {
                    setColor(bclor, bclor);
                    cout << " ";
                }
                else if (j < (38 - i)) {
                    setColor(pclor, pclor);
                    cout << "*";
                }
                else {
                    setColor(bclor, bclor);
                    cout << " ";
                }
            }
            else if (i < 14) {
                if (j < 8) {
                    setColor(bclor, bclor);
                    cout << " ";
                }
                else if (j < 29) {
                    setColor(pclor, pclor);
                    cout << "*";
                }
                else {
                    setColor(bclor, bclor);
                    cout << " ";
                }
            }
            else {
                setColor(bclor, bclor);
                cout << " ";
            }
        }
        cout << endl;
    }
}
void printqueen(int h, int k, int bclor, int pclor) {
    for (int i = 0;i < 16;i++) {
        gotoRowCol(40 * (k + 4), i + (h * 16));
        for (int j = 0;j < 40;j++) {
            if (i < 1) {
                setColor(bclor, bclor);
                cout << " ";
            }
            else if (i < 5) {
                if (j < 21 - (i * 3)) {
                    setColor(bclor, bclor);
                    cout << " ";
                }
                else if (j < 19 + (i * 3)) {
                    setColor(pclor, pclor);
                    cout << "*";
                }
                else {
                    setColor(bclor, bclor);
                    cout << " ";
                }
            }
            else if (i < 7) {
                if (j < 1 + (i * 2)) {
                    setColor(bclor, bclor);
                    cout << " ";
                }
                else if (j < 34 - i) {
                    setColor(pclor, pclor);
                    cout << "*";
                }
                else {
                    setColor(bclor, bclor);
                    cout << " ";
                }
            }
            else if (i < 11) {
                if (j < 14) {
                    setColor(bclor, bclor);
                    cout << " ";
                }
                else if (j < 27) {
                    setColor(pclor, pclor);
                    cout << "*";
                }
                else {
                    setColor(bclor, bclor);
                    cout << " ";
                }
            }
            else if (i < 13) {
                if (j < 23 - i) {
                    setColor(bclor, bclor);
                    cout << " ";
                }
                else if (j < 18 + i) {
                    setColor(pclor, pclor);
                    cout << "*";
                }
                else {
                    setColor(bclor, bclor);
                    cout << " ";
                }
            }
            else if (i < 15) {
                if (j < 10) {
                    setColor(bclor, bclor);
                    cout << " ";
                }
                else if (j < 31) {
                    setColor(pclor, pclor);
                    cout << "*";
                }
                else {
                    setColor(bclor, bclor);
                    cout << " ";
                }
            }
            else {
                setColor(bclor, bclor);
                cout << " ";
            }
        }
        cout << endl;
    }
}
void printking(int h, int k, int bclor, int pclor) {
    for (int i = 0;i < 16;i++) {
        gotoRowCol(40 * (k + 4), i + (h * 16));
        for (int j = 0;j < 40;j++) {
            if (i < 1) {
                setColor(bclor, bclor);
                cout << " ";
            }
            else if (i < 3) {
                if (j < 18) {
                    setColor(bclor, bclor);
                    cout << " ";
                }
                else if (j < 22) {
                    setColor(pclor, pclor);
                    cout << "*";
                }
                else {
                    setColor(bclor, bclor);
                    cout << " ";
                }
            }
            else if (i < 5) {
                if (j < 16) {
                    setColor(bclor, bclor);
                    cout << " ";
                }
                else if (j < 24) {
                    setColor(pclor, pclor);
                    cout << "*";
                }
                else {
                    setColor(bclor, bclor);
                    cout << " ";
                }
            }
            else if (i < 6) {
                if (j < 18) {
                    setColor(bclor, bclor);
                    cout << " ";
                }
                else if (j < 22) {
                    setColor(pclor, pclor);
                    cout << "*";
                }
                else {
                    setColor(bclor, bclor);
                    cout << " ";
                }
            }
            else if (i < 8) {
                if (j < 9 + i) {
                    setColor(bclor, bclor);
                    cout << " ";
                }
                else if (j < 31 - i) {
                    setColor(pclor, pclor);
                    cout << " ";
                }
                else {
                    setColor(bclor, bclor);
                    cout << " ";
                }
            }
            else if (i < 11) {
                if (j < 16) {
                    setColor(bclor, bclor);
                    cout << " ";
                }
                else if (j < 24) {
                    setColor(pclor, pclor);
                    cout << " ";
                }
                else {
                    setColor(bclor, bclor);
                    cout << " ";
                }
            }
            else if (i < 13) {
                if (j < 26 - i) {
                    setColor(bclor, bclor);
                    cout << " ";
                }
                else if (j < 14 + i) {
                    setColor(pclor, pclor);
                    cout << " ";
                }
                else {
                    setColor(bclor, bclor);
                    cout << " ";
                }
            }
            else if (i < 15) {
                if (j < 12) {
                    setColor(bclor, bclor);
                    cout << " ";
                }
                else if (j < 28) {
                    setColor(pclor, pclor);
                    cout << " ";
                }
                else {
                    setColor(bclor, bclor);
                    cout << " ";
                }
            }
            else {
                setColor(bclor, bclor);
                cout << " ";
            }
        }
        cout << endl;
    }
}
void printbishop(int h, int k, int bclor, int pclor) {
    for (int i = 0;i < 16;i++) {
        gotoRowCol(40 * (k + 4), i + (h * 16));
        for (int j = 0;j < 40;j++) {
            if (i < 2) {
                setColor(bclor, bclor);
                cout << " ";
            }
            else if (i < 5) {
                if (j < 19 - i) {
                    setColor(bclor, bclor);
                    cout << " ";
                }
                else if (j < 21 + i) {
                    if (i == 3 && (j == 21)) {
                        setColor(bclor, bclor);
                        cout << " ";
                    }
                    else if (i == 4 && (j == 20)) {
                        setColor(bclor, bclor);
                        cout << " ";
                    }
                    else {
                        setColor(pclor, pclor);
                        cout << "*";
                    }
                }
                else {
                    setColor(bclor, bclor);
                    cout << " ";
                }
            }
            else if (i < 7) {
                if (j < 11 + i) {
                    setColor(bclor, bclor);
                    cout << " ";
                }
                else if (j < 29 - i) {
                    setColor(pclor, pclor);
                    cout << "*";
                }
                else {
                    setColor(bclor, bclor);
                    cout << " ";
                }
            }
            else if (i < 10) {
                if (j < 17) {
                    setColor(bclor, bclor);
                    cout << " ";
                }
                else if (j < 23) {
                    setColor(pclor, pclor);
                    cout << "*";
                }
                else {
                    setColor(bclor, bclor);
                    cout << " ";
                }
            }
            else if (i < 12) {
                if (j < 26 - i) {
                    setColor(bclor, bclor);
                    cout << " ";
                }
                else if (j < 14 + i) {
                    setColor(pclor, pclor);
                    cout << "*";
                }
                else {
                    setColor(bclor, bclor);
                    cout << " ";
                }
            }
            else if (i < 14) {
                if (j < 13) {
                    setColor(bclor, bclor);
                    cout << " ";
                }
                else if (j < 27) {
                    setColor(pclor, pclor);
                    cout << "*";
                }
                else {
                    setColor(bclor, bclor);
                    cout << " ";
                }
            }
            else {
                setColor(bclor, bclor);
                cout << " ";
            }
        }
    }
}
void printpiece(char** board, int x, int y, int dx, int dy, int bcolor, int& pcolor) {
    if (board[x][y] == 'p') {
        pcolor = 1;
        printpawn(dx, dy, bcolor, pcolor);
    }
    else if (board[x][y] == 'r') {
        pcolor = 1;
        printrook(dx, dy, bcolor, pcolor);
    }
    else if (board[x][y] == 'h') {
        pcolor = 1;
        printknight(dx, dy, bcolor, pcolor);
    }
    else if (board[x][y] == 'q') {
        pcolor = 1;
        printqueen(dx, dy, bcolor, pcolor);
    }
    else if (board[x][y] == 'k') {
        pcolor = 1;
        printking(dx, dy, bcolor, pcolor);
    }
    else if (board[x][y] == 'b') {
        pcolor = 1;
        printbishop(dx, dy, bcolor, pcolor);
    }
    else if (board[x][y] == 'P') {
        pcolor = 0;
        printpawn(dx, dy, bcolor, pcolor);
    }
    else if (board[x][y] == 'H') {
        pcolor = 0;
        printknight(dx, dy, bcolor, pcolor);
    }
    else if (board[x][y] == 'R') {
        pcolor = 0;
        printrook(dx, dy, bcolor, pcolor);
    }
    else if (board[x][y] == 'Q') {
        pcolor = 0;
        printqueen(dx, dy, bcolor, pcolor);
    }
    else if (board[x][y] == 'B') {
        pcolor = 0;
        printbishop(dx, dy, bcolor, pcolor);
    }
    else if (board[x][y] == 'K') {
        pcolor = 0;
        printking(dx, dy, bcolor, pcolor);
    }
    else {
        printCell(dx, dy, bcolor);
    }
}
void printuiboard(char** board) {
    int bcolor = 0, pcolor = 0;
    int row, col;
    setColor(0, 0);
    for (int h = 0;h < rows;h++) {
        for (int k = 0;k < cols;k++) {
            if ((k + (h + 1)) % 2 != 0) {
                bcolor = 255;
            }
            else {
                bcolor = 136;
            }
            printpiece(board, h, k, h, k, bcolor, pcolor);
            cout << endl;
        }
    }
    setColor(0, 0);
}
void clickLocation(int& x, int& y) {
    int row, col, temp = 0;
    getRowColbyLeftClick(x, y);
    y = y / 16;
    x = (x / 40) - 4;
    temp = x;
    x = y;
    y = temp;
}
void printmenu() {
    char ch = 219;
    for (int i = 0;i < 20;i++) {
        gotoRowCol(200, i + 10);
        for (int j = 0;j < 200;j++) {
            if (i > 3 && i < 16) {
                if ((i == 4 || i == 9) && (j > 114 && j < 136)) {
                    setColor(0, 0);
                    cout << ch;
                }
                else if (j == 115 || j == 116) {
                    setColor(0, 0);
                    cout << ch;
                }
                else if ((j == 135 || j == 136) && i < 10) {
                    setColor(0, 0);
                    cout << ch;
                }
                else if ((i == 4 || i == 15) && (j > 63 && j < 68)) {
                    setColor(0, 0);
                    cout << ch;
                }
                else if (j == 65 || j == 66) {
                    setColor(0, 0);
                    cout << ch;
                }
                else {
                    setColor(255, 255);
                    cout << ch;
                }
            }
            else {
                setColor(255, 255);
                cout << ch;
            }
        }
        cout << endl;
    }
    for (int i = 0;i < 20;i++) {
        gotoRowCol(200, i + 50);
        for (int j = 0;j < 200;j++) {
            if (i > 3 && i < 16) {
                if ((i == 4 || i == 9) && (j > 114 && j < 136)) {
                    setColor(0, 0);
                    cout << ch;
                }
                else if (j == 115 || j == 116) {
                    setColor(0, 0);
                    cout << ch;
                }
                else if ((j == 135 || j == 136) && i < 10) {
                    setColor(0, 0);
                    cout << ch;
                }
                else if ((i == 4 || i == 15) && (j > 57 && j < 69)) {
                    setColor(0, 0);
                    cout << ch;
                }
                else if (j == 65 || j == 66 || j == 60 || j == 61) {
                    setColor(0, 0);
                    cout << ch;
                }
                else {
                    setColor(255, 255);
                    cout << ch;
                }
            }
            else {
                setColor(255, 255);
                cout << ch;
            }
        }
        cout << endl;
    }
}
void boardinitialization(char** board) {
    ifstream reader("board.txt");
    for (int i = 0;i < rows;i++) {
        for (int j = 0;j < cols;j++) {
            reader >> board[i][j];
        }
    }
    reader.close();
}
bool validsource(char** board, int x, int y, int turn) {
    if (x < 0 || y < 0 || x >= rows || y >= cols)
        return false;
    if (turn == 1) {
        if (board[x][y] >= 'a' && board[x][y] <= 'z')
            return true;
        else
            return false;
    }
    else {
        if (board[x][y] >= 'A' && board[x][y] <= 'Z')
            return true;
        else
            return false;
    }
}
char pieceidentify(char** board, int x, int y) {
    return board[x][y];
}
bool pawnvalidmove1(char** board, int x, int y, int dx, int dy, char turn) {
    if (board[dx][dy] >= 'a' && board[dx][dy] <= 'z')
        return false;
    if (x == 6) {
        if ((dx == x - 2 || dx == x - 1) && y == dy && board[x - 1][y] == '.' && board[dx][dy] == '.') {
            return true;
        }
        else if (((dx == x - 1 && dy == y + 1) || (dx == x - 1 && dy == y - 1)) && board[dx][dy] >= 'A' && board[dx][dy] <= 'Z') {
            return true;
        }
    }
    else if (((dx == x - 1 && dy == y + 1) || (dx == x - 1 && dy == y - 1)) && board[dx][dy] >= 'A' && board[dx][dy] <= 'Z') {
        return true;
    }
    else {
        if (dx == x - 1 && dy == y && board[dx][dy] == '.')
            return true;
        else
            return false;
    }
    return false;
}
bool pawnvalidmove2(char** board, int x, int y, int dx, int dy, char turn) {
    if (board[dx][dy] >= 'A' && board[dx][dy] <= 'Z')
        return false;
    if (x == 1) {
        if ((dx == x + 2 || dx == x + 1) && y == dy && board[x + 1][y] == '.' && board[dx][dy] == '.') {
            return true;
        }
        else if (((dx == x + 1 && dy == y - 1) || (dx == x + 1 && dy == y + 1)) && board[dx][dy] >= 'a' && board[dx][dy] <= 'z') {
            return true;
        }
    }
    else if (((dx == x + 1 && dy == y - 1) || (dx == x + 1 && dy == y + 1)) && board[dx][dy] >= 'a' && board[dx][dy] <= 'z') {
        return true;
    }
    else {
        if (dx == x + 1 && dy == y && board[dx][dy] == '.')
            return true;
        else
            return false;
    }
    return false;
}
bool rockvalidmove(char** board, int x, int y, int dx, int dy, int turn) {
    if (turn == 1) {
        if (board[dx][dy] >= 'a' && board[dx][dy] <= 'z')
            return false;
    }
    else if (turn == 0) {
        if (board[dx][dy] >= 'A' && board[dx][dy] <= 'Z')
            return false;
    }
    bool flag = false;
    if (y == dy) {
        for (int i = x - 1;i >= 0;i--) {
            if (i == dx) {
                flag = true;
                break;
            }
            else if (board[i][y] != '.') {
                flag = false;
                break;
            }
        }
        if (flag)
            return true;
        for (int i = x + 1;i < rows;i++) {
            if (i == dx) {
                flag = true;
                break;
            }
            else if (board[i][y] != '.') {
                flag = false;
                break;
            }
        }
        if (flag)
            return true;
    }
    else if (x == dx) {
        for (int i = y - 1;i >= 0;i--) {
            if (i == dy) {
                flag = true;
                break;
            }
            else if (board[x][i] != '.') {
                flag = false;
                break;
            }
        }
        if (flag)
            return true;
        for (int i = y + 1;i < cols;i++) {
            if (i == dy) {
                flag = true;
                break;
            }
            else if (board[x][i] != '.') {
                flag = false;
                break;
            }
        }
        if (flag)
            return true;
    }
    else {
        return false;
    }
    return false;
}
bool bishopvalidmove(char** board, int x, int y, int dx, int dy, int turn) {
    bool flag = false;
    if (turn == 1) {
        if (board[dx][dy] >= 'a' && board[dx][dy] <= 'z')
            return false;
    }
    else if (turn == 0) {
        if (board[dx][dy] >= 'A' && board[dx][dy] <= 'Z')
            return false;
    }
    for (int i = x + 1, j = y + 1;i < rows && j < cols;i++, j++) {
        if (i == dx && j == dy) {
            flag = true;
            break;
        }
        else if (board[i][j] != '.') {
            break;
        }
    }
    if (flag)
        return true;
    for (int i = x - 1, j = y - 1;i >= 0 && j >= 0;i--, j--) {
        if (i == dx && j == dy) {
            flag = true;
            break;
        }
        else if (board[i][j] != '.') {
            break;
        }
    }
    if (flag)
        return true;
    for (int i = x + 1, j = y - 1;i < rows && j >= 0;i++, j--) {
        if (i == dx && j == dy) {
            flag = true;
            break;
        }
        else if (board[i][j] != '.') {
            break;
        }
    }
    if (flag)
        return true;
    for (int i = x - 1, j = y + 1;i >= 0 && j < cols;i--, j++) {
        if (i == dx && j == dy) {
            flag = true;
            break;
        }
        else if (board[i][j] != '.') {
            break;
        }
    }
    if (flag)
        return true;
    else
        return false;
}
bool queenvalidmove(char** board, int x, int y, int dx, int dy, int turn) {
    if (turn == 1) {
        if (board[dx][dy] >= 'a' && board[dx][dy] <= 'z')
            return false;
    }
    else if (turn == 0) {
        if (board[dx][dy] >= 'A' && board[dx][dy] <= 'Z')
            return false;
    }
    if (rockvalidmove(board, x, y, dx, dy, turn) || bishopvalidmove(board, x, y, dx, dy, turn))
        return true;
    else
        return false;
}
bool horsevalidmove(char** board, int x, int y, int dx, int dy, int turn) {
    if (turn == 1) {
        if (board[dx][dy] >= 'a' && board[dx][dy] <= 'z')
            return false;
    }
    else if (turn == 0) {
        if (board[dx][dy] >= 'A' && board[dx][dy] <= 'Z')
            return false;
    }
    if ((dx == x + 2 && dy == y + 1) || (dx == x + 2 && dy == y - 1) || (dx == x - 2 && dy == y + 1) || (dx == x - 2 && dy == y - 1) || (dx == x + 1 && dy == y + 2) || (dx == x - 1 && dy == y + 2) || (dx == x + 1 && dy == y - 2) || (dx == x - 1 && dy == y - 2)) {
        return true;
    }
    else {
        return false;
    }
}
bool kingvalidmove(char** board, int x, int y, int dx, int dy, int turn) {
    if (turn == 1) {
        if (board[dx][dy] >= 'a' && board[dx][dy] <= 'z')
            return false;
    }
    else if (turn == 0) {
        if (board[dx][dy] >= 'A' && board[dx][dy] <= 'Z')
            return false;
    }
    if ((dx == x + 1 || dx == x - 1 || dx == x) && (dy == y + 1 || dy == y - 1 || dy == y) && !(dx == x && dy == y)) {
        return true;
    }
    else {
        return false;
    }
}
bool validmove(char** board, int x, int y, int dx, int dy, int turn) {
    if ((dx < 0 || dy < 0 || dx >= rows || dy >= cols) || (x < 0 || y < 0 || x >= rows || y >= cols))
        return false;
    char sor = pieceidentify(board, x, y);
    if (!validsource(board, x, y, turn)) {
        return false;
    }
    if (sor == 'p' && turn == 1) {
        if (pawnvalidmove1(board, x, y, dx, dy, turn))
            return true;
        else
            return false;
    }
    else if (sor == 'P' && turn == 0) {
        if (pawnvalidmove2(board, x, y, dx, dy, turn))
            return true;
        else
            return false;
    }
    else if (sor == 'k') {
        if (kingvalidmove(board, x, y, dx, dy, 1))
            return true;
        else
            return false;
    }
    else if (sor == 'K') {
        if (kingvalidmove(board, x, y, dx, dy, 0))
            return true;
        else
            return false;
    }
    else if (sor == 'q') {
        if (queenvalidmove(board, x, y, dx, dy, 1))
            return true;
        else
            return false;
    }
    else if (sor == 'Q') {
        if (queenvalidmove(board, x, y, dx, dy, 0))
            return true;
        else
            return false;
    }
    else if (sor == 'r') {
        if (rockvalidmove(board, x, y, dx, dy, 1))
            return true;
        else
            return false;
    }
    else if (sor == 'R') {
        if (rockvalidmove(board, x, y, dx, dy, 0))
            return true;
        else
            return false;
    }
    else if (sor == 'h') {
        if (horsevalidmove(board, x, y, dx, dy, 1))
            return true;
        else
            return false;
    }
    else if (sor == 'H') {
        if (horsevalidmove(board, x, y, dx, dy, 0))
            return true;
        else
            return false;
    }
    else if (sor == 'b') {
        if (bishopvalidmove(board, x, y, dx, dy, 1))
            return true;
        else
            return false;
    }
    else if (sor == 'B') {
        if (bishopvalidmove(board, x, y, dx, dy, 0))
            return true;
        else
            return false;
    }
    else {
        return false;
    }
}
void placement(char** board, int dx, int dy, int x, int y) {
    char sor = pieceidentify(board, x, y);
    board[x][y] = '.';
    board[dx][dy] = sor;
}
void piecemenu() {
    printpawn(3, 1, 42, 0);
    printbishop(3, 2, 42, 0);
    printknight(3, 3, 42, 0);
    printrook(3, 4, 42, 0);
    printqueen(3, 5, 42, 0);
}
void printbuttons() {
    char ch = 219;
    for (int i = 0;i < rows;i++) {
        gotoRowCol(60, i + 20);
        for (int j = 0;j < 30;j++) {
            if (i > 0 && i < 7) {
                if (j == 10 || j == 11 || j == 20 || j == 21) {
                    setColor(0, 0);
                    cout << ch;
                }
                else if (i == 6 && j > 11 && j < 21) {
                    setColor(0, 0);
                    cout << ch;
                }
                else {
                    setColor(255, 255);
                    cout << ch;
                }
            }
            else {
                setColor(255, 255);
                cout << ch;
            }
        }
        cout << endl;
    }for (int i = 0;i < rows;i++) {
        gotoRowCol(60, i + 40);
        for (int j = 0;j < 30;j++) {
            if (i > 0 && i < 7) {
                if (j == 10 || j == 11) {
                    setColor(0, 0);
                    cout << ch;
                }
                else if (i < 5 && (j == 20 || j == 21)) {
                    setColor(0, 0);
                    cout << ch;
                }
                else if (i > 4 && i < 7 && (j == 16 || j == 17)) {
                    setColor(0, 0);
                    cout << ch;
                }
                else if (i == 1 && j > 11 && j < 21) {
                    setColor(0, 0);
                    cout << ch;
                }
                else if (i == 4 && j > 11 && j < 21) {
                    setColor(0, 0);
                    cout << ch;
                }
                else {
                    setColor(255, 255);
                    cout << ch;
                }
            }
            else {
                setColor(255, 255);
                cout << ch;
            }
        }
        cout << endl;
    }
}
int pawnpromotion(char** board, int& x, int& y) {
    for (int i = 0;i < rows;i++) {
        if (board[0][i] == 'p') {
            x = 0;
            y = i;
            return 1;
        }
        else if (board[7][i] == 'P') {
            x = 0;
            y = i;
            return 2;
        }
    }
    return 0;
}
void printvalidmoves(char** board, int x, int y, int turn) {
    int pcolor = 0;
    for (int i = 0;i < rows;i++) {
        for (int j = 0;j < cols;j++) {
            if (validmove(board, x, y, i, j, turn)) {
                if (board[i][j] != '.') {
                    printpiece(board, i, j, i, j, 4, pcolor);
                }
                else {
                    printCell(i, j, 134);
                }
            }
        }
    }
}
void removevalidmoves(char** board, int x, int y, int turn) {
    int pcolor = 0;
    for (int i = 0;i < rows;i++) {
        for (int j = 0;j < cols;j++) {
            if (validmove(board, x, y, i, j, turn)) {
                if ((i + (j + 1)) % 2 != 0) {
                    if (board[i][j] != '.') {
                        printpiece(board, i, j, i, j, 255, pcolor);
                    }
                    else {
                        printCell(i, j, 255);
                    }
                }
                else {
                    if (board[i][j] != '.') {
                        printpiece(board, i, j, i, j, 136, pcolor);
                    }
                    else {
                        printCell(i, j, 136);
                    }
                }
            }
        }
    }
}
float calculatescore(char** board) {
    float matscore1 = 0, matscore2 = 0;
    float cenactive1 = 0, cenactive2 = 0;
    float attack1 = 0, attack2 = 0;
    float kingsafe1 = 0, kingsafe2 = 0;
    float pieactive1 = 0, pieactive2 = 0;
    float score1 = 0, score2 = 0;
    for (int i = 0;i < rows;i++) {
        for (int j = 0;j < cols;j++) {
            if (board[i][j] >= 'a' && board[i][j] <= 'z') {
                if (board[i][j] == 'p') {
                    if ((i == 3 || i == 4) && (j == 3 || j == 4))
                        cenactive1 = cenactive1 + 0.5;
                    matscore1++;
                }
                else if (board[i][j] == 'h') {
                    if ((i == 3 || i == 4) && (j == 3 || j == 4))
                        cenactive1++;
                    matscore1 = matscore1 + 3;
                }
                else if (board[i][j] == 'b') {
                    if ((i == 3 || i == 4) && (j == 3 || j == 4))
                        cenactive1++;
                    matscore1 = matscore1 + 3.5;
                }
                else if (board[i][j] == 'r')
                    matscore1 = matscore1 + 5;
                else if (board[i][j] == 'q')
                    matscore1 = matscore1 + 9;
                else if (board[i][j] == 'k') {
                    if (i > 0 && j > 0 && (board[i - 1][j - 1] >= 'a' && board[i - 1][j - 1] <= 'z') && (board[i - 1][j] >= 'a' && board[i - 1][j] <= 'z') && (board[i - 1][j - 1] >= 'a' && board[i - 1][j + 1] <= 'z'))
                        kingsafe1++;
                    matscore1 = matscore1 + 9000;
                }
                for (int h = 0;h < rows;h++) {
                    for (int k = 0;k < cols;k++) {
                        if (board[i][j] == 'p') {
                            if (validmove(board, h, k, i, j, 0))
                                attack2++;
                        }
                        else if (board[i][j] == 'h') {
                            if (validmove(board, i, j, h, k, 1))
                                pieactive1 = pieactive1 + 0.1;
                            if (validmove(board, h, k, i, j, 0))
                                attack2 += 3;
                        }
                        else if (board[i][j] == 'b') {
                            if (validmove(board, i, j, h, k, 1))
                                pieactive1 = pieactive1 + 0.15;
                            if (validmove(board, h, k, i, j, 0))
                                attack2 += 3.5;
                        }
                        else if (board[i][j] == 'r') {
                            if (validmove(board, i, j, h, k, 1))
                                pieactive1 = pieactive1 + 0.2;
                            if (validmove(board, h, k, i, j, 0))
                                attack2 += 5;
                        }
                        else if (board[i][j] == 'q') {
                            if (validmove(board, i, j, h, k, 1))
                                pieactive1 = pieactive1 + 0.25;
                            if (validmove(board, h, k, i, j, 0))
                                attack2 += 9;
                        }
                        else if (board[i][j] == 'k') {
                            if (validmove(board, h, k, i, j, 0))
                                attack2 += 900;
                        }
                    }
                }
            }
            else if (board[i][j] >= 'A' && board[i][j] <= 'Z') {
                if (board[i][j] == 'P') {
                    if ((i == 3 || i == 4) && (j == 3 || j == 4))
                        cenactive2 = cenactive2 + 0.5;
                    matscore2++;
                }
                else if (board[i][j] == 'H') {
                    if ((i == 3 || i == 4) && (j == 3 || j == 4))
                        cenactive2++;
                    matscore2 = matscore2 + 3;
                }
                else if (board[i][j] == 'B') {
                    if ((i == 3 || i == 4) && (j == 3 || j == 4))
                        cenactive2++;
                    matscore2 = matscore2 + 3.5;
                }
                else if (board[i][j] == 'R')
                    matscore2 = matscore2 + 5;
                else if (board[i][j] == 'Q')
                    matscore2 = matscore2 + 9;
                else if (board[i][j] == 'K') {
                    if (j > 0 && (board[i + 1][j - 1] >= 'A' && board[i + 1][j - 1] <= 'Z') && (board[i + 1][j] >= 'A' && board[i + 1][j] <= 'Z') && (board[i + 1][j + 1] >= 'A' && board[i + 1][j + 1] <= 'Z'))
                        kingsafe2++;
                    matscore2 = matscore2 + 9000;
                }
                for (int h = 0;h < rows;h++) {
                    for (int k = 0;k < cols;k++) {
                        if (board[i][j] == 'P') {
                            if (validmove(board, h, k, i, j, 1))
                                attack1++;
                        }
                        else if (board[i][j] == 'H') {
                            if (validmove(board, i, j, h, k, 0))
                                pieactive2 = pieactive2 + 0.1;
                            if (validmove(board, h, k, i, j, 1))
                                attack1 += 3;
                        }
                        else if (board[i][j] == 'B') {
                            if (validmove(board, i, j, h, k, 0))
                                pieactive2 = pieactive2 + 0.15;
                            if (validmove(board, h, k, i, j, 1))
                                attack1 += 3.5;
                        }
                        else if (board[i][j] == 'R') {
                            if (validmove(board, i, j, h, k, 0))
                                pieactive2 = pieactive2 + 0.2;
                            if (validmove(board, h, k, i, j, 1))
                                attack1 += 5;
                        }
                        else if (board[i][j] == 'Q') {
                            if (validmove(board, i, j, h, k, 0))
                                pieactive2 = pieactive2 + 0.25;
                            if (validmove(board, h, k, i, j, 1))
                                attack1 += 9;
                        }
                        else if (board[i][j] == 'K') {
                            if (validmove(board, h, k, i, j, 1))
                                attack1 += 900;
                        }
                    }
                }
            }
        }
    }
    score1 = matscore1 + (cenactive1 * 1.2) + (pieactive1 * 0.8) + (kingsafe1 * 1.5) + (attack1 * 1.1);
    score2 = matscore2 + (cenactive2 * 1.2) + (pieactive2 * 0.8) + (kingsafe2 * 1.5) + (attack2 * 1.1);
    return (score1 - score2);
}
void duplicateboard(char** board, char** duplicate) {
    for (int i = 0;i < rows;i++) {
        for (int j = 0;j < cols;j++) {
            duplicate[i][j] = board[i][j];
        }
    }
}
bool check(char** board, int x, int y, int dx, int dy, int turn, int temp) {
    int turn2 = 0, pclor, bclor, ct = 0, temx = 0, temy = 0;
    char** duplicate = new char* [rows];
    for (int i = 0;i < rows;i++) {
        duplicate[i] = new char[cols];
    }
    char ch;
    bool flag = true;
    if (turn == 1) {
        pclor = 1;
        ch = 'k';
        turn2 = 0;
    }
    else {
        pclor = 0;
        turn2 = 1;
        ch = 'K';
    }
    duplicateboard(board, duplicate);
    placement(duplicate, dx, dy, x, y);
    for (int i = 0;i < rows;i++) {
        for (int j = 0;j < cols;j++) {
            if (duplicate[i][j] == ch) {
                for (int h = 0;h < rows;h++) {
                    for (int k = 0;k < cols;k++) {
                        if (validmove(duplicate, h, k, i, j, turn2)) {
                            if (temp == 0) {
                                if (board[x][y] == ch) {
                                    printking(x, y, 4, pclor);
                                }
                                else {
                                    printking(i, j, 4, pclor);
                                }
                            }
                            return false;
                        }
                    }
                }
                if (temp == 0) {
                    if ((i + (j + 1)) % 2 != 0) {
                        bclor = 255;
                    }
                    else {
                        bclor = 136;
                    }
                    printking(i, j, bclor, pclor);
                }
            }
        }
    }
    for (int i = 0;i < rows;i++) {
        delete[] duplicate[i];
    }
    delete[] duplicate;
    return true;
}
bool checkmate(char** board, int turn) {
    char ch;
    int x = 0, y = 0, pclor;
    if (turn == 1) {
        pclor = 1;
        ch = 'k';
    }
    else {
        pclor = 0;
        ch = 'K';
    }
    bool flag = true;
    char** duplicate = new char* [rows];
    for (int i = 0;i < rows;i++) {
        duplicate[i] = new char[cols];
    }
    for (int i = 0;i < rows;i++) {
        for (int j = 0;j < cols;j++) {
            if (board[i][j] == ch) {
                x = i;
                y = j;
            }
            for (int h = 0;h < rows;h++) {
                for (int k = 0;k < cols;k++) {
                    if (validmove(board, i, j, h, k, turn) && check(board, i, j, h, k, turn, 1)) {
                        flag = false;
                        break;
                    }
                }
                if (!flag)
                    break;
            }
            if (!flag)
                break;
        }
        if (!flag)
            break;
    }
    for (int i = 0;i < rows;i++) {
        delete[] duplicate[i];
    }
    delete[] duplicate;
    if (flag) {
        printking(x, y, 4, pclor);
        return true;
    }
    return false;
}
float* regrowscore(float*& ptr, int& size) {
    float* temp = new float[size + 1];
    for (int i = 0;i < size;i++) {
        temp[i] = ptr[i];
    }
    size++;
    delete[] ptr;
    return temp;
}
float maxscore2(float* ptr, int size) {
    float max = ptr[0];
    for (int i = 0;i < size;i++) {
        if (*(ptr + i) > max)
            max = (*(ptr + i));
    }
    return max;
}
float minscore2(float* ptr, int size) {
    float min = ptr[0];
    for (int i = 0;i < size;i++) {
        if (*(ptr + i) < min)
            min = (*(ptr + i));
    }
    return min;
}
char*** regrow3d(char***& board, int& size) {
    char*** temp = new char** [size + 1];
    for (int j = 0;j < size + 1;j++) {
        temp[j] = new char* [s];
        for (int i = 0;i < s;i++) {
            temp[j][i] = new char[s];
        }
    }
    for (int h = 0;h < size;h++) {
        for (int i = 0;i < rows;i++) {
            for (int j = 0;j < cols;j++) {
                temp[h][i][j] = board[h][i][j];
            }
        }
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < s; ++j) {
            delete[] board[i][j];
        }
        delete[] board[i];
    }
    delete[] board;
    size++;
    return temp;
}
void duplicatechild(char*** board, char***& duplicate, int& size) {
    duplicate = new char** [size];
    for (int i = 0;i < size;i++) {
        duplicate[i] = new char* [s];
        for (int j = 0; j < s; ++j) {
            duplicate[i][j] = new char[s];
        }
    }
    for (int h = 0;h < size;h++) {
        for (int i = 0;i < rows;i++) {
            for (int j = 0;j < cols;j++) {
                duplicate[h][i][j] = board[h][i][j];
            }
        }
    }
}
void duplicateparent(char** board, char**& duplicate) {
    duplicate = new char* [s];
    for (int i = 0;i < rows;i++) {
        duplicate[i] = new char[s];
    }
    for (int h = 0;h < rows;h++) {
        for (int i = 0;i < cols;i++) {
            duplicate[h][i] = board[h][i];
        }
    }
}
void deleteduplicatechild(char*** duplicate) {
    for (int i = 0; i < s; ++i) {
        for (int j = 0; j < s; ++j) {
            delete[] duplicate[i][j];
        }
        delete[] duplicate[i];
    }
    delete[] duplicate;
}
void deleteduplicateparent(char** duplicate) {
    for (int i = 0; i < s; ++i) {
        delete[] duplicate[i];
    }
    delete[] duplicate;
}
abc treeforAI(char** board, int depth) {
    struct abc branch;
    struct abc res;
    int size = 1, turn = 1, pt = 0, size2 = 1;
    float sab = 0, sc = 0;
    char*** duplicate = new char** [size];
    char** result = new char* [s];
    for (int i = 0;i < s;i++) {
        result[i] = new char[s];
    }
    for (int i = 0;i < size;i++) {
        duplicate[i] = new char* [s];
        for (int j = 0; j < s; ++j) {
            duplicate[i][j] = new char[s];
        }
    }
    for (int i = 0;i < rows;i++) {
        for (int j = 0;j < cols;j++) {
            for (int h = 0;h < rows;h++) {
                for (int k = 0;k < cols;k++) {
                    if (validmove(board, i, j, h, k, (depth + 1) % 2)) {
                        duplicateboard(board, duplicate[pt]);
                        placement(duplicate[pt], h, k, i, j);
                        pt++;
                        duplicate = regrow3d(duplicate, size);
                    }
                }
            }
        }
    }
    size--;
    duplicateparent(board, branch.parent);
    duplicatechild(duplicate, branch.child, size);
    branch.size = size;
    branch.score = new float[size];
    if (depth < 2) {
        for (int i = 0;i < branch.size;i++) {
            res = treeforAI(branch.child[i], depth + 1);
            branch.score[i] = res.realscore;
        }
    }
    if (depth == 2) {
        for (int i = 0;i < branch.size;i++) {
            branch.score[i] = calculatescore(branch.child[i]);
        }
    }
    if ((depth + 1) % 2 == 0) {
        sab = minscore2(branch.score, size);
    }
    else {
        sab = maxscore2(branch.score, branch.size);
    }
    branch.realscore = sab;
    return branch;
}
void AImovement(abc& AI, char** board, int& x, int& y, int& dx, int& dy) {
    for (int i = 0;i < AI.size;i++) {
        if (AI.score[i] == AI.realscore) {
            for (int h = 0;h < rows;h++) {
                for (int k = 0;k < cols;k++) {
                    if (board[h][k] != AI.child[i][h][k]) {
                        if (AI.child[i][h][k] == '.') {
                            x = h;
                            y = k;
                        }
                        else {
                            dx = h;
                            dy = k;
                        }
                    }
                }
            }
            return;
        }
    }
}
int main()
{
    struct abc AI;
    int depth = 0;
    int pt = 0, size = 1;
    char*** board = new char** [s];
    for (int i = 0;i < size;i++) {
        board[i] = new char* [s];
        for (int j = 0;j < s;j++) {
            board[i][j] = new char[s];
        }
    }
    int x = 0, y = 0, dx = 0, dy = 0;
    int i = 1, bcolor = 0, pcolor = 0, player = 1;
    printmenu();
    while (true) {
        getRowColbyLeftClick(x, y);
        if (x > 169 && x < 371 && y>9 && y < 31) {
            player = 1;
            setColor(0, 0);
            system("cls");
            break;
        }
        else if (x > 169 && x < 371 && y>49 && y < 71) {
            player = 2;
            setColor(0, 0);
            system("cls");
            break;
        }
    }
    boardinitialization(board[pt]);
    printbuttons();
    printuiboard(board[pt]);
    board = regrow3d(board, size);
    pt++;
    duplicateboard(board[pt - 1], board[pt]);
    while (true) {
        bool flag = false;
        cout << endl;
        if (i % 2 == 1) {
            if (player == 1) {
                if (checkmate(board[pt], i % 2)) {
                    return 0;
                }
                AI = treeforAI(board[pt], depth);
                AImovement(AI, board[pt], x, y, dx, dy);
                if ((x + (y + 1)) % 2 != 0) {
                    bcolor = 255;
                }
                else {
                    bcolor = 136;
                }
                printCell(x, y, bcolor);
                if ((dx + (dy + 1)) % 2 != 0) {
                    bcolor = 255;
                }
                else {
                    bcolor = 136;
                }
                printpiece(board[pt], x, y, dx, dy, bcolor, pcolor);
                placement(board[pt], dx, dy, x, y);
                int pawncheck = pawnpromotion(board[pt], x, y);
                if (pawncheck == 1) {
                    for (int i = 0;i < rows;i++) {
                        if (board[pt][0][i] == 'p') {
                            board[pt][0][i] = 'q';
                            break;
                        }
                    }
                    setColor(0, 0);
                    system("cls");
                    printbuttons();
                    printuiboard(board[pt]);
                }
            }
            else if (player == 2) {
                while (true) {
                    if (checkmate(board[pt], i % 2)) {
                        return 0;
                    }
                    while (true) {
                        clickLocation(x, y);
                        if (x == 1 && (y == -2 || y == -3)) {
                            if (pt > 0) {
                                if (player == 1) {
                                    i++;
                                    if (pt == size - 1)
                                        pt = pt - 3;
                                    else
                                        pt = pt - 2;
                                }
                                else if (pt == size - 1)
                                    pt = pt - 2;
                                else
                                    pt--;
                                flag = true;
                                setColor(0, 0);
                                system("cls");
                                printbuttons();
                                printuiboard(board[pt]);
                                break;
                            }
                        }
                        else if (x == 2 && (y == -2 || y == -3)) {
                            if (pt < (size - 1)) {
                                if (player == 1)
                                    pt++;
                                pt++;
                                flag = false;
                                setColor(0, 0);
                                system("cls");
                                printbuttons();
                                printuiboard(board[pt]);
                                break;
                            }
                        }
                        else if (validsource(board[pt], x, y, i % 2)) {
                            printvalidmoves(board[pt], x, y, i % 2);
                            break;
                        }
                    }
                    if (flag)
                        break;
                    clickLocation(dx, dy);
                    removevalidmoves(board[pt], x, y, i % 2);
                    if (validmove(board[pt], x, y, dx, dy, i % 2) && check(board[pt], x, y, dx, dy, i % 2, 0)) {
                        if ((x + (y + 1)) % 2 != 0) {
                            bcolor = 255;
                        }
                        else {
                            bcolor = 136;
                        }
                        printCell(x, y, bcolor);
                        if ((dx + (dy + 1)) % 2 != 0) {
                            bcolor = 255;
                        }
                        else {
                            bcolor = 136;
                        }
                        printpiece(board[pt], x, y, dx, dy, bcolor, pcolor);
                        placement(board[pt], dx, dy, x, y);
                        int pawncheck = pawnpromotion(board[pt], x, y);
                        if (pawncheck == 1) {
                            piecemenu();
                            while (true) {
                                getRowColbyLeftClick(x, y);
                                clickLocation(x, y);
                                if (x == 3 && y == 1) {
                                    for (int i = 0;i < rows;i++) {
                                        if (board[pt][0][i] == 'p') {
                                            board[pt][0][i] = 'p';
                                        }
                                    }
                                    setColor(0, 0);
                                    system("cls");
                                    printbuttons();
                                    printuiboard(board[pt]);
                                    break;
                                }
                                else if (x == 3 && y == 2) {
                                    for (int i = 0;i < rows;i++) {
                                        if (board[pt][0][i] == 'p') {
                                            board[pt][0][i] = 'b';
                                        }
                                    }
                                    setColor(0, 0);
                                    system("cls");
                                    printbuttons();
                                    printuiboard(board[pt]);
                                    break;
                                }
                                else if (x == 3 && y == 3) {
                                    for (int i = 0;i < rows;i++) {
                                        if (board[pt][0][i] == 'p') {
                                            board[pt][0][i] = 'h';
                                        }
                                    }
                                    setColor(0, 0);
                                    system("cls");
                                    printbuttons();
                                    printuiboard(board[pt]);
                                    break;
                                }
                                else if (x == 3 && y == 4) {
                                    for (int i = 0;i < rows;i++) {
                                        if (board[pt][0][i] == 'p') {
                                            board[pt][0][i] = 'r';
                                        }
                                    }
                                    setColor(0, 0);
                                    system("cls");
                                    printbuttons();
                                    printuiboard(board[pt]);
                                    break;
                                }
                                else if (x == 3 && y == 5) {
                                    for (int i = 0;i < rows;i++) {
                                        if (board[pt][0][i] == 'p') {
                                            board[pt][0][i] = 'q';
                                        }
                                    }
                                    setColor(0, 0);
                                    system("cls");
                                    printbuttons();
                                    printuiboard(board[pt]);
                                    break;
                                }
                                else {
                                    continue;
                                }
                                setColor(0, 0);
                                system("cls");
                                printbuttons();
                                printuiboard(board[pt]);
                            }
                        }
                        break;
                    }
                    else if (dx == 1 && (dy == -2 || dy == -3)) {
                        if (pt > 0) {
                            if (player == 1) {
                                i++;
                                if (pt == size - 1)
                                    pt = pt - 3;
                                else
                                    pt = pt - 2;
                            }
                            else if (pt == size - 1)
                                pt = pt - 2;
                            else
                                pt--;
                            flag = true;
                            setColor(0, 0);
                            system("cls");
                            printbuttons();
                            printuiboard(board[pt]);
                            break;
                        }
                    }
                    else if (dx == 2 && (dy == -2 || dy == -3)) {
                        if (pt < (size - 1)) {
                            if (player == 1)
                                pt++;
                            pt++;
                            flag = true;
                            setColor(0, 0);
                            system("cls");
                            printbuttons();
                            printuiboard(board[pt]);
                            break;
                        }
                    }
                    if (flag)
                        break;
                }
            }
        }
        else {
            while (true) {
                if (checkmate(board[pt], i % 2)) {
                    return 0;
                }
                while (true) {
                    clickLocation(x, y);
                    if (x == 1 && (y == -2 || y == -3) && pt > 0) {
                        if (player == 1) {
                            i++;
                            if (pt == size - 1)
                                pt = pt - 3;
                            else
                                pt = pt - 2;
                        }
                        else if (pt == (size - 1))
                            pt = pt - 2;
                        else
                            pt--;
                        flag = true;
                        setColor(0, 0);
                        system("cls");
                        printbuttons();
                        printuiboard(board[pt]);
                        break;
                    }
                    else if (x == 2 && (y == -2 || y == -3) && (pt < (size - 1))) {
                        if (player == 1) {
                            pt++;
                            i++;
                        }
                        pt++;
                        flag = true;
                        setColor(0, 0);
                        system("cls");
                        printbuttons();
                        printuiboard(board[pt]);
                        break;
                    }
                    else if (validsource(board[pt], x, y, i % 2)) {
                        printvalidmoves(board[pt], x, y, i % 2);
                        break;
                    }
                }
                if (flag)
                    break;
                clickLocation(dx, dy);
                removevalidmoves(board[pt], x, y, i % 2);
                if (validmove(board[pt], x, y, dx, dy, i % 2) && check(board[pt], x, y, dx, dy, i % 2, 0)) {
                    if ((x + (y + 1)) % 2 != 0) {
                        bcolor = 255;
                    }
                    else {
                        bcolor = 136;
                    }
                    printCell(x, y, bcolor);
                    if ((dx + (dy + 1)) % 2 != 0) {
                        bcolor = 255;
                    }
                    else {
                        bcolor = 136;
                    }
                    printpiece(board[pt], x, y, dx, dy, bcolor, pcolor);
                    placement(board[pt], dx, dy, x, y);
                    int pawncheck = pawnpromotion(board[pt], x, y);
                    if (pawncheck == 2) {
                        piecemenu();
                        while (true) {
                            getRowColbyLeftClick(x, y);
                            clickLocation(x, y);
                            if (x == 3 && y == 1) {
                                for (int i = 0;i < rows;i++) {
                                    if (board[pt][7][i] == 'P') {
                                        board[pt][7][i] = 'P';
                                    }
                                }
                                setColor(0, 0);
                                system("cls");
                                printbuttons();
                                printuiboard(board[pt]);
                                break;
                            }
                            else if (x == 3 && y == 2) {
                                for (int i = 0;i < rows;i++) {
                                    if (board[pt][7][i] == 'P') {
                                        board[pt][7][i] = 'B';
                                    }
                                }
                                setColor(0, 0);
                                system("cls");
                                printbuttons();
                                printuiboard(board[pt]);
                                break;
                            }
                            else if (x == 3 && y == 3) {
                                for (int i = 0;i < rows;i++) {
                                    if (board[pt][7][i] == 'P') {
                                        board[pt][7][i] = 'H';
                                    }
                                }
                                setColor(0, 0);
                                system("cls");
                                printbuttons();
                                printuiboard(board[pt]);
                                break;
                            }
                            else if (x == 3 && y == 4) {
                                for (int i = 0;i < rows;i++) {
                                    if (board[pt][7][i] == 'P') {
                                        board[pt][7][i] = 'R';
                                    }
                                }
                                setColor(0, 0);
                                system("cls");
                                printbuttons();
                                printuiboard(board[pt]);
                                break;
                            }
                            else if (x == 3 && y == 5) {
                                for (int i = 0;i < rows;i++) {
                                    if (board[pt][7][i] == 'P') {
                                        board[pt][7][i] = 'Q';
                                    }
                                }
                                setColor(0, 0);
                                system("cls");
                                printbuttons();
                                printuiboard(board[pt]);
                                break;
                            }
                            else {
                                continue;
                            }
                        }
                    }
                    break;
                }
                else if (dx == 1 && (dy == -2 || dy == -3)) {
                    if (pt > 0) {
                        if (player == 1) {
                            i++;
                            if (pt == size - 1)
                                pt = pt - 3;
                            else
                                pt = pt - 2;
                        }
                        else if (pt == size - 1)
                            pt = pt - 2;
                        else
                            pt--;
                        flag = true;
                        setColor(0, 0);
                        system("cls");
                        printbuttons();
                        printuiboard(board[pt]);
                        break;
                    }
                }
                else if (dx == 2 && (dy == -2 || dy == -3)) {
                    if (pt < (size - 1)) {
                        if (player == 1) {
                            i++;
                            pt++;
                        }
                        pt++;
                        flag = true;
                        setColor(0, 0);
                        system("cls");
                        printbuttons();
                        printuiboard(board[pt]);
                        break;
                    }
                }
                if (flag)
                    break;
            }
        }
        i++;
        if (flag)
            continue;
        pt++;
        if (pt == size) {
            board = regrow3d(board, size);
        }
        duplicateboard(board[pt - 1], board[pt]);
    }
    for (int i = 0;i < size;i++) {
        for (int j = 0;j < s;j++) {
            delete[] board[i][j];
        }
        delete[] board[i];
    }
    delete[] board;
    return 0;
}