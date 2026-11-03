class Solution {
public:
    double myPow(double x, int n) {
        double prod = 1;
        long long new_n = n;
        if(new_n < 0) new_n = -1 * new_n;
        while(new_n > 0)
        {
            if(new_n % 2 == 0)
            {
                x = x * x;
                new_n = new_n/2;
            }
            else
            {
                prod = prod * x; 
                new_n -= 1;
            }
        }
        if(n < 0) prod = 1/prod;
        return prod;
    }
};