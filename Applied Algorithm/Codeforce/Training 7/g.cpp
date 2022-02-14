#include<bits/stdc++.h>
using namespace std;

int n, res = 0;
vector<pair<int,int>> t;

void input(){
    cin >> n;
    int a,b;
    for(int i=1;i<=n;i++){
        cin >> a >> b;
        t.push_back(make_pair(a,b));
    }
}

bool compare(pair<int, int> t1, pair<int, int> t2){
    return t1.second<t2.second;
}

int main(){
    input();
    sort(t.begin(), t.end(), compare);
    int r = t[0].second;
    for(int i=1;i<n;i++){
        if(t[i].first>r){
            r = t[i].second;
            res+=1;
        }
    }
    cout << res+1;
    return 0;
}