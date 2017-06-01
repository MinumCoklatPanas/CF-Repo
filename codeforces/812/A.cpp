#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
	int i,j,lawan;
	bool tab[5][5];
	memset(tab,0,sizeof(tab));
	for (i=1;i<=4;i++)
	 for (j=1;j<=4;j++)
	  cin>>tab[i][j];
    bool b=false;
    int mobil;
    for (i=1;i<=4;i++)
     for (j=1;j<=3;j++)
     {
     	mobil=i-j;
     	if (mobil<=0)
     	 mobil+=4;
   	    if (i!=mobil)
   	    if ((tab[i][j])&&(tab[mobil][4]))
   	    {
   	    	//cout<<i<<" "<<j<<"\n";
   	    	//cout<<mobil<<"\n";
	    	 b=true;
	    	 break;
	   }
	   if (b)
	    break;
	 }
	 if (b)
	  cout<<"YES\n";
     else
	 if (!b)
	  {
	  	//cout<<"yo\n";
	  	b=true;
	  	bool b1=false;
	  	for (i=1;i<=4;i++)
	  	 {
	  	  	if ((tab[i][4])&&((tab[i][1])||(tab[i][2])||(tab[i][3])))
	  	  	{
	  	  		cout<<"YES\n";
	  	  		b=false;
	  	  		break;
			}
	     }
	     if (b)
	      cout<<"NO\n";
	  }
}
