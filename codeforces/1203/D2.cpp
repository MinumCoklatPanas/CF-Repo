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

int maxPrefix[200010];
int maxSuffix[200010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s,t;
    cin >> s >> t;
    int ptr = 0;
    for (int i = 0 ; i < s.length() ; i++)
    {
        if (ptr < t.length() && s[i] == t[ptr]) ++ptr;
        maxPrefix[i] = ptr;
    }
    ptr = t.length() - 1;
    for (int i = s.length() - 1 ; i >= 0 ; i--)
    {
        if (ptr >= 0 && s[i] == t[ptr]) --ptr;
        maxSuffix[i] = ptr;
    }
    // for (int i = 0 ; i < s.length() ; i++)
    // {
    //     cout << maxSuffix[i] << " ";
    // }
    // cout << endl;
    // return 0;
    int ans = -INF;
    for (int i = 0 ; i < s.length() ; i++)
    {
        int cari = maxPrefix[i] - 1;
        if (cari == t.length() - 1)
        {
            ans = max(ans,(int)s.length() - (i + 1));
            break;
        }
        int l = i + 1;
        int r = s.length() - 1;
        // cout << l << " " << r << " " << cari << endl;
        // return 0;
        while (r - l > 1)
        {
            int mid = (l + r) >> 1;
            if (maxSuffix[mid] > cari)
                r = mid - 1;
            else
            if (maxSuffix[mid] == cari)
                l = mid;
            else
                l = mid + 1;
        }
        int ambil;
        if (maxSuffix[r] == cari)
            ambil = r;
        else
        {
            assert(maxSuffix[l] == cari);
            ambil = l;
        }
        int keep = i + 1 + (s.length() - ambil);
        int buang = s.length() - keep;
        // cout << i << " " << keep << " " << buang << endl;
        ans = max(ans,buang);
    }
    for (int i = s.length() - 1 ; i >= 0 ; i--)
    {
        int cari = maxSuffix[i] + 1;
        if (cari == 0)
        {
            ans = max(ans,i);
            break;
        }
        int l = 0;
        int r = i - 1;
        while (r - l > 1)
        {
            int mid = (l + r) >> 1;
            if (maxPrefix[mid] > cari)
                r = mid - 1;
            else
            if (maxPrefix[mid] == cari)
                r = mid;
            else
            if (maxPrefix[mid] < cari)
                l = mid + 1;
        }
        int ambil;
        if (maxPrefix[l] == cari)
            ambil = l;
        else
        {
            assert(maxPrefix[r] == cari);
            ambil = r;
        }
        int keep = ambil + 1 + (s.length()  - i);
        int buang = s.length() - keep;
        ans = max(ans,buang);
    }
    cout << ans << endl;
    return 0;
}