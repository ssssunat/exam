#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct spisok {
	spisok *next;
	string  key;
	spisok(string s) :next(NULL), key(s) {}
};
int Hash(string s,int size) {
	int hash = 0;
	for (int i = 0; i < s.length(); i++) {
		hash = (hash*5 + s[i]) % size;
	}
	return hash;
}
bool has(vector<spisok*>&table,int size,string s) {
	int k = Hash(s,size);
	spisok *x = table[k];
	while (x != NULL) {
		if (x->key == s)
			return true;
		x = x->next;
	}
	return false;
}
bool add(vector<spisok*>&table, int size,string s, int &realsize) {
	if (has(table, size, s))
		return false;
	realsize++;
	int k = Hash(s,size);
	spisok *x = new spisok(s);
	if (table[k] != NULL) {
		x->next = table[k];
		table[k] = x;
	}
	else
		table[k] = x;
	return true;
}
bool del(vector<spisok*>&table, int size, string s, int &realsize) {
	if (!has(table, size, s))
		return false;
	int k = Hash(s, size);
	spisok *x = table[k];
	realsize--;
	if (x->next == NULL) {
		table[k] = table[k]->next;
		delete x;
		return true;
	}
	while (x->next != NULL) {
		if (x->next->key == s)
			break;
		x = x->next;
	}
	spisok *l = x->next;
	x->next = x->next->next;
	delete l;
	return true;
}
void newHash(int& size, int realsize, vector<spisok*>&hash)
{
	vector<spisok*>newhash(2*size);
	int  m = 2 * size;
	int i = 0;
	while (i<=size) {
		while (table[i]!= NULL) {
			add(newhash(Hash(table[i]->key, m)),m,;
			table[i] = table[i]->next;
		}
	}
	hash = newhash;
	size *= 2;
}
int main() {
	char a;
	string  s;
	int size = 8;
	int realsize = 0;
	int Mb = 0;
	vector<spisok*>table(size);
	string res[] = { "FAIL\n", "OK\n" };
	while (cin >> a >> s) {
		if(Mb>=1)
			newHash(size, realsize, table);
		switch (a) {
		case '+': cout << res[add(table,size,s,realsize)];
			break;
		case '-': cout << res[del(table,size,s,realsize)];
			break;
		case '?': cout << res[has(table,size,s)];
			break;
		}
		Mb = realsize / size;
	}
	return 0;
}
