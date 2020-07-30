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

pair<int,int> tab[5010];
int pref[5010];
int cnt[3][5010];

int get(int kode,int l,int r)
{
    return cnt[kode][r] - cnt[kode][l - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin >> n >> q;
    for (int i = 1 ; i <= q ; i++)
    {
        int a,b;
        cin >> a >> b;
        tab[i] = {a,b};
        pref[a]++; pref[b + 1]--;
    }
    int tot = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        pref[i] += pref[i - 1];
        tot += (pref[i] > 0);
        cnt[1][i] = cnt[1][i - 1];
        cnt[2][i] = cnt[2][i - 1];
        if (pref[i] == 1)
            cnt[1][i]++;
        if (pref[i] == 2)
            cnt[2][i]++;
    }
    int ans = 0;
    for (int i = 1 ; i <= q ; i++)
        for (int j = i + 1 ; j <= q ; j++)
        {
            int tmp = tot;
            int satu = get(1,tab[i].first,tab[i].second) + get(1,tab[j].first,tab[j].second);
            tmp -= satu;
            int l = max(tab[i].first,tab[j].first);
            int r = min(tab[i].second,tab[j].second);
            if (l <= r)
                tmp -= get(2,l,r);
            ans = max(ans,tmp);
        }
    cout << ans << endl;
    return 0;
}