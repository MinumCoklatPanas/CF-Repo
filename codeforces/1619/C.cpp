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
    string a,b;
    cin >> a >> b;
    // while (a.length() < b.length()) a = '0' + a;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    // cerr << b << endl;
    // cerr << a << endl;
    string ans;
    int ptrA,ptrB;
    for (ptrA = 0,ptrB = 0 ; ptrA < a.length() && ptrB < b.length() ; ptrA++,ptrB++)
    {
        int curB = b[ptrB] - '0';
        int curA = a[ptrA] - '0';
        // cerr << curB << " " << curA << endl;
        if (curB >= curA)
        {
            int diff = curB - curA;
            if (diff > 9)
            {
                cout << -1 << endl;
                return;
            }
            ans += '0' + diff;
        }
        else
        {
            if (ptrB + 1 == b.length())
            {
                cout << -1 << endl;
                return;
            }
            curB += (b[ptrB + 1] - '0') * 10;
            ++ptrB;
            // cerr << curB << " " << curA << endl;
            if (curB >= curA)
            {
                int diff = curB - curA;
                if (diff > 9)
                {
                    cout << -1 << endl;
                    return;
                }
                ans += '0' + diff;    
            }
            else
            {
                cout << -1 << endl;
                return;
            }
        }
    }
    while (ptrB < b.size())
    {
        ans += b[ptrB];
        ++ptrB;
    }
    // cerr << ans << " ans\n";
    
    if (ptrA != a.size())
    {
        cout << -1 << endl;
        return;
    }
    reverse(ans.begin(),ans.end());
    while (ans[0] == '0') ans.erase(ans.begin());
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