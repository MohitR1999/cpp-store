#include<bits/stdc++.h>
using namespace std;
class Node {
public:
	int key, val;
	Node *next, *prev;
	Node(int key, int val) {
		this->key = key;
		this->val = val;
		this->next = NULL;
		this->prev = NULL;
	}
};

Node *startq, *endq;
int sizeq = 0;
class LRUCache {
public:
	unordered_map<int, Node*> hash;
	int cap;
	LRUCache(int capacity) {
		hash.clear();
		startq = new Node(0, 0);
		endq = new Node(0, 0);
		startq->next = endq;
		startq->prev = NULL;
		endq->prev = startq;
		endq->next = NULL;
		this->cap = capacity;
		sizeq = 0;
	}

	int get(int key) {
		int ans = -1;
		if (hash.find(key) != hash.end())
		{
			int value = hash[key]->val;
			erase(hash[key]);
			Node* cur = add(key, value);
			hash[key] = cur;
			ans = value;
		}

		return ans;
	}

	void put(int key, int value) {
		if (hash.find(key) != hash.end())
		{
			Node* it = hash[key];
			erase(it);
			Node *cur = add(key, value);
			hash[key] = cur;
		}
		else
		{
			if (sizeq == this->cap)
			{
				int key = endq->prev->key;
				erase(hash[key]);
				hash.erase(key);
			}
			Node* cur = add(key, value);
			hash[key] = cur;
			sizeq = min(sizeq + 1, this->cap);
		}
	}

	void erase(Node *it) {
		Node *prev = it->prev;
		Node *next = it->next;
		delete(it);
		prev->next = next;
		next->prev = prev;
	}

	Node* add(int key, int val) {
		Node *newNode = new Node(key, val);
		Node *next = startq->next;
		newNode->next = next;
		newNode->prev = startq;
		next->prev = newNode;
		startq->next = newNode;
		return newNode;
	}
};

int main() {
	cout << "Program to implement LRU cache" << endl;
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	LRUCache a(n);
	a.put(1, 1);
	a.put(2, 3);
	a.put(3, 2);
	a.put(1, 2);
	a.get(2);
	a.get(4);
	a.get(3);

	return 0;
}
