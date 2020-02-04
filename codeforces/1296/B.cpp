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

ll pan[15];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	pan[0] = 1;
	for (ll i = 1 ; i <= 10 ; i++)
		pan[i] = pan[i - 1] * 10;
	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		if (n < 10)
		{
			cout << n << endl;
		}
		else
		{
			vector< ll > nums;
			ll tmp = n;
			while (tmp)
			{
				nums.push_back(tmp % 10);
				tmp /= 10;
			}
			// cout << "yo\n";
			reverse(nums.begin(),nums.end());
			// for (int i : nums)
			// 	cout << i;
			// cout << endl;
			ll ans = n;	
			for (ll i = 0 ; i + 1 < nums.size() ; i++)
			{
				ans += nums[i] * pan[nums.size() - 2 - i];
				// cout << nums[i] * pan[nums.size() - 2 - i] << endl;
				if (nums[i] + nums[i + 1] > 9)
				{
					// cout << i << " yo\n";
					// cout << pan[nums.size() - 2 - i] << endl;
					ans += pan[nums.size() - 2 - i];
					nums[i + 1]++;
				}
				nums[i + 1] = (nums[i] + nums[i + 1]) % 10;
			}
			cout << ans << endl;
			// cout << endl;
		}
	}
	return 0;
}