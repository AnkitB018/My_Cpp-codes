#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l, r;
    l = 0;
    r = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] < s[l])
        {
            r = i;
            break;
        }
        if (s[i] > s[l])
        {
            l = i;
        }
    }

    if (r == 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        cout << l + 1 << " " << r + 1 << endl;
    }

    return 0;
}