#include <bits/stdc++.h>
using namespace std;

vector<int> pos[30];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	for (int i = 0 ; i < n ; i++)
	{
		pos[s[i] - 'a' + 1].push_back(i);
	}
	if (k == 1)
	{
		int ans  = 0;
		for (int i = 1 ; i <= 26 ; i++)
		{
			ans = max(ans,(int)pos[i].size());
		}
		cout << ans << endl;
		return 0;
	}
	// return 0;
	int ans = 0;
	for (int i = 1 ; i <= 26 ; i++)
	{
		int cnt = 0;
		int j = 0;
		// cout << j << " " << pos[i].size() - 1 << endl;
		while (j < (int)pos[i].size() - 1)
		{
			// cout << "yo" << endl;
			int hitung = 1;
			while (pos[i][j + 1] == pos[i][j] + 1 && j < pos[i].size())
			{
				++j;
				++hitung;
				if (hitung == k) break;
			}
			cnt += (hitung == k);
			++j;
		}
		ans = max(ans,cnt);
	}
	cout << ans << endl;
}