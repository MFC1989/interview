//
//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>
//
//#ifdef _DEBUG
//#ifndef DBG_NEW
//#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
//#define new DBG_NEW
//#endif
//#endif  // _DEBUG

#include <ctime>
#include <cstdlib>
#include <cstdio>

#include "hashtable.h"
//#include <unordered_map>

#define SIZE 3000

void showTime()
{
	const time_t t = time(NULL);
	struct tm* current_time;

	current_time = localtime(&t);
	printf(" %d--%d\n",
		current_time->tm_min,
		current_time->tm_sec
		);
}
int main()
{
	
	showTime();
	hashTable table(100);

	for (int i = 0; i < 12000; i++)
	{
		table.Insert(rand(), 1);
	}

	int valid=0, invalid=0;
	for (int i = 0; i < table.LEN;i++)
	{
		if(table.value[i]==INT_MIN) {
			invalid++;
		}
		else {
			valid++;
		}
	}

	//table.show();
	//_CrtDumpMemoryLeaks();

	//cout<<"valid ="<<valid<<endl;
	//cout<<"invalid ="<<invalid<<endl;

	showTime();

	//unordered_map<int, int> table1;
	//for (int i = 0; i < 120000; i++)
	//{
	//	table1.insert(make_pair(rand(), 1));
	//}
	//showTime();

	return 0;
}