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

string fnd(ll n)
{
    string ret = "";
    while (n)
    {
        int tmp = n % 26;
        if (tmp == 0)
            tmp = 26;
        ret += 'a' + tmp - 1;
        n /= 26;
        if (tmp == 26)
            --n;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    cout << fnd(n) << endl;
    return 0;
}
