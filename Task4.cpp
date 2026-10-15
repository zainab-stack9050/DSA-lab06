#include <iostream>
#include <iomanip>
using namespace std;

//using recursive function to solve the problem with 2D pointer arr
bool solveKnightTour(int n, int currX, int currY, int moveNum, int** board, int moveX[], int moveY[]) {
    //base case: If all N^2 squares are visited
    if (moveNum == n * n) {
        return true;}

    //all 8 possible moves are tried
    for (int i = 0; i < 8; i++) {
        int nextX = currX + moveX[i];
        int nextY = currY + moveY[i];

        //checking if next move is valid: within bounds and unvisited
        if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < n && board[nextX][nextY] == -1) {
            board[nextX][nextY] = moveNum; //marking the move as visited
            //recursively attempt to complete the tour
            if (solveKnightTour(n, nextX, nextY, moveNum + 1, board, moveX, moveY)) {
                return true;
            }
            //undo the move if it doesn't lead to a valid solution
            board[nextX][nextY] = -1; }
    }
    return false;
}

int main() {
    int n;
    cout << "Enter chessboard size (N): ";
    cin >> n;

    if (n <= 0) {
        cout << "Error!!! Board size must be greater than 0.\n";
        return 0; }

    int startX, startY;
    cout << "Enter starting row (0 to " << n - 1 << "): ";
    cin >> startX;
    cout << "Enter starting column (0 to " << n - 1 << "): ";
    cin >> startY;

    if (startX < 0 || startX >= n || startY < 0 || startY >= n) {
        cout << "Error!!! Invalid starting coordinates!\n";
        return 0;
    }

    //dynamic allocation of an N x N 2D array
    int** board = new int*[n];
    for (int i = 0; i < n; i++) {
        board[i] = new int[n];
        for (int j = 0; j < n; j++) {
            board[i][j] = -1; //initializing all squares as unvisited
        }
    }

    //define the possible L-shaped row and column offsets for a knight
    int moveX[8] = {2, 1, -1, -2, -2, -1, 1, 2};  // 8 in number
    int moveY[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    //place knight at the starting position 
    board[startX][startY] = 0;

    //start backtracking from move number 1
    if (solveKnightTour(n, startX, startY, 1, board, moveX, moveY)) {
        cout << "\nKnight's Tour found successfully!\n";
        cout << "-----------------------------------------------\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << setw(4) << board[i][j] << " ";
            }
            cout << "\n\n";}
    } else {
        cout << "\nNo valid Knight's Tour found for the specified starting position.\n";}
    //freeing memory to prevent leaks
    for (int i = 0; i < n; i++) {
        delete[] board[i];}
    delete[] board;

    return 0;
}