#include <bits/stdc++.h>
using namespace std;

bool ada[30];

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	set<string> st;
	for (int i=1;i<=n;i++)
	{
		memset(ada,0,sizeof(ada));
		string s;
		cin>>s;
		string tmp;
		tmp="";
		for (int j=0;j<s.length();j++)
		 ada[s[j]-'a']=1;
		for (int j=0;j<26;j++)
		 if (ada[j])
		  tmp+=j+'a';
//		cout<<tmp<<"\n";
		st.insert(tmp);
	}
	cout<<st.size()<<"\n";
}
