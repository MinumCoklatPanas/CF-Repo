#include <bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int mon[48]={31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
	int n;
	cin>>n;
	int ask[30];
	for (int i=0;i<n;i++)
	 cin>>ask[i];
	for (int i=0;i<48;i++)
	{
		bool ya=true;
		for (int j=0;j<n;j++)
		{
			if (mon[(i+j)%48]!=ask[j])
			{
				ya=false;
				break;
			}
		}
		if (ya)
		{
			cout<<"Yes\n";
			return 0;
		}
	}
	cout<<"No\n";
}
