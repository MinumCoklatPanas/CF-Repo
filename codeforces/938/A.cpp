#include <bits/stdc++.h>
using namespace std;

map<char,bool> vowel;
bool nyala[110];
string s;

int main()
{
	vowel['a']=1;
	vowel['i']=1;
	vowel['u']=1;
	vowel['e']=1;
	vowel['o']=1;
	vowel['y']=1;
	int n;
	cin>>n;
	cin>>s;
	memset(nyala,1,sizeof(nyala));
	for (int i=0;i<s.length();i++)
	{
		if (!nyala[i] || !vowel[s[i]]) continue;
		int j=i+1;
		while (vowel[s[j]] && j<s.length())
		{
			nyala[j]=0;
			++j;
		}
	}
	for (int i=0;i<s.length();i++)
	 if (nyala[i]) cout<<s[i];
	cout<<"\n";
}
