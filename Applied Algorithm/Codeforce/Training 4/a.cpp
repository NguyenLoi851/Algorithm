#include<bits/stdc++.h>
using namespace std;

const int MAX=1e4+5;
const double PI = acos(-1.0);

int N,F;
double V[MAX];
int T;
double ans;
double L,R,M;

bool check(double val){
    int sum=0;
    for(int i=1;i<=N;i++){
        sum += floor(V[i]/val);
    }
    return sum >= F+1;
}

void solve(){
    cin >> T;
    for(int t=0;t<T;t++){
        cin >> N >> F;
        for(int i=1;i<=N;i++){
            double r;
            cin >> r;
            V[i] = PI*r*r;
        }
        sort(V+1,V+N+1);
        L=0;
        R=V[N];
        while(R-L > 1e-6){
            M = (L+R)/2;
            if(check(M)){
                ans = M;
                L=M;
            }else R=M;
        }
        printf("%0.6lf\n",ans);
    }
}



int main(){
    solve();
    return 0;
}