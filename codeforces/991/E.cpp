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
#define MULTI_TC 0

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
    vector<int> fak(20);
    fak[0] = 1;
    for (int i = 1 ; i < 20 ; i++) fak[i] = fak[i - 1] * i;
    string s;
    cin >> s;
    int n = s.length();
    set<string> sub;
    vector<int> frekTot(10,0);
    for (int i = 0 ; i < n ; i++) frekTot[s[i] - '0']++;
    const auto getComb = [&](vector<int> a) -> int
    {
        int sum = accumulate(a.begin(),a.end(),0);
        int atas = fak[sum];
        int bawah = 1;
        for (auto it : a) bawah *= fak[it];
        return atas / bawah;
    };

    const auto valid = [&](vector<int> a) -> bool
    {
        for (int i = 0 ; i < 10 ; i++) if (frekTot[i] > 0 && a[i] == 0) return false;
        return true;
    };

    set<string> subset;

    for (int i = 1 ; i < (1 << n) ; i++)
    {
        string tmp;
        for (int j = 0 ; j < n ; j++) if (i & (1 << j))
        {
            tmp += s[j];
        }
        sort(tmp.begin(),tmp.end());
        subset.insert(tmp);
    }
    int ans = 0;
    for (auto it : subset)
    {
        vector<int> tmpFrek(10,0);
        for (auto it2 : it) tmpFrek[it2 - '0']++;
        if (valid(tmpFrek))
        {
            // cout << it << endl;
            ans += getComb(tmpFrek);
            if (tmpFrek[0] > 0)
            {
                tmpFrek[0]--;
                ans -= getComb(tmpFrek);
            }
        }
    }
    cout << ans << endl;
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