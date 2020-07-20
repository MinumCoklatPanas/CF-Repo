#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

bool cmp(pair<int,int> a,pair<int,int> b)
{
    return (a.second < b.second);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> tab(n);
    // vector<pair<int,int>> sorted(n);
    for (int i = 0 ; i < n ; i++)
    {
        cin >> tab[i];
        // sorted[i].first = tab[i];
        // sorted[i].second = i;
    }
    int last = -1;
    int cur = 0;
    while (cur < n)
    {
        int dist = cur - last - 1;
        if (tab[cur] == 0)
        {
            if (dist < 3)
            {
                for (int i = 1 ; i <= dist ; i++)
                {
                    if (i == 1)
                        cout << "pushStack\n";
                    else
                    if (i == 2)
                        cout << "pushQueue\n";
                }
                cout << dist;
                if (dist == 0)
                    cout << "\n";
                if (dist == 1)
                    cout << " popStack\n";
                if (dist == 2)
                    cout << " popStack popQueue\n";
            }
            else
            {
                vector<pair<int,int>> sorted;
                for (int i = last + 1 ; i < cur ; i++)
                    sorted.emplace_back(tab[i],i);
                sort(sorted.begin(),sorted.end());
                reverse(sorted.begin(),sorted.end());
                sorted.resize(3);
                sort(sorted.begin(),sorted.end(),cmp);
                for (int i = last + 1 ; i < cur ; i++)
                {
                    if (i == sorted[0].second)
                        cout << "pushQueue\n";
                    else
                    if (i == sorted[1].second)
                        cout << "pushFront\n";
                    else
                    if (i == sorted[2].second)
                        cout << "pushStack\n";
                    else
                    if (i < sorted[0].second)
                        cout << "pushStack\n";
                    else
                        cout << "pushQueue\n";
                }
                cout << "3 popStack popQueue popFront\n";
            }
            last = cur;
        }
        ++cur;
    }
    for (int i = last + 1 ; i < cur ; i++)
        cout << "pushQueue\n";
    return 0;
}