#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,k;
	cin>>n>>k;
	ll ans=(k/n)+(k%n!=0);
	cout<<ans<<"\n";
}