// #include<bits/stdc++.h>
// using namespace std;

// const int MAX = 10005;
// int n,m;
// int a[MAX];
// int c[MAX];
// bool flag;

// void solution(){
//     if(flag==true){
//         for(int i=1;i<=m;i++){
//             cout << a[i] << " ";
//         }
//         exit(0);
//     }
//     for(int i=1;i<=m;i++){
//         if(a[i]!=c[i]) return; 
//     }
//     flag = true;
// }

// void TRY(int k){
//     for(int i=a[k-1]+1;i<=n-m+k;i++){
//         a[k]=i;
//         if(k==m){
//             solution();
//         }else TRY(k+1);
//     }
// }

// int main(){
//     cin >> n >> m;
//     for(int i=1;i<=m;i++) cin >> c[i];
//     memset(a,0,sizeof(a));
//     flag = false;
//     TRY(1);
//     cout << -1;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

const int MAX = 10005;
int n,m;
int a[MAX];
int c[MAX];

void input(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        cin >> a[i];
    }
}

void solution(){
    for(int i=1;i<=m;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void TRY(int k){
    for(int i=a[k-1]+1;i<=n-m+k;i++){
        a[k]=i;
        if(k==m) solution();
        else TRY(k+1);
    }
}

int main(){
    input();
    TRY(m);
    return 0;
}