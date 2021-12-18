#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> v[105];
vector<int> w;

struct Point{
    int left;
    int right;
    int data;
};

int main(){
    cin >> n;
    typedef Point Point;
    Point *point = new Point[n+1];
    int cnt = 0;
    for(int i=1;i<=n;i++){
        point[i].data = i;
        cin >> point[i].left;
        cin >> point[i].right;
        if(point[i].left == 0){
            v[cnt].push_back(i);  
            cnt++;
        }
    }
    if(n==1){
        cout << 0 << " " << 0;
        return 0;
    }
    for(int i=0;i<cnt;i++){
        int pp;  
        pp = v[i][0];
        while(point[pp].right!=0){
            pp = point[pp].right;
            v[i].push_back(pp);
        }
    }

    for(int i=0;i<cnt;i++){
        w.insert(w.end(),v[i].begin(),v[i].end());
    }
    
    int len = w.size();

    vector<pair<int,int> > p;
    for(int i=0;i<=len;i++){
        p.push_back(make_pair(0,0));
    }
    p[w[0]]=make_pair(0,w[1]);
    p[w[len-1]] = make_pair(w[len-2],0);
    for(int i=1;i<len-1;i++){
        p[w[i]]=make_pair(w[i-1],w[i+1]);
    }
    for(int i=1;i<=len;i++){
        cout << p[i].first << " " << p[i].second << endl;
    }
}