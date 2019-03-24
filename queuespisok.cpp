#include<iostream>
using namespace std;
struct spisok {
	spisok *next;
	int key;
	spisok(int k) :next(NULL), key(k) {}
};
class Queue {
public:
	void push(int element);
	int pop();
	Queue() :head(NULL), tail(NULL) {}
	~Queue() {
		spisok *temp = head;
		while (temp != NULL) {
			temp = head->next;
			delete head;
			head = temp;
		}
	}
private:
	spisok *head, *tail;
};
void Queue::push(int element) {
	spisok *temp = new spisok(element);
	if (head != NULL) {
		tail->next = temp;
		tail = temp;
	}
	else
		head = tail = temp;
}
int Queue::pop() {
	if (head != NULL) {
		int x = head->key;
		spisok *temp = head;
		head = head->next;
		delete temp;
		return x;
	}
	else
		return -1;
}
int main() {
	int n, a, b, i;
	cin >> n;
	Queue q;
	for (i = 0; i < n; i++) {
		cin >> a >> b;
		if (a == 3)
			q.push(b);
		if (a == 2) {
			if (q.pop() == b)
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
