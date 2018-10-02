//Max_flow
//@2018/05/04 Friday
//SAP  O(n^2 * m)  O(m*3*2)
//by Tawn 
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 200 + 10;
const int maxm = 200 + 10;

int n,m;
int head[maxn];//链式前向星
int tot = 0;

struct edge
{
  int to;
  int c;
  int next;
  edge(int x = 0, int y = 0, int z = 0) : to(x), c(y), next(z) {}
 }es[maxm*2];//记录边 注意是2倍

void add_edge(int u, int v, int c)
{
    es[tot] = edge(v,c,head[u]);
    head[u] = tot++;
}


int SAP(int s, int t)
{
	int numh[maxn],h[maxn],ce[maxn],pre[maxn];
	//numh 记录gap优化的统计高度数量数组，h 距离标号数组，ce 当前弧，pre前驱数组
	int f, ans = 0, u, temp, neck, i; //初始化最大流为0
	memset(h,0,sizeof(h));
	memset(numh,0,sizeof(numh));
	memset(pre,-1,sizeof(pre));
	for(i = 1; i <= n; i++)  ce[i] = head[i];
	numh[0] = n;
    u = s;
    while(h[s] < n)
    {
    	//寻找增广路
    	if(u == t)
    	{
    		f = INF;
    		for(i = s; i != t; i = es[ce[i]].to)
    		{
    			if(f > es[ce[i]].c)
    			{
    				neck = i;
    				f = es[ce[i]].c;
    			}
    		}
    		for(i = s; i != t; i = es[ce[i]].to)
    		{
    			temp = ce[i];
    			es[temp].c -= f;
    			es[temp^1].c += f;
    		}
    		ans += f;
    		u = neck;
    	}

    	//寻找可行弧
    	for(i = ce[u]; i != -1; i = es[i].next)
    		if(es[i].c && h[u] == h[es[i].to] + 1)  break;

       //寻找增广路
    	if(i != -1)
    	{
    		ce[u] = i;
    		pre[es[i].to] = u;
    		u = es[i].to;
    	}
    	else
    	{
    		if(!--numh[h[u]]) break; //gap optimization
    		ce[u] = head[u];
    		for(temp = n, i = head[u]; i != -1; i = es[i].next)
    			if(es[i].c)  temp = min(temp, h[es[i].to]);

    		h[u] = temp + 1;
    		++numh[h[u]];
    		if(u != s) u = pre[u];//重标号并且从当前点前驱重新增广 
    	}

    }
    return ans;
}

int main()
{
   while(~scanf("%d%d",&n,&m))
   {
   tot = 0;
   memset(head,-1,sizeof(head));
   int u,v,c;
   for(int i = 0; i < m; i++)
   {
    scanf("%d%d%d",&u,&v,&c);
    add_edge(u,v,c);
    add_edge(v,u,0);//增加反向边
   }
   int ans = SAP(1,n); 
   printf("%d\n",ans);
   }
   return 0;   
}
