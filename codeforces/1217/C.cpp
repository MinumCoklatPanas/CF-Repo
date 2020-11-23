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
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    vector<int> pref(s.length() + 5, 0);
    for (int i = 0 ; i < s.length() ; i++)
    {
        pref[i] = (s[i] == '0') + (i == 0 ? 0 : pref[i - 1]);
    }
    int ans = 0;
    for (int i = 0 ; i < s.length() ; i++)
    {
        for (int len = 1 ; len <= 18 ; len++)
        {
            if (i + len - 1 >= s.length()) break;
            if (s[i + len - 1] == '0') continue;
            int mul = 1;
            int sum = 0;
            for (int j = i ; j < i + len ; j++)
            {
                sum += mul * (s[j] - '0');
                mul *= 2;
            }
            if (len > sum) continue;
            if (len == sum)
            {
                // cout << i << " " << sum << " " << len << " yo\n";
                ++ans;
                continue;
            }
            // cout << i << " " << sum << " " << len << endl;
            int needs = sum - len;
            if (i + len - 1 + needs < s.length())
            {
                // cout << "yo\n";
                int tmp = pref[i + len - 1 + needs] - pref[i + len - 1];
                if (tmp == needs) ++ans;
            }
        }
    }
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