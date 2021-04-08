/*
Given an array of points where points[i] = [xi, yi] represents a point on
the X-Y plane, return the maximum number of points that lie on the same
straight line.

Example 1:
Input: points = [[1,1],[2,2],[3,3]]
Output: 3
Example 2:

Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
*/

class Line {
private:
    int _m1;
    int _m2;
    int _c1;
    int _c2;

    int gcd(int a, int b){
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

public:
    Line(int m1, int m2, int c1, int c2) : _m1(m1), _m2(m2), _c1(c1), _c2(c2) {
        int numsGcd = gcd(m1, m2);
        _m1 = m1 / numsGcd;
        _m2 = m2 / numsGcd;
        _c1  = c1;
	_c2  = c2;
    }
}


class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        unordered_map<Line, unordered_set<int>> linePoints;
	int max = -1;
        for (size_t i = 0; i < points.size(); i++) {
            for (size_t j = i+1; j < points.size(); j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
		int m1 = y2 - y1;
		int m2 = x2 - x1;
		int c1 = m2*y2 - m1*x2;
		Line* newline = new Line(m1, m2, c1, m2);
		linePoints[newLine].emplace(i);
		linePoints[newLine].emplace(j);
            }
        }

	for(auto& it: linePoints) {
	    if(it.second.size() > max) {
	        max = it.second.size();
	    }
	}

	return max;
    }
};
