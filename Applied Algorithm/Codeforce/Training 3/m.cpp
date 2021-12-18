// #include<bits/stdc++.h>
// using namespace std;

// int N;
// int a[8];
// int cnt = 0;

// void TRY(int k){
//     for(int i=a[k-1]+1;i<=9-7+k;i++){
//         a[k] = i;
//         if(k==7){
//             do{
//                 if(a[1]*100+a[2]*10+a[3]-a[7]*100-62+
//                 a[4]*1000+a[5]*100+a[6]*10+a[3]==N) cnt++;
//             }while(next_permutation(a+1,a+8));
//             //
//         }
//         else TRY(k+1);
//     }
// }

// int main(){
//     cin >> N;
//     a[0] = 0;
//     TRY(1);
//     cout << cnt;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

int n;
int a[10];
bool bMark[10];
int cnt = 0;

void input(){
    cin >> n;
}

bool check(int k, int i){
    if(bMark[i] == true) return false;
    else return true;
}

void solution(){
    int sum = a[1]*100+a[2]*10+a[3]-a[7]*100-62+
                a[4]*1000+a[5]*100+a[6]*10+a[3];
    if(sum==n) cnt++;
}

void TRY(int k){
    for(int i=1;i<=9;i++){
        if(check(k,i)){
            bMark[i] = true;
            a[k]=i;
            if(k==7){
                solution();
            }else{
                TRY(k+1);
            }
            bMark[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    TRY(1);
    cout << cnt;
    return 0;
}