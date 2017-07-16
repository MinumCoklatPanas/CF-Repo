#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
#define INF 1e9

int main()
{
	ll i,j,k,n,tab[200010];
	cin>>n;
	for (i=1;i<=n;i++)
	 cin>>tab[i];
	ll prefix[200010];
	 for (i=1;i<=n;i++)
	 {
	 	if (i==1)
	 	 prefix[i]=tab[i];
	 	else
	 	 prefix[i]=prefix[i-1]+tab[i];
	 }
	ll best=-1;
	for (i=1;i<n;i++)
	{
		ll sisa=prefix[n]-prefix[i];
		ll diff=abs(sisa-prefix[i]);
		if (best==-1)
		 best=diff;
		else
		 best=min(diff,best);
	}
	cout<<best<<"\n";
}