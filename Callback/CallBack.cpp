#include <iostream>
using namespace std;

//定义一个类型别名 Fuction：参数为int，返回值为void
typedef void(*Fuction)(int);

void positive(int n)
{
	cout <<n <<"is a positive number" << endl;
}

void negative(int n)
{
	cout << n<<" is a negative number" << endl;
}

void zero(int n)
{
	cout << n << " is zero" << endl;
}

void testCallBack(int n,Fuction *PF)
{
	if (n==0)
	{
		*PF = zero;
	}else if (n > 0)
	{
		*PF = positive;
	}
	else
	{
		*PF = negative;
	}

	(*PF)(n);
}



#include <iostream>
using std::cout;
using std::endl;

class MyClass
{
public:
	MyClass();
	static void Callback(MyClass* instance, int x);
private:
	int private_x;
};

class EventHandler
{
public:
	void addHandler(MyClass* owner)
	{
		cout << "Handler added..." << endl;
		//Let's pretend an event just occured
		owner->Callback(owner, 1);
	}
};

EventHandler* handler;

MyClass::MyClass()
{
	private_x = 5;
	handler->addHandler(this);
}

void MyClass::Callback(MyClass* instance, int x)
{
	cout << x + instance->private_x << endl;
}


int main()
{
	Fuction  mFuction;			//声明一个函数指针。		
	int a = 3;
	int b = 0;
	
	testCallBack(a, &mFuction);
	testCallBack(b, &mFuction);


	handler = new EventHandler();
	MyClass* myClass = new MyClass();
	return 0;
}