#include <iostream>
using namespace std;

int main ()
{
	int x,a,b;
	cin>>x>>a>>b;
	if (a>=b)
	 {
	 	cout<<"delicious\n";
	 	return 0;
	 }
	else
	 {
	 	if (b-a<=x)
	 	 {
	 	 	cout<<"safe\n";
	 	 	return 0;
		  }
		else
		 {
		 	cout<<"dangerous\n";
		 	return 0;
		 }
	 }
}