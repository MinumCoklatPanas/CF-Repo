    #include <iostream>
    #include <algorithm>
    #include <string>
    using namespace std;
     
    int main() {
    	int a,b,c;
    	int i,j,k,n;
    	string s;
    	cin>>s;
    	int panjang=s.length()-1;
    	int jumlah=1;
    	for (i=0;i<panjang;i++)
    	{
    		string potong;
    		potong=s;
    		potong.erase(panjang-i,jumlah);
    		jumlah++;
    		if (potong.length()%2==0)
    		{
    			int panjangpotong=potong.length();
    			int dua=panjangpotong/2;
    			bool cek=true;
    			for (j=0;j<dua;j++)
    			{
    				if (potong[j]!=potong[j+dua])
    				{
    					cek=false;
    					break;
    				}
    			}
    			if (cek)
    			{
    				cout<<panjangpotong<<"\n";
    				return 0;
    			}
    		}
    	}
    	return 0;
    }