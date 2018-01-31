#include <bits/stdc++.h>
using namespace std;

int valid (int x)
{
	int res=0;
	while (x>0)
	{
		res+=x%10;
		x/=10;
	}
	return (res==10);
}

int main()
{
	int n;
	int num=1;
	int i=1;
	int tab[10010];
	while (num<=10000){
	 if (valid(i))
//	  cout<<i<<" ke "<<num++<<"\n";
      tab[num++]=i;
	++i;
	}
//	return 0;
	cin>>n;
	cout<<tab[n]<<"\n";
//	cout<<n<<(10-valid(n))<<"\n";
//	cout<<n<"\n";
}
