#include<bits/stdc++.h>
using namespace std;

const int MAX = 10005;
int n,k;
int c[MAX], d[MAX];
vector<int> Adj[MAX];
bool bVisited[MAX];
int cntD[MAX]; // count number of town, max = d
vector<pair<int,int>> townAndFare[MAX]; 
int fare[MAX];

void input(){
    int u,v;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> c[i] >> d[i];
    }
    for(int i=1;i<=k;i++){
        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
}

void DFS(int start){
    queue<int> Q;
    Q.push(start);
    bVisited[start]=true;
    cntD[start]=0;
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=0;i<Adj[u].size();i++){
            int v=Adj[u][i];
            if(bVisited[v]==false){
                bVisited[v]=true;
                cntD[v]=cntD[u]+1;
                if(cntD[v]>d[start]) break;
                Q.push(v);
                townAndFare[start].push_back({v,c[start]});
            }
        }
    }
    for(int i=1;i<=n;i++){
        bVisited[i]=false;
    }
    memset(cntD,0,sizeof(cntD));
}

void BFS(){
    fare[1]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>,
                    greater<pair<int,int>>> PQ;
    PQ.push({1,0});
    while(!PQ.empty()){
        int v=PQ.top().first;
        PQ.pop();
        for(pair<int,int> i:townAndFare[v]){
            if(fare[i.first]>fare[v]+i.second){
                fare[i.first]=fare[v]+i.second;
                PQ.push({i.first, fare[i.first]});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    for(int i=1;i<=n;i++){
        DFS(i);
    }
    for(int i=2;i<=n;i++){
        fare[i]=INT_MAX;
    }
    BFS();
    cout << fare[n];
    return 0;
}