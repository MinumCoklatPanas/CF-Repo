#include <bits/stdc++.h>
using namespace std;

int main()
{
	int i,j,k,n;
	cin>>n;
	vector<int> tab;
	int ab;
	cout<<"? 1 2\n";
	cout<<flush;
	cin>>ab;
	int ac;
	cout<<"? 1 3\n";
	cout<<flush;
	cin>>ac;
	int bc;
	cout<<"? 2 3\n";
	cout<<flush;
	cin>>bc;
	int b=ab+bc-ac;
	b/=2;
	int c=ac+b-ab;
	int a=ab+c-bc;
	//cout<<a<<" "<<b<<" "<<c<<"\n";
	tab.push_back(a);
	tab.push_back(b);
	tab.push_back(c);
	int now=c;
	for (i=4;i<=n;i++)
	{
		int tambah;
		cout<<"? "<<i<<" "<<i-1<<"\n";
		cout<<flush;
		cin>>tambah;
		tambah-=now;
		tab.push_back(tambah);
		now=tambah;
	}
	cout<<"! ";
	for (i=0;i<n;i++)
	 {
	 	if (i==n-1)
	 	 cout<<tab[i]<<"\n";
	 	else
	 	 cout<<tab[i]<<" ";
	 }
}
