/*
Optimal Solution: Bucket Sort

1. Use an unordered_map to count the frequency of each number.

2. Create a vector of buckets:
       bucket[i] = numbers that appear i times

3. Put each number into the bucket corresponding to its frequency.

4. Iterate from the highest frequency down to 1.

5. Add elements to the answer until we have k elements.

Example:

Frequency:
1 -> 3
2 -> 2
3 -> 1

Buckets:
bucket[1] = [3]
bucket[2] = [2]
bucket[3] = [1]

Traverse backwards:
frequency 3 -> 1
frequency 2 -> 2

Answer: [1, 2]

Time Complexity: O(n)
Space Complexity: O(n)

Why O(n)?
- Counting frequencies: O(n)
- Creating buckets: O(n)
- Traversing buckets: O(n)

We avoid sorting, which would take O(n log n).
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        // Count frequencies
        for (int num : nums) {
            freq[num]++;
        }
        // bucket[i] contains numbers with frequency i  
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto& pair : freq) {
            int number = pair.first;
            int frequency = pair.second;
            bucket[frequency].push_back(number);
        }
        vector<int> ans;
        // Start from highest frequency
        for (int i = nums.size(); i >= 0 && ans.size() < k; i--) {
            for (int num : bucket[i]) {
                ans.push_back(num);
                if (ans.size() == k) {
                    break;
                }
            }
        }
        return ans;
    }
};
int main() {
    Solution sol;
    vector<int> nums = { 1, 1, 1, 2, 2, 3 };
    int k = 2;
    vector<int> result = sol.topKFrequent(nums, k);
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}