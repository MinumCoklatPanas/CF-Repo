#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	int i,j,k=0,n;
	cin>>s;
	i=0;
	j=s.length()-1;
	while (i<=j)
	{
		if (s[i]!=s[j])
		 k++;
		i++;
		j--;
	}
	//cout<<k<<"\n";
	if (k==1)
	 cout<<"YES\n";
	else
	 if (k==0)
	 {
	 	if (s.length()%2==1)
	 	 cout<<"YES\n";
	 	else
	 	 cout<<"NO\n";
	 }
	else
	 cout<<"NO\n";
}
