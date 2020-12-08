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

struct node
{
    int endPos;
    int val;
    int prev;
    int startPos;

    node(){};

    node(int _endPos,int _val,int _prev,int _startPos)
    {
        endPos = _endPos;
        val = _val;
        prev = _prev;
        startPos = _startPos;
    }
};


map< int,vector< node > > dp;
map< int,vector< pair<int,int> > > prefMax;
int tab[1505];
int pref[1505];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> tab[i];
        pref[i] = pref[i - 1] + tab[i];
    }
    int ans = 0;
    int End = -1;
    int sum = -INF;
    int ix = -1;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 0 ; j < i ; j++)
        {
            int curSum = pref[i] - pref[j];
            if (dp[curSum].size() == 0)
                dp[curSum].push_back(node(i,1,-1,j + 1)),prefMax[curSum].push_back({1,0});
            else
            {
                int val = 1;
                int prv = -1;
                int l = 0;
                int r = dp[curSum].size() - 1;
                while (r - l > 1)
                {
                    int mid = (l + r) >> 1;
                    if (dp[curSum][mid].endPos <= j)
                        l = mid;
                    else
                        r = mid - 1;
                }
                if (dp[curSum][r].endPos <= j)
                {
                    int tmp = prefMax[curSum][r].first + 1;
                    if (tmp > val)
                    {
                        val = tmp;
                        prv = prefMax[curSum][r].second;
                    }
                }
                else
                if (dp[curSum][l].endPos <= j)
                {
                    int tmp = prefMax[curSum][l].first + 1;
                    if (tmp > val)
                    {
                        val = tmp;
                        prv = prefMax[curSum][l].second;
                    }
                }
                dp[curSum].push_back(node(i,val,prv,j + 1));
                if (val > prefMax[curSum].back().first)
                {
                    prefMax[curSum].push_back({val,prefMax[curSum].size()});
                }
                else
                {
                    prefMax[curSum].push_back(prefMax[curSum].back());
                }
            }
            if (dp[curSum].back().val > ans)
            {
                ans = dp[curSum].back().val;
                End = dp[curSum].back().endPos;
                sum = curSum;
                ix = dp[curSum].size() - 1;
            }
        }
    }
    assert(ix != -1);
    vector< pair<int,int> > range;
    cout << ans << endl;
    while (ix != -1)
    {
        range.push_back({dp[sum][ix].startPos,dp[sum][ix].endPos});
        ix = dp[sum][ix].prev;
    }
    for (auto it : range)
        cout << it.first << " " << it.second << endl;
    return 0;
}