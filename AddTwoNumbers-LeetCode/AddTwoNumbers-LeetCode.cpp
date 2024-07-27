#include <iostream>
#include <algorithm>

// Definition for singly-linked list.
struct Node {
	int val;
	Node* next;
	Node() : val(0), next(nullptr) {}
	Node(int x) : val(x), next(nullptr) {}
	Node(int x, Node* next) : val(x), next(next) {}
};



class Solution {
public:
	Node* addTwoNumbers(Node* l1, Node* l2) {
	
		Node* dummyHead = new Node(0);
		Node* curr = dummyHead;
		int carry = 0;

		while (l1 != NULL || l2 != NULL || carry != 0) {

			int x = l1 ? l1->val : 0;
			int y = l2 ? l2->val : 0;

			int sum = carry + x + y; //2+5
			carry = sum / 10; //7 / 10

			curr->next = new Node(sum % 10);
			curr = curr->next;

			l1 = l1 ? l1->next : nullptr;
			l2 = l2 ? l2->next : nullptr;
		}

		Node* result = dummyHead->next;
		delete dummyHead; // Freeing the memory allocated for dummyHead
		return result;

	}

	//Solution() :
};

void iterar(Node* n) {
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
	Node l1(5, new Node(4, new Node(3))); //list: [2,4,3]
	Node l2(6, new Node(9, new Node(8))); //list: [5,6,4]


	Solution solution;
	Node* lw = solution.addTwoNumbers(&l1, &l2);

	//int a = 12 % 10;
	//std::cout << a;
	iterar(lw);
}

