#include<iostream>
using namespace std;
class stack {
public:
	stack(int size) :buffersize(size), top(-1) {
		buffer = new int[size];
	}
	void push(int element) {
		buffer[++top] = element;
	}
	int pop() {
		if (top == -1)
			return -1;
		return buffer[top--];
	}
	int size() {
		return (top + 1);
	}
	~stack() {
		delete[]buffer;
	}
private:
	int *buffer;
	int buffersize;
	int top;
};
class Queue {
public:
	Queue(int size) :s1(size), s2(size) {}
	void push(int a) {
		s1.push(a);
	}
	int pop() {
		if (s2.size() == 0) {
			while (s1.size() != 0) {
				s2.push(s1.pop());
			}
		}
		return s2.pop();
	}
private:
	stack s1, s2;
};

int main() {
	int n, a, b, i;
	cin >> n;
	Queue q(n);
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
