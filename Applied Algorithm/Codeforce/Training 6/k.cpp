#include<bits/stdc++.h>
using namespace std;

const int MAX = 100005;
int n;
struct edge{
    int u,v,w;
    edge(int _u, int _v, int _w){
        u=_u;v=_v;w=_w;
    }
};

vector<edge> Adj[MAX];
bool bVisited[MAX];
int res = 0;
int maxFromVertex;
int len=0;

void input(){
    int u,v,w;
    cin >> n;
    for(int i=1;i<=n-1;i++){
        cin >> u >> v >> w;
        Adj[u].push_back(edge(u,v,w));
        Adj[v].push_back(edge(v,u,w));
    }
}

void DFS(int u){
    bool flag = false;
    for(int i=0;i<Adj[u].size();i++){
        int v=Adj[u][i].v, w=Adj[u][i].w;
        if(bVisited[v]==false){
            flag = true;
            len+=w;
            bVisited[v]=true;
            DFS(v);
            len-=w;
            bVisited[v]=false;
        }
    }
    if(flag == false){
        if(len>res){
            res = len;
            maxFromVertex = u;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    bVisited[1] = true;
    DFS(1);
    res = 0;
    len = 0;
    memset(bVisited,false,sizeof(bVisited));
    DFS(maxFromVertex);
    cout << res;
    return 0;
}