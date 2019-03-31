#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 2e5;
const int MOD = 1e9 + 7;

int frek[200010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
	{
		int ta;
		cin >> ta;
		frek[ta]++;
		if (frek[ta] > 2)
		{
			cout << "NO\n";
			return 0;
		}
	}
	vector<int> naik,turun;
	for (int i = 0 ; i <= 200000 ; i++)
	{
		if (frek[i])
		{
			naik.push_back(i);
			--frek[i];
		}
		if (frek[i])
		{
			turun.push_back(i);
			--frek[i];
		}
	}
	reverse(turun.begin(),turun.end());
	cout << "YES\n";
	cout << naik.size() << endl;
	for (int i = 0 ; i < naik.size() ; i++)
		cout << naik[i] << " ";
	cout << endl;
	cout << turun.size() << endl;
	for (int i = 0 ; i < turun.size() ; i++)
		cout << turun[i] << " ";
	cout << endl;
}