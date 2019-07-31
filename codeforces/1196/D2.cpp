#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

vector<int> pos[3][3];
int tab[200010];
int n,k;

int rec(int huruf1,int huruf2,int huruf3,int ix)
{
	int satu = ix % 3;
	int dua = (ix - 1) % 3;
	int tiga = (ix - 2) % 3;
	int cnt1 = upper_bound(pos[huruf1][satu].begin(),pos[huruf1][satu].end(),ix) -
			   lower_bound(pos[huruf1][satu].begin(),pos[huruf1][satu].end(),ix - k + 1);
	int cnt2 = upper_bound(pos[huruf2][dua].begin(),pos[huruf2][dua].end(),ix) -
			   lower_bound(pos[huruf2][dua].begin(),pos[huruf2][dua].end(),ix - k + 1);
	int cnt3 = upper_bound(pos[huruf3][tiga].begin(),pos[huruf3][tiga].end(),ix) -
			   lower_bound(pos[huruf3][tiga].begin(),pos[huruf3][tiga].end(),ix - k + 1);
	// cout << huruf1 << " " << huruf2 << " " << huruf3 << " " << ix << " state\n";
	// cout << cnt1 << " " << cnt2 << " " << cnt3 << " hasil\n"; 			   
	return k - (cnt1 + cnt2 + cnt3);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin >> q;
	while (q--)
	{
		for (int i = 0 ; i < 3 ; i++)
			for (int j = 0 ; j < 3 ; j++)
				pos[i][j].clear();
		cin >> n >> k;
		string s;
		cin >> s;
		for (int i = 0 ; i < n ; i++)
		{
			if (s[i] == 'R')
				tab[i] = 0;
			if (s[i] == 'G')
				tab[i] = 1;
			if (s[i] == 'B')
				tab[i] = 2;
		}
		if (k == 1)
		{
			cout << 0 << endl;
			continue;
		}
		if (k == 2)
		{
			int ans = 1;
			for (int i = 0 ; i + 1 < n ; i++)
			{
				if (tab[i] == 0 && tab[i + 1] == 1)
					ans = 0;
				if (tab[i] == 1 && tab[i + 1] == 2)
					ans = 0;
				if (tab[i] == 2 && tab[i + 1] == 0)
					ans = 0;
			}
			cout << ans << endl;
			continue;
		}
		for (int i = 0 ; i < n ; i++)
		{
			pos[tab[i]][i % 3].push_back(i);
		}
		int ans = INF;
		for (int i = k - 1 ; i < n ; i++)
		{
			ans = min(ans,rec(2,1,0,i));
			ans = min(ans,rec(0,2,1,i));
			ans = min(ans,rec(1,0,2,i));		
		}
		cout << ans << endl;
	}
}