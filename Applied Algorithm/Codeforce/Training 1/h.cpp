// #include<iostream>
// #include<vector>
// #include<iterator>
// #include<algorithm>
// using namespace std;

// int main(){
//     int n, m, temp, res =1;
//     cin >> n;
//     vector<int> v;
//     for(int i=0; i<n; i++){
//         cin >> temp;
//         v.push_back(temp);
//     }
//     cin >> m;
//     for(int i=0;i<m; i++){
//         cin>>temp;
//         vector<int>::iterator it = find(v.begin(),v.end(),temp);
//         if(it==v.end()){
//             res = 0;
//             break;
//         }
//     }
//     cout << res; 
//     return 0;
// }

#include<iostream>
using namespace std;

int main(){
    int n,m,a=0,b=0,tmp,res=1;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        a = a | (1<<tmp);
    }
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> tmp;
        if(a & (1<<tmp)){
            continue;
        }else{
            res=0;
        }
    }
    cout << res;
    return 0;
}

