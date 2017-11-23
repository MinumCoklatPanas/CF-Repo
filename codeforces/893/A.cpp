#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int tab[3]={1,2,3};
	for (int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		if (a==tab[2])
		{
			cout<<"NO\n";
			return 0;
		}
		if (a==1)
		{
			if (tab[0]==1)
			 swap(tab[1],tab[2]);
			else
			 swap(tab[0],tab[2]);
		}
		else
		 if (a==2)
		 {
		 	if (tab[0]==2)
		 	 swap(tab[1],tab[2]);
		 	else
		 	 swap(tab[0],tab[2]);
		 }
		 else
		  {
		  	if (tab[0]==3)
		 	 swap(tab[1],tab[2]);
		 	else
		 	 swap(tab[0],tab[2]);
		  }
	}
	cout<<"YES\n";
}
