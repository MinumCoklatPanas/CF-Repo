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

void solve()
{
    // int n = 1 + rng() % 20;
    // int m = 1 + rng() % 20;
    // if (n < m) swap(n,m);
    string s,t;
    cin >> s >> t;
    // for (int i = 0 ; i < n ; i++)
    // {
    //     s += (char)('a' + rng() % 5);
    // }
    // for (int i = 0 ; i < m ; i++)
    // {
    //     t += (char)('a' + rng() % 5);
    // }

    // const auto bf = [&]() -> bool
    // {
    //     for (int i = 0 ; i < (1 << n) ; i++)
    //     {
    //         string tmp = "";
    //         for (int j = 0 ; j < n ; j++)
    //         {
    //             if (i & (1 << j))
    //                 tmp += s[j];
    //             else
    //             if (tmp.size() > 0)
    //                 tmp.pop_back();
    //         }
    //         if (tmp == t) return 1;
    //     }
    //     return 0;
    // };

    int ptrS = s.length() - 1;
    int ptrT = t.length() - 1;
    string build = "";
    while (ptrS >= 0 && ptrT >= 0)
    {
        if (t[ptrT] == s[ptrS])
        {
            build += t[ptrT];
            --ptrT; --ptrS;
        }
        else
            ptrS -= 2;
    }
    reverse(build.begin(),build.end());
    if (build == t)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}