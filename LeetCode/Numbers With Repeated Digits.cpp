#define ll long long int

class Solution {
public:
    int uniqueDigits = 0;
    int numDupDigitsAtMostN(int N) {
        backtrack(0, 0, N);
        return N - uniqueDigits + 1;
    }
    
    void backtrack(long curr, int bitmask, int N) {
        if(curr > N)
            return;
        uniqueDigits++;
        for(int digit = 0; digit < 10; digit++) {
            if(bitmask == 0 && digit == 0)
                continue;
            if(bitmask & (1 << digit))
                continue;
            backtrack(curr * 10 + digit, bitmask | (1 << digit), N);
        }
    }
};
