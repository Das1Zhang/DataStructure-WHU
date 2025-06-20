#include"HashMap.h"

struct Pair {
public:
	int key;
	string val;
	Pair(int key, string val) {
		this->key = key;
		this->val = val;
	}
};

class ArrayHashMap {
private:
	vector<Pair*> buckets;

public:
	// ��ʼ����100��bucket
	ArrayHashMap() {
		buckets = vector<Pair*>(100);
	}

	~ArrayHashMap() {
		for (const auto& bucket : buckets) {
			delete bucket;
		}
		buckets.clear();
	}

	int hashFunc(int key) {
		int index = key % 100;
		return index;
	}

	string get(int key) {
		int index = hashFunc(key);
		Pair* pair = buckets[index];
		if (pair == nullptr) {
			return "";
		}
		return pair->val;
	}

	void put(int key, string val) {
		Pair* pair = new Pair(key, val);
		int index = hashFunc(key);
		buckets[index] = pair;
	}

	void remove(int key) {
		int index = hashFunc(key);
		delete buckets[index];
		buckets[index] = NULL;
	}

	vector<Pair*> pairSet() {
		vector<Pair*> pairSet;
		for (Pair* pair : buckets) {
			if (pair != nullptr) {
				pairSet.push_back(pair);
			}
		}
	}

	vector<int> keySet() {
		vector<int> keySet;
		for (Pair* pair : buckets) {
			if (pair != nullptr) {
				keySet.push_back(pair->key);
			}
		}
	}

	vector<string> valueSet() {
		vector<string> valueSet;
		for (Pair* pair : buckets) {
			if (pair != nullptr) {
				valueSet.push_back(pair->val);
			}
		}
	}

	void print() {
		for (Pair* kv : pairSet()) {
			cout << kv->key << " -> " << kv->val << endl;
		}
	}

};

class HashMapChaining {
private:
	int size;
	int capacity;
	double loadThres;
	int extendRatio;
	vector<vector<Pair*>> buckets;
public:
	HashMapChaining() :size(0), capacity(4), loadThres(2.0 / 3.0), extendRatio(2) {
		buckets.resize(capacity);
	}

	~HashMapChaining() {
		for (auto& bucket : buckets) {
			for (Pair* pair : bucket) {
				delete pair;
			}
		}
	}

	int hashFunc(int key) {
		return key % capacity;
	}

	double loadFactor() {
		return (double)size / (double)capacity;
	}

	string get(int key) {
		int index = hashFunc(key);

		for (Pair* pair : buckets[index]) {
			if (pair->key = key) {
				return pair->val;
			}
			return "";
		}
	}

	void put(int key, string val) {
		if (loadFactor() > loadThres) {
			extend();
		}
		int index = hashFunc(key);
		for (Pair* pair : buckets[index]) {
			if (pair->key == key) {
				pair->val = val;
				return;
			}
		}
		buckets[index].push_back(new Pair(key, val));
		size++;
	}

	void remove(int key) {
		int index = hashFunc(key);
		auto& bucket = buckets[index];
		for (int i = 0; i < bucket.size();i++) {
			if (bucket[i]->key == key) {
				Pair* tmp = bucket[i];
				bucket.erase(bucket.begin() + i);
				delete tmp;
				size--;
				return;
			}
		}
	}

	void extend() {
		vector<vector<Pair*>> bucketTmp = buckets;
		capacity *= extendRatio;
		buckets.clear();
		buckets.resize(capacity);
		size = 0;
		for (auto& bucket : bucketTmp) {
			for (Pair* pair : bucket) {
				put(pair->key, pair->val);
				delete pair;
			}
		}
	}
};

class HashMapOpenAddressing {
private:
	int size;
	int capacity = 4;
	const double loadThres = 2.0 / 3.0;
	const int extendRatio = 2;
	vector<Pair*> buckets;
	Pair* TOMBSTONE = new Pair(-1, "-1");

public:
	HashMapOpenAddressing() :size(0), buckets(capacity, nullptr) {}

	~HashMapOpenAddressing() {
		for (Pair* pair : buckets) {
			if (pair != nullptr && pair != TOMBSTONE) {
				delete pair;
			}

		}
		delete TOMBSTONE;
	}

	int hashFunc(int key) {
		return key % capacity;
	}

	double loadFactor() {
		return (double)size / capacity;
	}

	int findBucket(int key) {
		int index = hashFunc(key);
		int firstTombstone = -1;

		while (buckets[index] != nullptr) {
			if (buckets[index]->key == key) {
				if (firstTombstone != -1) {
					buckets[firstTombstone] = buckets[index];
					buckets[index] = TOMBSTONE;
					return firstTombstone;
				}
				return index;
			}
			if (firstTombstone == -1 && buckets[index] == TOMBSTONE) {
				firstTombstone == index;
			}
			index = (index + 1) % capacity;
		}
		return firstTombstone == -1 ? index : firstTombstone;
	}

	string get(int key) {
		int index = findBucket(key);
		if (buckets[index] != nullptr && buckets[index] == TOMBSTONE) {
			return buckets[index]->val;
		}

		return "";
	}

	void put(int key, string val){
		if (loadFactor() > loadThres) {
			extend();
		}
		int index = findBucket(key);
		if (buckets[index] != nullptr && buckets[index] != TOMBSTONE) {
			buckets[index]->val = val;
			return;
		}
		buckets[index] = new Pair(key, val);
		size++;
	}

	void remove(int key) {
		int index = findBucket(key);
		if (buckets[index] != nullptr && buckets[index] != TOMBSTONE) {
			delete buckets[index];
			buckets[index] = TOMBSTONE;
			size--;
		}
	}

	void extend() {
		vector<Pair*>bucketsTmp = buckets;
		capacity *= extendRatio;
		buckets = vector<Pair*>(capacity, nullptr);
		size = 0;
		for (Pair* pair : bucketsTmp) {
			if (pair != nullptr && pair != TOMBSTONE) {
				put(pair->key, pair->val);
				delete pair;
			}
		}
	}

	void Disp() {
		for (Pair* pair : buckets) {
			if (pair == nullptr) {
				cout << "nullptr" << endl;
			}
			else if (pair == TOMBSTONE) {
				cout << "TOMBSTORE" << endl;
			}
			else {
				cout << pair->key << " -> " << pair->val << endl;
			}
		}
	}
};