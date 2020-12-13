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

bitset<10> segment[10];
string disp[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
bitset<10> tab[2010];

void input(bitset<10> &bs,string s)
{
    for (int i = 0 ; i < s.length() ; i++)
        bs[i] = (s[i] == '1');
}

int dp[2010][2010];
int n,k;

int rec(int index,int sisa)
{
    if (index > n) return (sisa == 0);
    if (dp[index][sisa] != -1) return dp[index][sisa];
    int ret = 0;
    for (int i = 9 ; i >= 0 ; i--)
    {
        bitset<10> tmp = tab[index] & segment[i];
        if (tmp == tab[index])
        {
            int nambah = 0;
            for (int j = 0 ; j < 7 ; j++) if (segment[i][j] && !tab[index][j]) ++nambah;
            // if (index == 1) cout << i << " " << nambah << endl;
            if (sisa >= nambah)
                ret |= rec(index + 1,sisa - nambah);
        }
    }
    // cout << index << " " << sisa << " " << ret << endl;
    return dp[index][sisa] = ret;
}

string ans;

void backtrack(int index,int sisa)
{
    if (index > n) return;
    for (int i = 9 ; i >= 0 ; i--)
    {
        bitset<10> tmp = tab[index] & segment[i];
        if (tmp == tab[index])
        {
            int nambah = 0;
            for (int j = 0 ; j < 7 ; j++) if (segment[i][j] && !tab[index][j]) ++nambah;
            
            if (sisa >= nambah)
            {
                int nxt = rec(index + 1,sisa - nambah);
                if (nxt)
                {
                    ans += '0' + i;
                    backtrack(index + 1,sisa - nambah);
                    break;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0 ; i < 10 ; i++)
        input(segment[i],disp[i]);
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i++)
    {
        string s;
        cin >> s;
        input(tab[i],s);
    }
    memset(dp,-1,sizeof(dp));
    int can = rec(1,k);
    if (!can)
        cout << -1 << endl;
    else
    {
        backtrack(1,k);
        cout << ans << endl;
    }
    return 0;
}