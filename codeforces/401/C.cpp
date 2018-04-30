#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	if (n>m)
	 {
	 	if (n-m==1)
	 	 {
	 	 	for (int i=1;i<=m;i++)
	 	 	 cout<<"01";
	 	 	cout<<0<<"\n";
		 }
		else
		 cout<<"-1";
	 }
	else
	 if (n==m)
	 {
	 	for (int i=1;i<=n;i++)
	 	 cout<<"10";
	 	cout<<"\n";
	 }
	else
	 {
	 	if (m-2*n>2)
	 	 cout<<-1<<"\n";
	 	else
	 	 {
	 	 	while ((m>n) && (n>0))
	 	 	{
	 	 		cout<<"110";
	 	 		m-=2;
	 	 		n--;
			}
			if (n>0)
			{
				assert(m==n);
				for (int i=1;i<=n;i++)
				 cout<<"10";
				cout<<"\n";
			}
			else
			 {
			 	for(int i=1;i<=m;i++)
			 	 cout<<"1";
			 	cout<<"\n";
			 }
		 }
	 }
}
