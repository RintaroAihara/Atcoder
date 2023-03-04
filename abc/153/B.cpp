#include <iostream>
using namespace std;

int main(void)
{
    int H, N;
    int A[999999];
    int i,j;
    int ij;
    int max;

    cin >> H >> N;

    for (i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for ( i = 0; i < N; i++)
    {
        H -= A[i];
    }

    if (H <= 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}