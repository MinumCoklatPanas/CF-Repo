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
    int a,b,k;
    cin >> a >> b >> k;
    int mx = ((a > 0 && b > 1) ? b + a - 2 : 0);
    if (k > mx)
    {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    string big = "";
    for (int i = 1 ; i <= b ; i++) big += "1";
    for (int i = 1 ; i <= a ; i++) big += "0";
    
    string smol = big;
    int curSum = 0;
    for (int i = b ; i < smol.length() ; i++)
    {
        if (curSum == k) break;
        swap(smol[i],smol[i - 1]);
        ++curSum;
    }
    if (curSum == k)
    {
        cout << big << endl;
        cout << smol << endl;
        return 0;
    }
    for (int i = b - 1 ; i > 0 ; i--)
    {
        if (curSum == k) break;
        swap(smol[i],smol[i - 1]);
        ++curSum;
    }
    if (curSum == k)
    {
        cout << big << endl;
        cout << smol << endl;
        return 0;
    }
    return 0;
}