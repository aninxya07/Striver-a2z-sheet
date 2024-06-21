/*Given an integer n, return an array ans of length n + 1 such that
for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.*/

//338. Counting Bits

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countSetBits(int num);

    std::vector <int> countBits(int n) {
        vector <int> ans;
        for (int i = 0; i <= n; i++)
        {
            int res = countSetBits(i);
            ans.push_back(res);
        }
        return ans;
    }
};

int Solution::countSetBits(int num) {
    int count = 0;
    while (num > 0)
    {
        if (num % 2)
        {
            count++;
        }
        num = num >> 1;
    }
    return count;
}

int main() {
    Solution sol;
    int n;
    cout << "Enter a non-negative integer n: ";
    cin >> n;

    vector<int> result = sol.countBits(n);

    cout << "Resulting vector: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}