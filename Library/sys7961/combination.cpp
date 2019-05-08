#define MOD 1000000007
#define SIZE 4000000
int f[SIZE +1];
int inv[SIZE+1 ];
void make_com(){
        inv[0] = inv[1] = f[0] = f[1] = 1;
        for (int i = 2; i <=SIZE ; i++)f[i] = 1LL*f[i - 1] * i % MOD;
        for (int i = 2; i <= SIZE ; i++)inv[i] = -1LL * (MOD / i) * inv[MOD % i] % MOD;
        for (int i = 2; i <= SIZE ; i++)inv[i] = 1LL * inv[i - 1] * ((inv[i] + MOD) % MOD) % MOD;
}
int C(int n, int r){return (long long)f[n] * inv[r] % MOD * inv[n - r] % MOD;}


