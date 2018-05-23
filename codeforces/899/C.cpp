#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll genap(ll x)
{
	ll sum=(x*(x+1))/2;
	return sum;
}

bool sudah[60010];

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	ll n;
	cin>>n;
	if (n==2)
	{
		cout<<1<<"\n";
		cout<<1<<" "<<1<<"\n";
		return 0;
	}
	vector<ll> ans;
	ll tot=genap(n);
//	cout<<tot<<" tot\n";
	ll cari=tot/2;
	ll pos=-1;
	ll cnt=0;
	for (ll i=n;i>=1;i--)
	{
		ll len=n-i+1;
		cnt+=i;
		ll sisa=cari-cnt;
//		cout<<i<<" "<<cnt<<" "<<sisa<<"\n";
		sudah[i]=1;
		if (sisa<0) break;
		if (sisa>n) continue;
		if (sudah[sisa]) continue;
		pos=i;
	}
//	cout<<pos<<" pos\n";
	assert(pos!=-1);
	ll sum=0;
	for (ll i=pos;i<=n;i++)
	 {
	 	ans.push_back(i);
	 	sum+=i;
	 }
//	cout<<sum<<" sum\n";
//	cout<<cari-sum<<" kurang\n";
	if (cari>sum)
	 ans.push_back(cari-sum);
	assert(cari-sum<=n);	
	sum+=cari-sum;
//	cout<<genap(n)<<" "<<sum<<"\n";
	cout<<genap(n)-2*sum<<"\n";
//	cout<<sum<<" sum\n";
	cout<<ans.size()<<" ";
	for (ll i=0;i<ans.size();i++)
	 {
	 	if (i==ans.size()-1)
	 	 cout<<ans[i]<<"\n";
	 	else
	 	 cout<<ans[i]<<" ";
	 }
}
