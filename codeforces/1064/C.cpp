#include <bits/stdc++.h>
using namespace std;

char to_char(int a)
{
	return a+'a'-1;
}

int to_int(char a)
{
	return a-'a'+1;
}

int frek[30];

bool cmp(int a,int b)
{
	return (frek[a]>frek[b]);
}

bool cmp2(int a,int b)
{
	return (frek[a]<frek[b]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	string s;
	cin>>s;
	sort(s.begin(),s.end());
	cout<<s<<"\n";
	return 0;
	for (int i=0;i<s.length();i++)
		frek[to_int(s[i])]++;
	vector<int> ganjil,genap;
	for (int i=1;i<=26;i++)
	{
		if (frek[i]%2==0)
			 genap.push_back(i);
		else
			 ganjil.push_back(i);
	}
	sort(ganjil.begin(),ganjil.end(),cmp);
	sort(genap.begin(),genap.end(),cmp);
	string gan,gen;
	string ans;
	ans="";
	for (int i=0;i<min(ganjil.size(),genap.size());i++)
	{
		// cout<<"yo\n";
			string tmp;
			tmp="";
			if (abs(frek[ganjil[i]]-frek[genap[i]])==1){
			if (frek[ganjil[i]]>frek[genap[i]])
			{
				// cout<<frek[ganjil[i]]<<" "<<frek[genap[i]]<<"\n";
				for (int j=1;j<=frek[genap[i]];j++)
				{
					tmp+=(to_char(ganjil[i]));
					tmp+=(to_char(genap[i]));
				}
				for (int j=1;j<=frek[ganjil[i]]-frek[genap[i]];j++)
					tmp+=(to_char(ganjil[i]));
			}
			else
			{
				for (int j=1;j<=frek[ganjil[i]];j++)
				{
					tmp+=(to_char(genap[i]));
					tmp+=(to_char(ganjil[i]));
				}
				for (int j=1;j<=frek[genap[i]]-frek[ganjil[i]];j++)
					tmp+=(to_char(genap[i]));
			}}
			else
			{
				for (int j=1;j<=frek[ganjil[i]];j++)
					tmp+=(to_char(ganjil[i]));
				for (int j=1;j<=frek[genap[i]];j+=2)
				{
					tmp=tmp+(to_char(genap[i]));
					tmp=(to_char(genap[i]))+tmp;
				}
			}
			ans+=tmp;
	}
	if (ganjil.size()<genap.size())
	{
		string tmp;
		tmp="";
		for (int i=ganjil.size();i<genap.size();i++)
		{
			for (int j=1;j<=frek[genap[i]];j+=2)
			{
				tmp=tmp+(to_char(genap[i]));
				tmp=(to_char(genap[i]))+tmp;
			}
		}
		ans=tmp+ans;
	}
	else
	{
		string tmp;
		tmp="";
		for (int i=genap.size();i<ganjil.size();i++)
		{
			for (int j=1;j<=frek[ganjil[i]];j++)
				tmp+=(to_char(ganjil[i]));
		}
		ans=tmp+ans;
	}
	// assert(ans.size()==n);
	cout<<ans<<"\n";
}