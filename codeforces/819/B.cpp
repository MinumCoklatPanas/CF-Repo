#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
#define int long long
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> tab(n);
    for (auto &it : tab) cin >> it;
    multiset<int> kurang;
    int cur = 0;
    for (int i = 0 ; i < n ; i++)
    {
        if ((i + 1) < tab[i] && i != n - 1)
            kurang.insert(tab[i] - (i + 1));
        cur += abs(tab[i] - (i + 1));
    }
    int ans = cur;
    int id = 0;
    queue<int> q;
    for (int i = n - 1 ; i >= 0 ; i--) q.push(tab[i]);
    // cout << 0 << " " << cur << endl;
    for (int i = 1 ; i < n ; i++)
    {
        int kur = kurang.size();
        int leb = (n - 1) - kur;
        int pindah = q.front();
        q.pop();
        cur += leb - kur - (n - pindah) + (pindah - 1);
        // cout << "-------------------------\n";
        // cout << i << " " << cur << endl;
        // cout << kur << " " << leb << " " << pindah << endl;
        // for (auto it : kurang)
        //     cout << it << " ";
        // cout << endl;
        if (cur < ans)
        {
            ans = cur;
            id = i;
        }
        if (pindah != 1)
        {
            kurang.insert(i + (pindah - 1));
        }
        while (kurang.find(i) != kurang.end())
            kurang.erase(kurang.find(i));
        // cout << "-------------------------\n";
    }
    cout << ans << " " << id << endl;
    return 0;
}