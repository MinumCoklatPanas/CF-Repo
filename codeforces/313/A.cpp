#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int i,j,k,n;
	cin>>n;
	if (n>=0)
	 cout<<n<<"\n";
	else
	 {
	 	j=n%10;
	 	//cout<<j<<"\n";
	 	int a=n/10;
	 	k=a%10;
	 	//cout<<k<<"\n";
	 	if (j>k)
	 	{
	 		int a=n/100;
	 		a=a*10;
	 		int b=n%10;
	 		int ret=a+b;
	 		cout<<ret<<"\n";
		 }
		else
		 cout<<n/10<<"\n";
	}
	 return 0;
}
