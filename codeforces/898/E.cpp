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
    int n;
    cin >> n;
    vector<int> sqr,bukan;
    for (int i = 0 ; i < n ; i++)
    {
        int ta;
        cin >> ta;
        int akar = sqrt(ta);
        if (akar * akar == ta)
            sqr.push_back(ta);
        else
            bukan.push_back(ta);
    }
    if (sqr.size() == bukan.size())
        cout << 0 << endl;
    else
    {
        vector<int> needSqr,needBukan;
        for (auto it : sqr)
        {
            if (it == 0) needSqr.push_back(2);
            else needSqr.push_back(1);
        }
        for (auto it : bukan)
        {  
            int a = sqrt(it);
            int b = a + 1;
            int aa = it - a * a;
            int bb = b * b - it;
            needBukan.push_back(min(bb,aa));
        }
        sort(needSqr.begin(),needSqr.end());
        sort(needBukan.begin(),needBukan.end());
        const auto process = [&](vector<int> a,vector<int> b) -> int
        {
            vector<int> prefB = b;
            for (int i = 1 ; i < prefB.size() ; i++) prefB[i] += prefB[i - 1];
            vector<int> prefA = a;
            for (int i = 1 ; i < prefA.size() ; i++) prefA[i] += prefA[i - 1];
            int ret = INFF;
            for (int i = 0 ; i <= a.size() ; i++)
            {
                int need = n / 2 - a.size() + i;
                int cost = (i == 0 ? 0 : prefA[i - 1]) + prefB[need - 1];
                // cout << i << " " << need << " " << prefB[need - 1] << endl;
                ret = min(ret,cost);
            }
            return ret;
        };
        int ans;
        if (sqr.size() > bukan.size())
            ans = process(needBukan,needSqr);
        else
            ans = process(needSqr,needBukan);
        cout << ans << endl;
    }
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