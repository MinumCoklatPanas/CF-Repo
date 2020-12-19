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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

pair<int,int> bf(int n,int x,int y)
{
    vector<int> firstRound,secondRound;
    for (int i = 1 ; i <= n ; i++) firstRound.push_back(i);
    secondRound = firstRound;
    int mn = INF;
    int mx = -INF;
    do
    {
        bool valid = 0;
        for (int i = 0 ; i < n ; i++) if (firstRound[i] == x)
        {
            if (secondRound[i] == y)
                valid = 1;
            break;
        }
        if (valid)
        {
            int rnk = 1;
            for (int i = 0 ; i < n ; i++) if (firstRound[i] != x)
            {
                int score = firstRound[i] + secondRound[i];
                rnk += (score <= x + y);
            }
            // if (rnk == 4)
            // {
            //     for (auto it : firstRound)
            //         cout << it << " ";
            //     cout << endl;
            //     for (auto it : secondRound)
            //         cout << it << " ";
            //     cout << endl << endl;
            // }
            mn = min(mn,rnk);
            mx = max(mx,rnk);
        }
    } while (next_permutation(secondRound.begin(),secondRound.end()));
    return make_pair(mn,mx);
}

void solve()
{
    int n,x,y;
    cin >> n >> x >> y;
    int mn,mx;
    //MIN
    if (x + y <= n)
    {
        mn = 1;
    }
    else
    {
        mn = min(n,x + y - n + 1);
    }

    //MAX
    if (x + y > n)
    {
        mx = n;
    }
    else
    {
        mx = x + y - 1;
    }
    cout << mn << " " << mx << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // for (int i = 5 ; i <= 9 ; i++)
    // {
    //     for (int j = 1 ; j <= i ; j++)
    //     {
    //         for (int k = 1 ; k <= i ; k++)
    //         {
    //             auto tmp = bf(i,j,k);
    //             cout << "(" << i << "," << j << "," << k << ") -> " << tmp.first << " " << tmp.second << endl;
    //         }
    //     }
    // }
    // return 0;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}