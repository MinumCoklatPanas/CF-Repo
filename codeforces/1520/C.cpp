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

void solve()
{
    int n;
    cin >> n;
    if (n == 2)
    {
        cout << "-1\n";
        return;
    }
    vector< vector<int> > tab(n,vector<int>(n,-1));
    pair<int,int> kiri = {0,0};
    pair<int,int> kanan = {n - 1,n - 1};
    int cur = 1;
    bool state = 0;
    while (cur <= n * n)
    {
        if (!state)
        {
            auto tmp = kiri;
            while (0 <= tmp.first && tmp.first < n && 0 <= tmp.second && tmp.second < n)
            {
                tab[tmp.first][tmp.second] = cur++;
                ++tmp.first;
                --tmp.second;
            }
            ++kiri.second;
        }
        else
        {
            auto tmp = kanan;
            while (0 <= tmp.first && tmp.first < n && 0 <= tmp.second && tmp.second < n)
            {
                tab[tmp.first][tmp.second] = cur++;
                ++tmp.first;
                --tmp.second;
            }
            --kanan.first;
        }
        state ^= 1;
    }

    const auto valid = [&]() -> bool
    {
        for (int i = 0 ; i < n ; i++)
            for (int j = 0 ; j < n ; j++)
            {
                int kiri = (j > 0 ? tab[i][j - 1] : INF);
                if (abs(kiri - tab[i][j]) == 1) return false;
                int kanan = (j + 1 < n ? tab[i][j + 1] : INF);
                if (abs(kanan - tab[i][j]) == 1) return false;
                int atas = (i > 0 ? tab[i - 1][j] : INF);
                if (abs(atas - tab[i][j]) == 1) return false;
                int bawah = (i + 1 < n ? tab[i + 1][j] : INF);
                if (abs(bawah - tab[i][j]) == 1) return false;
            }
        return true;
    };
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < n ; j++)
        {
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}