#include <cstdio>

int sudoku[10][10];

void readSudoku();
bool isAvailable(int row, int col, int val);
bool searchForAnswer(int beginRow = 1, int beginCol = 1);
void printSudoku();

int main()
{
    readSudoku();
    searchForAnswer();
    printSudoku();

    return 0;
}

int block(int pos)
{
    switch ((pos - 1) / 3)
    {
    case 0:
        return 1;
    case 1:
        return 4;
    case 2:
        return 7;
    default:
        return 0;
    }
}
bool isAvailable(int row, int col, int val)
{
    int rowBlock = block(row);
    int colBlock = block(col);

    for (int i = 1; i < 10; i++)
    {
        if (sudoku[row][i] == val || sudoku[i][col] == val)
            return false;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (sudoku[rowBlock + i][colBlock + j] == val)
                return false;
        }
    }
    return true;
}

bool searchForAnswer(int beginRow, int beginCol)
{
    if (beginRow > 9)
        return true;

    if (sudoku[beginRow][beginCol] != 0)
    {
        return searchForAnswer(beginRow + (beginCol + 1) / 10, (beginCol + 1) % 10);
    }

    for (int i = 1; i < 10; i++)
    {
        if (isAvailable(beginRow, beginCol, i))
        {
            sudoku[beginRow][beginCol] = i;
            if (searchForAnswer(beginRow + (beginCol + 1) / 10, (beginCol + 1) % 10))
            {
                return true;
            }
        }
    }
    sudoku[beginRow][beginCol] = 0;
    return false;
}

void readSudoku()
{
    char line[16];
    for (int i = 0; i < 9; i++)
    {
        fgets(line, 16, stdin);
        for (int j = 0; j < 9; j++)
        {
            sudoku[i + 1][j + 1] = line[j] - '0';
        }
    }
}

void printSudoku()
{
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            putchar(sudoku[i][j] + '0');
        }
        putchar('\n');
    }
}