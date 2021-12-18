// // // #include<bits/stdc++.h>
// // // using namespace std;

// // // const int MAX = 105;

// // // int n,r;
// // // int c[MAX][MAX];
// // // vector<int> v[15];
// // // vector<int> a;
// // // bool bMark[MAX];
// // // int x[MAX];
// // // int best; 
// // // int dist;
// // // int s; // size of route

// // // void input(){
// // //     string str;
// // //     cin >> n >> r;
// // //     for(int i=1;i<=n;i++){
// // //         for(int j=1;j<=n;j++){
// // //             cin >> c[i][j];
// // //         }
// // //     }
// // //     getline(cin,str);
// // //     for(int i=1;i<=r;i++){
// // //         v[i].push_back(0);
// // //         getline(cin,str);
// // //         for(int j=0;j<str.length();j++){
// // //             if(j<str.length()-1 && str[j]=='1' && str[j+1]=='0'){
// // //                 v[i].push_back(10);
// // //                 continue;
// // //             }
// // //             if(str[j] != ' '){
// // //                 v[i].push_back(str[j]-'0');
// // //             }
// // //         }
// // //     }
// // // }

// // // bool check(int k, int i){
// // //     if(bMark[i] == true || c[x[k-1]][i] == 0) return false;
// // //     else return true;
// // // }

// // // void TRY(int k){
// // //     for(int i=2;i<=s-1;i++){
// // //         if(check(k,a[i])){
// // //             bMark[a[i]] = true;
// // //             x[k] = a[i];
// // //             dist += c[x[k-1]][x[k]];
// // //             if(k==s-1){
// // //                 if(c[x[k]][a[s]] != 0){
// // //                     dist += c[x[k]][a[s]];
// // //                     best = min(best, dist);
// // //                     dist -= c[x[k]][a[s]];
// // //                 }
// // //             }else{
// // //                 TRY(k+1);
// // //             }
// // //             bMark[a[i]] = false;
// // //             dist -= c[x[k-1]][x[k]];
// // //         }
// // //     }
// // // }

// // // void solve(){
// // //     for(int i=1;i<=r;i++){
// // //         for(int j=0;j<MAX;j++){
// // //             bMark[j] = false;
// // //         }
// // //         x[1] = v[i][1];
// // //         s = v[i].size()-1;
// // //         x[s] = v[i][s];
// // //         bMark[x[1]]=true;
// // //         bMark[x[s]] = true;
// // //         a.erase(a.begin(),a.end());
// // //         a = v[i]; 
// // //         best = INT_MAX;
// // //         dist = 0;
// // //         TRY(2);
// // //         if(best == INT_MAX) cout << 0 << endl;
// // //         else cout << best << endl;
// // //     }
// // // }

// // // int main(){
// // //     input();
// // //     // for(int i=1;i<=r;i++){
// // //     //     for(int j=1;j<v[i].size();j++){
// // //     //         cout << v[i][j]<< " ";
// // //     //     }
// // //     //     cout << endl;
// // //     // }
// // //     solve();
// // //     return 0;
// // // }

#include<bits/stdc++.h>
using namespace std;

const int MAX = 205;

// int n,r;
int c[MAX][MAX]; 
int best;
int dist;
// string str;
vector<int> v;
int x[MAX];
bool bMark[MAX];
int minC = INT_MAX;

bool check(int k, int i){
    if(c[x[k-1]][v[i]] == 0) return false;
    if(bMark[v[i]]) return false;
    return true;
}

void TRY(int k){
    for(int i=1;i<=v.size()-2;i++){
        if(check(k,i)){
            bMark[v[i]] = true;
            dist += c[x[k-1]][v[i]];
            x[k] = v[i];
            if(k==v.size()-1){
                if(c[x[k]][x[v.size()]] != 0) 
                    best = min(best, dist + c[x[k]][x[v.size()]]);
            }else{
                if(dist + minC*(v.size()-k) < best) TRY(k+1);
            }
            bMark[v[i]] = false;
            dist -= c[x[k-1]][v[i]];
        }
    }
}

