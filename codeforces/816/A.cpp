#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int balik (int x)
{
	if (x/10==0)
	 return x*10;
    int r,temp;
	temp=x;
	r=0;
	while (temp>0)
	{
		r=(r*10)+(temp%10);
		temp=temp/10;
	}
	return r;
}

int main()
{
    int i,j,k,n;
    char titik;
    int depan,belakang;
    cin>>depan>>titik>>belakang;
    //cout<<balik(depan)<<" "<<belakang<<"\n";
    if (depan%10>=6 || (balik(depan)<belakang && (depan%10==5)))
    {
    	//cout<<"yo\n";
        int ans_dep,ans_bel;
        ans_bel=(depan/10)+1;
        //cout<<ans_bel<<"\n";
        ans_dep=ans_bel*10;
        //ans_dep-=depan;
        ans_bel+=60-belakang;
        //cout<<ans_bel<<"\n";
        ans_dep-=depan+1;
        ans_dep*=60;
        //cout<<ans_dep<<"\n";
        int ans=ans_bel+ans_dep;
        cout<<ans<<"\n";
        return 0;
    }
    else
     {
     	if (balik(depan)==belakang){
     		cout<<0<<"\n";
     		return 0;
		 }
         if (balik(depan)>belakang){
           int ans=balik(depan)-belakang;
           cout<<ans<<"\n";
           return 0;
       	}
         else
          {
              if (depan==23)
               {
                   int ans=60-belakang;
                   cout<<ans<<"\n";
                   return 0;
               }
              else
               {
                   int ans_dep,ans_bel;
                   ans_dep=depan+1;
                   ans_bel=balik(ans_dep);
                   ans_bel+=(60-belakang);
                   int ans=ans_bel;
                   cout<<ans_bel<<"\n";
                   return 0;
               }
          }
     }
}
