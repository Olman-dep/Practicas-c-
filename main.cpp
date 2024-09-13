
#include <iostream>
using namespace std;

// Función para imprimir el tablero
void printBoard(char board[3][3]) {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

// Función para verificar si hay un ganador
bool checkWin(char board[3][3], char player) {
    // Verificar filas y columnas
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || // fila
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) { // columna
            return true;
        }
    }
    // Verificar diagonales
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Función para verificar si el tablero está lleno
bool checkFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char currentPlayer = 'X';
    int row, col;

    while (true) {
        printBoard(board);
        cout << "Jugador " << currentPlayer << ", ingrese la fila (0, 1, 2) y la columna (0, 1, 2): ";
        cin >> row >> col;

        // Verificar entrada válida
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Movimiento inválido. Intente de nuevo." << endl;
            continue;
        }

        // Colocar el movimiento en el tablero
        board[row][col] = currentPlayer;

        // Verificar si el jugador actual ha ganado
        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            cout << "¡Jugador " << currentPlayer << " ha ganado!" << endl;
            break;
        }

        // Verificar si el tablero está lleno
        if (checkFull(board)) {
            printBoard(board);
            cout << "¡Es un empate!" << endl;
            break;
        }

        // Cambiar el turno
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
