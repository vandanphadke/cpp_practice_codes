/*
Implement the RandomizedSet class:

bool insert(int val) Inserts an item val into the set if not present.
Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the set if present. Returns true
if the item was present, false otherwise.
int getRandom() Returns a random element from the current set of elements
(it's guaranteed that at least one element exists when this method is called).
Each element must have the same probability of being returned.
Follow up: Could you implement the functions of the class with each function
works in average O(1) time?
*/

class RandomizedSet {

private:
    vector<int> elements;
    unordered_map<int, int> elementIndexMap;
public:

    /** Initialize your data structure here. */
    RandomizedSet() {}

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (elementIndexMap.find(val) != elementIndexMap.end()) {
            return false;
        }
        elements.push_back(val);
        elementIndexMap[val] = elements.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (elementIndexMap.find(val) == elementIndexMap.end()) {
            return false;
        }
        int last = elements.back();
        elementIndexMap[last] = elementIndexMap[val];
        elements[elementIndexMap[val]] = last;
        elements.pop_back();
        elementIndexMap.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return elements[(rand()%(elements.size()))];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
