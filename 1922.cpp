//  count good numbers 

class Solution {
    public:
        const int MOD = 1e9+7;
        int countGoodNumbers(long long n) {
            long long evenpos = (n+1)/2;
            long long oddpos = n/2;
    
            long long evenways = power(5,evenpos);
            long long oddways = power(4,oddpos);
    
            return (evenways*oddways)%MOD;
        }
    
        long long power(long long base , long long exp){
            if(exp == 0) return 1;
    
            long long half = power(base ,exp/2);
            half = (half*half)%MOD;
            return exp%2==0? half:(half*base)%MOD;
        }
    };