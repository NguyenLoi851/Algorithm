#include<bits/stdc++.h>
using namespace std;

int T,L,C; 

int main(){
    cin >> T;
    int temp;
    for(int t=0;t<T;t++){
        int d[3000][3000]={0};
        vector<pair<int,int> > a;
        vector<pair<int,int> > b; 
        cin >> L >> C;
        for(int i=1;i<=L;i++){
            for(int j=1;j<=C;j++){
                cin >> temp;  
                if(temp==1) a.push_back({i,j});
            }
        }
        for(int i=1;i<=L;i++){
            for(int j=1;j<=C;j++){
                cin >> temp; 
                if(temp==1) b.push_back({i,j});
            }
        }
        int res = 0;
        int len1 = a.size();
        int len2 = b.size();
        for(int i=0;i<len1;i++){
            for(int j=0;j<len2;j++){
                temp = ++d[1000+a[i].first-b[j].first][1000+a[i].second-b[j].second];
                res = max(res,temp);
            }
        }
        cout << res << endl;
    }
    
    return 0;
}

