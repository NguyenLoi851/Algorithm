#include<bits/stdc++.h>
using namespace std;

const int MAX = 30;
int h[MAX][MAX];
int n,m,x,y,cnt;
bool bCol[MAX]; 
bool bDiag1[MAX*2]; 
bool bDiag2[MAX*2]; 

void TRY(int k){
    for(int j=1;j<=n;j++){
        if(bCol[j] && bDiag1[k+j] && bDiag2[k-j+12] && (h[k][j]==0)){
            bCol[j] = false;
            bDiag1[k+j] = false;
            bDiag2[k-j+12] = false;
            if(k==n) cnt++;
            else TRY(k+1);
            bCol[j] = true;
            bDiag1[k+j] = true;
            bDiag2[k-j+12] = true;            
        }
    }
}

int main(){
    while(true){
        cin >> n >> m;
        cnt = 0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                h[i][j]=0;
            }
        }
        for(int i=0;i<=n;i++){
            bCol[i] = true;
        }
        for(int i=0;i<=3*n;i++){
            bDiag1[i] = true;
            bDiag2[i] = true;
        }
        if(n==0 && m==0){
            break;
        }else{
            for(int i=0;i<m;i++){
                cin >> x >> y;
                h[x][y]=1;
            }
            TRY(1);
            cout << cnt << endl;
        }
    }
    return 0;
}


// #include<bits/stdc++.h>
// using namespace std;

// int n,cnt; 
// bool bCol[10];
// bool bDiag1[40],bDiag2[40];
// int iRes[10];

// void solution(){
//     cnt++;
//     for(int i=1;i<=n;i++){
//         cout << iRes[i] << " ";
//     }
//     cout << endl;
// }

// void TRY(int i){
//     for(int j=1;j<=n;j++){
//         if(bCol[j] && bDiag1[i+j] && bDiag2[i-j+10]){
//             iRes[i]=j;
//             bCol[j]=false;
//             bDiag1[i+j]=false;
//             bDiag2[i-j+10]=false;
//             if(i==n) solution();
//             else TRY(i+1);
//             bCol[j]=true;
//             bDiag1[i+j]=true;
//             bDiag2[i-j+10]=true;
//         }
//     }
// }

// int main(){
//     cin >> n;
//     for(int i=0;i<=n;i++){
//         bCol[i]=true;
//     }
//     for(int i=0;i<=4*n;i++){
//         bDiag1[i]=true;
//         bDiag2[i]=true;
//     }
//     TRY(1);
//     cout << cnt;
//     return 0;
// }