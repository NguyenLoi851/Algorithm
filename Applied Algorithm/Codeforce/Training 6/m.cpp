#include<bits/stdc++.h>
using namespace std;

const int MAX = 100005;
int n,m;
long long res = 0;

struct edge{
    int u,v,w;
    edge(int _u, int _v, int _w){
        u=_u; v=_v; w=_w;
    }
};

vector<edge> Edges;

struct Union_Find{
    vector<int> iParent;
    Union_Find(int n){
        iParent = vector<int> (n+2);
        for(int i=1;i<=n;i++){
            iParent[i] = i;
        }
    }
    int Find(int x){
        if(iParent[x] == x){
            return x;
        }else{
            iParent[x] = Find(iParent[x]);
            return iParent[x];
        }
    }
    void Unite(int x, int y){
        iParent[Find(x)] = Find(y);
    }
};

bool Edge_Cmp(const edge &a, const edge &b){
    return a.w < b.w;
}

long long MST(){
    Union_Find UF(n);
    sort(Edges.begin(), Edges.end(), Edge_Cmp);
    long long res = 0;
    for(int i=0;i<Edges.size();i++){
        int u = Edges[i].u, v = Edges[i].v;
        if(UF.Find(u) != UF.Find(v)){
            UF.Unite(u,v);
            res += Edges[i].w;
        }
    }
    return res;
}

void input(){
    int u,v,w;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        cin >> u >> v >> w;
        Edges.push_back(edge(u,v,w));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    struct Union_Find UF(n);
    sort(Edges.begin(), Edges.end(), Edge_Cmp);
    for(int i=0;i<Edges.size();i++){
        int u = Edges[i].u, v = Edges[i].v;
        if(UF.Find(u) != UF.Find(v)){
            UF.Unite(u,v);
            res += Edges[i].w;
        }
    }
    cout << res;
    return 0;
}

