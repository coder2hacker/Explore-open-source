#include <iostream>
using namespace std;


int subset(int input[], int n, int output[][20])
{
    if (n == 0)
    {
        output[0][0] = {0};
        return 1;
    }

    int c = subset(input, n - 1, output);

    for (int i = 0; i < c; i++)
    {
        int size = output[i][0];
        for (int j = 0; j <= size; j++)
        {
            output[i + c][j] = output[i][j];
        }
        output[i + c][size + 1] = input[n - 1];
        output[i + c][0]++;
    }
    return c * 2;
}

int main()
{
    int input[20], length, output[35000][20];
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];

    int size = subset(input, length, output);

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}