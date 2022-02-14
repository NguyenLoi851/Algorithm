#include<bits/stdc++.h>
using namespace std;

const int MAX = 105;
int n,cnt=1;
int h[MAX];

bool compare(vector<int> solid1, vector<int> solid2){
    return ((solid1[1]<solid2[1]&&solid1[2]<solid2[2]) || (solid1[2]<solid2[1]&&solid1[1]<solid2[2]));
}

void input(){
    while(true){
        cin >> n;
        if(n==0) break;
        vector<vector<int>> solid(3*n+1, vector<int>(4,0));
        for(int i=1;i<=n;i++){
            cin >> solid[3*i-2][1] >> solid[3*i-2][2] >> solid[3*i-2][3];
            solid[3*i-1][1] = solid[3*i-2][2]; solid[3*i-1][2] = solid[3*i-2][3]; solid[3*i-1][3] = solid[3*i-2][1];
            solid[3*i][1] = solid[3*i-2][3]; solid[3*i][2] = solid[3*i-2][1]; solid[3*i][3] = solid[3*i-2][2];
        }
        for(int i=1;i<=3*n-1;i++){
            for(int j=i+1;j<=3*n;j++){
                if(compare(solid[i], solid[j])){
                    vector<int> temp = solid[i];
                    solid[i] = solid[j];
                    solid[j] = temp;
                }
            }
        }
        h[1] = solid[1][3];
        for(int i=2;i<=3*n;i++){
            int maxH = 0;
            for(int j=1;j<i;j++){
                if(compare(solid[i], solid[j])){
                    if(h[j]>maxH){
                        maxH = h[j];
                    }
                }
            }
            h[i] = maxH + solid[i][3];
        }
		int res=0;
		for (int i=1;i<=3*n;i++) if (h[i]>res) res=h[i];
		cout<<"Case "<<cnt<<": maximum height = "<<res<<endl;
        cnt++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    return 0;
}