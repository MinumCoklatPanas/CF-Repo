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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<string> hehe = {"ARC","AGC","AHC","ABC"};
    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    for (auto it : hehe)
    {
        if (it != s1 && it != s2 && it != s3)
        {
            cout << it << endl;
        }
    }
    return 0;
}