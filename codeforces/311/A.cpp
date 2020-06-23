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

double dist(pair<int,int> a,pair<int,int> b)
{
    double dx = (a.first - b.first) * 1.0;
    double dy = (a.second - b.second) * 1.0;
    return sqrt(dx * dx + dy * dy);
}

void cnt(vector< pair<int,int> > point,int n,int k)
{
    sort(point.begin(),point.end());
    double d = INFF;
    int tot = 0;
    for (int i = 1 ; i <= n ; i++)
        for (int j = i + 1 ; j <= n ; j++)
        {
            ++tot;
            if ((double)(point[j].first - point[i].first) >= d) break;
            d = min(d,dist(point[i],point[j]));
        }
    // cout << tot << endl;
    // if (tot > k)
    // {
    //     cout << "failed\n";
    // }
    assert(tot > k);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    if (k >= ((n * (n - 1)) / 2))
        cout << "no solution\n";
    else
    {
        int cur = (ll)-1e8;
        vector< pair<int,int> > point;
        for (int i = 1 ; i <= n ; i++)
        {
            cout << 0 << " " << cur << endl;
            point.emplace_back(0,cur);
            cur += 10000;
        }
        cnt(point,n,k);
    }
    return 0;
}