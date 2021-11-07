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
    int n;
    cin >> n;
    vector<pair<int,int>> tab(n);
    for (auto &it : tab) cin >> it.first >> it.second;
    set<pair<int,int>> st;
    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < n ; j++) if (i != j)
        {
            int dx = tab[i].first - tab[j].first;
            int dy = tab[i].second - tab[j].second;
            int fpb = __gcd(dx,dy);
            dx /= fpb;
            dy /= fpb;
            st.insert({dx,dy});
        }
    cout << st.size() * 2 << endl;
    return 0;
}