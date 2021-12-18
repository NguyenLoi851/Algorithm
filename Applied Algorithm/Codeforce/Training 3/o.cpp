// #include<bits/stdc++.h>
// using namespace std;

// typedef unsigned long long ull;

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);cout.tie(0);
//     int n,k;
//     cin >> n >> k;
//     k-=1;
//     int start; 

//     ull check_fact = 1;
//     for(int i=1;i<=n;i++){
//         check_fact *= i;
//         if(check_fact>k+1){
//             start = i;
//             break;
//         }
//     }
//     if(check_fact <= k+1){
//         cout << -1;
//         return 0;
//     }

//     int first_num_index; 
//     int nn=n;
//     int n_partial_fact = --nn;
//     while(k>=n_partial_fact && nn>1){
//         n_partial_fact*=(nn-1); 
//         nn--;
//     }
//     first_num_index = k / n_partial_fact+1;
//     k = k % n_partial_fact;

//     //cout << first_num_index << endl << k << endl;

//     int *h = new int[n+1];
//     for(int i=1; i<=n; i++){
//         h[i]=i;
//     }
//     int temp=h[1];
//     h[1]=first_num_index;
//     for(int i=first_num_index;i>1;i--){
//         if(i!=2) h[i]=h[i-1];
//         else h[i]=temp;
//     }
//     cout << k << endl;
//     for(int i=1;i<=k;i++){
//         if(next_permutation(h+n-start,h+n+1)==false){
//             cout << -1;
//             return 0;
//         }
//     }
//     for(int i=1;i<=n;i++){
//         cout << h[i] << " ";
//     }
//     return  0;
// }

// // // #include<bits/stdc++.h>
// // // using namespace std;

// // // const int MAX = 10005;
// // // int n,kk;
// // // int bMark[MAX],c[MAX];
// // // int x[MAX];
// // // int cnt;

// // // void input(){
// // //     cin >> n >> kk;
// // //     for(int i=1;i<=n;i++){
// // //         cin >> c[i];
// // //     }
// // // }

// // // bool check(int i){
// // //     if(bMark[i]==false) return true;
// // //     return false;
// // // }

// // // void solution(){
// // //     cnt++;
// // //     for(int i=1;i<=n;i++){
// // //         cout << x[i] << " ";
// // //     }
// // //     cout << endl;
// // // }

// // // void TRY(int k){
// // //     for(int i=1;i<=n;i++){
// // //         if(check(i)){
// // //             bMark[i]=true;
// // //             x[k]=i;
// // //             if(k==n) solution();
// // //             else TRY(k+1);
// // //             bMark[i]=false;
// // //         }
// // //     }
// // // }

// // // int main(){
// // //     input();
// // //     cnt = 0;
// // //     TRY(4);
// // //     //cout << cnt;
// // //     return 0;
// // // }

// // #include<bits/stdc++.h>
// // using namespace std;

// // typedef unsigned long long ull;

// // int main(){
// //     int n, k;
// //     cin >> n >> k;

// //     ull fact = 1;
// //     int start; 
// //     for(int i=1;i<=n;i++){
// //         fact *= i;
// //         cout << fact << endl;
// //         if(fact>=k){
// //             start = i;
// //             break;
// //         }
// //     }

// //     int *h = new int[n+1];
// //     for(int i=1;i<=n;i++){
// //         h[i]=i;
// //     }
// //     for(int i=1;i<k;i++){
// //         if(next_permutation(h+n-start,h+n+1)==false){
// //             cout << -1;
// //             return 0;
// //         }
// //     }
// //     for(int i=1;i<=n;i++){
// //         cout << h[i] << " ";
// //     }
// //     return 0;
// // }

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e4+5;

int n,kk;
int a[MAX];
int bMark[MAX];
int cnt = 0;

void input(){
    cin >> n >> kk;
}

bool check(int k, int i){
    if(bMark[i]==true) return false;
    else return true;
}

void solution(){
    cnt++;
    if(cnt == kk){
        for(int i=1;i<=n;i++){
            cout << a[i] << " ";
        }
    }
    return;
}

void TRY(int k){
    for(int i=1;i<=n;i++){
        if(check(k,i)){
            bMark[i]=true;
            a[k]=i;
            if(k==n){
                solution();
            }else{
                if(cnt < kk) TRY(k+1);
            }
            bMark[i]=false;
        }
    }
}

void solve(){
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
    TRY(1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    if(cnt < kk) cout << "-1";
    return 0;
}