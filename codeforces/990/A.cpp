#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll cei(ll x,ll y)
{
	return (x/y)+(x%y!=0);
}

int main()
{
//	freopen("input.txt","r",stdin);
	ll n,m,a,b;
	cin>>n>>m>>a>>b;
	ll bawah=(n/m)*m;
	ll atas=cei(n,m)*m;
	ll diff1=abs(bawah-n);
	ll diff2=abs(atas-n);
	cout<<min(diff1*b,diff2*a)<<"\n";	
}
