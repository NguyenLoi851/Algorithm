#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;
int n, m;
vector<int> Adj[MAX];
vector<int> Low(MAX), Num(MAX, -1); // Num is Discover Time
vector<int> isAP(MAX, 0);
int curnum = 0;
int cntAP = 0; // count Articulation Point
int cntB = 0;  // count Bridge

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
    int childNode = 0;
    Low[u] = curnum + 1;
    Num[u] = ++curnum;
    for (int i = 0; i < Adj[u].size(); i++)
    {
        int v = Adj[u][i];
        if (v == p)
            continue;
        if (Num[v] == -1)
        {
            childNode++;
            AnalyzeDFS1(v, u);
            Low[u] = min(Low[u], Low[v]);
            if (p != -1 && Low[v] >= Num[u])
                isAP[u] = 1;
        }
        else
        {
            Low[u] = min(Low[u], Num[v]);
        }
        if (Low[v] > Num[u])
            cntB++;
    }
    if (p == -1 && childNode >= 2)
        isAP[u] = 1;
}

int main()
{
    input();
    for (int i = 1; i <= n; i++)
    {
        sort(Adj[i].begin(), Adj[i].end());
    }
    for (int i = 1; i <= n; i++)
    {
        if (Num[i] == -1)
            AnalyzeDFS1(i, -1);
    }
    for (int i = 1; i <= n; i++)
    {
        if (isAP[i] == 1)
            cntAP++;
    }
    cout << cntAP << " " << cntB;
    return 0;
}
