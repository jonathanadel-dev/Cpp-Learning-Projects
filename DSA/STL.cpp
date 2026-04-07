#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <concurrent_priority_queue.h>
#include <set>
#include <unordered_set>
#include <map>
using namespace std;

// Pairs
void pairs(){

	pair<int, int> p;
	p = { 1, 2 };
	cout << p.first << endl;

	pair<int, char> p2;
	p2 = { 1, 'a' };
	cout << p2.second;


}


// Vectors
void vectors() {

	// Creating vectors
	vector<int> v;
	v.push_back(1);
	v.emplace_back(2);
	v.clear();

	// Adding elements
	vector<pair<int, int>> v1{ {1, 2}, {3, 4} };
	vector<int> v2( 5, 20 );
	vector<int> v3;
	v3.push_back(7);
	v3.push_back(8);
	v3.push_back(9);
	cout << v3.back() << endl;

	// Accessing with a pointer and the auto keyword
	auto p = v3.begin();
	cout << *(p) << endl;
	auto x = 5;
	cout << x << endl;

	// Iterating
	for (vector<int>::iterator i = v3.begin(); i != v3.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;
	for (auto i : v3) {
		cout << i << " ";
	}
	cout << endl;

	// Erasing
	vector<int> v4{1, 2, 3, 4, 5, 6, 7, 8};
	vector<int>::reverse_iterator i4 = v4.rbegin();
	v4.erase(v4.begin() + 1);
	v4.erase(v4.begin(), v4.begin() + 2);
	for (int i : v4) {
		cout << i << " ";
	}
	cout << endl;

	// Inseting
	vector<int> v5{ 1, 2, 3, 4, 5, 6, 7, 8 };
	v5.insert(v5.begin() + v5.size(), 9);
	v5.insert(v5.begin(), 3, 10);
	v5.insert(v5.begin() + v5.size(), v3.begin(), v3.end());
	v5.pop_back();
	for (int i : v5) {
		cout << i << " ";
	}
	cout << endl;
	cout << v5.empty() << endl;
	v5.clear();

}


// Lists
void lists() {
	list<int> l{ 1, 2, 3, 4 };
	l.push_back(5);
	l.emplace_front(0);
	list<int>::iterator i = l.begin();
	cout << *i << endl;
	for (int i : l) {
		cout << i << " ";
	}
}


// Deques
void deques() {

	// Same as vectors and lists

}


// Stacks
void stacks() {

	// LIFO -> Last in first out

	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	s.pop();
	cout << s.top() << endl;

	stack<int> s1, s2;
	s1 = s;

	s1.swap(s2);

	cout << s2.top();

}


// Queues
void queues() {

	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.pop();
	cout << q.front() << endl;
	cout << q.back() << endl;

}


// Priority Queues
void pqs() {

	// Greater first queue
	priority_queue<int> pq;
	pq.emplace(1);
	pq.emplace(5);
	pq.emplace(2);

	pq.pop();
	cout << pq.top() << endl;


	// Smaller first queue
	priority_queue<int, vector<int>, greater<int>> spq;
	spq.emplace(1);
	spq.emplace(5);
	spq.emplace(2);

	spq.pop();
	cout << spq.top();
}


// Sets
void sets() {

	// Store unique numbers in order
	set<int> s;
	s.emplace(1);
	s.emplace(2);
	s.emplace(1);
	s.insert(4);
	s.emplace(3);
	auto id = s.find(1);
	s.erase(4);
	cout << s.count(20) << endl; // 1 if 2 exists, 0 if not
	auto i2 = s.find(2);
	auto i4 = s.find(3);
	s.erase(i2, i4);

}


// Multi sets
void multisets() {

	// Ordered but not unique
	multiset<int> ms;
	ms.insert(1);
	ms.insert(1);
	ms.insert(1);
	cout << ms.count(1) << endl;
	ms.erase(1);
	cout << ms.count(1) << endl;

}


// Unordered sets
void unorderedSets() {


	// Unordered but unique
	unordered_set<int> us;

}


// Maps
void maps() {

	// Stores unique keys in sorted order
	map<int, int> m;
	m[1] = 10;
	m.insert({ 4, 20 });
	m.emplace(3, 30);

	cout << m[3];

}


// Multimaps
void multimaps() {
	// Ordered duplicate keys
}


// Unordered maps
void unorderedmaps() {
	// Unordered duplicate keys
}