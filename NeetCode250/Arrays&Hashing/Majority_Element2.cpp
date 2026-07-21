/*
Majority Element II

Problem:
Find all elements that appear more than floor(n / 3) times.

Important:
There can be at most 2 valid elements.

Why?
If 3 different elements appeared more than n / 3 times,
their total number of occurrences would be greater than n.

--------------------------------------------------

Solution 1: Hash Map

Idea:
Use a hash map to count the frequency of every number.

Example:
nums = [5,2,3,2,2,2,2,5,5,5]

Frequency:
5 -> 4
2 -> 5
3 -> 1

Then check:
if frequency > n / 3

Code idea:

unordered_map<int, int> freq;

for (int x : nums) {
    freq[x]++;
}

for (auto& pair : freq) {
    if (pair.second > n / 3) {
        ans.push_back(pair.first);
    }
}

Time Complexity: O(n)
Space Complexity: O(n)

--------------------------------------------------

Solution 2: Boyer-Moore Voting Algorithm

The main change is that we no longer store the frequency
of every number in a hash map.

Since there can be at most 2 valid answers,
we only keep:

candidate1 + count1
candidate2 + count2

First pass:
Find 2 possible candidates.

If the current number matches a candidate:
    increase its count.

If one candidate has count 0:
    replace it with the current number.

Otherwise:
    decrease both counts.

This cancels out 3 different numbers.

Important:
After the first pass, the candidates are only POSSIBLE answers.
They are not guaranteed to appear more than n / 3 times.

Therefore, we need a second pass to count their real frequencies.

Second pass:
    Count how many times candidate1 and candidate2
    actually appear.

Then:
    if count > n / 3
        add the candidate to the answer.

Time Complexity: O(n)
Space Complexity: O(1)

--------------------------------------------------

Main Difference:

Hash Map Solution:
    Store every number and its frequency.

    Space: O(n)

Boyer-Moore Solution:
    Store only 2 candidates and 2 counters.

    Space: O(1)

Both solutions have:
    Time Complexity: O(n)

The second solution is more space efficient,
but the first solution is simpler and easier to understand.
*/
#include<iostream>
#include<vector>
#include<unordered_map>
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = 0;
        int candidate2 = 1;
        int count1 = 0;
        int count2 = 0;
        // First pass: find two possible candidates
        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            }
            else if (num == candidate2) {
                count2++;
            }
            else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            }
            else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }
        // Second pass: verify the candidates
        count1 = 0;
        count2 = 0;

        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            }

            if (num == candidate2) {
                count2++;
            }
        }
        vector<int> result;

        if (count1 > nums.size() / 3) {
            result.push_back(candidate1);
        }

        if (count2 > nums.size() / 3) {
            result.push_back(candidate2);
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {  5, 2, 3, 2, 2, 2, 2, 5, 5, 5 };
    vector<int> nums2 = {  4, 4, 4, 4, 4 };
    vector<int> nums3 = { 1, 2, 3 };
    vector<int> result1 = sol.majorityElement(nums1);
    vector<int> result2 = sol.majorityElement(nums2);
    vector<int> result3 = sol.majorityElement(nums3);
    cout << "Example 1: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Example 2: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Example 3: ";
    for (int num : result3) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}