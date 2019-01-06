#include <bits/stdc++.h>
using namespace std;

int DP[3][100010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	DP[0][0] = DP[1][0] = DP[2][0] = 0;
 	for (int i = 1 ; i <= n ; i++)
	{
		cin >> DP[0][i] >> DP[1][i] >> DP[2][i];
		DP[0][i] += max(DP[1][i - 1],DP[2][i - 1]);
		DP[1][i] += max(DP[0][i - 1],DP[2][i - 1]);
		DP[2][i] += max(DP[0][i - 1],DP[1][i -1]);
	}
	int ans = max(DP[0][n],max(DP[1][n],DP[2][n]));
	cout << ans << endl;
}