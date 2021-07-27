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
    int n,m;
    cin >> n >> m;
    map<string,int> mp;
    for (int i = 1 ; i <= n ; i++)
    {
        string ta;
        cin >> ta;
        mp[ta]++;
    }
    for (int i = 1 ; i <= m ; i++)
    {
        string ta;
        cin >> ta;
        vector<int> pos;
        for (int j = 0 ; j < ta.size() ; j++) if (ta[j] == '?') pos.push_back(j);
        if (pos.size() == 0)
        {
            cout << mp[ta] << endl;
            continue;
        }
        int num = 1;
        for (int j = 1 ; j <= pos.size() ; j++) num *= 6;
        int cnt = 0;
        set<string> st;
        for (int j = 0 ; j < num ; j++)
        {
            string bit = "";
            int tmp = j;
            while (tmp)
            {
                bit += '0' + (tmp % 6);
                tmp /= 6;
            }
            while (bit.size() < pos.size()) bit += '0';
            // cerr << bit << endl;
            string tmp2 = ta;
            for (int k = 0 ; k < pos.size() ; k++)
            {
                if (bit[k] == '5')
                    tmp2[pos[k]] = '-';
                else
                    tmp2[pos[k]] = 'a' + bit[k] - '0';  
            }
            string tmp3;
            for (int k = 0 ; k < tmp2.size() ; k++) if (tmp2[k] != '-')
                tmp3 += tmp2[k];
            st.insert(tmp3);
        }
        for (auto it : st)
            cnt += mp[it];
        cout << cnt << endl;
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