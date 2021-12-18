// #include <cstdio>
// #include <cstring>

// using namespace std;

// int main() {
//     int l = 1, r = 1000000;
//     while (l != r) {
//         int mid = (l + r + 1) / 2;
//         printf("%d\n", mid);
//         fflush(stdout);

//         char response[3];
//         scanf("%s", response);
//         if (strcmp(response, "<") == 0)
//             r = mid - 1;
//         else
//             l = mid;
//     }

//     printf("! %d\n", l);
//     fflush(stdout);
// }

#include<bits/stdc++.h>
using namespace std;

map<int,pair<int,int> > m; 
int a[10]={0,4,8,15,16,23,42};
int ans[10][2];
bool flag[50];
int q[10]; 
int res[10];

int query(int a, int b){
    printf("? %d %d\n", a, b);
    int tmp;
    cin >> tmp;
    return tmp;
}

int main(){
    for(int i=1;i<=6;i++){
        for(int j=i+1;j<=6;j++){
            m[a[i]*a[j]] = {a[i],a[j]};
        }
    }
    q[1] = query(1,1); q[2] = query(2,4);
    q[3] = query(3,5); q[4] = query(3,4);
    ans[1][0] = sqrt(q[1]); 
    res[1] = ans[1][0];
    for(int i=2;i<=4;i++){
        ans[i][0] = m[q[i]].first;
        ans[i][1] = m[q[i]].second;
    }
    for(int i=0;i<=1;i++){
        for(int j=0;j<=1;j++){
            if(ans[2][i]==ans[4][j]){
                res[4] = ans[4][j];
                res[2] = q[2] / res[4];
                res[3] = q[4] / res[4];
                res[5] = q[3] / res[3];
            }
        }
    }
    for(int i=1;i<=5;i++){
        flag[res[i]] = true;
    }
    for(int i=1;i<=6;i++){
        if(flag[a[i]] == false){
            res[6] = a[i];
            break;
        }
    }
    cout << "! ";
    for(int i=1;i<=6;i++){
        cout << res[i] << " ";
    }
    return 0;
}