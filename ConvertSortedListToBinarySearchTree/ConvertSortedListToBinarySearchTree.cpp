#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* sortedListToBST(ListNode* head) {

    if (!head) return nullptr;
    if (!head->next) return new TreeNode(head->val);

    ListNode* temp = nullptr;
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next)
    {
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;

    }
    temp->next = nullptr;

    TreeNode* node = new TreeNode(slow->val);

    node->left = sortedListToBST(head);
    node->right = sortedListToBST(slow->next);

    return node;
}


int main()
{


}
