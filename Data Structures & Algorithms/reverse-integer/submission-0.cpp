class Solution {
public:
    int reverse(int x) {
        long int reversed_num = 0;
        while(x != 0)
        {
            int rem = x % 10;
            reversed_num = reversed_num * 10 + rem;
            if(reversed_num > INT_MAX || reversed_num < INT_MIN)
                return 0;
            x = x / 10;
        }
        return reversed_num;
    }
};
