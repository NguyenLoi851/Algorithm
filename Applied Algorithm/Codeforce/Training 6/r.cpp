#include<bits/stdc++.h>
using namespace std;

const int MAX = 1000005;
int f,s,g,u,d;
bool bVisited[MAX];
int Num[MAX] = {0};
bool flag = false;

void input(){
    cin >> f >> s >> g >> u >> d;
}

void BFS(int start){
    queue<int> Q;
    Q.push(start);
    Num[start] = 0;
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        if(v+u<=f && bVisited[v+u]==false){
            Q.push(v+u);
            Num[v+u] = Num[v]+1;
            bVisited[v+u] = true;
            if(v+u==g){
                cout << Num[g];
                flag = true;
                return;
            }
        }
        if(v-d>=1 && bVisited[v-d]==false){
            Q.push(v-d);
            Num[v-d]=Num[v]+1;
            bVisited[v-d] = true;
            if(v-d==g){
                cout << Num[g];
                flag = true;
                return;
            }
        }
    }
}

int main(){
    input();
    BFS(s);
    if(flag==false) cout << "use the stairs";
    return 0;
}