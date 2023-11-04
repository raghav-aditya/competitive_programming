#include <bits/stdc++.h>

#define bit(n) (1<<(n))
#define inf 1000000000
#define eps 1e-9
#define pi 3.1415926535897932385
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) a.begin(),a.end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) if(a>(b)) a=(b)
#define MAX(a,b) if(a<(b)) a=(b)
#define sqr(x) ((x)*(x))
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

#define N 55555

int b[N],a[N];
int n;

void add(int x,int d)
{
    for(;x<=n;x+=(x&-x)) a[x]+=d;
}

int getsum(int x)
{
    int s=0;
    for(;x>0;x-=(x&-x)) s+=a[x];
    return s;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    int T,t=0;
    for(scanf("%d",&T);T--;)
    {
        int m,i;
        scanf("%d%d",&m,&n);
        m++;
        fill(a,0);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
            b[i]++;
            add(i,b[i]);
        }
        scanf("\n");
        printf("Case #%d:\n",++t);
        char type;
        while(scanf("%c",&type)>0)
        {
            if(type=='E') break;
            if(type=='C')
            {
                int x,d;
                scanf("%d%d",&x,&d);
                d++;
                add(x,d-b[x]);
                b[x]=d;
            }
            else
            {
                int x;
                scanf("%d",&x);
                int it;
                for(i=it=0;;it++)
                {
                    int si=getsum(i);
                    int l=i,r=n+1;
                    while(l+1<r)
                    {
                        int mid=(l+r)/2;
                        if(m<getsum(mid)-si) r=mid; else l=mid;
                    }
                    if(x<=l) break;
                    i=l;
                }
                printf("%d\n",it+1);
            }
            scanf("\n");
        }
        printf("\n");
    }
    return 0;
}