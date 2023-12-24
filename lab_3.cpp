#include <iostream>
using namespace std;

#define N 4 //allows the programmer to give a name to a constant value before the program is compiled

// function to check whether the position is safe or not 
bool SafePlace(int board[N][N], int row, int column) //смотрим, безопасное ли место или нет для королевы. row - строка, column - столбец
{
    int i, j;

    for (i = 0; i < column; i++) //горизонталь - нельзя
        if (board[row][i])
            return false;

    for (i = row, j = column; i >= 0 && j >= 0; i--, j--) //диагональ - нельзя
        if (board[i][j])
            return false;

    for (i = row, j = column; j >= 0 && i < N; i++, j--) //вертикаль - нельзя
        if (board[i][j])
            return false;

    return true;
}

bool Solution(int board[N][N], int column)
{
    if (column >= N)
        return true;


    for (int i = 0; i < N; i++) 
    {
        if (SafePlace(board, i, column)) 
        {
            board[i][column] = 1; //если SafePlace true, тогда ставим королеву

            if (Solution(board, column + 1)) 
                return true;

            board[i][column] = 0; //если Solution в следующей колонке той же строки 1, то убираем королеву
        }
    }


    return false;
}

void FinishPrint(int board[N][N]) //вывод решения
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << " " << board[i][j];
        cout << "\n";
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int board[N][N] = {{0},
                       {0}}; //изначально, все клетки 0

    if (Solution(board, 0) == false) //если нет способа расположить N королев на N*N board
    {
        cout << "Нет решения";
        return 0;
    }

    FinishPrint(board); //если есть решение, вывод его

    return true;
    return 0;
}