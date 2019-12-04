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
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        set<ll> st;
        st.insert(0);
        st.insert(n);
        for (ll i = 1 ; i * i <= n ; i++) {
            st.insert(i);
            st.insert(n / i);
        }
        cout << st.size() << endl;
        for (auto it : st) {
             cout << it << " ";
        }
        cout << endl;
    }
}