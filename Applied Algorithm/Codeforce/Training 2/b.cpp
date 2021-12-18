#include<bits/stdc++.h>
using namespace std;

int n,k,x,m;

unsigned long long solve(vector<pair<int,int>>& v){
    unsigned long long res = 0;
    for(int i=v.size()-1;i>=0;i--){
        unsigned long long times = v[i].second/k;
        int plus = v[i].second%k;
        if(plus > 0) times++;
        res += 2*times*v[i].first;
        int remaining=(plus>0) ? (k-plus) : 0;
        if(i==0) break;
        int j=i-1;
        int flag = 1;
        while(flag&&remaining>0&&j>=0){
            if(v[j].second>=remaining){
                v[j].second -= remaining;
                flag=0;
            }else{
                remaining -= v[j].second;
                v[j].second=0;
                if(j==0) flag=0;
                j--;
            }
        }
    }
    return res;
}

int main(){
    cin >> n >> k;
    vector<pair<int,int> > v;
    vector<pair<int,int> > w;

    for(int i=0; i<n; i++){
        cin >> x >> m;
        if(x>0) v.push_back(make_pair(x,m));
        else w.push_back(make_pair(-x,m));
    }

    sort(v.begin(),v.end());
    sort(w.begin(),w.end());

    
    cout << solve(v) + solve(w);  
    return 0;
}