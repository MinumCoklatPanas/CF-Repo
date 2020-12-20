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

map<int,int> ada;
int tab[100010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,l,x,y;
    cin >> n >> l >> x >> y;
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        ada[ta] = 1;
        tab[i] = ta;
    }
    bool adaX = 0,adaY = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        adaX |= ada[tab[i] - x];
        adaX |= ada[tab[i] + x];
        adaY |= ada[tab[i] - y];
        adaY |= ada[tab[i] + y];
    }
    if (adaX && adaY)
    {
        cout << 0 << endl;
    }
    else
    if (adaX && !adaY)
    {
        cout << 1 << endl;
        cout << y << endl;
    }
    else
    if (!adaX && adaY)
    {
        cout << 1 << endl;
        cout << x << endl;
    }
    else
    {
        for (int i = 1 ; i <= n ; i++)
        {
            int curNambah = tab[i] - x;
            if ((ada[curNambah + y] || ada[curNambah - y]) && (curNambah >= 0))
            {
                cout << 1 << endl;
                cout << curNambah << endl;
                return 0;
            }
            curNambah = tab[i] + x;
            if ((ada[curNambah + y] || ada[curNambah - y]) && (curNambah <= l))
            {
                cout << 1 << endl;
                cout << curNambah << endl;
                return 0;
            }
            curNambah = tab[i] - y;
            if ((ada[curNambah + x] || ada[curNambah - x]) && (curNambah >= 0))
            {
                cout << 1 << endl;
                cout << curNambah << endl;
                return 0;
            }
            curNambah = tab[i] + y;
            if ((ada[curNambah + x] || ada[curNambah - x]) && (curNambah <= l))
            {
                cout << 1 << endl;
                cout << curNambah << endl;
                return 0;
            }
        }
        cout << 2 << endl;
        cout << x << " " << y << endl;
    }
    
    
    
    return 0;
}