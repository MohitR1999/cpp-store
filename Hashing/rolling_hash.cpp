#include<bits/stdc++.h>
using namespace std;

class HashNode {
public:
	string key;
	int data;
	HashNode* next;

	HashNode(string k, int d) {
		key = k;
		data = d;
		next = NULL;
	}
};

class HashTable {
public:
	vector<HashNode*> buckets;
	int currentSize, tableSize;

	HashTable(int s = 7) {
		tableSize = s;
		currentSize = 0;
		buckets.resize(tableSize, NULL);
	}

	int compute_hash(string s) {
		int p = 31;
		int hash_code = 0;
		int p_pow = 1;
		for (int i = 0; i < s.size(); i++) {
			hash_code = ( hash_code + (s[i] - 'a' + 1) * p_pow) % tableSize;
			p_pow = (p_pow * p) % tableSize;
		}
		return hash_code % tableSize;
	}

	void rehash() {
		int old_table_size = tableSize;
		vector<HashNode*> oldBuckets = buckets;
		currentSize = 0;
		tableSize *= 2;
		buckets.resize(tableSize, NULL);

		for (int i = 0; i < old_table_size; i++) {
			HashNode* hd = oldBuckets[i];
			while (hd != NULL) {
				insert(hd->key, hd->data);
				hd = hd->next;
			}
			delete oldBuckets[i];
		}
		oldBuckets.clear();
	}
	void insert(string s, int d) {
		int hash_code = compute_hash(s);
		HashNode * new_node = new HashNode(s, d);
		new_node->next = buckets[hash_code];
		buckets[hash_code] = new_node;
		currentSize++;
		float ff = (float)currentSize / tableSize;;
		if (ff > 0.7) {
			cout << "Rehashing" << endl;
			rehash();
		}
	}
	int search(string s) {
		int hash_code = compute_hash(s);
		HashNode* t = buckets[hash_code];
		while (t != NULL) {
			if (t->key == s) return (t->data);
			t = t->next;
		}
		return -1;
	}

};


int main() {

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif


	HashTable ht;
	ht.insert("Rajesh", 1234);
	ht.insert("Ravi", 2345);
	ht.insert("Ramesh", 3456);
	ht.insert("Mahesh", 5678);
	ht.insert("Sursh", 8901);
	ht.insert("Raesh", 1234);

	int ans = ht.search("Ravi");
	if (ans == -1) {
		cout << "NOT FOUND" << " ";
	}
	else {
		cout << "FOUND " << ans << " ";
	}
	cout << endl;

	ans = ht.search("ravi");
	if (ans == -1) {
		cout << "NOT FOUND" << " ";
	}
	else {
		cout << "FOUND" << ans << " ";
	}
	cout << endl;


	return 0;
}
