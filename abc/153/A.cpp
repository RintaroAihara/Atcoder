#include <iostream>
using namespace std;

int main(void)
{
    int H, A;
    int count = 0;

    cin >> H >> A;

    while (H > 0)
    {
        H -= A;
        count++;
    }

    cout << count << endl;

    return 0;
}
