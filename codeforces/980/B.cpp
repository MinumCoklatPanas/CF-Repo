#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	 	if (k%2==0)
	 	{
	 		cout<<"YES\n";
	 		for (int i=1;i<=4;i++)
	 		 for (int j=1;j<=n;j++)
	 		 {
	 		 	if (i==1 || i==4)
				  {
				  	if (j==n)
				  	 cout<<".\n";
				  	else
				  	 cout<<".";
				  } 
				else
				 {
				 	if (j==1)
				 	 cout<<".";
				 	else
				 	 if (j==n)
				 	  cout<<".\n";
				 	else
				 	if (j-1<=k/2)
				 	 cout<<"#";
				 	else
				 	 cout<<".";
//				 	if (j==n)
//				 	 cout<<"\n";
				 }
			 }
		}
		else
		 {
		 	int tengah=(n+1)/2;
		 	int bagi=k/(n-2)+(k%(n-2)!=0);
			cout<<"YES\n";
		 	k%=n-2;
		 	if (k==0)
		 	 k=n-2;
		 	int jarak=k/2;
		 	for (int i=1;i<=n;i++)
		 	 {
		 	 	if (i==n)
		 	 	 cout<<".\n";
		 	 	else
		 	 	 cout<<".";
			 }
			for (int i=1;i<=n;i++)
			{
				if (i==1)
				 cout<<".";
				else
				 if (i==n)
				  cout<<".\n";
				 else
				  if (bagi>1)
				   cout<<"#";
			      else
			       if (abs(tengah-i)<=jarak)
			        cout<<"#";
			       else
			        cout<<".";
			}
			for (int i=1;i<=n;i++)
			 {
			 	if (i==1)
			 	 cout<<".";
			 	else
			 	if (i==n)
			 	 cout<<".\n";
			 	else
			 	 if (bagi<=1)
			 	  cout<<".";
			 	 else
			 	  if (abs(1-i)<=jarak || abs(n-i)<=jarak)
			 	   cout<<"#";
			 	  else
			 	   cout<<".";
			 }
			for (int i=1;i<=n;i++)
		 	 {
		 	 	if (i==n)
		 	 	 cout<<".\n";
		 	 	else
		 	 	 cout<<".";
			 }
		 }
}
