#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int i,j,k,n,tab[110];
	cin>>n;
	for (i=1;i<=n;i++)
	 cin>>tab[i];
	i=1;
	if (n<=2)
	{
		cout<<"YES\n";
		return 0;
	}
	while (1)
	{
		if (tab[i+1]<tab[i])
		{
			while (tab[i+1]<tab[i] && i<n)
			 i++;
			if (i>=n)
			 {
			 	cout<<"YES\n";
			 	return 0;
			 }
			else
			 {
			 	cout<<"NO\n";
			 	return 0;
			 }
		}
		else
		 if (tab[i+1]==tab[i])
		 {
		 	while (tab[i+1]==tab[i] && i<n)
		 	 i++;
		 	//i++; 
		 	if (i>=n)
		 	 {
		 	 	cout<<"YES\n";
		 	 	return 0;
			 }
		 	if (tab[i+1]>tab[i])
		 	{
		 		cout<<"NO\n";
		 		return 0;
			}
			else
			 {
			 	while (tab[i+1]<tab[i] && i<n)
				  i++;
				 //i++;
				 if (i<n)
				  {
				  	cout<<"NO\n";
				  	return 0;
				  }
				 else
				  {
				  	cout<<"YES\n";
				  	return 0;
				  } 
			 }
		 }
		 else
		  {
		  	while (tab[i+1]>tab[i] && i<n)
		  	 i++;
		  	
		  	//i++;
		  	while (tab[i+1]==tab[i] && i<n)
		  	 i++;
		  	//i++;
		  	while (tab[i+1]<tab[i] && i<n)
		  	 i++;
		  	//i++;
		  	if (i<n)
		  	{
		  		cout<<"NO\n";
		  		return 0;
			}
			else
			 {
			 	cout<<"YES\n";
			 	return 0;
			 }
		  }
	}
	int kosongkah;
}
