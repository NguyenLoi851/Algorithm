#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1005, MAXT = 105;
int N,T,D;
int a[MAXN]; 
int t[MAXN];
int dp[MAXN][MAXT];
int best;

void input(){
    cin >> N >> T >> D;
    for(int i=1;i<=N;i++) cin >> a[i];
    for(int i=1;i<=N;i++) cin >> t[i];
}

void solve(){
    best = 0;
    for(int i=1;i<=N;i++){
        for(int k=1;k<=T;k++){
            // if(k!=t[i]) dp[i][k] = 0;
            // else dp[i][k] = a[i]; 
            // if(k>=t[i]){
            //     for(int j=i-1;j>=max(0,i-D);j--){
            //         dp[i][k] = max(dp[i][k], dp[j][k-t[i]]+a[i]);
            //     }
            // }
            if(k<t[i]) dp[i][k] = 0;
            else{
                for(int j=i-1;j>=max(0,i-D);j--){
                    dp[i][k] = max(dp[i][k], dp[j][k-t[i]]+a[i]);
                }
            }
            best = max(best, dp[i][k]);
        }
    }
    cout << best << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}