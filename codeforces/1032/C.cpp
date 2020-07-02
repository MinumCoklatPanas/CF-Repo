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

bool can[7][7][100010];
bool vis[7][100010];
int tab[100010];

vector<int> ans;
void backtrack(int indeks,int cur)
{
    // cout << indeks << " " << cur << endl;
    if (indeks == 0)
    {
        reverse(ans.begin(),ans.end());
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
        exit(0);
    }
    vis[cur][indeks] = 1;
    // vis[indeks][cur] = 1;
    ans.push_back(cur);
    for (int i = 1 ; i <= 5 ; i++) if (can[i][cur][indeks] && !vis[i][indeks - 1])
    {
        backtrack(indeks - 1,i);
    }
    ans.pop_back();
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
        cin >> tab[i];
    for (int i = 1 ; i <= 5 ; i++)
        for (int j = 1 ; j <= 5 ; j++)
            can[i][j][1] = 1;
    for (int i = 2 ; i <= n ; i++)
    {
        for (int cur = 1 ; cur <= 5 ; cur++)
        {
            for (int bef = 1 ; bef <= 5 ; bef++)
            {
                if (tab[i - 1] < tab[i] && bef >= cur) continue;
                if (tab[i - 1] > tab[i] && bef <= cur) continue;
                if (tab[i - 1] == tab[i] && bef == cur) continue;
                bool tmp = 0;
                for (int befbef = 1 ; befbef <= 5 ; befbef++)
                {
                    if (can[befbef][bef][i - 1])
                    {
                        tmp = 1;
                        break;
                    }
                }
                can[bef][cur][i] = 1;
            }
        }
    }
    for (int i = 1 ; i <= 5 ; i++)
    {
        for (int j = 1 ; j <= 5 ; j++)
        {
            if (can[i][j][n])
            {
                // cout << i << " " << j << " " << n << endl;
                backtrack(n,j);
            }
        }
    }
    cout << -1 << endl;
    return 0;
}