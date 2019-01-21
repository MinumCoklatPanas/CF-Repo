#include <bits/stdc++.h>
using namespace std;

long long tab[2010][2010];
long long d[2][8010];
long long mx[2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin >> n;
	mx[0] = -1; mx[1] = -1;
	for (long long i = 1 ; i <= n ; i++)
		for (long long j = 1 ; j <= n ; j++)
		{
			cin >> tab[i][j];
			d[0][i + j] += tab[i][j];
			d[1][i - j + n] += tab[i][j];
		}
	pair<long long,long long> coor[2];
	for (long long i = 1 ; i <= n ; i++)
		for (long long j = 1 ; j <= n ; j++)
		{
			long long sum = d[0][i + j] + d[1][i - j + n] - tab[i][j];
			// cout << i << " " << j << " " << sum << endl;
			long long tmp = (i + j) & 1;
			if (sum > mx[tmp])
			{
				mx[tmp] = sum;
				coor[tmp].first = i;
				coor[tmp].second = j;
			}
		}
	cout << mx[0] + mx[1] << endl;
	cout << coor[0].first << " " << coor[0].second << " " << coor[1].first << " " << coor[1].second << endl;
}