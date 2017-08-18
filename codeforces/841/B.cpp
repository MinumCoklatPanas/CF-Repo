#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
	int i,j,k,n,satu;
	scanf("%d",&n);
	satu=0;
	for (i=1;i<=n;i++)
	{
		scanf("%d",&k);
		if (k%2==1)
		 satu++;
	}
	if (satu==0)
	{
		printf("Second\n");
		return 0;
	}
	else
	 printf("First\n");
}
