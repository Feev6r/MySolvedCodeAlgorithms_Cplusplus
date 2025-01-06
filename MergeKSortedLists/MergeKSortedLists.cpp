#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {

	if (lists.empty()) return nullptr;
	if (lists.size() == 1) return lists[0];

	ListNode* l1 = lists[0];

	for (int i = 1; i < lists.size(); i++)
	{
		ListNode* cur = new ListNode();
		ListNode* dummy = cur;

		ListNode* l2 = lists[i];

		while (l1 && l2)
		{
			if (l1->val <= l2->val) {
				
				cur->next = l1;
				l1 = l1->next;

			}
			else {
				cur->next = l2;
				l2 = l2->next;
			}

			cur = cur->next;
		}

		if (l1) {
			cur->next = l1;
			l1 = l1->next;
		}
		if (l2) {
			cur->next = l2;
			l2 = l2->next;
		}

		l1 = dummy->next;
	}

	return l1;

}


struct Compare {
	bool operator()(ListNode* a, ListNode* b) {
		return a->val > b->val;  // Para que la cola ordene de menor a mayor
	}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		// Crear priority queue que ordena por valor menor
		priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

		// Insertar el primer nodo de cada lista
		for (ListNode* list : lists) {
			if (list) pq.push(list);
		}

		// Nodo dummy para construir la nueva lista
		ListNode dummy(0);
		ListNode* tail = &dummy;

		// Mientras haya elementos en la priority queue
		while (!pq.empty()) {

			// Obtener el nodo con el valor más pequeño
			ListNode* current = pq.top();
			pq.pop();

			// Añadir a la lista resultado
			tail->next = current;
			tail = tail->next;

			// Si hay más nodos en esta lista, añadir el siguiente
			if (current->next) {
				pq.push(current->next);
			}
		}

		return dummy.next;
	}
};



ListNode* mergeKLists(vector<ListNode*>& lists) {
	// Crear priority queue que ordena por valor menor
	priority_queue<ListNode*, vector<ListNode*>, Compare> pq;


	ListNode dummy(0);
	ListNode* tail = &dummy;

	for (ListNode* list : lists) {
		if (list) pq.push(list);
	}

	while (!pq.empty())
	{

		ListNode* cur = pq.top();
		pq.pop();

		tail->next = cur;
		tail = tail->next;


		if (cur->next) {
			pq.push(cur->next);
		}

	}

	return dummy.next;
}


int main()
{
    std::cout << "Hello World!\n";
}
