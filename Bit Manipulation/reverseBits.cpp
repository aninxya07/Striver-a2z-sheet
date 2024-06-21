//Reverse bits of a given 32 bits unsigned integer.

//190. Reverse Bits

#include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++) {
            ans <<= 1;
            ans |= (n & 1);
            n >>= 1;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Predefined input value
    uint32_t input = 0b00000010100101000001111010011100; // Binary representation of 43261596

    uint32_t reversed = sol.reverseBits(input);

    cout << "Reversed bits: " << reversed << endl;

    return 0;
}
