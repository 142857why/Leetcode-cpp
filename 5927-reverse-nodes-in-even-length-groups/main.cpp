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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        for (int i = 1; i < left; ++i) {
            prev = prev->next;
            head = head->next;
        }
        ListNode* curr = head;

        for (int i = left; i < right; ++i) {
            ListNode* tempNext = curr->next;
            curr->next = tempNext->next;
            tempNext->next = prev->next;
            prev->next = tempNext;
        }
        return dummy->next;
    }

    int lenListNode(ListNode* head) {
        int ans = 0;
        while (head) {
            head = head->next;
            ans++;
        }
        return ans;
    }

public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int len = lenListNode(head), n = len;
        if (len == 1 || len == 2) return head;
        int curr_partition = 1, left = 1;
        while (n > curr_partition) {
            n -= curr_partition;
            if (curr_partition % 2 == 0) {
                head = reverseBetween(head, left, left + curr_partition - 1);
            }
            left += curr_partition;
            curr_partition++;
        }
        curr_partition = len - left + 1;
        if (curr_partition % 2 == 0) {
            head = reverseBetween(head, left, left + curr_partition - 1);
        }
//        cout << "left = " << left << endl;
//        cout << "curr_partition = " << curr_partition << endl;
        return head;
    }
};

int main() {
    ListNode* head = createListNodeFromArray({5,2,6,3,9,1,7,3,8,4});
//    ListNode* head = createListNodeFromArray({0, 4, 2, 1, 3});
    auto* obj = new Solution();
    head = obj->reverseEvenLengthGroups(head);
    printLinkedList(head);
    delete obj;
    return 0;
}
