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

bool isPrime[2010];

void solve()
{
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> frek(26,0);
    for (int i = 0 ; i < n ; i++) frek[s[i] - 'a']++;
    int ans = 1;
    for (int len = 2 ; len <= n ; len++)
    {
        int kNow = k % len;
        vector<int> atas(len),bawah(len);
        for (int i = 0 ; i < len ; i++)
        {
            atas[i] = i;
            bawah[i] = (i + kNow) % len;
        }
        vector<bool> vis(len,0);
        vector<int> cnt;
        for (int i = 0 ; i < len ; i++) if (!vis[i])
        {
            int cur = atas[i];
            int tmp = 0;
            do
            {
                ++tmp;
                vis[cur] = 1;
                cur = bawah[cur];
            } while (cur != atas[i]);
            cnt.push_back(tmp);
        }
        priority_queue<int> pq;
        for (int i = 0 ; i < 26 ; i++) 
        {
            // if (len == 2)
            //     cerr << frek[i] << endl;
            pq.push(frek[i]);
        }
        bool can = 1;
        for (auto it : cnt)
        {
            if (pq.top() < it)
            {
                can = 0;
                break;
            }
            int tmp = pq.top();
            pq.pop();
            tmp -= it;
            pq.push(tmp);
        }
        if (can) ans = max(ans,len);
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(isPrime,1,sizeof(isPrime));
    isPrime[1] = 0;
    for (int i = 2 ; i <= 2000 ; i++) if (isPrime[i])
    {
        for (int j = i + i ; j <= 2000 ; j += i)
            isPrime[j] = 0;
    }
    int t = getTC();
    while (t--)
    {
        solve();
    }
    return 0;
}