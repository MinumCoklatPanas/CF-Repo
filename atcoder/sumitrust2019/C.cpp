#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MOD = 1e9 + 7;
const ll MAXN = 1e3;
const double EPS = 1e-9;

bool can[100010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    can[100] = can[101] = can[102] = can[103] = can[104] = can[105] = 1;
    vector< int > tab = {100,101,102,103,104,105};
    for (int i = 106 ; i <= 100000 ; i++) {
        for (int j = 0 ; j < 6 ; j++)
            can[i] |= can[i - tab[j]];
    }
    int n;
    cin >> n;
    cout << can[n] << endl;
}