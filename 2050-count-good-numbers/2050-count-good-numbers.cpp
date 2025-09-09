class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long Pow(long long  x , long long n){
        long long  ans = 1  ;
        x = x % MOD;
        while(n){
            if(n % 2 == 0){
                x = (x * x ) % MOD ; 
                n = n/2 ;
            }else {
                ans = (ans * x) % MOD ;
                n = n - 1 ; 
            }
        }
        return  (ans); 
    }

    int countGoodNumbers(long long n) {
        long long No_of_odd_index =  n/2  ;
        long long No_of_even_index  = n - No_of_odd_index ;
        long long total_possible_for_odd = 4 ;
        long long total_possible_for_even = 5 ; 
        
        long long ans = Pow(4,No_of_odd_index )  * Pow(5,No_of_even_index ) ; 
        ans = ans % MOD ; 
        return ans ; 
    }
};