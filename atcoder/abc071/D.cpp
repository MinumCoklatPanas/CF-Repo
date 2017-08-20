#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

const
 ll MOD=1e9+7;

int main()
{
	//freopen("input.txt","r",stdin);
	ll i,j,k,n;
	string s1,s2;
	cin>>n;
	cin>>s1>>s2;
	ll start;
	if (s1[0]==s2[0])
	 start=1;
	else
	 start=2;
	ll res=-1;
	ll kode;
	if (start==1)
	 {
	 	res=3;
	 	kode=1;
	 }
	else
	 {
	 	res=6;
	 	kode=2;
	 }
	i=start;
	ll pengali=2;
	while (i<s1.length())
	{
		//cout<<kode<<" kode\n";
		//cout<<res<<" res\n";
		if (s1[i]==s1[i+1])
		{
			if (kode==1)
			 {
			 	res*=2;
			 	res%=MOD;
			 }
			else
			 {
			 	res*=3;
			 	res%=MOD;
			 }
			i+=2;
			kode=2;
		}
		else
		 {
		 	if (kode==1)
		 	 {
		 	 	res*=2;
		 	 	res%=MOD;
			 }
			 i++;
			 kode=1;
		 }
	}
	//res%=MOD;
	cout<<res<<"\n";
}