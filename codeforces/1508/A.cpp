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

void solve()
{
    int n;
    cin >> n;
    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    int p1 = 0;
    int p2 = 0;
    int p3 = 0;
    string ans;
    while (p1 < s1.length() && p2 < s2.length() && p3 < s3.length())
    {
        if (s1[p1] == s2[p2])
        {
            ans += s1[p1];
            ++p1; ++p2;
        }
        else
        if (s1[p1] == s3[p3])
        {
            ans += s1[p1];
            ++p1; ++p3;
        }
        else
        if (s2[p2] == s3[p3])
        {
            ans += s2[p2];
            ++p2; ++p3;
        }
    }
    // cerr << p1 << " " << p2 << " " << p3 << endl;
    if (p1 < s1.length() && (ans.length() + s1.length() - p1 <= 3 * n))
    {
        while (p1 < s1.length()) ans += s1[p1++];
    }
    else
    if (p2 < s2.length() && (ans.length() + s2.length() - p2 <= 3 * n))
    {
        while (p2 < s2.length()) ans += s2[p2++];
    }
    else
    if (p3 < s3.length() && (ans.length() + s3.length() - p3 <= 3 * n))
    {
        while (p3 < s3.length()) ans += s3[p3++];
    }
    const auto cek = [&](string s) -> bool
    {
        int ix = 0;
        for (int i = 0 ; i < ans.length() ; i++)
        {
            if (ans[i] == s[ix]) ++ix;
            if (ix == s.length()) return 1;
        }
        return 0;
    };
    // cerr << ans.length() << "\n";
    // if (cek(s1)) cerr << "match 1\n";
    // if (cek(s2)) cerr << "match 2\n";
    // if (cek(s3)) cerr << "match 3\n";
    cout << ans << endl;
}

signed main()
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