int main(){
    string stra;
    bool flag = true;
    int n,r;
    cin >> n >> r;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> c[i][j];
            if(c[i][j]>0) minC = min(minC, c[i][j]);
        }
    }
    getline(cin, stra);
    while(r>0){
        string str;
        flag = true;
        best = INT_MAX;
        dist = 0;
        getline(cin, str);
        // for(int i=0;i<str.length();i++){
        //     if(str[i] != ' '){
        //         v.push_back(str[i]-'0');
        //     }
        // }
        while (!str.empty()){
            stringstream convert(str.substr(0, str.find(" ")));
            int tmp = 0;
            convert >> tmp;
            if(tmp>0) v.push_back(tmp);
            if(tmp > n) {
                flag = false;
            }
            // cout << " vt.back: " << vt.back()<< endl;

            if (str.find(" ") > str.size()){
                break;
            } else {
                str.erase(0, str.find(" ") + 1); // Update string
            }

            // cout << "str: " << str << endl;
        }
        if(flag == false){
            cout << '0' << endl;
            return 0;
        }
        x[1] = v[0];
        x[v.size()] = v[v.size()-1]; 
        // memset(bMark, false, sizeof(bMark));
        for(int i=0;i<205;i++){
            bMark[i] = false;
        }
        bMark[x[1]] = true;
        bMark[x[v.size()]] = true;
        TRY(2);
        if(best == INT_MAX) cout << 0 << endl;
        else cout << best << endl;
        // v.erase(v.begin(), v.end());
        v.clear();
        r--;
    }
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// const int MAX = 200;
// int n, r;
// int price[MAX][MAX];
// int x[MAX];
// bool visited[MAX];
// vector<int> vt;
// int min_price;
// int sum_price;
// int start, destination, numberOfPoint;

// void input(){
//     cin >> n >> r;
//     for(int i=0; i<n; i++)
//         for(int j=0; j<n; j++){
//             cin >> price[i][j];
//         }
// }

// bool check(int a, int i){
//     if(visited[vt[i]]) return false;
//     if(price[x[a-1]][vt[i]] == 0) return false;
//     return true;
// }

// void solution(){
//     if(price[x[numberOfPoint-2]][destination] == 0) return;
//     min_price = min(min_price, sum_price + price[x[numberOfPoint-2]][destination]);
// }

// void TRY(int a){
//     for(int i=1; i<numberOfPoint-1; i++){
//         if(check(a, i)){
//             visited[vt[i]] = true;
//             sum_price += price[x[a-1]][vt[i]];

//             x[a] = vt[i];
//             if(a == numberOfPoint-2) solution();
//             else TRY(a+1);

//             visited[vt[i]] = false;
//             sum_price -= price[x[a-1]][vt[i]];
//         }
//     }
// }

// int main(){
//     string str;
//     input(); getline(cin,str);

//     while(r > 0){
//         min_price = INT_MAX;
//         sum_price = 0;

//         getline(cin, str);

//         // Tach str thanh cac so va ghi vao vector vt
//         /*
//         int pre = 0;
//         for(int i=0; i<str.length(); i++){
//             if(str[i] == ' '){
//                 string tmp = str.substr(pre,i);
//                 pre = i + 1;
//                 stringstream convert(tmp);
//                 int tmp_int = 0;
//                 convert >> tmp_int;
//                 vt.push_back(tmp_int - 1);
//             }
//         }
//         string tmp = str.substr(pre,str.length());
//         stringstream convert(tmp);
//         int tmp_int = 0;
//         convert >> tmp_int;
//         vt.push_back(tmp_int - 1);
//         */
//         while (!str.empty()){
//             stringstream convert(str.substr(0, str.find(" ")));
//             int tmp = 0;
//             convert >> tmp;
//             vt.push_back(tmp - 1);

//             cout << " vt.back: " << vt.back()<< endl;

//             if (str.find(" ") > str.size()){
//                 break;
//             } else {
//                 str.erase(0, str.find(" ") + 1); // Update string
//             }

//             cout << "str: " << str << endl;
//         }

//         // // Bat dau khoi tao cac du lieu can thiet truoc khi quay lui
//         // start = vt[0]; // diem bat dau dau
//         // destination = vt[vt.size()-1]; // diem dich
//         // numberOfPoint = vt.size(); // so diem phai di qua
//         // x[0] = start; x[numberOfPoint-1] = destination;
//         // for(int i=0; i<n; i++)
//         //     visited[i] = false;

//         // TRY(1);

//         // // In ra ket qua
//         // if(min_price == INT_MAX) cout << "0" << endl;
//         // else cout << min_price << endl;

//         // // Xoa vector va chuyen sang khach tiep theo
//         // vt.erase(vt.begin(), vt.end());
//         r--;
//     }
// }