#include <bits/stdc++.h>
using namespace std;

int main()
{
	map<char,int> mp;
	mp.clear();
	string s;
	cin>>s;
	for (int i=0;i<s.length();i++)
	 mp[s[i]]++;
	int ans=0;
	for (char i='a';i<='z';i++)
	 if (mp.count(i)) ++ans;
	cout<<(ans%2==0 ? "CHAT WITH HER!" : "IGNORE HIM!")<<"\n";
}
