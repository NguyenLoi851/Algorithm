#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

int main(){
    int n, m, temp, res =1;
    cin >> n;
    vector<int> v;
    for(int i=0; i<n; i++){
        cin >> temp;
        v.push_back(temp);
    }
    cin >> m;
    for(int i=0;i<m; i++){
        cin>>temp;
        vector<int>::iterator it = find(v.begin(),v.end(),temp);
        if(it==v.end()){
            res = 0;
            break;
        }
    }
    cout << res; 
    return 0;
}
