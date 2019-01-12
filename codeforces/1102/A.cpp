#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	ll sum = (n * (n + 1)) / 2;
	cout << (sum % 2) << endl;
}