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
const int blk = 710;

int readInt ()
{
    bool minus = false;
    int result = 0;
    char ch;
    ch = getchar();
    while (true)
    {
            if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus = true;
    else result = ch-'0';
    while (true)
    {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

struct queries
{
    int L;
    int R;
    int ix;
};

int cei(int x,int y)
{
    return ((x / y) + (x % y != 0));
}

bool cmp(queries a,queries b)
{
    int kiri = cei(a.L,blk);
    int kanan = cei(b.L,blk);
    if (kiri == kanan)
        return (a.R < b.R);
    return (kiri < kanan);
}

queries ask[500010];
int cnt[500010];
int tab[500010];
int ans[500010];
int tot = 0;

void add(int ix)
{
    ++cnt[tab[ix]];
    if (cnt[tab[ix]] == 1)
        ++tot;
}

void erase(int ix)
{
    --cnt[tab[ix]];
    if (cnt[tab[ix]] == 0)
        --tot;
}

int main()
{
    int n = readInt(), q = readInt();
    for (int i = 1 ; i <= n ; i++)
    {
        tab[i] = readInt();
    }
    for (int i = 1 ; i <= q ; i++)
    {
        ask[i].L = readInt();
        ask[i].R = readInt();
        ask[i].ix = i;
    }
    sort(ask + 1,ask + q + 1,cmp);
    // for (int i = 1 ; i <= q ; i++)
    //     cout << ask[i].L << " " << ask[i].R << endl;
    int currL = 1;
    int currR = 1;
    for (int i = 1 ; i <= q ; i++)
    {
        int L = ask[i].L;
        int R = ask[i].R;
        while (currL > L)
        {
            add(currL - 1);
            --currL;
        }
        while (currR <= R)
        {
            add(currR);
            ++currR;
        }
        while (currL < L)
        {
            erase(currL);
            ++currL;
        }
        while (currR > R + 1)
        {
            erase(currR - 1);
            --currR;
        }
        // for (int j = 1 ; j <= n ; j++)
        //     cout << cnt[j] << " ";
        // cout << endl;
        ans[ask[i].ix] = tot;
    }
    for (int i = 1 ; i <= q ; i++)
        printf("%d\n",ans[i]);
    return 0;
}