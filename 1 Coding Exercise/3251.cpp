#include<cstdio>
#include<algorithm>
#include<cstring>
#define ok(a,b,c,d) (a>=0&&b>=0&&c>=0&&d>=0&&a<=n&&b<=n&&c<=n&&d<=n)

// https://blog.csdn.net/mars_ch/article/details/52838769

using namespace std;
//by mars_ch
char map[201][201],enter;
int n,p,q,ans;
int main()
{
    scanf("%d",&n);
    for (register int i=1;i<=n;i++)
    {
        scanf("%c",&enter);
        for (register int j=1;j<=n;j++)
            scanf("%c",&map[i][j]);
    }
    for (register int x=1;x<=n;x++)
        for (register int y=1;y<=n;y++)
            if (map[x][y]=='J')//枚举第一个点为J
                for (register int i=n;i>=1;i--)
                    for(register int j=n;j>=1;j--)//倒着枚举第二个点
                    {

                        p=i-x;q=j-y;//直角三角形
                        if(p*p+q*q<=ans) continue;//先算面积
                        if(map[i][j] == 'B' ) continue;//J或者空都ok
                        if (ok(x-q,i-q,y+p,j+p)&&(map[x-q][y+p]=='J')&&(map[i-q][j+p]=='J') || ok(y-p,j-p,i+q,x+q)&&(map[x+q][y-p]=='J')&&(map[i+q][j-p]=='J'))
                            ans=p*p+q*q;
                    }

    printf("%d",ans);
    return 0;
}