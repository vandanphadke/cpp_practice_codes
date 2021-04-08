/*
Design a stack-like data structure to push elements to the
stack and pop the most frequent element from the stack.

Implement the FreqStack class:

FreqStack() constructs an empty frequency stack.
void push(int val) pushes an integer val onto the top of the stack.
int pop() removes and returns the most frequent element in the stack.
If there is a tie for the most frequent element, the element closest
to the stack's top is removed and returned.


Example 1:

Input
["FreqStack", "push", "push", "push", "push", "push", "push", "pop",
"pop", "pop", "pop"]
[[], [5], [7], [5], [7], [4], [5], [], [], [], []]
Output
[null, null, null, null, null, null, null, 5, 7, 5, 4]

Explanation
FreqStack freqStack = new FreqStack();
freqStack.push(5); // The stack is [5]
freqStack.push(7); // The stack is [5,7]
freqStack.push(5); // The stack is [5,7,5]
freqStack.push(7); // The stack is [5,7,5,7]
freqStack.push(4); // The stack is [5,7,5,7,4]
freqStack.push(5); // The stack is [5,7,5,7,4,5]
freqStack.pop();   // return 5, as 5 is the most frequent. The stack
becomes [5,7,5,7,4].
freqStack.pop();   // return 7, as 5 and 7 is the most frequent, but 7 is
closest to the top. The stack becomes [5,7,5,4].
freqStack.pop();   // return 5, as 5 is the most frequent. The stack
becomes [5,7,4].
freqStack.pop();   // return 4, as 4, 5 and 7 is the most frequent,
but 4 is closest to the top. The stack becomes [5,7].
*/

/* ATTEMPT I - TLE */
class FreqStack {
private:
    map<int, unordered_set<int>> freqElementMap;
    unordered_map<int, int> elementFreqMap;
    stack<int> elementsStack;

    void printMap() {
        cout << "+++++++" << endl;
        for(auto& it: elementFreqMap) {
            cout << it.first << "  " << it.second << endl;
        }
    }

public:
    FreqStack() {

    }

    void push(int val) {
        elementsStack.push(val);
        if(elementFreqMap.find(val) == elementFreqMap.end()) {
            elementFreqMap[val] = 1;
            freqElementMap[1].emplace(val);
        } else {
            int oldFreq = elementFreqMap[val];
            elementFreqMap[val] = oldFreq + 1;
            freqElementMap[oldFreq].erase(val);
            freqElementMap[oldFreq+1].emplace(val);
        }
    }

    int pop() {
        int maxFreq = freqElementMap.rbegin()->first;
        unordered_set<int> tempSet = freqElementMap.rbegin()->second;
        stack<int> tempStack;
        int top = 0;
        while(!elementsStack.empty()){
            top = elementsStack.top();
            elementsStack.pop();
            if(tempSet.count(top) == 0) {
                tempStack.push(top);
            } else {
                elementFreqMap[top] = maxFreq - 1;
                if(tempSet.size() == 1) {
                    freqElementMap.erase(maxFreq);
                } else {
                    freqElementMap[maxFreq].erase(top);
                }

                freqElementMap[maxFreq-1].emplace(top);
                break;
            }
        }
        while(!tempStack.empty()){
            int top1 = tempStack.top();
            tempStack.pop();
            elementsStack.push(top1);
        }
        return top;
    }
};


/* ATTEMPT II - Final Submission */
class FreqStack {
private:
    map<int, vector<int>> freqElementMap;
    unordered_map<int, int> elementFreqMap;

    void printMap() {
        cout << "+++++++" << endl;
        for(auto& it: elementFreqMap) {
            cout << it.first << "  " << it.second << endl;
        }
    }

public:
    FreqStack() {

    }

    void push(int val) {
        if(elementFreqMap.find(val) == elementFreqMap.end()) {
            elementFreqMap[val] = 1;
            freqElementMap[1].emplace_back(val);
        } else {
            int oldFreq = elementFreqMap[val];
            elementFreqMap[val] = oldFreq + 1;
            freqElementMap[oldFreq+1].emplace_back(val);
        }
    }

    int pop() {
        int maxFreq = freqElementMap.rbegin()->first;
        vector<int>& tempVec = freqElementMap.rbegin()->second;
        int element = tempVec.back();
        elementFreqMap[element] = maxFreq - 1;

        if(tempVec.size() == 1) {
            freqElementMap.erase(maxFreq);
        } else {
            freqElementMap[maxFreq].pop_back();
        }
        return element;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
