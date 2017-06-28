#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
	ll i,j,k,n,tab[100010];
	cin>>n;
	for (i=1;i<=n;i++)
	 cin>>tab[i];
	sort(tab+1,tab+n+1);
	i=2;
	int sum=1;
	int hitung=1;
	i=1;
	if (n<=2)
	 {
	 	cout<<0<<"\n";
	 	return 0;
	 }
	while (tab[i+1]==tab[i])
	{
		i++;
		sum++;
		if (i==n)
		 break;
	}
	//cout<<sum<<"\n";
	if (sum==n)
	 {
	 	cout<<0<<"\n";
	 	return 0;
	 }
	//cout<<sum<<"\n";
	i=n;
	while (tab[i-1]==tab[i])
	{
		i--;
		hitung++;
	}
	sum+=hitung;
	int ans=n-sum;
	cout<<ans<<"\n";
}
