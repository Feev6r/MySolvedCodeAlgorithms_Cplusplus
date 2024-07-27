#include <iostream>


using namespace std;

//Definition for singly-linked list.
struct Node {
	int val;
	Node* next;
	Node() : val(0), next(nullptr) {}
	Node(int x) : val(x), next(nullptr) {}
	Node(int x, Node* next) : val(x), next(next) {}
};

//Example
struct s {
	int v1;
	int v2;

	s() : v1(0), v2(1) {}
	s(int x) : v1(x), v2(1) {}
	s(int x, int y) : v1(x), v2(y) {}
};

//My Solution (at least i was be able to learning even if the code is a little mess up)
Node* removeNthFromEnd(Node* head, int n) {

	int i = 0;

	Node* temp = head;

	while (temp != NULL) {
		i++;
		temp = temp->next;
	}

	if (n == i) return head->next;

	temp = head;
	i = i - n;

	while (i > 1)
	{
		i--;
		temp = temp->next;
	}

	if (temp->next == NULL)	return head = NULL;

	temp->next = temp->next->next;
	return head;

}


//Clean Solution
Node* removeNthFromEnd2(Node* head, int n) {
	Node* res = new Node(0, head);
	Node* dummy = res;

	for (int i = 0; i < n; i++) {
		head = head->next;
	}

	while (head != nullptr) {
		head = head->next;
		dummy = dummy->next;
	}
	//200IQ this solution lol!!!

	dummy->next = dummy->next->next;

	return res->next;
}


int main()
{
	Node(1, new Node(2, new Node(3, new Node(4))));
}

