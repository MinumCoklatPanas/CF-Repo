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

bool cek(int x1,int y1,int x2,int y2,int a,int b)
{
    if (x1 + x2 <= a && max(y1,y2) <= b) return true;
    if (x1 + x2 <= b && max(y1,y2) <= a) return true;

    if (x1 + y2 <= a && max(y1,x2) <= b) return true;
    if (x1 + y2 <= b && max(y1,x2) <= a) return true;

    if (y1 + x2 <= a && max(x1,y2) <= b) return true;
    if (y1 + x2 <= b && max(x1,y2) <= a) return true;

    if (y1 + y2 <= a && max(x1,x2) <= b) return true;
    if (y1 + y2 <= b && max(x1,x2) <= a) return true;

    return false;
}

int x[110];
int y[110];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,a,b;
    cin >> n >> a >> b;
    for (int i = 1 ; i <= n ; i++) cin >> x[i] >> y[i];
    int ans = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= n ; j++) if (i != j)
        {
            if (cek(x[i],y[i],x[j],y[j],a,b))
                ans = max(ans,x[i] * y[i] + x[j] * y[j]);
        }
    }
    cout << ans << endl;
    return 0;
}