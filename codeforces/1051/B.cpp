#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll l,r;
	cin>>l>>r;
	cout<<"YES\n";
	for (ll i=l;i<=r;i+=2)
	{
		cout<<i<<" "<<i+1<<"\n";
	}
}