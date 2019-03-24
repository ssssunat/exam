#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#define a  9834497
using namespace std;
int Getkey(string str1 , int  size)
{
	long long  hash = 0;
	for ( int i = str1.size() - 1; i >= 0; --i)
	{
		hash += (hash * a + int(str1[i])) % size;
	}
	return hash % size;
}
void Qprob(int  &key ,int &prob, int  size)
{
	++prob;
	key = (key + prob) % size;

}
int Isthere(vector<pair<string, bool>>&hash, string str3, int key, int size)
{
	int prob = 0;
	while ((prob < size) && (hash[key].first != "") )
	{
		if ((hash[key].first == str3) && (hash[key].second == false))
		{
			return key;
		}
		else
			Qprob(key, prob, size);
	}
	return -1;
}
bool addElement(vector<pair<string, bool>>&hash, int  key, string str2, int size ,int& realsize)
{
	bool added = false;
	int prob = 0;
	if (Isthere(hash, str2, key, size) != -1)
		return false;
	while (!added) {
       
		if ((hash[key].first == "") || (hash[key].second==true))
		{
			hash[key].first = str2;
			++realsize;
			added = true;
			hash[key].second = false;
		}
		else
			
			Qprob(key, prob, size);
	}
	return true;
}

void newHash(int& size, int realsize ,vector<pair<string,bool>>&hash)
{
	vector<pair<string, bool>>newhash(2 * size);
	int  m = 2 * size;
	for (long long i = 0; i < m; ++i)
	{
		newhash[i].first = "";
		newhash[i].second = false;
	}
	int i = 0, j = 0;
	while ((i < size) && (j <=realsize))
	{
		if ((hash[i].first != "") && (hash[i].second == false))
		{
			int key = Getkey(hash[i].first, m);
			bool t= addElement(newhash, key, hash[i].first,m, j);
		}
		++i;
	}
	hash = newhash;
	size *= 2;


}
bool deleteElement( vector<pair<string,bool>>&hash ,string str, int key, int size, int&realsize)
{
 int  m =Isthere(hash, str, key, size);
	if (m == -1)
		return false;
	else
	{
		hash[m].second = true;
		--realsize;
		return true;
	}
}

int main()
{
	string str;
	char type;
	int size = 8;
	int  realsize = 0;
	bool t = false;
	int Mb = 0;
	vector<pair<string,bool>>Hash(size);
	for (int  i = 0; i < size; ++i)
	{
		Hash[i].first = "";
		Hash[i].second = false;
	}
	while (cin >> type) 
		{
		if (Mb >= 0.75)
		
			newHash(size, realsize,Hash);
		
		
		getline(cin, str);
		long long m = Getkey(str,size);
			if (type == '+')
				 t = addElement(Hash ,m ,str ,size  ,realsize);
			if (type == '-')
			     t = deleteElement(Hash ,str ,m ,size, realsize);
			if (type == '?') {
				long long  k = Isthere(Hash, str, m, size);
				if (k == -1)
					cout << "FAIL" << endl;
				else
					cout << "OK" << endl;
				continue;
			}
			if(t)
				cout << "OK" << endl;
			else
				cout << "FAIL" << endl;
		
			Mb = realsize / size;

		}
	return 0;
}
