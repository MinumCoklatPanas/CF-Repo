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

void solve()
{
    int n;
    cin >> n;
    map<int,int> sum;
    vector<int> tab(n);
    for (auto &it : tab) 
    {
        cin >> it;
        sum[it]++;
    }
    vector<int> frek(n + 5,0);
    for (auto it : sum)
        frek[it.second]++;
    vector<int> prefFrek(n + 5,0);
    vector<int> prefSum(n + 5,0);
    for (int i = 1 ; i <= n ; i++)
    {
        prefFrek[i] = frek[i] + prefFrek[i - 1];
        prefSum[i] = frek[i] * i + prefSum[i - 1];
    }
    int ans = INF;
    for (int i = 1 ; i <= n ; i++)
    {
        int hapusKiri = prefSum[i - 1];
        int hapusKanan = (prefSum[n] - prefSum[i]) - ((prefFrek[n] - prefFrek[i]) * i);
        // cout << i << " " << hapusKiri << " " << hapusKanan << endl;
        ans = min(ans,hapusKiri + hapusKanan);
    }    
    ans = min(ans,n);
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}