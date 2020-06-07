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

struct op
{
    int tipe;
    int k;
    char dir;
};

char d1[2] = {'D','U'};
char d2[2] = {'L','R'};

pair<int,int> tab[100010];

bool cmp(pair<int,int> a,pair<int,int> b)
{
    return (abs(a.first) + abs(a.second) < abs(b.first) + abs(b.second));
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int n = readInt();
    // cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        tab[i].first = readInt();
        tab[i].second = readInt();
        // cin >> tab[i].first >> tab[i].second;
    }
    sort(tab + 1,tab + n + 1,cmp);
    vector< op > ans;
    for (int i = 1 ; i <= n ; i++)
    {
        int x = tab[i].first;
        int y = tab[i].second;
        // cin >> x >> y;
        int ix1 = (x > 0);
        int ix2 = (y > 0);
        if (x != 0)
            ans.push_back((op){1,abs(x),d2[ix1]});
        if (y != 0)
            ans.push_back((op){1,abs(y),d1[ix2]});
        ans.push_back((op){2,0,'A'});
        if (x != 0)
            ans.push_back((op){1,abs(x),d2[ix1 ^ 1]});
        if (y != 0)
            ans.push_back((op){1,abs(y),d1[ix2 ^ 1]});
        ans.push_back((op){3,0,'A'});
    }
    printf("%d\n",(int)ans.size());
    // cout << ans.size() << endl;
    for (auto it : ans)
    {
        if (it.tipe != 1)
            printf("%d\n",it.tipe);
            // cout << it.tipe << endl;
        else
        {
            printf("%d %d %c",it.tipe,it.k,it.dir);
            // cout << it.tipe << " " << it.k << " " << it.dir << endl;
        }
        
    }
    return 0;
}