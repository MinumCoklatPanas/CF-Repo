#include <bits/stdc++.h>
using namespace std;

double DP[2][3010][3010];
double val[2][3010];
int n;

double rec(int state,int index,int nyala,int mati)
{
	// cout << state << " " << index << " " << nyala << " " << mati << endl;
	if (DP[state][index][nyala] != -1.0) return DP[state][index][nyala];
	if (index == n)
	{
		if (mati >= nyala) return DP[state][index][nyala] = 0.0;
		// cout << state << " " << index << " " << nyala << " " << mati << " " ;
		return DP[state][index][nyala] = val[state][index];
	}
	double ret = 0.0;
	ret += val[state][index] * rec(state,index + 1,nyala + (state ^ 1),mati + (state));
	ret += val[state][index] * rec(state^1,index + 1,nyala + (state),mati + (state ^ 1));
	// cout << state << " " << index << " " << nyala << " " << ret << endl;
	return DP[state][index][nyala] = ret;
}

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> val[0][i];
		val[1][i] = 1 - val[0][i];
	}
	for (int i = 0 ; i < 2 ; i++)
		for (int j = 1 ; j <= n ; j++)
			for (int k = 0 ; k <= n ; k++)
				DP[i][j][k] = -1.0;
	double ans = rec(0,1,1,0) + rec(1,1,0,1);
	printf("%.12lf\n", ans);
}