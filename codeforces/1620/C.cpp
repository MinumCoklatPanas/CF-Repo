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
    int n,k,x;
    cin >> n >> k >> x;
    string s;
    cin >> s;
    vector<pair<char,int>> compress;
    compress.emplace_back(s[0],1);
    for (int i = 1 ; i < n ; i++)
    {
        if (s[i] == compress.back().first)
            ++compress.back().second;
        else
            compress.emplace_back(s[i],1);
    }
    vector<pair<char,int>> ans;
    for (auto it : compress)
    {
        if (it.first == '*')
            ans.emplace_back(it.first,0);
        else
            ans.push_back(it);
    }
    --x;
    while (x)
    {
        int cnt = 0;
        bool firstOccurence = 0;
        for (int i = compress.size() - 1 ; i >= 0 ; i--) if (compress[i].first == '*')
        {
            int pengali;
            if (!firstOccurence)
            {
                firstOccurence = 1;
                pengali = compress[i].second * k + 1;
            }
            else
                pengali = compress[i].second * k * cnt;
            // assert(pengali > 0);
            // cerr << pengali << endl;
            // return;
            if (cnt + pengali > x || pengali <= 0)
            {
                ans[i].second = x / (cnt == 0 ? 1 : cnt);
                x %= (cnt == 0 ? 1 : cnt);
                break;
            }
            else
                cnt += pengali;
        }
        // for (auto it : ans)
        // {
        //     cerr << it.first << "," << it.second << " ";
        // } 
        // cerr << endl;
        // return;
    }
    for (auto it : ans)
    {
        for (int i = 1 ; i <= it.second ; i++)
            cout << (it.first == '*' ? 'b' : 'a');
    } 
    cout << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = getTC();
    // if (t == 521) t = 35;
    while (t--)
    {
        solve();
    }
    return 0;
}