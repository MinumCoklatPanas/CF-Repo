#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

bool ada[10][3];
int cnt[10][3];

void proc(string a)
{
	if (a[1] == 's')
	{
		ada[a[0] - '0'][0] = 1;
		cnt[a[0] - '0'][0]++;
 	}
 	else
 	if (a[1] == 'm')
 	{
 		ada[a[0] - '0'][1] = 1;
		cnt[a[0] - '0'][1]++;	
 	}
 	else
 	{
 		ada[a[0] - '0'][2] = 1;
		cnt[a[0] - '0'][2]++;
 	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s1,s2,s3;
	cin >> s1 >> s2 >> s3;
	proc(s1);
	proc(s2);
	proc(s3);
	int ans = INF;
	for (int i = 1 ; i <= 9 ; i++)
		for (int j = 0 ; j < 3 ; j++)
			ans = min(ans,3 - cnt[i][j]);
	for (int i = 0 ; i < 3 ; i++)
	{
		int mx = 0;
		int tmp = 0;
		for (int j = 1 ; j <= 9 ; j++)
		{
			if (!ada[j][i])
			{
				mx = max(mx,tmp);
				tmp = 0;
			}

			else
			{
				++tmp;
			}
		}
		mx = max(mx,tmp);
		for (int j = 1 ; j <= 7 ; j++)
		{
			if (ada[j][i] && ada[j + 2][i] && !ada[j + 1][i])
			{
				mx = max(mx,2);
				break;
			}
		}
		ans = min(ans,3 - mx);
	}
	cout << ans << endl;
}