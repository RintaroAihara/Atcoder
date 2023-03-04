#include <iostream>
using namespace std;

int main(void)
{
    long int H;
    int i, j;
    int count = 0;
    long int sum, answer;

    cin >> H;

    while (H > 0)
    {
        H /= 2;
        count++;
    }

    for (i = 0, sum = 1; i < count; i++)
    {
        sum *= 2;
    }

    answer =  (sum - 1);

    cout << answer << endl;

    return 0;
}