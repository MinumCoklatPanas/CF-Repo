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

string s;
int cnt(vector<char> &a)
{
    int cur = 0;
    int ret = 0;
    for (int i = 0 ; i < s.length() ; i++)
    {
        if (s[i] == a[cur])
        {
            ++ret;
            cur ^= 1;
        }
    }
    return ret - (ret % 2 && (a[0] != a[1]));
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
        cin >> s;
        int ans = 0;
        for (char i = '0' ; i <= '9' ; i++)
            for (char j = '0' ; j <= '9' ; j++)
            {
                vector<char> tmp(2);
                tmp[0] = i;
                tmp[1] = j;
                // if (cnt(tmp) == 5)
                //     cout << i << " " << j << endl;
                ans = max(ans,cnt(tmp));
            }
        cout << s.length() - ans << endl;
    }
    return 0;
}