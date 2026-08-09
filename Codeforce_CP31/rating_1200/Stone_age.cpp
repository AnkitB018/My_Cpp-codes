#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<long long> vec(n);

    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
        sum += vec[i];
    }

    vector<vector<long long>> queries;
    queries.reserve(q);

    for (int i = 0; i < q; i++)
    {
        vector<long long> row;
        int temp;
        cin >> temp;
        row.push_back(temp);
        if (temp == 1)
        {
            int idx;
            cin >> idx;
            row.push_back(idx);
            long long val;
            cin >> val;
            row.push_back(val);
        }
        else
        {
            long long val;
            cin >> val;
            row.push_back(val);
        }
        queries.push_back(row);
    }

    bool first_two = false;
    long long last;
    set<int> changed;

    for (int i = 0; i < q; i++)
    {
        if (queries[i][0] == 1)
        {
            int idx = queries[i][1];
            idx--;
            long long rep = queries[i][2];
            if (first_two)
            {
                if (changed.find(idx) == changed.end())
                {
                    sum -= last;
                    sum += rep;
                    vec[idx] = rep;
                    changed.insert(idx);
                }
                else
                {
                    sum -= vec[idx];
                    sum += rep;
                    vec[idx] = rep;
                }
            }
            else
            {
                sum -= vec[idx];
                sum += rep;
                vec[idx] = rep;
            }
        }
        else
        {
            long long val = queries[i][1];
            last = val;
            sum = n * val;
            first_two = true;
            changed.clear();
        }

        cout << sum << endl;
    }

    return 0;
}