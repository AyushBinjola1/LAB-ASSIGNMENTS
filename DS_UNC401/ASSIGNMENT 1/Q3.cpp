#include <iostream>
using namespace std;

int main()
{
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    int a[rows][cols], b[rows][cols], sum[rows][cols], diff[rows][cols];

    cout << "Enter elements of first matrix:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> a[i][j];

    cout << "Enter elements of second matrix:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> b[i][j];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
            diff[i][j] = a[i][j] - b[i][j];
        }

    cout << "\nSum of matrices:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++) cout << sum[i][j] << " ";
        cout << endl;
    }

    cout << "\nDifference of matrices:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++) cout << diff[i][j] << " ";
        cout << endl;
    }

    return 0;
}
