#include <iostream>
#include <algorithm>
using namespace std;

int a,b,c,d,tombol[110];

void solve()
{
	cin>>a>>b>>c>>d;
	for (int i=a;i<=b;i++)
	 tombol[i]++;
	for (int i=c;i<=d;i++)
	 tombol[i]++;
	int sum=0;
	for (int i=0;i<=100;i++)
	 if (tombol[i]==2)
	  sum++;
	if (sum==0)
	 sum++;
	cout<<sum-1<<"\n";
	return;
}

int main()
{
	solve();
}