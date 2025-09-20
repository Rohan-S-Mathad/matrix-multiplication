#include<stdio.h>
#define MOD 1000000007
int main(){
    long long  a[2][2],n,base[2][2],temp[2][2],res[2][2];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%lld",&a[i][j]);
           base[i][j] = a[i][j];
;
        }
        
    }
     res[0][0] = res[1][1] = 1;
    res[0][1] = res[1][0] = 0;
    printf ("How many tomes to multipy the matrix to itself. ");
    scanf("%lld",&n);
   
   while (n > 0) {
        if (n % 2 == 1) {
            // res = res * base (mod MOD)
            temp[0][0] = (res[0][0]*base[0][0] % MOD + res[0][1]*base[1][0] % MOD) %MOD;
            temp[0][1] = (res[0][0]*base[0][1] % MOD + res[0][1]*base[1][1] % MOD) % MOD;
            temp[1][0] = (res[1][0]*base[0][0] % MOD + res[1][1]*base[1][0] % MOD) % MOD;
            temp[1][1] = (res[1][0]*base[0][1] % MOD + res[1][1]*base[1][1] % MOD) % MOD;

            // Copy temp to res
            res[0][0] = temp[0][0];
            res[0][1] = temp[0][1];
            res[1][0] = temp[1][0];
            res[1][1] = temp[1][1];
        }

        // base = base * base (mod MOD)
        temp[0][0] = (base[0][0]*base[0][0] % MOD + base[0][1]*base[1][0] % MOD) % MOD;
        temp[0][1] = (base[0][0]*base[0][1] % MOD + base[0][1]*base[1][1] % MOD) % MOD;
        temp[1][0] = (base[1][0]*base[0][0] % MOD + base[1][1]*base[1][0] % MOD) % MOD;
        temp[1][1] = (base[1][0]*base[0][1] % MOD + base[1][1]*base[1][1] % MOD) % MOD;

        // Copy temp to base
        base[0][0] = temp[0][0];
        base[0][1] = temp[0][1];
        base[1][0] = temp[1][0];
        base[1][1] = temp[1][1];

        n /= 2;
    }


    printf ("the rsulting matrix is|%lld %lld| \n                      |%lld %lld|",res[0][0], res[0][1], res[1][0], res[1][1]);
    
    
}