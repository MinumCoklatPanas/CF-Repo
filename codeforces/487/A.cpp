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

struct data
{
    int hp;
    int atk;
    int def;
};

int cei(int x,int y)
{
    return ((x / y) + (x % y != 0));
}

bool can(data a,data b)
{
    if (a.atk <= b.def) return 0;
    if (b.atk <= a.def) return 1;
    // cout << "yo\n";
    int timA = cei(b.hp,a.atk - b.def);
    int timB = cei(a.hp,b.atk - a.def);
    // cout << timA << " " << timB << endl;
    return (timA < timB);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    data y,m,price;
    cin >> y.hp >> y.atk >> y.def;
    cin >> m.hp >> m.atk >> m.def;
    cin >> price.hp >> price.atk >> price.def;
    // cout << can(y,m) << endl;
    // return 0; 
    int ans = INF;
    for (int i = 0 ; i <= 5000 ; i++)
        for (int j = 0 ; j <= 200 ; j++)
            for (int k = 0 ; k <= 100 ; k++)
            {
                int tot = 0;
                y.hp += i;
                y.atk += j;
                y.def += k;
                tot = (i * price.hp) + (j * price.atk) + (k * price.def);
                if (can(y,m))
                    ans = min(ans,tot);
                y.hp -= i;
                y.atk -= j;
                y.def -= k;
            }
    cout << ans << endl;
    return 0;
}