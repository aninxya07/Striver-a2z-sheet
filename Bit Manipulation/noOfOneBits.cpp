/*Write a function that takes the binary representation of a positive
integer and returns the number of set bits it has (also known as the Hamming weight).*/

//191. Number of 1 bits

#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        while(n>0)
        {
            if(n%2==1)
            {
                count++;
            }
            n=n>>1;
        }
        return count;
    }
};

int main()
{
    Solution sol;
    int a;
    cout << "Enter a no:" << endl;
    cin >> a;
    int res=sol.hammingWeight(a);
    cout << "No of bits present in " << a << " is: " << res << endl;
}