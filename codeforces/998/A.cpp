#include <bits/stdc++.h>
using namespace std;

int tab[15];

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	if (n==1)
	{
		cout<<-1<<"\n";
		return 0;
	}
	for (int i=0;i<n;i++)
	 cin>>tab[i];
	if (n==2 && tab[0]==tab[1])
	 cout<<-1<<"\n";
	else
	 {
	 	for (int mask=1;mask<(1<<n)-1;mask++)
	 	{
	 		int a=0,b=0;
	 		for (int j=0;j<n;j++)
	 		{
	 			if (mask&(1<<j))
	 			 a+=tab[j];
	 			else
	 			 b+=tab[j];
			}
			if (a!=b)
			{
				int cnt=0;
				vector<int> ans;
				for (int j=0;j<n;j++)
				{
					if (mask&(1<<j))
					{
						++cnt;
						ans.push_back(j+1);
					}
				}
				cout<<cnt<<"\n";
				for (int j=0;j<cnt;j++)
				{
					if (j==cnt-1)
					 cout<<ans[j]<<"\n";
					else
					 cout<<ans[j]<<" ";
				}
				break;
			}
		}
	 }
}
