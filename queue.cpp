#include<iostream>
#include<algorithm>
using namespace std;
class Queue {
public:
	Queue(int size) :buffersize(size), tail(0), head(0)
	{
		buffer = new int[buffersize];
	}
	~Queue()
	{
		delete[]buffer;
	}
	void push(int element);
	int pop();
private:
	int *buffer;
	int buffersize;
	int tail, head;
};
void Queue::push(int element){
	buffer[tail] = element;
	tail = (tail + 1) % buffersize;
}
int Queue::pop() {
	if (tail==head)
		return -1;
	int s = buffer[head];
	head = (head + 1) % buffersize;
	return s;
}
int main()
{
	int n,a,b,i;
	cin >> n;
	Queue q(n);
	for(i=0;i<n;i++){
		cin >> a >> b;
		if (a == 3)
			q.push(b);
		else {
			if (a == 2 && q.pop() == b)
				true;
			else {
				i = n;
			}
		}
	}
	if (i != n )
		cout << "NO";
	else
		cout << "YES";
	return 0;
}
