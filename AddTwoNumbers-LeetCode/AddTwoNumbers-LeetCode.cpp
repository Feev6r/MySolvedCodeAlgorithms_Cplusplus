#include <iostream>
#include <algorithm>

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};



class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	
		ListNode* dummyHead = new ListNode(0);
		ListNode* curr = dummyHead;
		int carry = 0;

		while (l1 != NULL || l2 != NULL || carry != 0) {

			int x = l1 ? l1->val : 0;
			int y = l2 ? l2->val : 0;

			int sum = carry + x + y; //2+5
			carry = sum / 10; //7 / 10

			curr->next = new ListNode(sum % 10);
			curr = curr->next;

			l1 = l1 ? l1->next : nullptr;
			l2 = l2 ? l2->next : nullptr;
		}

		ListNode* result = dummyHead->next;
		delete dummyHead; // Freeing the memory allocated for dummyHead
		return result;

	}

	//Solution() :
};

void iterar(ListNode* n) {
	while (n != NULL)
	{
		std::cout << n->val << std::endl;
		n = n->next;

	}
}

// Función de utilidad para imprimir el contenido de una array
void print(int arr[], int n)
{
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
}

// Función de utilidad para invertir elementos de una array
void reverse(int arr[], int n)
{
	int temp;
	for (int low = 0, high = n - 1; low < high; low++, high--) {

		temp = arr[low];
		arr[low] = arr[high];
		arr[high] = temp;

		//std::swap(arr[low], arr[high]);
	}
}



int main()
{
	//int arr[] = { 1, 4, 65, 23, 133 };
	//int n = sizeof(arr) / sizeof(arr[0]);

	//reverse(arr, n);
	//print(arr, n);
	ListNode l1(5, new ListNode(4, new ListNode(3))); //list: [2,4,3]
	ListNode l2(6, new ListNode(9, new ListNode(8))); //list: [5,6,4]


	Solution solution;
	ListNode* lw = solution.addTwoNumbers(&l1, &l2);

	//int a = 12 % 10;
	//std::cout << a;
	iterar(lw);
}

