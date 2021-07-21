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
    int n;
    cin >> n;
    string s;
    cin >> s;
    const auto cek = [&](int ix) -> string
    {
        string tmp = s;
        string a = "abacaba";
        bool can = 1;
        for (int i = ix ; i < ix + 7 ; i++)
        {
            if (tmp[i] == '?')
            {
                tmp[i] = a[i - ix];
            }
            else
            if (tmp[i] != a[i - ix])
            {
                return "-1";
            }
        }
        for (int i = 0 ; i < n ; i++) if (i < ix || i >= ix + 7)
        {
            if (tmp[i] == '?') tmp[i] = 'z';
        }
        int cnt = 0;
        for (int i = 0 ; i + 6 < n ; i++)
        {
            string sub = tmp.substr(i,7);
            cnt += (sub == a);
        }
        if (cnt > 1) tmp = "-1";
        return tmp;
    };
    for (int i = 0 ; i + 6 < n ; i++)
    {
        string tmp = cek(i);
        if (tmp != "-1")
        {
            cout << "Yes\n";
            cout << tmp << endl;
            return;
        }
    }
    cout << "No\n";
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