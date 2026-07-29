/*
Find K Closest Elements:

The array is already sorted.

Start with the whole array:

    left = 0
    right = n - 1

Remove elements until only k remain.

At each step compare:

    |arr[left] - x|
    |arr[right] - x|

If the left element is farther:
    left++

Otherwise:
    right--

If the distances are equal,
remove the larger value
(by moving right).

Main insight:

The answer is always a contiguous
subarray because the array is sorted.

Instead of choosing k elements,
remove the farthest elements
until only k remain.

Time Complexity: O(n)
Space Complexity: O(1)
*/
#include <iostream>
#include <vector>
using namespace std;    
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - 1;
        while (right - left + 1 > k) {
            if (abs(arr[left] - x) > abs(arr[right] - x)) {
                left++;
            }
            else {
                right--;
            }
        }
        return vector<int>(arr.begin() + left,arr.begin() + right + 1);
    }
};
void print(vector<int> v) {
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i + 1 != v.size())
            cout << ",";
    }
    cout << "]" << endl;
}
int main() {
    Solution sol;
    vector<int> arr1 = { 2,4,5,8 };
    print(sol.findClosestElements(arr1, 2, 6));
    vector<int> arr2 = { 2,3,4 };
    print(sol.findClosestElements(arr2, 3, 1));
    return 0;
}