// What is the greatest product of four adjacent numbers in the
// same direction (up, down, left, right, or diagonally) in the 20×20 grid?

#include <iostream>
#include "SimpleTimer.h"
#include <fstream>

#define PATH "Problem_11_Largest_product_in_a_grid.txt"

using namespace std;

void fill_arr(int **arr)
{
    ifstream file;
    file.open(PATH);

    if (!file.is_open())
        return;

    int buff;

    for (int i = 0; i < 20; ++i)
        for (int j = 0; j < 20; ++j)
            file >> arr[i][j];

    file.close();
}

int largest_row(int** arr)
{
    int result = 0;

    for (int i = 0; i < 20; ++i)
        for (int j = 0; j < 16; ++j)
            if (arr[i][j] * arr[i][j + 1] * arr[i][j + 2] * arr[i][j + 3] > result)
                result = arr[i][j] * arr[i][j + 1] * arr[i][j + 2] * arr[i][j + 3];

    return result;
}

int largest_column(int** arr)
{
    int result = 0;

    for (int i = 0; i < 16; ++i)
        for (int j = 0; j < 20; ++j)
            if (arr[i][j] * arr[i + 1][j] * arr[i + 2][j] * arr[i + 3][j] > result)
                result = arr[i][j] * arr[i + 1][j] * arr[i + 2][j] * arr[i + 3][j];

    return result;
}

int largest_diag(int** arr)
{
    int result = 0;
    int x, y;

    for (int i = 0; i < 16; ++i)
        for (int j = 0; j < 16; ++j)
            if (arr[i][j] * arr[i + 1][j + 1] * arr[i + 2][j + 2] * arr[i + 3][j + 3] > result)
                result = arr[i][j] * arr[i + 1][j + 1] * arr[i + 2][j + 2] * arr[i + 3][j + 3];

    for (int i = 0; i < 16; ++i)
        for (int j = 4; j < 20; ++j)
            if (arr[i][j] * arr[i + 1][j - 1] * arr[i + 2][j - 2] * arr[i + 3][j - 3] > result)
                result = arr[i][j] * arr[i + 1][j - 1] * arr[i + 2][j - 2] * arr[i + 3][j - 3];

    return result;
}

int find_largest_product()
{
    SimpleTimer timer;

    int** arr;

    arr = new int* [20];
    for (int i = 0; i < 20; ++i)
        arr[i] = new int[20];

    fill_arr(arr);

    int result = largest_column(arr);
    if (result < largest_row(arr))
        result = largest_row(arr);
    if (result < largest_diag(arr))
        result = largest_diag(arr);

    for (int i = 0; i < 20; ++i)
        delete[] arr[i];
    delete[] arr;

    return result;
}

int main()
{
    cout << "The greatest product of four adjacent numbers in the grid = "
        << find_largest_product() << endl << endl; 

    return 0;
}