#include <bits/stdc++.h>
using namespace std;
 
//Made with <3 by MinumCoklatPanas
typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 510;
const ll MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

bool isPrime[1000010];
vector<ll> primes;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(isPrime,1,sizeof(isPrime));
	isPrime[1] = 0;
	for (ll i = 2 ; i <= 1000000 ; i++) if (isPrime[i])
	{
		primes.push_back(i);
		for (ll j = i + i ; j <= 1000000 ; j += i)
			isPrime[j] = 0;
	}
	ll t;
	cin >> t;
	while (t--)
	{
		vector<pair<ll,ll>> factors;
		ll n;
		cin >> n;
		ll tmp = n;
		for (ll i = 0 ; primes[i] * primes[i] <= n ; i++) if (n % primes[i] == 0)
		{
			factors.emplace_back(primes[i],0);
			while (n % primes[i] == 0)
			{
				n /= primes[i];
				++factors.back().second;
			}
		}
		// continue;
		if (n >= 2)
			factors.emplace_back(n,1);
		// continue;
		if (factors.size() > 2)
		{
			cout << "YES\n";
			cout << factors[0].first << " " << factors[1].first << " " << (tmp / (factors[0].first * factors[1].first)) << endl;
		}
		else
		if (factors.size() == 2)
		{
			if (factors[0].second + factors[1].second < 4)
				cout << "NO\n";
			else
			{
				cout << "YES\n";
				cout << factors[0].first << " " << factors[1].first << " " << (tmp / (factors[0].first * factors[1].first)) << endl;			
			}

		}
		else
		{
			// cout << "yo\n";
			// continue;
			if (factors[0].second < 6)
				cout << "NO\n";
			else
			{
				cout << "YES\n";
				// continue;
				cout << factors[0].first << " " << factors[0].first * factors[0].first << " " << (tmp / (factors[0].first * factors[0].first * factors[0].first)) << endl;
			}
		}
	}
	return 0;
}
