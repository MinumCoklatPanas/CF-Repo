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
    int n;
    cin >> n;
    for (int i = 1 ; i <= 100000 ; i++) {
        double price = 1.0 * i * 1.08;
        if ((int)floor(price) == n) {
            cout << i << endl;
            return 0;
        }
    }
    cout << ":(\n";
}