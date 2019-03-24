#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct spisok {
	spisok *next, *prev;
	int key;
	spisok(int a) :key(a), next(NULL), prev(NULL) {}
};
class Deque {
public:
	void push_back(int a);
	int pop_back();
	void push_front(int a);
	int pop_front();
	Deque() :size(0) {
		head = new spisok(0);
		tail = new spisok(0);
	}
	~Deque() {
		while (head != NULL) {
			spisok *x = head;
			head = head->next;
			delete x;
		}
	}
private:
	spisok *head, *tail;
	int size;
};
void Deque::push_back(int a) {
	spisok *temp = new spisok(a);
	if (size!=0) {
		tail->next = temp;
		temp->prev = tail;
		tail = tail->next;
	}
	else
		head = tail = temp;
	size++;
}
void Deque::push_front(int a) {
	spisok *temp = new spisok(a);
	if (size!=0) {
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	else
		head = tail = temp;
	size++;
}
int Deque::pop_back() {
	if (size==0)
		return -1;
	int x = tail->key;
	spisok *temp = tail;
	if (size==1)
		head = tail = NULL;
	else
		tail = tail->prev;
	delete temp;
	size--;
	return x;
}
int Deque::pop_front() {
	if (size==0)
		return -1;
	int x = head->key;
	spisok *temp = head;
	head = head->next;
	delete temp;
	size--;
	return x;
}

int main() {
	int n;
	cin >> n;
	int a, b, i;
	Deque d;
	for (i = 0; i < n; i++) {
		cin >> a >> b;
		if (a == 1)
			d.push_front(b);
		if (a == 2) {
			if (d.pop_front() == b)
				true;
			else
				i = n;
		}
		if (a == 3)
			d.push_back(b);
		if (a == 4) {
			if (d.pop_back() == b)
				true;
			else
				i = n;
		}
	}
	if (i != n)
		cout << "NO";
	else
		cout << "YES";
	return 0;
}
