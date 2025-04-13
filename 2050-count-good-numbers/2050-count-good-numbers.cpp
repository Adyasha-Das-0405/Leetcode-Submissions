class Solution {
public:
    const int MOD = 1e9 + 7 ;
    long long power(long long base , long long exponent){
        long long result = 1 ;
        while(exponent > 0){
            if(exponent % 2 == 1){
                result = (result * base) % MOD ;
            }
            base = (base * base) % MOD ;
            exponent /= 2 ;
        }
        return result ;
    }

    int countGoodNumbers(long long n) {
        long long oddPlace = n / 2 ;
        long long evenPlace = (n + 1) / 2 ; 
        long long ans = (power(5,  evenPlace) * power(4 , oddPlace)) % MOD ;
        return ans ;
    }
};