#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int k,a,b;
	cin>>k>>a>>b;
	if (abs(k-a)<abs(k-b))
	 cout<<"A\n";
	else
	 cout<<"B\n";
}