#include <iostream>
#include <string>

using namespace std;

bool isMatch(string s, string p)
{
    vector<vector<int>> dp(p.size(), vector<int>(s.size(), 0));
    int num_stars = 0;

    for (int i = 0; i < dp.size(); i++)
    {
        char curr = p[i];
        if (curr == '*')
        {
            num_stars += 2;
        }
        for (int j = max(0, i - num_stars); j < dp[0].size(); j++)
        {
            if (curr == '*')
            {
                char prev = p[i - 1];
                if (i - 2 >= 0)
                {
                    if (dp[i - 2][j] == 1)
                    {
                        dp[i][j] = 1;
                    }
                    else
                    {
                        if (i - num_stars == j)
                        {
                            continue;
                        }
                        if (j - 1 >= 0)
                        {
                            if (dp[i - 2][j - 1] == 1 || dp[i][j - 1] == 1)
                            {
                                if (s[j] == prev || prev == '.')
                                {
                                    dp[i][j] = 1;
                                }
                                else
                                {
                                    dp[i][j] = 0;
                                }
                            }
                        }
                        else
                        {
                            if (s[j] == prev || prev == '.')
                            {
                                dp[i][j] = 1;
                            }
                            else
                            {
                                dp[i][j] = 0;
                            }
                        }
                    }
                }
                else
                {
                    if (j == 0)
                    {
                        if (prev == s[j] || prev == '.')
                        {
                            dp[i][j] = 1;
                        }
                        else
                        {
                            dp[i][j] = 0;
                        }
                    }
                    else
                    {
                        if (dp[i][j - 1])
                        {
                            if (prev == s[j] || prev == '.')
                            {
                                dp[i][j] = 1;
                            }
                            else
                            {
                                dp[i][j] = 0;
                            }
                        }
                        else
                        {
                            dp[i][j] = 0;
                        }
                    }
                }
            }
            else if (curr == '.')
            {
                if ((i - 1) >= 0 && (j - 1) >= 0)
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    if (j == 0)
                    {
                        dp[i][j] = 1;
                    }
                    else
                    {
                        dp[i][j] = 0;
                    }
                }
            }
            else
            {
                if ((i - 1) >= 0 && (j - 1) >= 0)
                {
                    if ((s[j] == curr) && (dp[i - 1][j - 1] == 1))
                    {
                        dp[i][j] = 1;
                    }
                    else
                    {
                        dp[i][j] = 0;
                    }
                }
                else
                {
                    if (j == 0)
                    {
                        if (curr == s[j])
                        {
                            dp[i][j] = 1;
                        }
                        else
                        {
                            dp[i][j] = 0;
                        }
                    }
                }
            }
        }
    }

    return dp[dp.size() - 1][dp[0].size() - 1];
}

int main()
{
    cout << endl;
    string s = "aab";
    string p = "c*a*b";
    cout << isMatch(s, p) << endl;
    ;
}