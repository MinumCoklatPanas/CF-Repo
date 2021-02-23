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
    ll n,k,d1,d2;
    cin >> n >> k >> d1 >> d2;
    if (n % 3 != 0)
    {
        cout << "no\n";
        return;
    }
    if (k == n)
    {
        if (d1 == d2 && d2 == 0)
            cout << "yes\n";
        else
            cout << "no\n";
        return;
    }
    if (d1 + d2 > n)
    {
        cout << "no\n";
        return;
    }

    ll w1,w2,w3;

    //2 > 1,2 > 3
    if ((k + d1 + d2) % 3 == 0)
    {
        w2 = (k + d1 + d2) / 3;
        w1 = w2 - d1;
        w3 = w2 - d2;
        if (w2 <= (n / 3) && (w1 <= n / 3) && (w3 <= n / 3) && (w1 >= 0 && w2 >= 0 && w3 >= 0))
        {
            ll need = n - (w1 + w2 + w3);
            if (need == n - k)
            {
                cout << "yes\n";
                return;
            }
        }
    }

    //1 > 2,3 > 2
    if ((k - d1 - d2) % 3 == 0)
    {
        w2 = (k - d1 - d2) / 3;
        w1 = d1 + w2;
        w3 = d2 + w2;
        if ((w2 <= (n / 3) && w1 <= (n / 3) && w3 <= (n / 3)) && (w1 >= 0 && w2 >= 0 && w3 >= 0))
        {
            ll need = n - (w1 + w2 + w3);
            if (need == n - k)
            {
                cout << "yes\n";
                return;
            }
        }
    }

    //1 > 2,2 > 3
    if ((k + d1 + d1 + d2) % 3 == 0)
    {
        w1 = (k + d1 + d1 + d2) / 3;
        w2 = w1 - d1;
        w3 = w2 - d2;
        if ((w2 <= (n / 3) && w1 <= (n / 3) && w3 <= (n / 3)) && (w1 >= 0 && w2 >= 0 && w3 >= 0))
        {
            ll need = n - (w1 + w2 + w3);
            if (need == n - k)
            {
                cout << "yes\n";
                return;
            }
        }
    }

    //2 > 1,3 > 2
    if ((k + d1 + d2 + d2) % 3 == 0)
    {
        w3 = (k + d1 + d2 + d2) / 3;
        w2 = w3 - d2;
        w1 = w2 - d1;
        if ((w2 <= (n / 3) && w1 <= (n / 3) && w3 <= (n / 3)) && (w1 >= 0 && w2 >= 0 && w3 >= 0))
        {
            ll need = n - (w1 + w2 + w3);
            if (need == n - k)
            {
                cout << "yes\n";
                return;
            }
        } 
    }

    cout << "no\n";
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