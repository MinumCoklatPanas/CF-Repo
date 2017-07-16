#include <iostream>
using namespace std;

int main()
{
	int a,b;
	cin>>a>>b;
	if (a%3==0)
	{
		cout<<"Possible\n";
		return 0;
	}
	if (b%3==0)
	{
		cout<<"Possible\n";
		return 0;
	}
	if ((a+b)%3==0)
	{
		cout<<"Possible\n";
		return 0;
	}
	cout<<"Impossible\n";
	return 0;
}