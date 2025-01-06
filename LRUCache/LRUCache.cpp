#include <iostream>
#include <unordered_map>


using namespace std;

struct ListNode {
	int val;
	int key;

	ListNode* next;
	ListNode* prev;
	ListNode() : val(0), next(nullptr), prev(nullptr) {}
	ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next), prev(nullptr) {}
	ListNode(int x, ListNode* next, ListNode* prev) : val(x), next(next), prev(prev) {}
};


class LRUCache {
private:
	unordered_map<int, ListNode*> mp;
	ListNode* start = new ListNode();
	ListNode* head = start;

	int capacity;

public:
	LRUCache(int _capacity) {
		capacity = _capacity;
	}

	int get(int key) {

		if (mp.find(key) != mp.end()) {

			if (start->next->next && mp[key] != head) {

				mp[key]->prev->next = mp[key]->next;
                mp[key]->next->prev = mp[key]->prev;

				head->next = mp[key];
				mp[key]->prev = head;

				head = head->next;
			}

			return mp[key]->val;
		}

		return -1;
	}

	void put(int key, int value) {

		//erase the first node if there's no space and if its a new key value
		if (mp.find(key) == mp.end() && mp.size() >= capacity) {

			mp.erase(start->next->key);

			ListNode* temp = start->next;

			if (start->next->next) {

				start->next = start->next->next;
				start->next->prev = start;
			}
			else {
				start->next = nullptr;
				head = start;
			}

			delete temp;
		}

		//create the new node
		if (mp.find(key) == mp.end()) {
			ListNode* temp = head;

			head->next = new ListNode(value, nullptr, temp);
			head = head->next;
			head->key = key;

			mp[key] = head;
		}	
		else {
			//if the key value already exists, 
			//put the node at the end and change it the value
			if (start->next->next && mp[key] != head) {

				mp[key]->prev->next = mp[key]->next;
                mp[key]->next->prev = mp[key]->prev;

				head->next = mp[key];
				mp[key]->prev = head;
				head = head->next;

				head->val = value;

			}
			mp[key]->val = value;

		}

	}

};




//ANOTHER SOLUTION I THINK THIS IS BETTER THAN MINE

struct Node {
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int key = -1, int val = -1) : key(key), val(val), next(nullptr), prev(nullptr) {}
};

class LRUCache {
private:
    int cap;
    int size;
    unordered_map<int, Node*> map;
    Node* head, *tail;
public:
    LRUCache(int capacity) : cap(capacity), size(0) {
        head = new Node(-1);
        tail = new Node(-1);
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache() {
        while (head) {
            Node* nxt = head->next;
            delete head;
            head = nxt;
        }
    }

    void insert_front(Node* node) {
        node->next = head->next;
        head->next = node;
        node->prev = head;
        node->next->prev = node;
        size++;
    }

    void remove_node(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }

    int get(int key) {
        if (map[key] == nullptr) {
            return -1;
        }

        Node* node = map[key];
        remove_node(node);
        insert_front(node);

        return node->val;
    }

    void put(int key, int value) {

        if (map[key] != nullptr) {

            Node* node = map[key];
            node->val = value;

            remove_node(node);
            insert_front(node);
        }
        else {
            Node* node = new Node(key, value);

            if (size == cap) {

                Node* tmp = tail->prev;
                map[tmp->key] = nullptr;
                
				remove_node(tmp);
                delete tmp;
            }

            insert_front(node);
            map[key] = node;
        }
    }
};


int main()
{
	std::cout << "Hello World!\n";
}

