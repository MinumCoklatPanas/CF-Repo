#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int digit (long long x)
{
	int count=0;
	while (x>0)
	{
		count++;
		x=x/10;
	}
	return count;
}

 long long sepuluhpangkat(int y)
 {
 	long long pangkat=1;
 	for (int loop=1;loop<=y;loop++)
 	 pangkat=pangkat*10;
 	return pangkat;
 }
 
int main()
{
	long long i,n;
	cin>>n;
	if (digit(n)==1)
	 cout<<1<<"\n";
	else
	 {
	 	long long a=n/(sepuluhpangkat(digit(n)-1));
	 	a++;
	 	a=a*(sepuluhpangkat(digit(n)-1));
	 	int hasil=a-n;
	 	cout<<hasil<<"\n";
	 }
	 return 0;
}

