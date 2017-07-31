#include <iostream>
using namespace std;

int main()
{
	int s,v1,v2,t1,t2;
	cin>>s>>v1>>v2>>t1>>t2;
	int tot1=0;
	tot1+=(2*t1)+(v1*s);
	int tot2=(2*t2)+(v2*s);
	//cout<<tot1<<" "<<tot2<<"\n";
	if (tot1==tot2)
	{
		cout<<"Friendship\n";
	}
	else
	 {
	 	if (tot1<tot2)
	 	{
	 		cout<<"First\n";
		 }
		else
		 cout<<"Second\n";
	 }
}
