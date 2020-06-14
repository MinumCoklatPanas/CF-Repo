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

multiset<int> belongs[200010];
int tree[800010];
int place[200010];
int val[200010];

void upd(int node,int l,int r,int ix)
{
    if (l == r)
    {
        if (belongs[l].empty())
        {
            tree[node] = INF;
        }
        else
        {
            tree[node] = (*belongs[l].rbegin());
        }
        return;
    }
    int mid = (l + r) >> 1;
    int child = node << 1;
    if (ix > mid)
        upd(child | 1,mid + 1,r,ix);
    else
        upd(child,l,mid,ix);
    tree[node] = min(tree[child],tree[child | 1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin >> n >> q;
    for (int i = 1 ; i <= n ; i++)
    {
        int a,b;
        cin >> a >> b;
        val[i] = a;
        place[i] = b;
        belongs[b].insert(a);
    }
    for (int i = 1 ; i <= 200000 ; i++)
        upd(1,1,200000,i);
    while (q--)
    {
        int ix,newPlace;
        cin >> ix >> newPlace;
        int value = val[ix];
        int oldPlace = place[ix];
        belongs[oldPlace].erase(belongs[oldPlace].lower_bound(value));
        belongs[newPlace].insert(value);
        place[ix] = newPlace;
        upd(1,1,200000,oldPlace);
        upd(1,1,200000,newPlace);
        cout << tree[1] << endl;
    }
    return 0;
}