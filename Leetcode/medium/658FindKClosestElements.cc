/*
Given a sorted integer array arr, two integers k and x, return the k
closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b


Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int elementIndex = binarySearch(arr, x);
        cout << elementIndex << endl;
        int l = elementIndex, r = elementIndex+1;
        vector<int> result;
        while ((l >= 0) && (r < arr.size()) && (result.size() != k)) {
            if (abs(arr[l] - x) < abs(arr[r] - x)) {
                result.push_back(arr[l]);
                --l;
            } else if (abs(arr[l] - x) > abs(arr[r] - x)) {
                result.push_back(arr[r]);
                ++r;
            } else {
                result.push_back(arr[l]);
                --l;
            }
        }

        if (result.size() != k) {
            if (l < 0) {
                while ((r <= arr.size()) && (result.size() != k)) {
                    result.push_back(arr[r]);
                    ++r;
                }
            } else {
                while ((l >= 0) && (result.size() != k)) {
                    result.push_back(arr[l]);
                    --l;
                }
            }
        }

        sort(result.begin(), result.end());
        return result;
    }



private:
    int binarySearch(vector<int>& arr, int element){
        int l = 0, r = arr.size(), n = arr.size();
        if (element <= arr[0]) {
            return 0;
        }
        if (element >= arr[r-1]) {
            return r-1;
        }
        int mid = 0;
        while(l <= r){
            mid = l + (r - l)/2;
            if (arr[mid] == element) {
                return mid;
            }
            if (element < arr[mid]) {
                if (mid > 0 && element > arr[mid-1]) {
                    if (element - arr[mid-1] > arr[mid] - element) {
                        return mid;
                    } else {
                        return mid-1;
                    }
                }
                r = mid;
            } else {
                if (mid < n - 1 && element < arr[mid+1]) {
                    if (element - arr[mid] > arr[mid+1] - element) {
                        return mid+1;
                    } else {
                        return mid;
                    }
                }
                l = mid;
            }
        }
        return arr[mid];
    }
};
