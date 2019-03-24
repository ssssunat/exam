#include<iostream>
using namespace std;
class Deque {
public:
	void push_back(int element);
	void push_front(int element);
	int pop_back();
	int pop_front();
	Deque(int size) :head(0), tail(0),buffersize(size){
		buffer = new int[buffersize];
	}
	~Deque() {
		delete[]buffer;
	}
private:
	int *buffer;
	int buffersize;
	int tail, head;
};
void Deque::push_back(int element) {
	buffer[tail] = element;
	tail = (tail + 1) % buffersize;
}
void Deque::push_front(int element) {
	head = (head - 1+buffersize) % buffersize;
	buffer[head] = element;
}
int Deque::pop_front() {
	if (head == tail)
		return -1;
	int x = buffer[head];
	head = (head + 1) % buffersize;
	return x;
}
int Deque::pop_back() {
	if (head == tail)
		return -1;
	tail = (tail - 1 + buffersize) % buffersize;
	return buffer[tail];
}
int main() {
	int n, a, b, i;
	cin >> n;
	Deque q(n);
	for (i = 0; i < n; i++) {
		cin >> a >> b;
		if (a == 1)
			q.push_front(b);
		if (a == 3)
			q.push_back(b);
		if(a==2){
			if (q.pop_front() == b)
				true;
			else
				i = n;
		}
		if (a == 4) {
			if (q.pop_back() == b)
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
