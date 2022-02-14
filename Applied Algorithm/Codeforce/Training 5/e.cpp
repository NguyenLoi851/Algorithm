#include<bits/stdc++.h>
using namespace std;

const int MAX = 2e6+5;

int n;
int t_max;
int L[MAX],R[MAX];
int ans;

void input(){
    cin >> n;
    t_max = 0;
    memset(L,0,MAX);
    memset(R,0,MAX);
    for(int i=1;i<=n;i++){
        int s,t;
        cin >> s >> t;
        L[t] = max(L[t], t-s);
        R[s] = max(R[s], t-s);
        if(t>t_max) t_max = t;
    }
}

void solve(){
    for(int i=1;i<=t_max;i++){
        L[i] = max(L[i],L[i-1]);
    }
    for(int i=t_max-1;i>=0;i--){
        R[i] = max(R[i],R[i+1]);
    }
    ans = -1;
    for(int i=0;i<t_max;i++){
        if(L[i] != 0 && R[i+1] != 0)
            ans = max(ans,L[i]+R[i+1]);
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}