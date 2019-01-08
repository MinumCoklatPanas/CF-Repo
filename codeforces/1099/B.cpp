#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin >> n;
	long long akar = (long long)sqrt(n);
	long long mn = 1e18;
	for (long long i = 1 ; i <= akar ; i++)
	{
		long long sisa = n / i;
		mn = min(mn,i + sisa + (n % i !=0));
	}
	cout << mn << endl;
}