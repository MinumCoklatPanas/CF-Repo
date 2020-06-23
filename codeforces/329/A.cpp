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

char tab[110][110];
int n;

vector< pair<int,int> > cekRow()
{
    vector< pair<int,int> > ret;
    for (int i = 1 ; i <= n ; i++)
    {
        int cnt = 0;
        bool sudah = 0;
        for (int j = 1 ; j <= n ; j++) if (tab[i][j] == '.')
        {
            if (!sudah)
                ret.emplace_back(i,j);
            sudah = 1;
            ++cnt;
        }
        if (cnt == 0)
        {
            ret.clear();
            return ret;
        }
    }
    return ret;
}

vector< pair<int,int> > cekCol()
{
    vector< pair<int,int> > ret;
    for (int i = 1 ; i <= n ; i++)
    {
        int cnt = 0;
        bool sudah = 0;
        for (int j = 1 ; j <= n ; j++) if (tab[j][i] == '.')
        {
            if (!sudah)
                ret.emplace_back(j,i);
            sudah = 1;
            ++cnt;
        }
        if (cnt == 0)
        {
            ret.clear();
            return ret;
        }
    }
    return ret;
}

void print(vector< pair<int,int> > vec)
{
    for (auto it : vec)
        cout << it.first << " " << it.second << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= n ; j++)  
            cin >> tab[i][j];
    auto row = cekRow();
    auto col = cekCol();
    if (row.size() == 0 && col.size() == 0)
        cout << -1 << endl;
    else
    if (row.size() == 0)
    {
        print(col);
    }
    else
    if (col.size() == 0)
    {
        print(row);
    }
    else
    if (row.size() < col.size())
    {
        print(row);
    }
    else
    {
        print(col);
    }
    return 0;
}