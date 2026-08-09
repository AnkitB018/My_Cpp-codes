#include <iostream>
#include <algorithm>

using namespace std;

long long pow(long long base, long long exp)
{
    long long res = 1;
    while (exp)
    {
        if (exp & 1)
        {
            res = res * base;
        }
        base = base * base;
        exp = exp >> 1;
    }
    return res;
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        long long ans;
        int k = 2;
        bool flag = false;
        while (1)
        {
            long long i = 3;
            long long res = (pow(k, i) - 1) / (k - 1);
            if (res == n)
            {
                flag = true;
                break;
            }
            else if (res > n)
            {
                break;
            }
            i++;
            while (1)
            {
                long long res = (pow(k, i) - 1) / (k - 1);
                if (res == n)
                {
                    flag = true;
                    break;
                }
                else if (res > n)
                {
                    break;
                }
                i++;
            }
            if (flag)
            {
                break;
            }
            k++;
        }

        if(flag){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }


    }

    return 0;
}