/*Given an array nums containing n distinct numbers in the range [0, n],
return the only number in the range that is missing from the array.*/

//268. Missing Number

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        for(int i=0; i<n; i++)
        {
            if(nums[i]!=i)
            {
                return i;
            }
        }
        return n;
    }
};

int main() {
    Solution sol;
    int size;
    cout << "Enter the size of the vector: ";
    cin >> size;

    vector<int> nums(size);
    cout << "Enter the elements of the vector: ";
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }

    int missing = sol.missingNumber(nums);
    cout << "Missing number: " << missing << endl;

    return 0;
}