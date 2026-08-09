#include <iostream>
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
        string s;
        cin >> s;

        string ans = "";
        for (int i = 0; i < 26; i++)
        {
            char c = 'a' + i;
            if (s.find(c) == string::npos)
            {
                ans += c;
                break;
            }
        }

        if (ans != "")
        {
            cout << ans << endl;
            continue;
        }

        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                string curr = "";
                curr += ('a' + i);
                curr += ('a' + j);
                if (s.find(curr) == string::npos)
                {
                    ans += curr;
                    break;
                }
            }
            if (ans != "")
            {
                break;
            }
        }

        if (ans != "")
        {
            cout << ans << endl;
            continue;
        }

        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                for (int k = 0; k < 26; k++)
                {
                    string curr = "";
                    curr += ('a' + i);
                    curr += ('a' + j);
                    curr += ('a' + k);
                    if (s.find(curr) == string::npos)
                    {
                        ans += curr;
                        break;
                    }
                }
                if (ans != "")
                {
                    break;
                }
            }
            if (ans != "")
            {
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}