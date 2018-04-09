#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	ll x,d;
	cin>>x>>d;
	
	 	vector<ll> pangkat;
	 	ll xx=x;
	 	ll sum=0;
	 	while (xx>0)
	 	{
	 		ll power=(ll)log2(xx+1);
	 		xx-=(1<<power)-1;
	 		pangkat.push_back(power);
	 		sum+=power;
		 }
		if (sum>10000)
		 cout<<-1<<"\n";
		else
		 {
		 	ll now=pangkat[0];
		 	for (int i=1;i<pangkat.size();i++)
		 	 {
		 	 	now=now+d+pangkat[i];
		 	 	if (now>1000000000000000000)
		 	 	{
		 	 		cout<<-1<<"\n";
		 	 		return 0;
				}
			 }
			ll ans=0;
//			cout<<pangkat.size()<<"\n";
//			for (int i=0;i<pangkat.size();i++)
//			 cout<<pangkat[i]<<" ";
//			cout<<"\n";
			for (int i=0;i<pangkat.size();i++)
			{
				ans+=(1<<pangkat[i])-1;
			}
			if (ans!=x)
			{
				cout<<-1<<"\n";
				return 0;
			}
			if (d==1)
			{
				now=pangkat[0];
				cout<<sum<<"\n";
				ll noww=1;
				for (int i=0;i<pangkat.size();i++)
				{
					for (int j=1;j<=pangkat[i];j++)
					 cout<<noww<<" ";
					++noww;
				}
				return 0;
			}
			cout<<sum<<"\n";
			now=pangkat[0];
			for (int i=1;i<=now;i++)
			 cout<<i<<" ";
			now+=d;
			for (int i=1;i<pangkat.size();i++)
			{
				for (int j=1;j<=pangkat[i];j++)
				 {
				 	cout<<now+i<<" ";
				 	++now;
				 }
				now+=d+1;
			}
			cout<<"\n";
		 }
}
