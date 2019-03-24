#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct DTree{
	int key, prior;
	DTree *left, *right;
	DTree(int k, int pri) :key(k), prior(pri), left(NULL), right(NULL) {}
};
void Split(DTree *node,int k,DTree *&left,DTree *&right){
	if(node==NULL){
		left = NULL;
		right = NULL;
	}
	else{
		if (node->key > k) {
			Split(node->left, k, left,node->left);
			right = node;
		}
		else {
			Split(node->right, k, node->right,right);
			left = node;
		}
	}
}
void Insert(DTree *&node, DTree *node1) {
	if(node==NULL){
		node = node1;
		return;
	}
	if (node->prior < node1->prior) {
		Split(node, node1->key, node1->left, node1->right);
		node = node1;
	}else {
		if (node->key < node1->key)
			Insert(node->right, node1);
		else
			Insert(node->left, node1);
	}
}

int deep_count(DTree *node){
	if (node == NULL)
		return 0;
	return(max(deep_count(node->left), deep_count(node->right)) + 1);
}
struct simpleTree{
	int key;
	simpleTree *left, *right;
	simpleTree(int k) :key(k), left(NULL), right(NULL) {}
};
void add_node(simpleTree *&node1,int k ) {
	if (node1 == NULL)
	{
		node1 = new simpleTree(k);
		return;
	}
	if (node1->key < k)
		add_node(node1->right, k);
	else
		add_node(node1->left, k);
}
int deep_count(simpleTree *node) {
	if (node == NULL)
		return 0;
	return(max(deep_count(node->left), deep_count(node->right)) + 1);
}

int shirina(simpleTree *node1)
{
	queue<simpleTree*>q;
	q.push(node1);
	int k = 1, max = 0,t=1;
	while (q.empty()==0)
	{
		simpleTree *x = q.front();
		q.pop();
		if (x->left != NULL)
		{
			q.push(x->left);
			k++;
		}
		if (x->right != NULL)
		{
			q.push(x->right);
			k++;
		}
		t--;
		if (t == 0)
		{
			if (max < k)
				max = k;
			t = k;
			k = 0;
		}
	}
	return max;
}
int main()
{
	int n,x,y;
	cin >> n;
	DTree *node = NULL;
	simpleTree *node1 = NULL;
	for (int i = 0; i < n; i++){
		cin >> x >> y;
		add_node(node1, x);
		Insert(node,new DTree(x,y));
	}
	cout << deep_count(node1)-deep_count(node);
	return 0;
}
