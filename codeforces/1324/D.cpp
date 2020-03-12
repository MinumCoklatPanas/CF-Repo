#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
//Made with <3 by MinumCoklatPanas
typedef long long ll;
typedef tree<ll, null_type, less_equal<ll>,
rb_tree_tag,tree_order_statistics_node_update>
ordered_set;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 510;
const ll MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

ordered_set avl;
ll A[200010];
ll B[200010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	for (ll i = 1 ; i <= n ; i++)
		cin >> A[i];
	for (ll i = 1 ; i <= n ; i++)
		cin >> B[i];
	ll ans = 0;
	for (ll i = n ; i >= 1 ; i--)
	{
		ans += avl.order_of_key(A[i] - B[i]);
		avl.insert(B[i] - A[i]);
	}
	cout << ans << endl;
	return 0;
}