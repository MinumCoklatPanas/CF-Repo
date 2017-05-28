#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a,b,n;
	cin>>a>>b;
	n=1;
	int count=1;
	while (1)
	{
		//cout<<a<<" "<<b<<" "<<n<<"\n";
		if (count%2==1)
		 a-=n;
	    else
	     b-=n;
	    n++;
	    //cout<<a<<" "<<b<<"  "<<count<<"\n";
	    count++;
	    if (a<0)
	     {
	     	cout<<"Vladik\n";
	     	break;
		 }
	    if (b<0)
	    {
	    	cout<<"Valera\n";
	    	break;
		}
	}
	//cout<<a<<" "<<b<<"\n";
	//cout<<a<<" "<<b<<"\n";
}
