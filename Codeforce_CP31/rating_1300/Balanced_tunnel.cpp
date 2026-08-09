#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{

    int n;
    scanf("%d", &n);

    vector<int> enter(n);
    vector<int> exit(n);

    for (int i = 0; i < n; i++)
    {
        cin >> enter[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> exit[i];
    }

    set<int> visited;

    int l = 0;
    int r = 0;

    int cnt = 0;

    while (r < n && l < n)
    {
        int curr = enter[l++];
        if (visited.find(curr) != visited.end())
        {
            continue;
        }

        visited.insert(curr);

        while (r < n)
        {
            int now = exit[r++];
            if (now == curr)
            {
                break;
            }

            cnt++;
            visited.insert(now);
        }
    }

    printf("%d", cnt);
}