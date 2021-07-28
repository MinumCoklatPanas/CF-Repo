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
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int commaPos = 0;
    while (s[commaPos] != '.') ++commaPos;
    int startPoint = commaPos + 1;
    while (startPoint < n && s[startPoint] < '5') ++startPoint;
    if (startPoint == n)
    {
        cout << s << endl;
    }
    else
    {
        int rem = n - (startPoint + 1);
        for (int i = 1 ; i <= rem ; i++) s.pop_back();
        while (k > 0 && s[s.size() - 2] != '.' && s[s.size() - 1] != '.')
        {
            if (s.back() < '5') break;
            s.pop_back();
            char &kiri = s.back();
            --k;
            if (kiri != '9')
                ++kiri;
            else
            {
                while (s.back() == '9')
                {
                    s.pop_back();
                }
                if (s.back() == '.')
                {
                    s.pop_back();
                    if (s.back() == '9')
                    {
                        int cur = s.size() - 1;
                        while (cur >= 0 && s[cur] == '9')
                        {
                            s[cur] = '0'; 
                            --cur;
                        }
                        if (cur < 0)
                            cout << 1;
                        else
                            s[cur]++;
                        cout << s << endl;
                        return;
                    }
                    else
                        s.back()++;
                }
                else
                {
                    ++s.back();
                }
            }
        }
        if (k && s.back() >= '5')
        {
            // cerr << s << endl;
            assert(s[s.size() - 2] == '.');
            if (s.back() >= '5')
            {
                s.pop_back();
                s.pop_back();
                if (s.back() == '9')
                {
                    int cur = s.size() - 1;
                    while (cur >= 0 && s[cur] == '9')
                    {
                        s[cur] = '0'; 
                        --cur;
                    }
                    if (cur < 0)
                        cout << 1;
                    else
                        s[cur]++;
                    cout << s << endl;
                    return;
                }
                else
                    s.back()++;
                cout << s << endl;
                return;
            }
        }
        cout << s << endl;
        return;
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