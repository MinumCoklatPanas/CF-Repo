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

int l[110];
int r[110];

int findR(int x)
{
    while (r[x] != 0)
        x = r[x];
    return x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    queue<int> q;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> l[i] >> r[i];
        if (l[i] == 0)
            q.push(i);
    }
    int last = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        r[last] = cur;
        l[cur] = last;
        last = findR(cur);
    }
    for (int i = 1 ; i <= n ; i++)
        cout << l[i] << " " << r[i] << endl;
    return 0;
}