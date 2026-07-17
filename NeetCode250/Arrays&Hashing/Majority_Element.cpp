/*
Boyer-Moore Voting Algorithm:
Maintain a candidate and a count.
If the current number equals the candidate:
    count++
Otherwise:
    count--
If count becomes 0:
    choose the current number as the new candidate.
Because the majority element appears more than n / 2 times,
it cannot be completely cancelled by all the other elements.
Time: O(n)
Space: O(1)
*/
#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            if (num == candidate) {
                count++;
            }
            else {
                count--;
            }
        }
        return candidate;
    }
};
int main() {
    Solution sol;
    vector<int> nums1 = { 5, 5, 1, 1, 1, 5, 5 };
    vector<int> nums2 = { 2, 2, 2 };
    cout << "Output 1: " << sol.majorityElement(nums1) << endl;
    cout << "Output 2: " << sol.majorityElement(nums2) << endl;
    return 0;
}