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
#define int long long

int cntDig(int x)
{
    int ret = 0;
    while (x)
    {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}

int f(int a,int b,int c,int x)
{
    int s = x;
    int ret = 1;
    for (int i = 1 ; i <= a ; i++)
        ret *= s;
    ret *= b;
    ret += c;
    return ret;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> ans;
    int a,b,c;
    cin >> a >> b >> c;
    for (int i = 0 ; i <= 100 ; i++)
    {
        int ret = f(a,b,c,i);
        if (0 < ret && ret < INF)
        {
            if (cntDig(ret) == i)
                ans.push_back(ret);
        }
    }
    sort(ans.begin(),ans.end());
    cout << ans.size() << endl;
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
    return 0;
}