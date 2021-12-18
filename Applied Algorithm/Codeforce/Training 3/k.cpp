#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const ull MAX = 1e5+5;

ull c[MAX];

// ull C(ull k, ull n){
//     if(k==0) return 1;
//     if(k==1) return n % m;
//     if(k==n) return 1;
//     ull y = C(k,n-1);
//     ull z = y * k/ (n-k);
//     return (y + z);
// }

// ull fact(ull n){
//     ull res=1;
//     for(ull i=2;i<=n;i++){
//         res *= i;
//     }
//     return res;
// }
// ull C(ull k, ull n){
//     return (fact(n))/((fact(k)*(fact(n-k))));
// }

// ull C(ull k, ull n){
//     ull TS = 1, MS = 1;
//     if(n-k<k){
//         k=n-k; 
//     }
//     while(k!=0){
//         TS*=n;
//         MS*=k;
//         ull g = __gcd(TS,MS);
//         TS/=g;
//         MS/=g;
//         if(MS==1) TS %= m;
//         n--;
//         k--;
//     }
//     return TS;
// }

// ull C(ull k, ull n){
//     ull TS=1,MS=1;
//     if(n-k<k){
//         k=n-k;
//     }
//     for(ull i=1;i<=k;i++){
//         TS*=n--; 
//         TS/=i;
//         TS %= m;
//     }
//     return TS;
// }

// ull odm(ull n, ull k, ull m){
//     if(n-k<k) k=n-k;
//     for(int i=0;i<=k;i++) c[i]=0;
//     c[0]=1;
//     for(ull i=1;i<=n;i++){
//         for(ull j=min(i,k);j>0;j--){
//             c[j] = ( c[j] + c[j-1] ) % m;
//         }
//     }
//     return c[k];
// }
// ull tr(ull n, ull k, ull m){
//     if(k==0) return 1;
//     ull ni = n%m, ki = k%m;
//     return (tr(n/m,k/m,m)*odm(ni,ki,m)%m);
// }

ull moduloMultiplication(ull a, ull b, ull mod){
    ull res = 0;
    a %= mod;
    while(b){
        if(b&1) res = (res+a)%mod;
        a=(a*2)%mod;
        b >>=1;
    }
    return res;
}

ull gcdExtended(ull a,ull b,ull* x,ull* y){
    if(a==0){
        *x=0,*y=1;
        return b;
    }
    ull x1, y1;
 
    ull gcd = gcdExtended(b % a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

ull modInverse(ull b, ull mod){
    ull x,y;
    ull g = gcdExtended(b,mod,&x,&y);
    if(g!=-1) return -1;
    return (x%mod+mod)%mod;
}


ull modDivide(ull a, ull b, ull mod){
    a%=mod;
    ull inv = modInverse(b,mod);
    if(inv==-1){
        return 0;
    }else return(inv*a)%mod;
}

ull nCk(ull n, ull k, ull m){
    if(k>n) return 0;
    if(n-k<k) k = n-k;
    ull res=1;
    for(int i=1;i<=k;i++){
        res = moduloMultiplication(res,(n+1-i),m);
        res = modDivide(res,i,m);
    }
    return res;
}

int main(){
    int T;
    ull n,k,m;
    cin >> T;
    for(int i=0;i<T;i++){
        cin >> n >> k >> m;
        cout << nCk(n,k,m);
        cout << endl;
    }
    return 0;
}

//next in test.cpp