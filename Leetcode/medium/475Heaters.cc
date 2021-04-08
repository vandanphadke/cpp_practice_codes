/*
Winter is coming! During the contest, your first job is to design a standard
heater with a fixed warm radius to warm all the houses.

Every house can be warmed, as long as the house is within the heater's warm
radius range.

Given the positions of houses and heaters on a horizontal line, return the
minimum radius standard of heaters so that those heaters could cover all houses.

Notice that all the heaters follow your radius standard, and the warm radius
will the same.

Example 1:

Input: houses = [1,2,3], heaters = [2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the
radius 1 standard, then all the houses can be warmed.
Example 2:

Input: houses = [1,2,3,4], heaters = [1,4]
Output: 1
Explanation: The two heater was placed in the position 1 and 4. We need to use
radius 1 standard, then all the houses can be warmed.
Example 3:

Input: houses = [1,5], heaters = [2]
Output: 3
*/

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int maxDistance = -1, currentDistance = 0;
        for (size_t i = 0; i < houses.size(); i++) {
            currentDistance = abs(houses[i] - findClosestHeater(heaters, houses[i]));
            maxDistance = max(maxDistance, currentDistance);
        }
        return maxDistance;

    }

    int findClosestHeater(vector<int>& heaters, int house) {
        int n = heaters.size();
        if (house < heaters[0]) {
            return heaters[0];
        }
        if (house > heaters[n-1]) {
            return heaters[n-1];
        }

        int l = 0, r = heaters.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (house < heaters[mid]) {
                r = mid - 1;
            } else if (house > heaters[mid]) {
                l = mid + 1;
            } else {
                return heaters[mid];
            }
        }
        return (heaters[l] - house) < (house - heaters[r]) ? heaters[l] : heaters[r];
    }
};
