#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a,b;
	cin>>a>>b;
	if (b>a)
	 cout<<0<<"\n";
	else
	 if (b==a)
	  cout<<"infinity\n";
	 else
	  {
	  	int mod=a-b;
	  	int akar=(int)sqrt(mod);
	  	int ans=0;
	  	for (int i=1;i<=akar;i++)
	  	{
	  		if (mod%i==0)
	  		{
	  			if (i>b)
	  			 ++ans;
	  			if (i*i!=mod)
	  			{
	  				if (mod/i>b)
	  				 ++ans;
				}
			}
		}
		cout<<ans<<"\n";
	  }
}
