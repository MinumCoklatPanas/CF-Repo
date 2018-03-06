#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	ll n,m;
	cin>>n>>m;
	while (1)
	{
		if (n==0 || m==0 || (n==m) )
		{
			cout<<n<<" "<<m<<"\n";
			return 0;
		}
		if ((n<m))
		{
			if (m<2*n)
			{
				cout<<n<<" "<<m<<"\n";
				return 0;
			}
			else
			 {
//			 	cout<<"yo\n";
			 	ll hasil=m/n;
			 	ll sisa=m%n;
			 	if (hasil%2==0)
			 	 m=sisa;
			 	else
			 	 m=n+sisa;
			 }
		}
		else
		if ((m<n))
		{
			if (n<2*m)
			{
				cout<<n<<" "<<m<<"\n";
				return 0;
			}
			else
			 {
			 	ll hasil=n/m;
			 	ll sisa=n%m;
			 	if (hasil%2==0)
			 	 n=sisa;
			 	else
			 	 n=m+sisa;
			 }
		}
	}
}
