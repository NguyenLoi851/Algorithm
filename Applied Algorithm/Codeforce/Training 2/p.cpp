#include<bits/stdc++.h>
using namespace std;

int N,M,x,y;
int a[905][905];
int c[905][905]={};
int flag=1;
queue<pair<int,int> > q;

void pushAndCount(int n, int m, int now){
    if(x<1||y<1||x>N||y>M||a[n][m]==1) return;
    if(c[n][m]==0){
        q.push({n,m});
        c[n][m] = ++now;
    }
}

void solve(){
    int m,n;
    q.push({x,y});
    c[x][y]=1;
    while(!q.empty()){
        pair<int,int> u = q.front();
        q.pop();
        n = u.first; m = u.second;
        if(n==N||m==M||n==1||m==1){
            cout << c[n][m];
            flag=0;
            return;
        }
        pushAndCount(n-1,m,c[n][m]);
        pushAndCount(n+1,m,c[n][m]);
        pushAndCount(n,m+1,c[n][m]);
        pushAndCount(n,m-1,c[n][m]);
    }
}

int main(){
    cin >> N >> M >> x >> y;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> a[i][j];
        }
    }
    solve();
    if(flag==1) cout << -1;
    return 0;
}