#include <bits/stdc++.h>
using namespace std;

int cei(int x)
{
	return (x/2)+(x%2);
}

int main()
{
	int n;
	cin>>n;
	int gan=n/2;
	int gen=cei(n);
	int anak=1+cei(gan-1);
	if (anak>=gan)
	 cout<<-1<<"\n";
	else
	{
		for (int i=1;i<=gen;i++)
		 cout<<1<<" "<<i+1<<"\n";
		int par=2;
		int cnt=0;
		int now=gen+2;
		for (int i=1;i<gan;i++)
		{
			cout<<par<<" "<<now<<"\n";
			++now;
			++cnt;
			if (cnt==2)
			{
				cnt=0;
				++par;
			}
		}
	}
	for (int i=1;i<n;i++)
	 cout<<1<<" "<<i+1<<"\n";
}
