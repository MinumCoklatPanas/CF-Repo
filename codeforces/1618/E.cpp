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
    int n;
    cin >> n;
    vector<int> b(n);
    int sumB = 0;
    for (auto &it : b)
    { 
        cin >> it;
        sumB += it;
    }
    int komb = (n * (n + 1)) / 2;
    if (sumB % komb != 0)
    {
        cout << "NO\n";
        return;
    }
    int sumA = sumB / komb;
    vector<int> a(n);
    int curSum = 0;
    for (int i = 1 ; i < n ; i++)
    {
        int diff = sumA - (b[i] - b[i - 1]);
        if (diff % n != 0 || (diff <= 0))
        {
            cout << "NO\n";
            return;
        }
        a[i] = diff / n;
        curSum += a[i];
    }
    a[0] = sumA - curSum;
    if (a[0] <= 0)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (auto it : a)
        cout << it << " ";
    cout << endl;
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