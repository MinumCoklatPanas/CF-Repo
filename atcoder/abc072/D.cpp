#include <bits/stdc++.h>
using namespace std;

long long i,j,k,n,tab[100010];
int cei(int x)
{
	float f=(float)x/2;
	int e=x/2;
	if (e==f)
	 return e;
	return e+1;
}

int main()
{
	
	cin>>n;
	for (i=1;i<=n;i++)
	 cin>>tab[i];
	long long ans=0;
	for (i=1;i<=n;i++)
	{
		if (tab[i]!=i) continue;
		int hitung=0;
		while (tab[i]==i && i<=n)
		{
			hitung++;
			i++;
		}
		ans+=cei(hitung);
	}
	cout<<ans<<"\n";
}