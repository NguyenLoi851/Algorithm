// #include<bits/stdc++.h>
// using namespace std;

// const int MAX = 15;

// int n, K, Q;
// int d[MAX];
// int c[MAX][MAX];
// int best; 
// int iDistance;
// int q[MAX];
// int x[MAX];
// bool bMark[MAX];
// vector<vector<int>> w;

// void input(){
//     cin >> n >> K >> Q;
//     for(int i=1;i<=n;i++){
//         cin >> d[i];
//     }
//     for(int i=0;i<=n;i++){
//         for(int j=0;j<=n;j++){
//             cin >> c[i][j];
//         }
//     }
// }

// void setup(){
//     best = INT_MAX;
//     iDistance = 0;
//     for(int i=1;i<=K;i++){
//         q[i]=Q;
//     }
//     for(int i=1;i<=n;i++){
//         bMark[i]=false;
//     }
//     vector<int> v;
//     v.push_back(0);
//     for(int i=0;i<=K;i++){
//         w.push_back(v);
//     }
// }

// void solution(){
//     int temp = iDistance;
//     for(int i=1;i<=K;i++){
//         temp += c[w[i].back()][0];
//     }
//     best = min(best, temp);
// }

// void TRY(int k){ // lap qua tung thanh pho
//     for(int i=1;i<=K;i++){
//         if(q[i]>=d[k]){
//             iDistance += c[w[i].back()][k];
//             x[k]=i;
//             w[i].push_back(k);
//             q[i]-=d[k];
//             if(k==n){
//                 // iDistance += c[w[i].back()][0];
//                 // best = min(best, iDistance);
//                 // iDistance -= c[w[i].back()][0];
//                 solution();
//             }else{
//                 TRY(k+1);
//             }
//             w[i].pop_back();
//             iDistance -= c[w[i].back()][k];
//             q[i]+=d[k];
//         }
//     }
// }

// int main(){
//     input();
//     setup();
//     TRY(1);
//     cout << best; 
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

const int MAX = 15;

int n, K, Q;
int d[MAX];
int c[MAX][MAX];
int dist;
int bestDist; 
vector<int> h[MAX];
int q[MAX];
int cnt[MAX];

void input(){
    cin >> n >> K >> Q;
    for(int i=1;i<=n;i++){
        cin >> d[i];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cin >> c[i][j];
        }
    }
}

void setup(){
    bestDist = INT_MAX;
    dist = 0;
    for(int i=1;i<=K;i++){
        q[i] = Q;
    }
    for(int i=1;i<=K;i++){
        cnt[i] = 0;
    }
}

int updateAndCalc(vector<int> h){
    int bestTemp = INT_MAX;
    do{
        int distTemp = c[0][h[0]];
        int i;
        for(i=0;i<h.size()-1;i++){
            distTemp += c[h[i]][h[i+1]];
        }
        distTemp += c[h[i]][0];
        bestTemp = min(bestTemp, distTemp);
    }while(next_permutation(h.begin(),h.end()));
    return bestTemp;
}

void TRY(int k){

    if(k==n+1){
        dist = 0;
        for(int i=1;i<=K;i++){
            if(cnt[i]==0){
                return;
            }
            dist+=updateAndCalc(h[i]);
            // dist+=c[0][h[i][0]];
            // int j; 
            // for(j=0;j<cnt[i]-1;j++){
            //     dist += c[h[i][j]][h[i][j+1]];
            // }
            // dist+=c[h[i][j]][0];
        }
        bestDist = min(dist, bestDist);
        return;
    }

    for(int i=1;i<=K;i++){
        if(q[i]>=d[k]){
            q[i]-=d[k];
            h[i].push_back(k);
            cnt[i]++;
            TRY(k+1);
            q[i]+=d[k];
            h[i].pop_back();
            cnt[i]--;
        }
    }
}

int main(){
    input();
    setup();
    TRY(1);
    cout << bestDist; 
    return 0;
}