#include <iostream>

using namespace std;

struct Node {
	int val;
	Node* next;
	Node() : val(0), next(nullptr) {}
	Node(int x) : val(x), next(nullptr) {}
	Node(int x, Node* next) : val(x), next(next) {}
};


bool hasCycle(Node* head) {
 
	Node* slow = head;
	Node* fast = head;

	while (slow && fast)
	{
		slow = slow->next->next;
		fast = fast->next;

		if (fast == slow) {
			return true;
		}
	}

	return false;
}


int main()
{
    std::cout << "Hello World!\n";
}
