/*
The median is the middle value in an ordered integer list. If the size of the
list is even, there is no middle value and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within
10-5 of the actual answer will be accepted.

Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
*/

class MedianFinder {
public:

    priority_queue<int, vector<int>, greater<int>> maxHeap;
    priority_queue<int> minHeap;

    MedianFinder() {

    }

    void addNum(int num) {
        maxHeap.push(num);
        if (maxHeap.size() - minHeap.size() > 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return maxHeap.top() * (double)minHeap.top() * 0.5;
        } else {
            return (double)maxHeap.top();
        }
    }
};
