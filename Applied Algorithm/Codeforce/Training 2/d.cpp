#include<bits/stdc++.h>
using namespace std;

int c[1000][1000]={};
int a,b,cc,flag = 1;
queue<pair<int,int>> q;

void pushAndCount(int x, int y, int now){
    if(x<0||y<0||x>a||y>b) return;
    if(c[x][y]==0){
        q.push({x,y});
        c[x][y] = ++now;
    }
}

void solve(){
    int x,y;
    // q.push({a,b});
    q.push({0,0});
    // c[a][b]=1;
    c[0][0]=1;
    while(!q.empty()){
        pair<int,int> u = q.front();
        q.pop();
        x = u.first;y=u.second;
        if(x==cc||y==cc){
            cout<<c[x][y]-1;
            flag = 0;
            return;
        }
        pushAndCount(x,0,c[x][y]);
        pushAndCount(0,y,c[x][y]);
        pushAndCount(x,b,c[x][y]);
        pushAndCount(a,y,c[x][y]);
        pushAndCount(a,x+y-a,c[x][y]);
        pushAndCount(x+y,0,c[x][y]);
        pushAndCount(x+y-b,b,c[x][y]);
        pushAndCount(0,x+y,c[x][y]);
    }

}

int main(){
    cin >> a >> b >> cc;
    solve();
    if(flag==1) cout << -1;
    return 0;
}