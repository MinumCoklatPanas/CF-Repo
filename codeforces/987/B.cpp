#include <bits/stdc++.h>
using namespace std;

const
 long double EPS=1e-12;

int main()
{
//	freopen("input.txt","r",stdin);
	long double x,y;
	cin>>x>>y;
	if (x==1.0)
	{
		if (y==1.0)
		 cout<<"=\n";
		else
		 cout<<"<\n";
		return 0;
	}
	if (y==1.0)
	{
		if (x==1.0)
		{
			cout<<"=\n";
		}
		else
		 cout<<">\n";
		return 0;
	}
	long double kiri=log(y)/log(x);
	long double kanan=y/x;
	if (fabs(kiri-kanan)<=EPS)
	 cout<<"=\n";
	else
	 if (kiri-kanan>=EPS)
	  cout<<"<\n";
	 else
	  cout<<">\n";
}
