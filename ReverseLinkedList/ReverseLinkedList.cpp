#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
   
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr != nullptr) {
        ListNode* temp = curr->next;
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


ListNode* reverseList(ListNode* head) {

    ListNode* prev = nullptr;
    ListNode* cur = head;

    while (cur) {
        ListNode* temp = head->next;


        cur->next = prev;

        prev = cur;
        cur = temp;
        
        
    }

    return prev;

}



int main()
{

}

//OPENGL SHIT

//MINIMUM:
//C++ 6-12 meses de experiencia
//math - algebra lineal. geormetria y trigonometria
//ingles - b2

//RECOMMEND / ALL ABOVE:
//algoritmos (leetcode), trees etc big o n
//math - limites, derivadas e integrales
