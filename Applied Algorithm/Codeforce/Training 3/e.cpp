// #include<bits/stdc++.h>
// using namespace std;

// const int MAX = 20; 

// int n; // number of course
// int m; // number of semester
// int c[MAX]; // number of credits of subject i 
// int A[MAX][MAX]; 
// int best;
// int max_load;
// int load[MAX]; // total number of credit of semester i
// int x[MAX]; // the semeter has subject i 
// bool bMark[MAX]; // mark if learned subject i
// int cnt;
// int res;

// void input(){
//     cin >> n >> m;
//     for(int i=1;i<=n;i++){
//         cin >> c[i]; 
//     }
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){
//             cin >> A[i][j];
//         }
//     }
// }

// // bool check(int i, int k){
// //     if(bMark[k]==true) return false; 
// //     for(int j=1;j<=n;j++){
// //         if(A[j][k]==1 && bMark[j]==false) 
// //             return false;
// //     }
// //     return true;
// // }

// // void solution(){
// //     max_load = 0;
// //     for(int i=1;i<=m;i++) max_load = max(max_load, load[i]);
// //     best = min(max_load, best);
// // }

// // void TRY(int k){ // for each subject
// //     for(int i=1;i<=m;i++){
// //         if(check(i,k)){
// //             x[k]=i; 
// //             load[i]++;
// //             bMark[k] = true;
// //             if(k==n){
// //                 solution();
// //             }else{
// //                 if(load[i]<best) TRY(k+1);
// //             }
// //             load[i]--;
// //             bMark[k] = false;
// //         }
// //     }
// // }

// bool check(int i, int k){
//     if(bMark[i]==true) return false;
//     for(int j=1;j<=n;j++){
//         if(A[j][i] == 1 && bMark[j] == false) 
//             return false;
//     }
//     return true;
// }

// void solution(){
//     res = 0;
//     max_load = 0;
//     for(int i=1;i<=m;i++){
//         max_load = max(max_load, load[i]);
//     }
//     if(best > max_load){
//         best = max_load;
//         for(int i=1;i<=m;i++){
//             res += load[i];
//         }
//     }
// }

// void TRY(int k){ // for each semester
//     for(int i=1;i<=n;i++){ // for each course
//         if(check(i,k)){
//             x[i]=k; 
//             load[k]+=c[i];
//             bMark[i] = true; 
//             cnt++; 
//             if(cnt==n){
//                 solution();
//             }else{
//                 if(load[k]<best) TRY(k%m+1);
//             }
//             load[k]-=c[i];
//             bMark[i] = false;
//             cnt--;
//         }
//     }
// }



// int main(){
//     input();
//     best = INT_MAX; 
//     cnt = 0;
//     memset(bMark,false,MAX);
//     TRY(1);
//     cout << best; 
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// const int MAX = 24;

// int N, M, bestRes;
// int c[MAX], x[MAX], load[10];
// int A[MAX][MAX];

// void Setup()
// {

//     bestRes = INT_MAX;
//     cin >> N >> M;
//     for (int i = 1; i <= N; i++)
//         cin >> c[i];
//     for(int i =1;i<=M;i++) load[i] = 0;
//     for (int i = 1; i <= N; i++)
//     {
//         for (int j = 1; j <= N; j++)
//         {
//             cin >> A[i][j];
//         }
//     }
// }

// bool Check(int i, int k)
// {
//     for (int it = 1; it < k; it++)
//     {
//         if (A[it][k] == 1 && x[it] <= i)
//             return false;
//     }

//     return true;
// }

// void Solution()
// {
//     int maxLoad = 0;
//     for (int i = 1; i <= N; i++)
//         maxLoad = max(maxLoad, load[i]);
//     bestRes = min(bestRes, maxLoad);
// }
// void Try(int k)
// {
//     for (int i = 1; i <= M; i++)
//     {
//         if (Check(i, k))
//         {
//             x[k] = i;
//             load[i]+=c[k];

//             if (k == N)
//             {
//                 Solution();
//             }
//             else
//             {
//                 if (load[i] < bestRes)
//                     Try(k + 1);
//             }
//             load[i]-=c[k];
//         }
//     }
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     Setup();
//     Try(1);
//     cout << bestRes;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

const int MAX = 25; 

int n, m;
int c[MAX], a[MAX][MAX];
int x[MAX];
int load[MAX];
int best;

void input(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> c[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
}

void setup(){
    best = INT_MAX;
    for(int i=0;i<=m;i++){
        load[i] = 0;
    }
}

bool check(int s, int k){
    for(int i=1;i<=k;i++){
        if(a[i][k]==1 && x[i]>=s) return false;
        if(a[k][i]==1 && x[i]<=s) return false;
    }
    return true;
}

void solution(){
    int maxLoad = 0;
    for(int s=1;s<=m;s++){
        maxLoad = max(maxLoad, load[s]);
    }
    best = min(best, maxLoad);
}

void TRY(int k){ // for each course
    for(int s=1;s<=m;s++){ // for each semester
        if(check(s,k)){
            x[k]=s;
            load[s]+=c[k];
            if(k==n){
                solution();
            }else{
                TRY(k+1);
            }
            load[s]-=c[k];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0); 
    input();
    setup();
    TRY(1);
    cout << best;
    return 0;
}