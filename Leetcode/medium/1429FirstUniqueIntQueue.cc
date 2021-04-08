/*
You have a queue of integers, you need to retrieve the first unique integer in the queue.

Implement the FirstUnique class:

FirstUnique(int[] nums) Initializes the object with the numbers in the queue.
int showFirstUnique() returns the value of the first unique integer of the queue,
and returns -1 if there is no such integer.
void add(int value) insert value to the queue.


Example 1:

Input:
["FirstUnique","showFirstUnique","add","showFirstUnique","add","showFirstUnique","add","showFirstUnique"]
[[[2,3,5]],[],[5],[],[2],[],[3],[]]
Output:
[null,2,null,2,null,3,null,-1]
Explanation:
FirstUnique firstUnique = new FirstUnique([2,3,5]);
firstUnique.showFirstUnique(); // return 2
firstUnique.add(5);            // the queue is now [2,3,5,5]
firstUnique.showFirstUnique(); // return 2
firstUnique.add(2);            // the queue is now [2,3,5,5,2]
firstUnique.showFirstUnique(); // return 3
firstUnique.add(3);            // the queue is now [2,3,5,5,2,3]
firstUnique.showFirstUnique(); // return -1
Example 2:

Input:
["FirstUnique","showFirstUnique","add","add","add","add","add","showFirstUnique"]
[[[7,7,7,7,7,7]],[],[7],[3],[3],[7],[17],[]]
Output:
[null,-1,null,null,null,null,null,17]
Explanation:
FirstUnique firstUnique = new FirstUnique([7,7,7,7,7,7]);
firstUnique.showFirstUnique(); // return -1
firstUnique.add(7);            // the queue is now [7,7,7,7,7,7,7]
firstUnique.add(3);            // the queue is now [7,7,7,7,7,7,7,3]
firstUnique.add(3);            // the queue is now [7,7,7,7,7,7,7,3,3]
firstUnique.add(7);            // the queue is now [7,7,7,7,7,7,7,3,3,7]
firstUnique.add(17);           // the queue is now [7,7,7,7,7,7,7,3,3,7,17]
firstUnique.showFirstUnique(); // return 17
Example 3:

Input:
["FirstUnique","showFirstUnique","add","showFirstUnique"]
[[[809]],[],[809],[]]
Output:
[null,809,null,-1]
Explanation:
FirstUnique firstUnique = new FirstUnique([809]);
firstUnique.showFirstUnique(); // return 809
firstUnique.add(809);          // the queue is now [809,809]
firstUnique.showFirstUnique(); // return -1
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode() : val(0), next(nullptr), prev(nullptr) {}
    ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
};

class FirstUnique {
    ListNode* head;
    ListNode* tail;
    unordered_map<int, ListNode*> numNodeMap;

public:
    FirstUnique(vector<int>& nums) {
        if(nums.empty()) return;
        ListNode* current = new ListNode(nums[0]);
        numNodeMap.emplace(nums[0], current);
        head = current;
        tail = head;
        for (size_t i = 1; i < nums.size(); i++) {
            ListNode* newNode = new ListNode(nums[i]);
            tail->next = newNode;
            newNode->prev = tail;
            tail = tail->next;
            numNodeMap.emplace(nums[i], newNode);
        }
    }

    int showFirstUnique() {
        if (!head) {
            return -1;
        }
        return head->val;
    }

    void add(int value) {
        if (numNodeMap.find(value) == numNodeMap.end()) {
            ListNode* newNode = new ListNode(value);
            tail->next = newNode;
            newNode->prev = tail;
            tail = tail->next;
            numNodeMap.emplace(value, newNode);
        } else {
            ListNode* current = numNodeMap[value];
            if (current == head) {
                ListNode* next = head->next;
                head->next = nullptr;
                if (next) {
                    next->prev = nullptr;
                }
                head = next;
            } else if (current == tail) {
                ListNode* prev = tail->prev;
                tail->prev = nullptr;
                if (prev) {
                    prev->next = nullptr;
                }
                tail = prev;
            } else {
                ListNode* next = current->next;
                ListNode* prev = current->prev;
                if (prev) {
                    prev->next = next;
                }
                if (next) {
                    next->prev = prev;
                }
            }
            numNodeMap.erase(value);
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
