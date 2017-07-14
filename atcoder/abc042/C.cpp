#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int i,j,k,n;
bool dislike[10];

bool cek(int x)
{
	while (x>0)
	{
		int buntut=x%10;
		if (dislike[buntut])
		 return false;
		x/=10;
	}
	return true;
}

int main()
{
	memset(dislike,0,sizeof(dislike));
	cin>>n>>k;
	for (i=1;i<=k;i++)
	{
		cin>>j;
		dislike[j]=1;
	}
	while (1)
	{
		if (cek(n))
		{
			cout<<n<<"\n";
			return 0;
		}
		n++;
	}
}