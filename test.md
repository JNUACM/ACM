#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1000 + 10;
const int maxm = 1e5 + 10;
const int INF = 0x3f3f3f3f;

int n,m;
int f[maxn];
int g[maxn][maxn];
bool in[maxn][maxn];
int md[maxn][maxn];

struct edge
{
  int u,v,c;
  edge(int u = 0, int v = 0, int c = 0) : u(u), v(v), c(c) {}
}es[maxm];


bool cmp(edge a, edge b)
{
  return  a.c < b.c;
}

void init()
{
  for(int i = 0; i <= n; i++) f[i] = i;
}

int find(int x)
{
   return x == f[x] ? x : f[x] = find(f[x]);
}

void unit(int x, int y)
{
  f[find(x)] = find(y);
}

bool same(int x, int y)
{
  return find(x) == find(y);
}

int vis[maxn];

void dfs(int s,int x, int dis)
{
   vis[x] = true;
   for(int i = 1; i <= n; i++)
    {
       if(g[x][i] != -1 && !vis[i] && in[x][i])
            {
             md[s][i] = max(dis,g[x][i]);  
             dfs(s,i,max(dis,g[x][i]));
             }
    }
}

int main()
{
  int T;
  scanf("%d",&T);
  while(T--)
  {
    scanf("%d%d",&n,&m);
    init();
    memset(g,-1,sizeof(g));
    memset(in,false,sizeof(in));
    for(int i = 0; i < m; i++)
     {
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        es[i] = edge(u,v,c);
        g[u][v] = g[v][u] = c; 
     }
   sort(es,es+m,cmp);
   int res = 0, cnt = 0;
   for(int i = 0; i < m; i++)
    {
       if(!same(es[i].u,es[i].v))
         {
            res += es[i].c;
            unit(es[i].u,es[i].v);
            in[es[i].u][es[i].v] = in[es[i].v][es[i].u] = true; 
            if(++cnt == n-1) break;
         }
    }
   for(int i = 1; i <= n; i++)
      {
         memset(vis,false,sizeof(vis));
         dfs(i,i,0);     
      } 
   //cout << res << endl;
   int ans = INF;
   for(int i = 0; i < m; i++)
         {
            if(in[es[i].u][es[i].v]) continue;
            ans = min(ans,res-md[es[i].u][es[i].v] + es[i].c);
            //cout << es[i].u << " " << es[i].v << " " << md[es[i].u][es[i].v] << endl; 
         } 
   if(ans != res) printf("%d\n",res);
   else printf("Not Unique!\n"); 
   }
   return 0;
}


