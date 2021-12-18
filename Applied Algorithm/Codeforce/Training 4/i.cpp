// #include<bits/stdc++.h>
// using namespace std;

// const int MAX = 5005;

// int n,kk;
// int a[MAX];
// bool bMark[MAX];
// int x[4];
// // int cnt = 0;
// int cnt;
// int sum;

// void input(){
//     cin >> n >> kk;
//     for(int i=1;i<=n;i++){
//         cin >> a[i];
//     }
// }

// bool check(int i){
//     if(bMark[i]) return false;
//     return true;
// }

// void solution(){
//     if(a[x[1]]+a[x[2]]+a[x[3]] == kk) cnt++;
// }

// void TRY(int k){
//     for(int i=x[k-1]+1;i<=n;i++){
//         if(check(i)){
//             bMark[i] = true;
//             x[k]=i;
//             sum += a[x[k]];
//             if(k==3){
//                 // if(a[x[1]]+a[x[2]]+a[x[3]] == kk) cnt++;
//                 if(sum==kk) cnt++;
//             }else{
//                 if(sum <= kk ) 
//                     TRY(k+1);
//             }
//             bMark[i] = false;
//             sum -= a[x[k]];
//         }
//     }
// }

// int main(){
//     input();
//     memset(x,0,sizeof(x));
//     memset(bMark,false,sizeof(bMark));
//     sort(a+1, a+n+1);
//     sum = 0;
//     cnt=0;
//     TRY(1);
//     cout << cnt; 
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

const int MAX = 5005;

int n,k;
int a[MAX];
int cnt=0;

void input(){
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
}

int searchAndCount(int f, int l, int key){
    if(f<=l){
        int m = f + (l-f)/2;
        if(a[m]==key) return 1 + searchAndCount(f,m-1,key)
                             + searchAndCount(m+1,l,key);
        else{
            if(a[m]>key) return searchAndCount(f,m-1,key);
            else return searchAndCount(m+1,l,key);
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    sort(a+1,a+n+1);
    for(int i=1;i<=n-2;i++){
        for(int j=i+1;j<=n-1;j++){
            if(k-a[i]-a[j]<=0) continue;
            cnt += searchAndCount(j+1,n,k-a[i]-a[j]);
        }
    }
    cout << cnt; 

    return 0;
}