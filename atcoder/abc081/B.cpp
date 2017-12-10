#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int tab[210];
	bool ada=false;
	for (int i=1;i<=n;i++)
	 {
	 	cin>>tab[i];
	 	if (tab[i]%2==1)
	 	 ada=true;
	 }
	int ans=0;
	while (1)
	{
		ada=false;
		for (int i=1;i<=n;i++)
		 if (tab[i]%2==1)
		  {
		  	ada=true;
		  	break;
		  }
		if (ada) break;
		++ans;
		for (int i=1;i<=n;i++)
		 tab[i]/=2;	
	}
	cout<<ans<<"\n";
}