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
public:

    int lenList(ListNode* head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode* sortList(ListNode* head) {
        if (!head) return nullptr;
        int length = lenList(head);
        ListNode* dummy = new ListNode(0, head);
        for (int subLength = 1; subLength < length; subLength <<= 1) {
            ListNode* prev = dummy, *curr =dummy->next;
            while (curr) {
                ListNode* head1 = curr;
                for (int i = 1; i < subLength && curr->next; ++i) {
                    curr = curr->next;
                }
                ListNode* head2 = curr->next;
                curr->next = nullptr;
                curr = head2;
                for (int i = 1; i < subLength && curr && curr->next; ++i) {
                    curr = curr->next;
                }
                ListNode* next = curr ? curr->next : nullptr;
                if (curr) curr->next = nullptr;

                ListNode* merged = merge(head1, head2);
                prev->next = merged;
                while (prev->next) {
                    prev = prev->next;
                }
                curr = next;
            }
        }
        return dummy->next;
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0), *node = dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                node->next = l1;
                l1 = l1->next;
            } else {
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }
        node->next = l1 ? l1 : l2;
        return dummy->next;
    }
};

int main() {
    Solution* obj = new Solution();
    ListNode* head = createListNodeFromArray({-1, 5, 3, 4, 0});
    printLinkedList(head);
    ListNode* newHead = obj->sortList(head);
    printLinkedList(newHead);
    delete obj;
    return 0;
}
