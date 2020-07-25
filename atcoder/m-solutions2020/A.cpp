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
    int x;
    cin >> x;
    if (x < 600)
        cout << "8\n";
    else
    if (x < 800)
        cout << "7\n";
    else
    if (x < 1000)
        cout << "6\n";
    else
    if (x < 1200)
        cout << "5\n";
    else
    if (x < 1400)
        cout << "4\n";
    else
    if (x < 1600)
        cout << "3\n";
    else
    if (x < 1800)
        cout << "2\n";
    else
        cout << "1\n";
    return 0;
}