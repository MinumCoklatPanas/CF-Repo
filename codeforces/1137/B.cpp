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
    string s,t;
    cin >> s >> t;
    int n = s.length();
    int m = t.length();
    if (n < m)
        cout << s << endl;
    else
    {
        vector<int> pref0(m,0);
        vector<int> pref1(m,0);
        pref0[0] = (t[0] == '0');
        pref1[0] = (t[0] == '1');
        for (int i = 1 ; i < m ; i++)
        {
            pref0[i] = pref0[i - 1] + (t[i] == '0');
            pref1[i] = pref1[i - 1] + (t[i] == '1');
        }
        int cnt0 = 0,cnt1 = 0;
        for (int i = 0 ; i < n ; i++)
        {
            cnt0 += (s[i] == '0');
            cnt1 += (s[i] == '1');
        }
        if (pref0[m - 1] <= cnt0 && pref1[m - 1] <= cnt1)
        {
            const auto prefix_function = [&](string str) -> vector<int>
            {
                int k = (int)str.length();
                vector<int> pi(k);
                for (int i = 1; i < k; i++) 
                {
                    int j = pi[i-1];
                    while (j > 0 && str[i] != str[j])
                        j = pi[j-1];
                    if (str[i] == str[j])
                        j++;
                    pi[i] = j;
                }
                return pi;
            };
            vector<int> p = prefix_function(t);
            // for (auto it : p)
            //     cerr << it << ' ';
            // cerr << endl;
            string ans = t;
            cnt0 -= pref0[m - 1];
            cnt1 -= pref1[m - 1];
            while (1)
            {
                int need0 = pref0[m - 1] - (p[m - 1] == 0 ? 0 : pref0[p[m - 1] - 1]);
                int need1 = pref1[m - 1] - (p[m - 1] == 0 ? 0 : pref1[p[m - 1] - 1]);
                // cout << need0 << " " << need1 << endl;
                if ((need0 > cnt0) || (need1 > cnt1))
                    break;
                string tmp = t.substr(p[m - 1],m - p[m - 1]);
                ans += tmp;
                cnt0 -= need0;
                cnt1 -= need1;
            }
            for (int i = 1 ; i <= cnt0 ; i++) ans += '0';
            for (int i = 1 ; i <= cnt1 ; i++) ans += '1';
            cout << ans << endl;
        }
        else
            cout << s << endl;
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