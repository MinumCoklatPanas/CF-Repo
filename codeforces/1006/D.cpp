#include <bits/stdc++.h>
using namespace std;

map<char,int> frek;

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	string s1,s2;
	cin>>s1>>s2;
	int ans=0;
	for (int i=0;i<(n+1)/2;i++)
	{
		frek[s1[i]]++;
		frek[s1[n-i-1]]++;
		frek[s2[i]]++;
		frek[s2[n-i-1]]++;
//		cout<<s1[i]<<" "<<s1[n-i-1]<<" "<<s2[i]<<" "<<s2[n-i-1]<<"\n";
		int satu=0;
		int dua=0;
		int tiga=0;
		int empat=0;
		for (char j='a';j<='z';j++)
		{
			satu+=(frek[j]==1);
			dua+=(frek[j]==2);
			tiga+=(frek[j]==3);
			empat+=(frek[j]==4);
			assert(frek[j]<=4);
		}
		if (satu==4)
		 ans+=2;
		else
		 if (dua==1)
		  {
		  	if ((s1[i]==s1[n-i-1]))
		  	 ans+=2;
		  	else
		  	 ans++;
		  }
		 else
		  if (tiga==1)
		   ans+=1;
//		cout<<satu<<" "<<dua<<" "<<tiga<<" "<<empat<<"\n";
//		assert(satu+2*dua+3*tiga+4*empat==4);
		frek[s1[i]]=0;
		frek[s1[n-i-1]]=0;
		frek[s2[i]]=0;
		frek[s2[n-i-1]]=0;
	}
	if (n%2==1)
	{
		ans+=(s1[((n+1)/2)-1]!=s2[((n+1)/2)-1]);
	}
	cout<<ans<<"\n";
}