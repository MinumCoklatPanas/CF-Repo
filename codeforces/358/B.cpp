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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    for (int i = 1 ; i <= n ; i++)
    {
        string ta;
        cin >> ta;
        s += "<3" + ta;
    }
    s += "<3";
    string t;
    cin >> t;
    int ptr = 0;
    for (int i = 0 ; i < t.length() ; i++)
    {
        if (t[i] == s[ptr]) ++ptr;
        if (ptr == s.length()) break;
    }
    if (ptr == s.length())
        cout << "yes\n";
    else
        cout << "no\n";
    return 0;
}