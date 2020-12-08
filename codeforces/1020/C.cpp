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

vector<int> tab[3010];
int dp[3010][3010]; //[index][takenSoFar]
int suf[3010];
int n,m;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int sum = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        int a,b;
        cin >> a >> b;
        if (a != 1)
            sum += b;
        tab[a].push_back(b);
    }
    int curHave = tab[1].size();
    for (int i = 1 ; i <= m ; i++)
    {
        sort(tab[i].begin(),tab[i].end());
    }
    int ans = INFF;
    for (int i = 1 ; i <= n ; i++)
    {
        int cnt = 0;
        int ambil = tab[1].size();
        priority_queue< int,vector<int>,greater<int> > pq;
        for (int j = 2 ; j <= m ; j++) 
        {
            if (tab[j].size() >= i)
            {
                int lebih = tab[j].size() - i + 1;
                // cout << j << " " << lebih << endl;
                for (int k = 0 ; k < lebih ; k++)
                    cnt += tab[j][k];
                for (int k = lebih ; k < tab[j].size() ; k++)
                    pq.push(tab[j][k]);
                ambil += lebih;
            }
            else
            {
                for (auto it : tab[j])
                    pq.push(it);
            }
        }
        // cout << pq.size() << endl;
        while (ambil < i)
        {
            // cout << ambil << " " << ambil << endl;
            // cout << ambil << " " << pq.top() << endl;
            cnt += pq.top();
            pq.pop();
            ++ambil;
        }
        // cout << "yo\n";
        // cout << i << " " << cnt << endl;
        ans = min(ans,cnt);
        // cout << "-------------------------\n";
    }
    cout << ans << endl;
    return 0;
}