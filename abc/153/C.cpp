#include <iostream>
using namespace std;

void quicksort(int *A, int p, int r);
int partition(int *A, int p, int r);
void swap(int *x, int *y);

int main(void)
{
    int N, K;
    int H[300000];
    int i, j;
    int max;
    int ij;
    long int sum;

    cin >> N >> K;

    for (i = 0; i < N; i++)
    {
        cin >> H[i];
    }

    quicksort(H, 0, N - 1);

    for (i = 0, sum = 0; i <= N - K - 1; i++)
    {
        sum += H[i];
    }

    cout << sum << endl;

    return 0;
}

void swap(int *x, int *y)
{
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

void quicksort(int *A, int p, int r)
{
    int q;
    if (p < r)
    {
        q = partition(A, p, r);
        quicksort(A, p, q);
        quicksort(A, q + 1, r);
    }
}

int partition(int *A, int p, int r)
{
    int i, j, x, q;

    x = A[p];
    i = p;
    j = r;

    while (i < j)
    {
        while (A[j] > x)
        {
            j--;
        }

        while (A[i] < x)
        {
            i++;
        }

        if (i < j)
        {
            swap(&A[i], &A[j]);
            j--;
            i++;
        }
    }

    if (i == j && A[j] > x)
    {
        j = j - 1;
    }

    q = j;

    return q;
}
