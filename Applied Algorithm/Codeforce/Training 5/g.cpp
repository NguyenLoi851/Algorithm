#include<bits/stdc++.h>
using namespace std;

const int MAX = 700; 

int n,W,H;
int w[MAX],h[MAX];
int dp[MAX][MAX];

int main(){
    cin >> W >> H;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> w[i] >> h[i];
    }
    for(int i=1;i<=W;i++){
        for(int j=1;j<=H;j++){
            dp[i][j] = i*j;
            for(int k=1;k<=n;k++){
                if(i==w[k] && j== h[k]){
                    dp[i][j] = 0;
                    break;
                }
            }
            for(int k=1;k<i;k++){
                dp[i][j] = min(dp[i][j],
                dp[k][j] + dp[i-k][j]);
            }
            for(int k=1;k<j;k++){
                dp[i][j] = min(dp[i][j],
                dp[i][k]+dp[i][j-k]);
            }
        }
    }
    cout << dp[W][H];
    return 0;
}