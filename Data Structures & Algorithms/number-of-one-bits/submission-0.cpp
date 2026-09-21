class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        
        while (n != 0) {
            // Increment count if the least significant bit is 1
            count += n & 1;
            // Right shift the number to check the next bit
            n >>= 1;
        }
        return count;
    }
};