#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	if (n>36)
	 cout<<-1<<"\n";
	else
	 if (19<=n && n<=36)
	 {
	 	int lapan=n-18;
	 	int empat=18-lapan;
	 	for (int i=1;i<=empat;i++)
	 	 cout<<4;
	 	for (int i=1;i<=lapan;i++)
	 	 cout<<8;
	 	cout<<"\n";
	 }
	 else
	  {
	  	for (int i=1;i<=n;i++)
	  	 cout<<4;
	  	cout<<"\n";
	  }
}
