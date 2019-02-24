#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

vector<int> pos[100010];
bool sudah[200010];
ll DP[2][100010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1 ; i <= 2 * n ; i++)
	{
		int a;
		cin >> a;
		pos[a].push_back(i);
	}
	pos[0].push_back(1);
	pos[0].push_back(1);
	ll ans = 0ll;
	for (int i = 1 ; i <= n ; i++)
	{
		// cout << pos[i][0] << " " << pos[i][1] << endl;
		ans += min(abs(pos[i - 1][0]-pos[i][0]) + abs(pos[i - 1][1] - pos[i][1]),abs(pos[i - 1][0] - pos[i][1]) + abs(pos[i - 1][1] - pos[i][0]));
		// cout << abs(pos[i - 1][0] - pos[i][0]) + abs(pos[i - 1][1] - pos[i][1]) << " " << abs(pos[i - 1][0] - pos[i][1]) + abs(pos[i - 1][1] - pos[i][0]) << endl;
		// cout << ans << endl;
	}
	cout << ans << endl;
}