#include <bits/stdc++.h>
using namespace std;

int  main()
{
    //freopen("input.txt","r",stdin);
    string ask;
    cin>>ask;
    //cout<<ask<<"\n";
    int n;
    cin>>n;
   // cout<<n<<"\n";
    string tab[110];
    for (int i=1;i<=n;i++)
    {
        cin>>tab[i];
       // cout<<tab[i]<<endl;
    }
    //cout<<tab[2][0]<<endl;
    for (int i=1;i<=n;i++)
    {
        if (tab[i]==ask)
        {
            cout<<"YES\n";
            return 0;
        }
        for (int j=1;j<=n;j++)
        {
            string hasil;
            hasil="";
            hasil=tab[i][1];
            hasil+=tab[j][0];
           // cout<<hasil<<endl;
            if (hasil==ask)
            {
                cout<<"YES\n";
                return 0;
            }
        }
    }
    cout<<"NO\n";
    return 0;
}
