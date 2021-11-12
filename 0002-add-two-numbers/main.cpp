#include <iostream>
#include <vector>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* createListNodeFromArray(const vector<int>& arr) {
    ListNode* tail = new ListNode(arr[0]);
    ListNode* head = tail;
    for (unsigned int i = 1; i < arr.size(); ++i) {
        tail->next = new ListNode(arr[i]);
        tail = tail->next;
    }
    return head;
}

void printLinkedList(ListNode* head) {
    while (head) {
        if (head->next) cout << head->val << "->"; else cout << head->val << endl;
        head = head->next;
    }
}

class Solution {
private:
    void restSum(ListNode* node, ListNode*& head, int& carry) {
        while (node) {
            int tempSum = node->val + carry;
            carry = tempSum / 10;
            tempSum = tempSum % 10;
            head->next = new ListNode(tempSum);
            head = head->next;
            node = node->next;
        }
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0), *head = dummy;
        int carry = 0;
        while (l1 && l2) {
            int tempSum = l1->val + l2->val + carry;
            carry = tempSum / 10;
            tempSum = tempSum % 10;
            head->next = new ListNode(tempSum);
            head = head->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        restSum(l1, head, carry);
        restSum(l2, head, carry);
        if (carry) {
            head->next = new ListNode(carry);
        }
        return dummy->next;
    }
};


int main() {
    ListNode* l1 = createListNodeFromArray({2, 4, 3});
    ListNode* l2 = createListNodeFromArray({5, 6, 4});
    Solution* obj = new Solution();
    ListNode* sum = obj->addTwoNumbers(l1, l2);
    printLinkedList(sum);
    delete obj;
    return 0;
}
