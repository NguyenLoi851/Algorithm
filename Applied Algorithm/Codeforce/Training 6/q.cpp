#include<bits/stdc++.h>
using namespace std;

const int MAX = 100005;
int n,m;
vector<int> Adj[MAX], Adj_2[MAX];
vector<int> Low(MAX), Num(MAX, -1); // Num is Discover Time
long long cntB = 0, cntVertix = 0, res = 0, curnum = 0;
bool bVisited[MAX];

void input()
{
    int u, v;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
}

void AnalyzeDFS1(int u, int p)
{
    Low[u] = curnum + 1;
    Num[u] = ++curnum;
    for (int i = 0; i < Adj[u].size(); i++)
    {
        int v = Adj[u][i];
        if (v == p)
            continue;
        if (Num[v] == -1)
        {
            AnalyzeDFS1(v, u);
            Low[u] = min(Low[u], Low[v]);
        }
        else
        {
            Low[u] = min(Low[u], Num[v]);
        }
        if (Low[v] > Num[u]){
            cntB++;
            Adj_2[u].push_back(v);
            Adj_2[v].push_back(u);
        }
    }
}

void DFS(int start){
    cntVertix++;
    bVisited[start] = true;
    for(int i=0;i<Adj_2[start].size();i++){
        int v=Adj_2[start][i];
        if(bVisited[v]==false){
            bVisited[v] = true;
            DFS(v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    for(int i=1;i<=n;i++){
        if(Num[i]==-1){
            AnalyzeDFS1(i,-1);
        }
    }
    for(int i=1;i<=n;i++){
        if(bVisited[i]==false){
            DFS(i);
            res += (cntVertix * (cntVertix-1)) / 2;
            cntVertix = 0;
        }
    }
    cout << res - cntB;
    return 0;
}