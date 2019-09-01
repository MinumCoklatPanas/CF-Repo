#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// vector<int> urutan;
	// vector<int> ans;
	// for (int n = 1 ; n <= 8 ; n++)
	// {
	// 	urutan.clear();
	// 	ans.clear();
	// 	for (int i = 1 ; i <= n ; i++)
	// 		urutan.push_back(i);
	// 	// continue;
	// 	int mx = 0;
	// 	do{
	// 		int cnt = 0;
	// 		for (int i = 0 ; i < n ; i++)
	// 			cnt += (i + 1) % urutan[i];
	// 		// cout << cnt << endl;
	// 		if (cnt > mx)
	// 		{
	// 			// cout << cnt << endl;
	// 			mx = cnt;
	// 			ans = urutan;
	// 		}
	// 		// if (cnt == 28)
	// 		// {
	// 		// 	for (int i = 0 ; i < urutan.size() ; i++)
	// 		// 		cout << ans[i] << " ";
	// 		// 	cout << endl;	
	// 		// }
	// 	} while (next_permutation(urutan.begin(),urutan.end()));
	// 	cout << mx << endl;
	// 	// for (int i = 0 ; i < urutan.size() ; i++)
	// 	// 	cout << ans[i] << " ";
	// 	// cout << endl;
	// }
	ll n;
	cin >> n;
	ll ans = (n * (n - 1)) / 2;
	cout << ans << endl;
}