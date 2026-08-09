#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        string s;
        cin >> s;
        int ones = 0;
        int zeros = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                ones++;
            }
            else
            {
                zeros++;
            }
        }
        int t = 0;
        if (ones == zeros)
        {
            cout << 0 << endl;
            continue;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1' && zeros)
            {
                zeros--;
                t++;
            }
            else if (s[i] == '0' && ones)
            {
                ones--;
                t++;
            }
            else
            {
                break;
            }
        }
        cout << s.size() - t << endl;
    }

    return 0;
}