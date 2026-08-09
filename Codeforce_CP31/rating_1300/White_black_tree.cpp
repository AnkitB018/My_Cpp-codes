#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

pair<int, int> DFS(vector<pair<char, vector<int>>> &adj_mat, int start, long long &ans)
{
    int white = 0;
    int black = 0;
    if (adj_mat[start].first == 'W')
    {
        white++;
    }
    else
    {
        black++;
    }

    for (auto ele : adj_mat[start].second)
    {
        auto [w, b] = DFS(adj_mat, ele, ans);
        white += w;
        black += b;
    }

    if (white == black)
    {
        ans++;
    }

    return {white, black};
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        vector<int> vertices(n - 1);
        for (int i = 0; i < n - 1; i++)
        {
            cin >> vertices[i];
        }

        string s;
        cin >> s;
        vector<pair<char, vector<int>>> adj_mat(n + 1);
        for (int i = 1; i <= n; i++)
        {
            adj_mat[i].first = s[i - 1];
        }

        for (int i = 0; i < n - 1; i++)
        {
            adj_mat[vertices[i]].second.push_back(i + 2);
        }

        long long ans = 0;

        DFS(adj_mat, 1, ans);
        

        cout << ans << endl;
    }

    return 0;
}