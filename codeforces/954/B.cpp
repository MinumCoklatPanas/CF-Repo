#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	string now;
	now="";
	int ans=n;
	for (int i=0;i<n;i++)
	{
		if (i+1>n/2) break;
//		cout<<i<<"\n";
		now+=s[i];
		string tmp;
		tmp="";
		for (int j=i+1;j<=2*(i+1)-1;j++)
		 tmp+=s[j];
		if (now==tmp)
		{
			int sisa=n-(2*(i+1));
			int sum=i+2+sisa;
			ans=min(ans,sum);
		}
	}
	cout<<ans<<"\n";
}
