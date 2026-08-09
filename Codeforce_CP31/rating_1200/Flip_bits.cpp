#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;

        vector<bool> canFlip(n, false);
        int num1 = 0;
        int num2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == '1')
            {
                num1++;
            }
            else
            {
                num2++;
            }
            if (num1 == num2)
            {
                canFlip[i] = true;
            }
        }

        bool isflipped = false;
        bool ispos = true;

        for (int i = n - 1; i >= 0; i--)
        {
            if (!isflipped)
            {
                // bits are normal
                if (a[i] != b[i])
                {
                    if (canFlip[i])
                    {
                        isflipped = true;
                    }
                    else
                    {
                        ispos = false;
                        break;
                    }
                }
            }
            else
            {
                // bits are flipped in a so 1 is 0 and 0 is 1
                if (a[i] == b[i])
                { // it was same but we have flipped it so not same anymore, check if we can flip again
                    if (canFlip[i])
                    {
                        isflipped = false;
                    }
                    else
                    {
                        ispos = false;
                        break;
                    }
                }
            }
        }
        if (ispos)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}