#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

int tab[100010];
bool vis[100010];
int ans[100010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
		cin >> tab[i];
	sort(tab + 1,tab + n + 1);
	queue<int> q;
	// vector<int> ans;
	q.push(1);
	vis[1] = 1;
	int cur = 1;
	// return 0;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		// continue;
		// cout << q.size() << endl;
		// cout << now << endl;
		// continue;
		ans[now] = tab[cur++];
		// continue;
		int kiri = now - 1;
		if (kiri <= 0)
			kiri += n;
		int kanan = now + 1;
		if (kanan > n)
			kanan -= n;
		// continue;
		if (!vis[kanan])
		{
			q.push(kanan);
			vis[kanan] = 1;
		}
		if (!vis[kiri])
		{
			q.push(kiri);
			vis[kiri] = 1;
		}
	}
	// return 0;
	for (int i = 1 ; i <= n ; i++)
	{
		int kiri = i - 1;
		if (kiri <= 0)
			kiri += n;
		int kanan = i + 1;
		if (kanan > n)
			kanan -= n;
		if (ans[i] >= ans[kiri] + ans[kanan])
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	for (int i = 1 ; i <= n ; i++)
		cout << ans[i] << " ";
	cout << endl;
}