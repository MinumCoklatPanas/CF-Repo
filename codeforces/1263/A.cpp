#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MOD = 1e9 + 7;
const ll MAXN = 1e3;
const double EPS = 1e-9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int tab[3];
        cin >> tab[0] >> tab[1] >> tab[2];
        sort(tab,tab + 3);
        if (tab[2] <= tab[0] + tab[1])
            cout << tab[2] + ((tab[0] + tab[1] - tab[2]) / 2) << endl;
        else
            cout << tab[0] + tab[1] << endl;
            
    }
}