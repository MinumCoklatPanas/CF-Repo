#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 2e5;
const int MOD = 1e9 + 7;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<int> ganjil,genap;
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
	{
		int ta;
		cin >> ta;
		if (ta & 1)
			ganjil.push_back(ta);
		else
			genap.push_back(ta);
	}	
	sort(ganjil.begin(),ganjil.end());
	reverse(ganjil.begin(),ganjil.end());
	sort(genap.begin(),genap.end());
	reverse(genap.begin(),genap.end());
	vector<int> big,small;
	big = genap;
	small = ganjil;
	if (big.size() < small.size())
		swap(big,small);
	int ans = 0;
	for (int i = small.size() + 1 ; i < big.size() ; i++)
		ans += big[i];
	cout << ans << endl;
}