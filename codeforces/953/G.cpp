#include <stdio.h>

int min(int x,int y)
{
  if (x<y)
   return x;
  return y;
}

int main(void) {
	int n;
	scanf("%d",&n);
	int satu=0,dua=0;
	for (int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		// printf("%d\n",k);
		if (k%2==1)
		 ++satu;
		else
		 ++dua;
	}
	int ans=min(satu,dua);
	if (satu>dua)
	{
		satu-=dua;
		ans+=satu/3;
	}
	printf("%d\n",ans);
	return 0;
}
