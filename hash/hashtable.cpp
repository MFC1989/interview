#include "hashtable.h"

hashTable::hashTable(int div)
{
	LEN = div;

	D = div;

	value = (INTPTR)malloc(LEN*sizeof(int));
	key = (INTPTR)malloc(LEN*sizeof(int));

	for (int i = 0; i < LEN;i++)
	{
		value[i] =  INT_MIN;
		key[i] = INT_MIN;
	}

}




void hashTable::Insert(int k, int v)
{
	int b = Hsearch(k,INSERT);
	if (b == LEN - 1)
	{
		expand();
	}

	if (key[b]==k)
	{
		//cout << "the key " << k << " is exist,so can't insert" << endl;
	}
	else if (key[b]==INT_MIN)
	{
		key[b] = k;
		value[b] = v;
		return;
	}

}


bool hashTable::get(int k, int&e)
{
	int b = Hsearch(k,NOINSERT);

	if (key[b]==INT_MIN)
	{
		return false;
	}

	e=value[b];
	return true;

} 

void hashTable::clear()
{
	free(value);
	free(key);
}

void hashTable::expand()
{
	//cout << "the size was expand! " << endl;

	int increment =LEN*LEN;

	int newSize = sizeof(int)*LEN + increment * sizeof(int);

	key = (INTPTR)realloc(key, newSize);

	value = (INTPTR)realloc(value,newSize);

	LEN += increment;

	for (int i = LEN - increment; i < LEN; i++)
	{
		key[i] = INT_MIN;
		value[i] = INT_MIN;
	}

}

void hashTable::erase(int k)
{
	int b = Hsearch(k,NOINSERT);
	if (key[b]==k)
	{
		cout << "the key " << key[b] << " was deleted." << endl;
		value[b] = INT_MIN;
		key[b] = INT_MIN;
	}
	
}

void hashTable::show()
{
	int i;
	for ( i = 0; i < LEN; i++)
	{
		if (key[i]==INT_MIN)
		{
			cout << "KEY:\t" << "NULL" << "\t" << "VALUE:\t" << "NULL" << endl;
		}
		else
		{
			cout << "KEY:\t" << key[i] << "\t" << "VALUE:\t" << value[i] << endl;
		}
	}
}


int hashTable::Hsearch(int k,SEARCH_TYPE T)
{
	int i = k%D;
	int j = i;

	do 
	{
		if (T == INSERT)
		{
			if (key[j]==k)
			{
				return j;
			}
			if (key[j]==INT_MIN)		//如果查找的目的是为了寻找空位插入，那么找到空位即返回
			{
				return j;
			}
		}
		else
		{
			if (key[j] == k)			//如果查找的目的是为了找到该元素，那么要一直查找下去。
			{
				return j;				
			}
		}

		j = (j + 1) % LEN;
	} while (j!=i);
	return j ;
}