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
#define MULTI_TC 0

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
    vector<char> sign;
    sign.push_back('+');
    char tmp;
    while (cin >> tmp)
    {
        if (tmp == '=') break;
        if (tmp == '-' || tmp == '+') sign.push_back(tmp);
    }
    int k;
    cin >> k;
    int n = sign.size();
    if (n == 1)
    {
        cout << "Possible\n";
        cout << k << " = " << k << endl;
        return;
    }
    vector<int> num(n,1);
    int sum = 0;
    for (int i = 0 ; i < n ; i++)
    {
        if (sign[i] == '+')
            sum++;
        else
            sum--;
    }
    for (int i = 0 ; i < n && sum < k ; i++) if (sign[i] == '+')
    {
        int need = k - sum;
        int add = min(need,k - 1);
        num[i] += add;
        sum += add;
    }
    for (int i = 0 ; i < n && sum > k ; i++) if (sign[i] == '-')
    {
        int need = sum - k;
        int add = min(need,k - 1);
        num[i] += add;
        sum -= add;
    }
    if (sum != k)
        cout << "Impossible\n";
    else
    {
        cout << "Possible\n";
        cout << num[0];
        for (int i = 1 ; i < n ; i++)
        {   
            cout << " " << sign[i] << " " << num[i];
        }
        cout << " =  " << k << endl;
    }
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