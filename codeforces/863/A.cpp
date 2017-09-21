#include <bits/stdc++.h>
using namespace std;

int main()
{
	int i,j,k,n;
	string s;
	cin>>s;
	int ingat;
	for (i=s.length()-1;i>=0;i--)
	{
		if (s[i]!='0')
		{
			ingat=i;
			break;
		}
	}
	//cout<<ingat<<" ingat\n";
	int left=0;
	int right=ingat;
	bool cek=true;
	while (left<right)
	{
		if (s[left]!=s[right])
		{
			cek=false;
			break;
		}
		left++;
		right--;
	}
	cout<<(cek? "YES" : "NO")<<"\n";
}