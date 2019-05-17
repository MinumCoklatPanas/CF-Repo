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
	deque<char> baris[5];
	baris[0].push_back('a');
	baris[0].push_back('i');
	baris[0].push_back('u');
	baris[0].push_back('e');
	baris[0].push_back('o');
	for (int i = 1 ; i < 5 ; i++)
	{
		baris[i] = baris[i - 1];
		char tmp = baris[i][0];
		baris[i].pop_front();
		baris[i].push_back(tmp);
	}
	int k;
	cin >> k;
	deque< deque<char> > ans;
	for (int row = 5 ; row * row <= k ; row++) if (k % row == 0)
	{
		int col = k / row;
		if (col >= 5)
		{
			for (int i = 0 ; i < row; i++)
			{
				if (i < 5)
					ans.push_back(baris[i]);
				else
					ans.push_back(baris[0]);
				while (ans[i].size() < col)
					ans[i].push_back(baris[0][i % 5]);
			}
			string out;
			for (int i = 0 ; i < row ; i++)
			{
				for (int j = 0 ; j < col ; j++)
				{
					// cout << ans[i][j] << " ";
					out += ans[i][j];
				}
				// cout << endl;
			}
			assert(out.length() == k);
			cout << out << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}