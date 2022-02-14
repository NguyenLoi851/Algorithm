#include<bits/stdc++.h>
using namespace std;

const int MAX = 10005;
int n,m;
int x[MAX], y[MAX];
int iMem[MAX][MAX] = {-1};

int LCS(int i, int j){
    if(i==0||j==0) return 0;
    if(iMem[i][j]!=-1) return iMem[i][j];

    int res = 0;
    res = max(LCS(i,j-1), LCS(i-1,j));
    if(x[i]==y[j]){
        res = max(res, 1+LCS(i-1,j-1));
    }
    iMem[i][j] = res;
    return res;
}

void input(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> x[i];
    }
    for(int i=1;i<=m;i++){
        cin >> y[i];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    // memset(iMem, -1, sizeof(iMem));
    cout << LCS(n,m);
    return 0;
}