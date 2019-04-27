#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

map< pair<int,int>,int > mp;
int tab[200010];

int rec(int last,int l,int r)
{
	// cout << l << " " << r << endl;
	if (tab[l] <= last && tab[r] <= last) return mp[make_pair(l,r)] = 0;
	if (mp.count(make_pair(l,r))) return mp[make_pair(l,r)];

	if (l == r)
	{
		return mp[make_pair(l,r)] = (tab[l] > last);
	}
	if (tab[l] > last && tab[r] > last)
	{
		if (tab[l] < tab[r])
			return mp[make_pair(l,r)] = 1 + rec(tab[l],l + 1,r);
		else
		if (tab[r] < tab[l])
			return mp[make_pair(l,r)] = 1 + rec(tab[r],l,r - 1);
		else
		if (tab[l] == tab[r])
		{
			return mp[make_pair(l,r)] = 1 + max(rec(tab[l],l + 1,r),rec(tab[r],l,r - 1));
		}
	}
	else
	if (tab[l] > last)
		return mp[make_pair(l,r)] = 1 + rec(tab[l],l + 1,r);
	else
	if (tab[r] > last)
		return mp[make_pair(l,r)] = 1 + rec(tab[r],l,r - 1);
	return mp[make_pair(l,r)] = 0;
}

string ans;

void backtrack(int last,int l,int r)
{
	// if (l == r)
	// {
	// 	ans += 'R';
	// 	return;
	// }
	// cout << last << " " << l << " " << r << endl; 
	if (tab[l] <= last && tab[r] <= last)
	{

		return;
	}
	if (l == r)
	{
		ans += 'R';
		return;
	}
	if (tab[l] > last && tab[r] > last)
	{
		if (tab[l] < tab[r])
		{
			ans += 'L';
			backtrack(tab[l],l + 1,r);
		}
		else
		if (tab[r] < tab[l])
		{
			ans += 'R';
			backtrack(tab[r],l,r - 1);
		}
		else
		if (tab[l] == tab[r])
		{
			if (mp.count(make_pair(l + 1,r)) && mp[make_pair(l + 1,r)] == mp[make_pair(l,r)] - 1)
			{
				ans += 'L';
				backtrack(tab[l],l + 1,r);
			}	
			else
			if (mp.count(make_pair(l,r - 1)) && mp[make_pair(l,r - 1)] == mp[make_pair(l,r)] - 1)
			{
				ans += 'R';
				backtrack(tab[r],l,r - 1);	
			}
		}
	}
	else
	if (tab[l] > last)
	{
		ans += 'L';
		backtrack(tab[l],l + 1,r);
	}
	else
	if (tab[r] > last)
	{
		ans += 'R';
		backtrack(tab[r],l,r - 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
		cin >> tab[i];
	int cnt = rec(0,1,n);
	cout << cnt << endl;
	backtrack(0,1,n);
	// cout << mp[make_pair(1,n)] << endl;
	// assert(ans.length() == cnt);
	cout << ans << endl;
}
