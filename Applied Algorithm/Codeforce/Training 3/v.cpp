#include<bits/stdc++.h>
using namespace std;

const int MAX = 35;
int n,kk,m,c[MAX][MAX],x[MAX],load[MAX];
bool bMark[MAX]; 
vector<int> v[MAX]; 
int cnt; 

void input(){
    int a,b;
    cin >> n >> kk;
    cin >> m;
    for(int i=1;i<=m;i++){
        cin >> a >> b;
        c[a][b]=1;
        c[b][a]=1;
        load[a]++;
        load[b]++;
        v[a].push_back(b);
        v[b].push_back(a);
    }
}

void setup(){
    cnt=0;
}

bool check(int i, int k){
    // if(bMark[i] == true) return false;
    // if(c[x[k-1]][i] == 0 || c[i][x[k-1]] == 0) return false;
    // return true;
    if(bMark[i]==false && (c[x[k-1]][i]==1 || c[i][x[k-1]]==1 || k==1)) return true;
    return false;
}

void TRY(int k){
    for(int i=1;i<=n;i++){
        if(check(i,k)){
            x[k]=i;
            bMark[i]=true;
            int e = 0;
            if(k>1){
                m-=load[x[k-1]];
                // for(int j=1;j<=n;j++){
                //     if(c[x[k-1]][j]==1) load[j]--;
                // }
                int len = v[x[k-1]].size();
                for(int j=0;j<len;j++){
                    load[v[x[k-1]][j]]--;
                }
                // for(vector<int>::iterator it=v[x[k-1]].begin();it!=v[x[k-1]].end();it++){
                //     load[v[x[k-1]][*it]]--;
                // }
                //m-=(load[i]-1);
            } 
            if(k==kk+1){
                cnt++;
            }else{
                if(m-(load[i]-1)>=kk-k+1) TRY(k+1);
            }
            bMark[i]=false;
            if(k>1){
                m+=load[x[k-1]];
                // for(int j=1;j<=n;j++){
                //     if(c[x[k-1]][j]==1) load[j]++;
                // }               
                // for(vector<int>::iterator it=v[x[k-1]].begin();it!=v[x[k-1]].end();it++){
                //     load[v[x[k-1]][*it]]++;
                // }
                int len = v[x[k-1]].size();
                for(int j=0;j<len;j++){
                    load[v[x[k-1]][j]]++;
                }
                //m+=(load[i]-1); 
            } 
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0); 
    input();
    setup();
    TRY(1);
    cout << cnt/2;
    return 0;
}