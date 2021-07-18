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
    int sum = 0;
    for (auto &it : tab)
    {
        for (auto &it2 : it)
        {
            cin >> it2;
            sum += it2;
        }
    }   
    const auto countRow = [n,m](vector<vector<int>> &a) -> vector<pair<string,int>>
    {
        vector<pair<string,int>> ret;
        while (1)
        {
            int mx = 0;
            int choose = -1;
            for (int i = 0 ; i < n ; i++)
            {
                int cur = INF;
                for (int j = 0 ; j < m ; j++) cur = min(cur,a[i][j]);
                cur *= m;
                if (cur > mx)
                {
                    mx = cur;
                    choose = i + 1;
                }
            }
            if (choose == -1) break;
            for (int i = 0 ; i < mx / m ; i++)
                ret.push_back({"row",choose});
            for (int i = 0 ; i < m ; i++) a[choose - 1][i] -= mx / m;
            // cout << mx << endl;
            // for (auto it : a)
            // {
            //     for (auto it2 : it)
            //         cout << it2 << " ";
            //     cout << endl;
            // }
            // cout << endl;
        }
        return ret;
    };

    const auto countCol = [n,m](vector<vector<int>> &a) -> vector<pair<string,int>>
    {
        vector<pair<string,int>> ret;
        while (1)
        {
            int mx = 0;
            int choose = -1;
            for (int i = 0 ; i < m ; i++)
            {
                int cur = INF;
                for (int j = 0 ; j < n ; j++) cur = min(cur,a[j][i]);
                cur *= n;
                if (cur > mx)
                {
                    mx = cur;
                    choose = i + 1;
                }
            }
            // return ret;
            if (choose == -1) break;
            for (int i = 0 ; i < mx / n ; i++)
                ret.push_back({"col",choose});
            for (int i = 0 ; i < n ; i++) a[i][choose - 1] -= mx / n;
            // cout << mx << endl;
            // for (auto it : a)
            // {
            //     for (auto it2 : it)
            //         cout << it2 << " ";
            //     cout << endl;
            // }
            // cout << endl;
            // exit(0);
        }
        return ret;
    };

    const auto done = [n,m](vector<vector<int>> &a) -> bool
    {
        for (int i = 0 ; i < n ; i++)
        {
            for (int j = 0 ; j < m ; j++)
            {
                if (a[i][j] != 0) return false;
            }
        }
        return true;
    };

    auto a = tab;
    auto aRow = countRow(a);
    auto aCol = countCol(a);
    bool canA = done(a);
    vector<pair<string,int>> aRet;

    const auto ins = [](vector<pair<string,int>> tmpA,vector<pair<string,int>> &tmpB) -> void
    {
        for (auto it : tmpA)
            tmpB.push_back(it);
    };

    ins(aRow,aRet);
    ins(aCol,aRet);

    auto b = tab;
    auto bCol = countCol(b);
    auto bRow = countRow(b);
    bool canB = done(b);
    vector<pair<string,int>> bRet;
    ins(bCol,bRet);
    ins(bRow,bRet);

    const auto print = [](vector<pair<string,int>> tmp) -> void
    {
        cout << tmp.size() << endl;
        for (auto it : tmp)
            cout << it.first << " " << it.second << endl;
    };

    if (canA && canB)
    {
        if (aRet.size() < bRet.size())
            print(aRet);
        else
            print(bRet);
    }
    else
    if (canA)
        print(aRet);
    else
    if (canB)
        print(bRet);
    else
        cout << -1 << endl;
}
signed main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int t = getTC();
    while (t--)
    {
        solve();
    }
    return 0;
}