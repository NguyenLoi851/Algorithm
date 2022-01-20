#include<bits/stdc++.h>
using namespace std;

const int MAX = 1000005;
int n,m;
int s,t; // s: start, t: end

struct edge{
    int u,v,w;
    edge(int _u, int _v, int _w){
        u=_u;v=_v;w=_w;
    }
};

vector<edge> Adj[MAX];
vector<int> iDist(MAX, INT_MAX);

void input(){
    int u,v,w;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> u >> v >> w;
        Adj[u].push_back(edge(u,v,w));
    }
    cin >> s >> t;
}

void Dijkstra(int start){
    iDist[start] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>,
                    greater<pair<int,int>>> PQ;
    PQ.push(make_pair(iDist[start], start));
    while(!PQ.empty()){
        int u=PQ.top().second;
        PQ.pop();
        for(int i=0;i<Adj[u].size();i++){
            int v = Adj[u][i].v;
            int w = Adj[u][i].w;
            if(w+iDist[u]<iDist[v]){
                iDist[v] = w+iDist[u];
                PQ.push(make_pair(iDist[v],v));
            }
        }
    }
}

int main(){
    input();
    Dijkstra(s);
    if(iDist[t]==INT_MAX) cout << -1;
    else cout << iDist[t];
    return 0;
}