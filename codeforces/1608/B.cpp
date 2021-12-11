#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
#define int long long
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define MULTI_TC 1

int getTC()
{
    if (MULTI_TC)
    {
        int t;
        cin >> t;
        return t;
    }
    else return 1;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> tab(n);
    for (int i = 0 ; i < n ; i++) tab[i] = i + 1;
    int a,b;
    cin >> a >> b;
    const auto cei = [&](int x,int y) -> int
    {
        return (x / y) + (x % y != 0);
    };
    int mx = cei(n - 2,2);
    // cerr << max(a,b) << endl;
    if (max(a,b) > mx || abs(a - b) > 1 || a + b > n - 2)
    {
        cout << -1 << endl;
    }
    else
    {
        if (a == 0 && b == 0)
        {
            for (auto it : tab)
                cout << it << " ";
            cout << endl;
            return;
        }
        if (a == 1 && b == 0)
        {
            swap(tab[n - 1],tab[n - 2]);
            for (auto it : tab)
                cout << it << " ";
            cout << endl;
            return;
        }
        if (a == 0 && b == 1)
        {
            swap(tab[0],tab[1]);
            for (auto it : tab)
                cout << it << " ";
            cout << endl;
            return;
        }
        const auto valid = [&]() -> bool
        {
            int naik = 0,turun = 0;
            for (int i = 1 ; i + 1 < n ; i++)
            {
                naik += (tab[i] > tab[i - 1] && tab[i] > tab[i + 1]);
                turun += (tab[i] < tab[i - 1] && tab[i] < tab[i + 1]);
            }
            // cerr << naik << " " << turun << endl;
            return (naik == a && turun == b);
        };
        if (a == b) 
        {
            int aa = a;
            for (int i = 2 ; i < n && aa > 0 ; i += 2,aa--)
            {
                swap(tab[i],tab[i - 1]);
            }
            for (auto it : tab)
                cout << it << " ";
            cout << endl;
            assert(valid());
            return;
        }
        if (a > b)
        {
            int aa = a;
            swap(tab[n - 2],tab[n - 1]);
            --aa;
            for (int i = n - 3 ; i > 0 && aa ; i -= 2,aa--)
            {
                // cerr << i - 1 << " " << i << endl;
                swap(tab[i - 1],tab[i]);
            }
            // return;
            for (auto it : tab)
                cout << it << " ";
            cout << endl;
            // valid();
            assert(valid());
            return;
        }
        else
        {
            int aa = a;
            swap(tab[0],tab[1]);
            for (int i = 2 ; i < n && aa ; i += 2,aa--)
            {
                // cerr << tab[i] << " " << tab[i + 1] << endl;
                swap(tab[i],tab[i + 1]);
            }
            for (auto it : tab)
                cout << it << " ";
            cout << endl;
            // valid();
            assert(valid());
            return;
        }
    }
    // vector<int> tab = {1,2,3,4,5};
    // do {
    //     int mx = 0,mn = 0;
    //     for (int i = 1 ; i + 1 < tab.size() ; i++)
    //     {
    //         mx += (tab[i] > tab[i - 1] && tab[i] > tab[i + 1]);
    //         mn += (tab[i] < tab[i - 1] && tab[i] < tab[i + 1]);
    //     }
    //     if (1)
    //     {
    //         for (auto it : tab)
    //             cout << it << " ";
    //         cout << ": " << mx << " " << mn << endl;
    //     }
    // } while (next_permutation(tab.begin(),tab.end()));
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = getTC();
    while (t--)
    {
        solve();
    }
    return 0;
}