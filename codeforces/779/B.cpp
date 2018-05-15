#include <bits/stdc++.h>
using namespace std;

int main()
{
	string n;
	int k;
	cin>>n>>k;
	int len=n.length();
	int ans=100;
	bool bisa[15];
	for (int mask=0;mask<(1<<len);mask++)
	{
		string tmp;
		memset(bisa,1,sizeof(bisa));
		for (int i=0;i<len;i++)
		{
			bisa[i]=!(mask&(1<<i));
		}
		for (int i=0;i<len;i++)
		 if (bisa[i])
		  tmp+=n[i];
		if (tmp.length()!=1 && tmp[0]=='0') continue;
		if (tmp.length()==1 && tmp[0]=='0')
		 ans=min(ans,__builtin_popcount(mask));
		else
		 {
		 	int cnt=0;
		 	int i=tmp.length()-1;
		 	while (tmp[i]=='0' && i>=0)
			{
			 	++cnt;
			 	--i;
			}	
			if (cnt>=k)
			 {
//			 	cout<<tmp<<" "<<mask<<"\n";
			 	ans=min(ans,__builtin_popcount(mask));
			 }
		 }
	}
	cout<<ans<<"\n";
}
