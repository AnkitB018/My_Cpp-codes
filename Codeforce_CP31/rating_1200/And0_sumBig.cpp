#include <iostream>
#include <algorithm>

using namespace std;

int MOD = 1e9 + 7;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        long long n, k;
        cin >> n >> k;

        long long ans = 1;

        for(int i=0 ; i<k ; i++){
            ans = (n*ans) %MOD;
        }

        cout << ans << endl;
    }

    return 0;
}