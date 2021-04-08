/*
Design a data structure that supports all following operations in average O(1) time.

Note: Duplicate elements are allowed.
insert(val): Inserts an item val to the collection.
remove(val): Removes an item val from the collection if present.
getRandom: Returns a random element from current collection of elements. The
probability of each element being returned is linearly related to the number
of same value the collection contains.
*/

class RandomizedCollection {

private:
    vector<int> elements;
    unordered_map<int, vector<int>> elementIndexMap;

    void printElements() {
        cout << "Array " ;
        for(int i = 0; i < elements.size(); ++i)
            cout << elements[i] << "  ";
        cout << endl;
    }

public:

    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool found = false;
        if (elementIndexMap.find(val) == elementIndexMap.end()) {
            vector<int> temp;
            elementIndexMap[val] = temp;
            found = true;
        }
        elements.push_back(val);
        elementIndexMap[val].push_back(elements.size() - 1);
        printElements();
        return found;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (elementIndexMap.find(val) == elementIndexMap.end()) {
            return false;
        }
        int last = elements.back();
        vector<int> indexesLast = elementIndexMap[last];
        std::remove(indexesLast.begin(), indexesLast.end(), elements.size() - 1);
        vector<int> indexesVal = elementIndexMap[val];
        int valIndex = indexesVal.back(); 
        indexesVal.pop_back();
        indexesLast.push_back(valIndex);
        elements[valIndex] = last;
        elements.pop_back();
        printElements();
        cout << last << "  " << valIndex << endl;
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return elements[(rand()%(elements.size()))];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
