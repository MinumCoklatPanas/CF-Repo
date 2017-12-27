#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	vector<string> ans;
	for (int i=1;i<=s1.length();i++)
	 for (int j=1;j<=s2.length();j++)
	  {
	  	string tmp1;
	  	tmp1="";
	  	for (int k=0;k<=i-1;k++)
	  	 tmp1+=s1[k];
	  	string tmp2;
	  	tmp2="";
	  	for (int l=0;l<=j-1;l++)
	  	 tmp2+=s2[l];
	  	string res=tmp1+tmp2;
	  	ans.push_back(res);
	  }
	sort(ans.begin(),ans.end());
	cout<<ans[0]<<"\n";
}
