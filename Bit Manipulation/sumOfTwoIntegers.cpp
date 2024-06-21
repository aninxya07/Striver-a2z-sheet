//Given two integers a and b, return the sum of the two integers without using any operators
//371. Sum of two integers

#include <iostream>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        int c = 0;
        while(b!=0)
        {
            c = (a&b);
            a = (a^b);
            b = (c)<<1;
        }
        return a;
    }
};

int main() {
    Solution sol;
    int a, b;
    cout << "Enter first no:" << endl;
    cin >> a;
    cout << "Enter second no:" << endl;
    cin >> b;
    int sum = sol.getSum(a, b);
    cout << "Sum of " << a << " and " << b << " is: " << sum << endl;
    return 0;
}