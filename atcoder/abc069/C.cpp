#include <iostream>
#include <algorithm>
using namespace std;

int ceil(int x)
{
	float f=(float)x/2;
	int e=x/2;
	if (e==f)
	 return e;
	return e+1;
}

int main()
{
	int i,j,k,n,dua,empat;
	cin>>n;
	dua=0;
	empat=0;
	for (i=1;i<=n;i++)
	{
		cin>>k;
		if (k%4==0)
		 empat++;
		else
		 if (k%2==0)
		  dua++;
	}
	//cout<<dua<<" "<<empat<<"\n";
	if (dua>0){
	n-=dua;
	//cout<<n<<" n\n";
	if (empat>=ceil(n))
	{
		cout<<"Yes\n";
		return 0;
	}
	else
	 cout<<"No\n";
	}
	else
	{
		if (empat>=n/2)
	{
		cout<<"Yes\n";
		return 0;
	}
	else
	 cout<<"No\n";
	}
}