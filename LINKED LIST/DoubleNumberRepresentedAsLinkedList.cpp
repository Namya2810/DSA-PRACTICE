#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);

        ListNode* curr = head;
        int carry = 0;

        while (curr) {
            int val = curr->val * 2 + carry;
            curr->val = val % 10;
            carry = val / 10;

            if (!curr->next && carry) {
                curr->next = new ListNode(carry);
                carry = 0;
                break;
            }
            curr = curr->next;
        }

        return reverse(head);
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example: 9 -> 9 -> 9
    ListNode* head = new ListNode(9);
    head->next = new ListNode(9);
    head->next->next = new ListNode(9);

    Solution sol;
    ListNode* result = sol.doubleIt(head);

    printList(result);

    return 0;
}
