#include <iostream>
#include <cstdio>
using namespace std;

typedef long long int lli;
lli MOD = 1000000007;
lli mods[100001];

lli findpow(lli num){
    if(mods[num]) return mods[num];
    lli res = 1;
    lli qq = num;
    int k = MOD-2;
    while(k){
        if(k%2) res = (res * qq) % MOD;
        qq = (qq * qq) % MOD;
        k >>= 1;
    }
    return mods[num] = res;
}

int main(){
    int T,N,x;
    lli *arr,M;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %lld", &N, &x, &M);
        arr = new lli[N];
        for(int i=0;i<N;i++) {
            scanf("%lld", arr+i);
            arr[i]%=MOD;
        }
        lli ans = arr[x-1] % MOD;
        lli prev = M % MOD, helper = 0;
        for(int i = x-2, j = 1; i>=0; i--, j++){
            lli carpan = (prev + helper) % MOD;
            ans += (arr[i]*carpan)%MOD;
            ans %= MOD;
            prev = carpan;
            helper = (prev * ((M-1)%MOD)) % MOD;
            helper = (helper * findpow(j+1)) % MOD;
        }
        printf("%lld\n", ans);
        delete [] arr;
    }
}
