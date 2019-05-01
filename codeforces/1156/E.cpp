#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

int tree[800010];
int tab[200010];

int readInt ()
{
    bool minus = false;
    int result = 0;
    char ch;
    ch = _getchar_nolock();
    while (true)
    {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = _getchar_nolock();
    }
    if (ch == '-') minus = true;
    else result = ch-'0';
    while (true)
    {
        ch = _getchar_nolock();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}


void build(int node,int l,int r)
{
	if (l == r)
	{
		tree[node] = tab[l];
		return;
	}
	int child = node << 1;
	int mid = (l + r) >> 1;
	build(child,l,mid);
	build(child | 1,mid + 1,r);
	tree[node] = max(tree[child],tree[child | 1]);
}

int query(int node,int nodeL,int nodeR,int queryL,int queryR)
{
	if (queryL > nodeR || queryR < nodeL) return -INF;
	if (queryL <= nodeL && nodeR <= queryR) return tree[node];
	int mid = (nodeL + nodeR) >> 1;
	int child = node << 1;
	return max(query(child,nodeL,mid,queryL,queryR),
			   query(child | 1,mid + 1,nodeR,queryL,queryR)); 
}

int pos[200010];
int n;

int LeftBound(int ix)
{
	int l = 1;
	int r = ix;
	while (r - l > 1)
	{
		int mid = (l + r) >> 1;
		if (query(1,1,n,mid,ix) == tab[ix])
			r = mid;
		else
			l = mid + 1; 
	}
	if (query(1,1,n,l,ix) == tab[ix]) return l;
	else return r;
}

int RightBound(int ix)
{
	int l = ix;
	int r = n;
	while (r - l > 1)
	{
		int mid = (l + r) >> 1;
		if (query(1,1,n,ix,mid) == tab[ix])
			l = mid;
		else
			r = mid - 1;
	}
	if (query(1,1,n,ix,r) == tab[ix]) return r;
	else return l;
}

int main()
{
	// cin >> n;
	n = readInt();
	for (int i = 1 ; i <= n ; i++)
	{
		// cin >> tab[i];
		tab[i] = readInt();
		pos[tab[i]] = i;
	}
	build(1,1,n);
	int ans = 0;
	for (int i = 1 ; i <= n ; i++)
	{
		int BatasKiri = LeftBound(i);
		int BatasKanan = RightBound(i);
		if (BatasKanan == i) continue;
		// cout << i << " " << BatasKiri << " " << BatasKanan << endl;
		for (int j = BatasKiri ; j < i ; j++)
		{
			int sisa = abs(tab[j] - tab[i]);
			if (BatasKiri <= pos[sisa] && pos[sisa] <= BatasKanan && pos[sisa] >= i)
			{
				// cout << i << " I\n";
				// cout << tab[j] << " " << tab[i] << " " << pos[sisa] << endl;
				++ans;
			}
		}		
	}
	printf("%d\n",ans);
}