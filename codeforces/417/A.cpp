#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int c, d, m, n, k;
int main(){
    scanf("%d%d%d%d%d", &c, &d, &n, &m, &k);
    int x, y;
    int res = (m*n) - k;
    if(res < 0) res = 0;
    x = res*d;
    y = res/n * c;
    if(res % n != 0){
        int n1 = y + c;
        int n2 = y + (res%n) * d;
        y = n1 < n2 ? n1 : n2;
    }
    printf("%d\n", x < y? x : y);
    return 0;
}