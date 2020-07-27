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

map<int,int> frek;

void print(int mn,int mx)
{
    // cout << "yo\n";
    for (int i = mn ; i <= mx ; i++)
    {
        // cout << i << endl;
        for (int j = 1 ; j <= frek[i] ; j++)
            cout << i << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int mn = INF;
    int mx = -INF;
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        frek[ta]++;
        mn = min(mn,ta);
        mx = max(mx,ta);
    }
    // cout << mn << ' ' << mx << endl;
    if (mx - mn < 2)
    {
        cout << n << endl;
        print(mn,mx);
    }
    else
    {
        int opt1 = min(frek[mn],frek[mx]) * 2;
        int opt2 = ((frek[mn + 1]) / 2) * 2;
        // cout << opt1 << " " << opt2 << endl;
        if (opt1 > opt2)
        {
            cout << n - opt1 << endl;
            frek[mn] -= opt1 / 2;
            frek[mx] -= opt1 / 2;
            frek[mn + 1] += opt1;
            
            print(mn,mx);
        }
        else
        {
            cout << n - opt2 << endl;
            frek[mn + 1] -= opt2;
            frek[mn] += opt2 / 2;
            frek[mx] += opt2 / 2;
            print(mn,mx);
        }
    }
    return 0;
}