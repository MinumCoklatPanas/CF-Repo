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

int tab[55];
int frek[30];
int cntDepth[55];
int depthIndex[55];
char pos[55];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        memset(frek,0,sizeof(frek));
        memset(cntDepth,0,sizeof(cntDepth));
        string s;
        cin >> s;
        for (int i = 0 ; i < s.length() ; i++)
            frek[s[i] - 'a' + 1]++;
        int n;
        cin >> n;
        queue< pair<int,int> > q;
        for (int i = 1 ; i <= n ; i++)
        {
            cin >> tab[i];
            if (tab[i] == 0)
            {
                q.push({i,1});
            }
        }
        int maxDepth = 0;
        while (!q.empty())
        {
            int ix = q.front().first;
            int depth = q.front().second;
            // q.pop();
            // cout << ix << " " << depth << endl;
            maxDepth = max(maxDepth,depth);
            cntDepth[depth]++;
            depthIndex[ix] = depth;
            q.pop();
            for (int i = 1 ; i <= n ; i++) if (i != ix)
            {
                int dist = abs(i - ix);
                // cout << dist << endl;
                if (tab[i] >= dist)
                {
                    // cout << "y"
                    // dist -= tab[i];
                    tab[i] -= dist;
                    if (tab[i] == 0)
                     q.push({i,depth + 1});
                }
            }
        }
        int ptr = 26;
        for (int i = 1 ; i <= maxDepth ; i++)
        {
            // cout << cntDepth[i] << endl;
            if (ptr <= 0)
            {
                cout << "fail\n";
                return 0;
            }
            while (frek[ptr] < cntDepth[i])
                --ptr;
            pos[i] = 'a' + ptr - 1;
            --ptr;
        }
        for (int i = 1 ; i <= n ; i++)
        {
            assert(tab[i] == 0);
            char tmp = pos[depthIndex[i]];
            cout << tmp;
        }
        cout << endl;
    }
    return 0;
}