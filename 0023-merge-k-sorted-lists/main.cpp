#include <iostream>
#include <vector>
#include <queue>

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode *tail = &dummy;
        auto comp = [](ListNode* a, ListNode* b) {return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> q(comp);
        for (ListNode* list : lists) {
            if (list) q.push(list);
        }
        while (!q.empty()) {
            tail->next = q.top(); q.pop();
            tail = tail->next;
            if (tail->next) q.push(tail->next);
        }
        return dummy.next;
    }
};
int main() {
    vector<vector<int>> arr{
            {1, 4, 5},
            {1, 3, 4},
            {2, 6},
    };
    vector<ListNode*> lists;
    for (const auto &a : arr) {
        lists.emplace_back(createListNodeFromArray(a));
    }
    Solution *obj = new Solution();
    ListNode* newHead = obj->mergeKLists(lists);
    printLinkedList(newHead);
    delete obj;
    return 0;
}
