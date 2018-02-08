#include <bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	pair<bool,bool> bisa[10010];
	memset(bisa,0,sizeof(bisa));
	if (s.length()<=6)
	 cout<<0<<"\n";
	else
	if (s.length()==7)
	 {
	 	cout<<1<<"\n";
	 	cout<<s[5]<<s[6]<<"\n";
	 }
//	else
	else
	 {
	 	int n=s.length()-1;
		bisa[n-1].first=1;
		bisa[n-2].second=1;
		string tmp;
		tmp="";
		tmp+=s[n-1];
		tmp+=s[n];
		set<string> ans;
		ans.insert(tmp);
		tmp=s[n-2]+tmp;
		ans.insert(tmp);
		for (int i=n-3;i>4;i--)
		{
			string tmp1,tmp2;
			int satunya;
			//2 char
			tmp1="";
			tmp1+=s[i];
			tmp1+=s[i+1];
			satunya=i+2;
			if (n-satunya+1>=2)
			{
				if (bisa[satunya].second)
				{
					ans.insert(tmp1);
					bisa[i].first=1;
				}
				else
				 if (bisa[satunya].first)
				 {
				 	tmp2="";
				 	tmp2+=s[satunya];
				 	tmp2+=s[satunya+1];
				 	if (tmp1!=tmp2)
				 	{
				 		ans.insert(tmp1);
				 		bisa[i].first=1;
					 }
				 }
				 else
				  bisa[i].first=0;
			}
			//3 char
			tmp1+=s[i+2];
			satunya=i+3;
			if (n-satunya+1>=2)
			{
				if (bisa[satunya].first)
				{
					ans.insert(tmp1);
					bisa[i].second=1;
				}
				else
				 if (bisa[satunya].second)
				 {
				 	tmp2="";
				 	tmp2+=s[satunya];
				 	tmp2+=s[satunya+1];
				 	tmp2+=s[satunya+2];
				 	if (tmp1!=tmp2)
				 	{
				 		ans.insert(tmp1);
				 		bisa[i].second=1;
					}
					else
					 bisa[i].second=0;
				 }
			}
		}
		cout<<ans.size()<<"\n";
		for (set<string>::iterator it=ans.begin();it!=ans.end();++it)
		{
			string now=*it;
			cout<<now<<"\n";
		}
	 }
}
