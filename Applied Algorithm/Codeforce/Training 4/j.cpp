#include<bits/stdc++.h>
using namespace std;

struct point{
    long long x,y;
    int id;
};

point a[50005];
double res; 
int p1, p2;

bool cmp_x(point a, point b){
    return a.x < b.x;
}

bool cmp_y(point a, point b){
    return a.y < b.y;
}

double dis(point a, point b){
    return sqrt((double)1LL * (a.x - b.x) * (a.x-b.x) + (double)1LL * (a.y - b.y)*(a.y-b.y));
}

void update(point a, point b){
    double x = dis(a,b);
    if(x<res){
        res = x;
        p1 = a.id;
        p2 = b.id;
    }
}

void closest(int l, int r){
    if(l>=r) return;
    if(l+1 == r){
        update(a[l], a[r]);
        return;
    }

    int mid = (l+r)/2;
    int mid_x = a[mid].x;

    closest(l, mid);
    closest(mid+1, r);

    vector<point> v;
    for(int i=l;i<=r;i++){
        if(abs(a[i].x-mid_x)<=res){
            v.push_back(a[i]);
        }
    }
    sort(v.begin(),v.end(),cmp_y);
    double tmp = res;
    for(int i=0;i<v.size();i++){
        int j=i+1;
        while(j<v.size() && v[j].y - v[i].y <= tmp){
            update(v[i], v[j]);
            j++;
        }
    }
}

int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i].x >> a[i].y;
        a[i].id = i- 1;
    }

    sort(a+1, a+1+n,cmp_x);
    res = 1e9;
    closest(1,n);
    cout << setprecision(6) << fixed << min(p1,p2) << " " << max(p1,p2) << " " << res;
    return 0;
}