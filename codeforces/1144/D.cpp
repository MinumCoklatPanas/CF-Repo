#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 2e5;
const int MOD = 1e9 + 7;

int frek[200010];
int tab[200010];
bool vis[200010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> tab[i];
		frek[tab[i]]++;
	}
	int mx = 0;
	int num = -1;
	for (int i = 0 ; i <= 200000 ; i++)
	{
		if (frek[i] > mx)
		{
			mx = frek[i];
			num = i;
		}
	}
	vector< pair< int,pair<int,int> > > ans;
	queue< int > q;
	for (int i = 1 ; i <= n ; i++)
	{
		if (tab[i] == num)
		{
			q.push(i);
			vis[i] = 1;
		}
	}
	while (!q.empty())
	{
		int i = q.front();
		q.pop();
		if (i > 1 && !vis[i - 1])
		{
			if (tab[i - 1] > num)
			{
				ans.push_back(make_pair(2,make_pair(i - 1,i)));
			}
			else
			{
				ans.push_back(make_pair(1,make_pair(i - 1,i)));	
			}
			tab[i - 1] = num;
			vis[i - 1] = 1;
			q.push(i - 1);
		}
		if (i < n && !vis[i + 1])
		{
			if (tab[i + 1] > num)
			{
				ans.push_back(make_pair(2,make_pair(i + 1,i)));
			}
			else
			{
				ans.push_back(make_pair(1,make_pair(i + 1,i)));	
			}
			tab[i + 1] = num;
			vis[i + 1] = 1;
			q.push(i + 1);
		}
	}
	assert(ans.size() == n - mx);
	cout << ans.size() << endl;
	for (int i = 0 ; i < ans.size() ; i++)
		cout << ans[i].first << " " << ans[i].second.first << " " << ans[i].second.second << endl; 
}