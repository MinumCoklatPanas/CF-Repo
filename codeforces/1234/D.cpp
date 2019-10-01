#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

int tree[400010];
string s;


void upd(int node,int l,int r,int ix)
{
	// tree[node].resize(26,0);
	if (l == r)
	{
		tree[node] = (1 << (int) (s[l] - 'a'));
		return;
	}
	int mid = (l + r) >> 1;
	int child = node << 1;
	if (ix > mid)
		upd(child | 1,mid + 1,r,ix);
	else
		upd(child,l,mid,ix);
	tree[node] = tree[child] | tree[child | 1];
}

int query(int node,int nodeL,int nodeR,int queryL,int queryR)
{
	if (queryL > nodeR || queryR < nodeL) return -1;
	if (queryL <= nodeL && nodeR <= queryR) return tree[node];
	int mid = (nodeL + nodeR) >> 1;
	int child = node << 1;
	int kiri = query(child,nodeL,mid,queryL,queryR);
	int kanan = query(child | 1,mid + 1,nodeR,queryL,queryR);
	if (kiri == -1) return kanan;
	if (kanan == -1) return kiri;
	return kiri | kanan;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	int n = s.length();
	for (int i = 0 ; i < s.length() ; i++)
		upd(1,0,n - 1,i);
	int q;
	cin >> q;
	while (q--)
	{
		int ask;
		cin >> ask;
		if (ask == 1)
		{
			int ix;
			char c;
			cin >> ix >> c;
			--ix;
			s[ix] = c;
			upd(1,0,n - 1,ix);
		}
		else
		{
			int l,r;
			cin >> l >> r;
			--l; --r;
			int ans = __builtin_popcount(query(1,0,n - 1,l,r));
			cout << ans << endl;
		}
	}
}