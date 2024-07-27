#include <iostream>

using namespace std;

struct Node {
	int val;
	Node* next;
	Node() : val(0), next(nullptr) {}
	Node(int x) : val(x), next(nullptr) {}
	Node(int x, Node* next) : val(x), next(next) {}
};

Node* reverseList(Node* head) {
   
    Node* prev = nullptr;
    Node* curr = head;

    while (curr != nullptr) {
        Node* temp = curr->next;
        curr->next = prev;


        prev = curr;
        curr = temp;
    }

    return prev;

}

//[1,2,3,4,5,6,7]
// 
// node->null
// 
//temp -> 2...
//head (1->null)

//node = head (1->null)
//node->1->null






int main()
{

}


//C++ 6-12 meses de experiencia
//math - algebra lineal. geormetria y trigonometria
//ingles - b2


//algoritmos (leetcode), trees etc big o n
//math - limites, derivadas e integrales
