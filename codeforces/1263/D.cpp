#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MOD = 1e9 + 7;
const ll MAXN = 1e3;
const double EPS = 1e-9;

int par[200030];
int cnt[200030];
int setCount;

int finds(int x) {
    return (par[x] == x ? x : par[x] = finds(par[x]));
}

void joins(int x,int y) {
    int px = finds(x);
    int py = finds(y);
    if (px == py) return;
    par[px] = py;
    cnt[px] += cnt[py];
    --setCount;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1 ; i <= n + 26 ; i++) { 
        par[i] = i;
        cnt[i] = 0;
    }
    setCount = 26 + n;
    for (int i = 1 ; i <= n ; i++) {
        string ta;
        cin >> ta;
        for (int j = 0 ; j < ta.length() ; j++) {
            joins(i + 26,ta[j] - 'a' + 1);
        }
    }
    for (int i = 1 ; i <= 26 + n ; i++)
        cnt[finds(i)]++;
    int ans = 0;
    for (int i = 1 ; i <= 26 + n ; i++)
        ans += (cnt[i] > 1);
    cout << ans << endl;
}