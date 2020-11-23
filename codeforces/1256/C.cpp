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

int tab[1010];
int ans[1010];
int start[1010];
int suf[1010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,d;
    cin >> n >> m >> d;
    int sum = 0;
    for (int i = 1 ; i <= m ; i++)
    {
        cin >> tab[i];
        sum += tab[i];
    }
    if (sum + d >= n + 1)
    {
        int curPos = 1;
        for (int i = 1 ; i <= m ; i++)
        {
            for (int j = 1 ; j <= tab[i] ; j++)
            {
                ans[curPos++] = i;
            }
        }
        
    }
    else
    {
        int curPos = d;
        int rem = n - d;
        for (int i = 1 ; i <= m ; i++)
        {
            // cout << i << " i " << curPos << endl;
            if (sum >= rem)
            {
                int maju = sum - rem;
                curPos -= maju;
                for (int j = i ; j <= m ; j++)
                {
                    for (int k = 1 ; k <= tab[j] ; k++)
                        ans[curPos++] = j;
                }
                rem = 0;
                break;
            }
            else
            {
                sum -= tab[i];
                rem -= tab[i];
                for (int j = 1 ; j <= tab[i] ; j++)
                    ans[curPos++] = i;
                curPos += d - 1;
                if (i < m)
                    rem -= d - 1;
            }
        }
        // if (rem > d)
        // {
        //     cout << "NO\n";
        //     return 0;
        // }
    }
    int cnt = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        if (!ans[i])
        {
            ++cnt;
            if (cnt >= d)
            {
                cout << "NO\n";
                return 0;
            }
            // assert(cnt < d);
        }
        else
            cnt = 0;
    }
    cout << "YES\n";
    for (int i = 1 ; i <= n ; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}