/*
You are given two images img1 and img2 both of size n x n, represented as
binary, square matrices of the same size. (A binary matrix has only 0s and 1s as values.)

We translate one image however we choose (sliding it left, right, up, or down
any number of units), and place it on top of the other image.  After, the overlap
of this translation is the number of positions that have a 1 in both images.

(Note also that a translation does not include any kind of rotation.)

What is the largest possible overlap?
*/


class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int max_overlap = -1;
        int n = img1.size();
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < n; j++) {
                max_overlap = max(max_overlap, getOverLap(img1, img2, i, j, n));
            }
        }
        return max_overlap;
    }

    int getOverLap(vector<vector<int>>& img1, vector<vector<int>>& img2,
                    int x, int y, int n) {
        int count = 0;
        for (size_t i = x; i < n; i++) {
            for (size_t j = y; j < n; j++) {
                if ((img1[i-x][j-y] == 1) && (img1[i-x][j-y] == img2[i][j])) {
                    ++count;
                }
            }
        }
        return count;
    }
};
