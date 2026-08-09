#include <iostream>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int k = n / 2;
    int ans = 0;
    if (n % 2)
    {
        ans = 2 * (k + 1) * (k + 2);
    }
    else
    {
        ans = (k + 1) * (k + 1);
    }

    printf("%d \n", ans);

    return 0;
}