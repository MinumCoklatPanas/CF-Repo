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

struct node
{
    node *child[2] = { NULL };
    ll cnt = 0;
    bool akhir = 0;
};

void insert(node *root,int k)
{
    node *tmp = root;
    for (int i = 30 ; i >= 0 ; i--)
    {
        int ix = ((k & (1 << i)) > 0);
        // cout << i << " " << ix << " " << k << endl;
        if (tmp -> child[ix] == NULL)
            tmp -> child[ix] = new node;
        tmp = tmp -> child[ix];
        (tmp -> cnt)++;
    }
    tmp -> akhir = true;
}

void dfs(node *root, int &k, int curSum, ll& ans, int depth,int x)
{
    if (!root) return;
    // if (x == 3)
    // {
    //     cout << curSum << " " << depth << " " << (root -> cnt) << endl;
    //     if (root -> child[0]) cout << "ada 0\n";
    //     if (root -> child[1]) cout << "ada 1\n";
    //     cout << endl;
    // }
    if (curSum + (1ll << depth) - 1 < k) return;
    if (curSum >= k)
    {
        ans += (root -> cnt);
        return;
    }
    if (!(x & (1 << (depth - 1))))
    {
        dfs(root -> child[0], k, curSum, ans, depth - 1, x);
        // cout << "yo\n";
        dfs(root -> child[1], k, curSum + (1 << (depth - 1)), ans, depth - 1, x);
    }
    else
    {
        dfs(root -> child[1], k, curSum, ans, depth - 1, x);
        dfs(root -> child[0], k, curSum + (1 << (depth - 1)), ans, depth - 1, x);
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    int curXor = 0;
    node *root = new node;
    insert(root, 0);
    // return 0;
    ll ans = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        curXor ^= ta;
        insert(root, curXor);
        dfs(root, k, 0, ans, 31, curXor);
    }
    cout << ans << endl;
    return 0;
}
