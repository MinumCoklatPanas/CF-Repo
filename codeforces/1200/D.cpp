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

char tab[2010][2010];
int add[2010][2010];

void upd(int x1,int y1,int x2,int y2,int val = 1)
{
    add[x1][y1] += val;
    add[x1][y2 + 1] -= val;
    add[x2 + 1][y1] -= val;
    add[x2 + 1][y2 + 1] += val;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
            cin >> tab[i][j];
    }

    int curSum = 0;

    //process row
    vector< pair<int,int> > rows(n + 5);
    for (int i = 1 ; i <= n ; i++)
    {
        int firstOcc = INF;
        int lastOcc = -INF;
        for (int j = 1 ; j <= n ; j++)
        {
            if (tab[i][j] == 'B')
                firstOcc = min(firstOcc,j),lastOcc = max(lastOcc,j);
        }
        // cout << i << " " << firstOcc << " " << lastOcc << endl;
        if (firstOcc == INF)
            rows[i] = {INF,-INF},curSum++;
        else
        if (lastOcc - firstOcc + 1 <= k)
        {
            int x1 = max(1,i - k + 1);
            int x2 = i;
            int y1 = max(1,lastOcc - k + 1);
            int y2 = firstOcc;
            assert(y1 <= y2);
            assert(x1 <= x2);
            upd(x1,y1,x2,y2);
        }
    }

    //process col
    vector< pair<int,int> > cols(n + 5);
    for (int i = 1 ; i <= n ; i++)
    {
        int firstOcc = INF;
        int lastOcc = -INF;
        for (int j = 1 ; j <= n ; j++)
        {
            if (tab[j][i] == 'B')
                firstOcc = min(firstOcc,j),lastOcc = max(lastOcc,j);
        }
        if (firstOcc == INF)
            cols[i] = {INF,INF},curSum++;
        else
        if (lastOcc - firstOcc + 1 <= k)
        {
            int y1 = max(1,i - k + 1);
            int y2 = i;
            int x1 = max(1,lastOcc - k + 1);
            int x2 = firstOcc;
            upd(x1,y1,x2,y2);
            assert(y1 <= y2);
            assert(x1 <= x2);
        }
    }

    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
        {
            if (i - 1 >= 1)
                add[i][j] += add[i - 1][j];
            if (j - 1 >= 1)
                add[i][j] += add[i][j - 1];
            if (i - 1 >= 1 && j - 1 >= 1)
                add[i][j] -= add[i - 1][j - 1];
        }
    }

    // for (int i = 1 ; i <= n ; i++)
    // {
    //     for (int j = 1 ; j <= n ; j++)
    //     {
    //         cerr << add[i][j] << " ";
    //     }
    //     cerr << endl;
    // }

    int ans = curSum;

    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
            ans = max(ans,curSum + add[i][j]);
    }
    cout << ans << endl;
    return 0;
}