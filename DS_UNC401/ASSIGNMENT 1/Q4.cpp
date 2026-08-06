#include <iostream>
using namespace std;

int SIZE = 10;

int main()
{
    // Hardcoded first 10x10 matrix
    int a[SIZE][SIZE] = {
        {1, 5, 2, 3, 8, 7, 4, 9, 6, 0},
        {4, 2, 6, 7, 1, 9, 5, 3, 8, 0},
        {7, 1, 9, 4, 6, 2, 3, 5, 0, 8},
        {2, 8, 4, 1, 5, 3, 9, 0, 7, 6},
        {9, 3, 7, 5, 0, 8, 1, 6, 2, 4},
        {5, 6, 1, 8, 9, 0, 2, 4, 3, 7},
        {3, 9, 0, 2, 4, 6, 8, 7, 1, 5},
        {8, 4, 5, 9, 3, 1, 7, 2, 0, 6},
        {6, 0, 8, 3, 2, 5, 4, 1, 9, 7},
        {0, 7, 3, 6, 8, 4, 0, 9, 5, 2}
    };

    // Hardcoded second 10x10 matrix
    int b[SIZE][SIZE] = {
        {2, 1, 3, 4, 0, 9, 5, 6, 7, 8},
        {9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
        {1, 3, 5, 7, 9, 0, 2, 4, 6, 8},
        {8, 6, 4, 2, 0, 9, 7, 5, 3, 1},
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
        {9, 0, 8, 1, 7, 2, 6, 3, 5, 4},
        {4, 5, 3, 6, 2, 7, 1, 8, 0, 9},
        {5, 4, 6, 3, 7, 2, 8, 1, 9, 0},
        {7, 9, 1, 8, 2, 0, 3, 6, 4, 5},
        {3, 2, 9, 5, 8, 6, 0, 4, 1, 7}
    };

    int res[SIZE][SIZE];
    int i, j, k;

    // multiply a and b, store in res
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            res[i][j] = 0;
            for (k = 0; k < SIZE; k++)
                res[i][j] = res[i][j] + a[i][k] * b[k][j];
        }
    }

    cout << "Product of the two matrices is:" << endl;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
            cout << res[i][j] << "\t";
        cout << endl;
    }

    return 0;
}