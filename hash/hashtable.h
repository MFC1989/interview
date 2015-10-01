
#include <climits>
#include <iostream>
#include <malloc.h>
using namespace std;

typedef int * INTPTR;
enum SEARCH_TYPE   //查找的类型
{
	INSERT,
	NOINSERT
};


class hashTable
{
public:
	hashTable(int div = 11);
	~hashTable()
	{
		free(key);
		free(value);
	}
	bool get(int k, int&e);
	void Insert(int k,int v);

	void expand();		//增大空间 X1
	void clear();
	void show();
	int Hsearch(int key,SEARCH_TYPE T);
	void erase(int k);
	
	int LEN;   
	INTPTR key;
	INTPTR value;
private:
	
	int D; //余数
	int hSearch( int k) ;
};