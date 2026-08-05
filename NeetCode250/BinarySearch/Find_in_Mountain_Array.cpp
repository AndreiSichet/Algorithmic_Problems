/*
Find in Mountain Array:

Three binary searches.

Step 1:

Find the peak.

Compare:

arr[mid]

arr[mid+1]

If arr[mid] < arr[mid+1]:

    Peak is to the right.

Else:

    Peak is at mid or left.

Step 2:

Binary search the
ascending half.

If found:

    Return immediately.

Step 3:

Binary search the
descending half.

Reverse the comparison:

If value > target:

    Move right.

Else:

    Move left.

Main insight:

A mountain array is made
of two sorted arrays:

Increasing

then

Decreasing.

Find the peak first,
then search each sorted
half separately.

Important details:

- Always search the left
  half first because the
  problem asks for the
  minimum index.

- Descending binary search
  reverses the direction
  updates.

Time Complexity:

O(log n)

Space Complexity:

O(1)
*/
class Solution {
public:
    int findPeak(MountainArray& mountainArr) {
        int left = 0;
        int right = mountainArr.length() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
    int binarySearchAsc(MountainArray& mountainArr, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int value = mountainArr.get(mid);
            if (value == target)
                return mid;
            if (value < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
    int binarySearchDesc(MountainArray& mountainArr, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int value = mountainArr.get(mid);
            if (value == target)
                return mid;
            if (value > target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray& mountainArr) {
        int peak = findPeak(mountainArr);
        int leftAnswer = binarySearchAsc(mountainArr, 0, peak, target);
        if (leftAnswer != -1)
            return leftAnswer;
        return binarySearchDesc( mountainArr, peak + 1, mountainArr.length() - 1, target);
    }
};