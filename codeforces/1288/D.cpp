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
#define MULTI_TC 0

int getTC()
{
    if (MULTI_TC)
    {
        int t;
        cin >> t;
        return t;
    }
    else return 1;
}

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> tab(n,vector<int>(m));
    for (auto &it : tab)
        for (auto &it2 : it)
            cin >> it2;
    const auto Cek = [&](int x) -> bool
    {
        set<int> Mask;
        for (int i = 0 ; i < n ; i++)
        {
            int CurMask = 0;
            for (int j = 0 ; j < m ; j++) if (tab[i][j] >= x)
            {
                CurMask |= (1 << j);
            }
            // cerr << i << " " << CurMask << endl;
            Mask.insert(CurMask);
        }
        for (auto it : Mask)
            for (auto it2 : Mask)
            {
                
                if ((it | it2) == ((1 << m) - 1)) 
                {
                    // cerr << it << " " << it2 << endl;
                    return true;
                }
            }
        return false;
    };
    // Cek(1);
    // return;
    int l = 0;
    int r = INF;
    while (r - l > 1)
    {
        int mid = (l + r) >> 1;
        if (Cek(mid))
            l = mid;
        else
            r = mid - 1;
    }
    // cerr << l <<" " << r << endl;
    // cerr << "yo\n";
    // return;
    const auto Print = [&](int x) -> void
    {
        // cerr << x << endl;
        set<int> Mask;
        for (int i = 0 ; i < n ; i++)
        {
            int CurMask = 0;
            for (int j = 0 ; j < m ; j++) if (tab[i][j] >= x)
                CurMask |= (1 << j);
            Mask.insert(CurMask);
        }
        int MaskA = -1,MaskB  = -1;
        for (auto it : Mask)
        {
            for (auto it2 : Mask)
            {
                if ((it | it2) == ((1 << m) - 1))
                {
                    MaskA = it;
                    MaskB = it2;
                    goto hell;
                }
            }
        }
        hell:;
        assert(MaskA != -1);
        for (int i = 0 ; i < n ; i++)
        {
            int CurMask = 0;
            for (int j = 0 ; j < m ; j++) if (tab[i][j] >= x)
                CurMask |= (1 << j);
            if (CurMask == MaskA)
            {
                cout << i + 1 << " ";
                break;
            }
        }

        for (int i = 0 ; i < n ; i++)
        {
            int CurMask = 0;
            for (int j = 0 ; j < m ; j++) if (tab[i][j] >= x)
                CurMask |= (1 << j);
            if (CurMask == MaskB)
            {
                cout << i + 1 << endl;
                break;
            }
        }
    };
    if (Cek(r))
        Print(r);
    else
        Print(l);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = getTC();
    while (t--)
    {
        solve();
    }
    return 0;
}