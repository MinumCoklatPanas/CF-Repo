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

bool cek(string s,string t)
{
    return (s.find(t) != string::npos);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    string t = "CODEFORCES";
    for (int i = 0 ; i < s.length() ; i++)
    {
        for (int j = i ; j < s.length() ; j++)
        {
            string tmp = "";
            for (int k = 0 ; k < i ; k++)
                tmp += s[k];
            for (int k = j + 1 ; k < s.length() ; k++)
                tmp += s[k];
            if (tmp == t)
            {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}