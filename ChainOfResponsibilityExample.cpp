#include <iostream>
#include <vector>
class Handler
{
public:
	Handler* successor;
    
	Handler()
	{
		successor = nullptr;
	}
	virtual void handle(int ReqNO) = 0;
	
	void makeSuccessor(Handler* obj)
	{
		successor = obj;
	}
};

class concreteHandler1 :public Handler
{
public:
	void handle(int req)
	{
		std::cout << " concreteHandler1 ::handle()\n" << std::endl;
		if (req < 5)
		{
			std::cout << "HandledReq request number: " << req << std::endl;
		}
		else if(successor != nullptr)
		{
			successor->handle(req);
		}
	}
};

class concreteHandler2 :public Handler
{
public:
	void handle(int req)
	{
		std::cout << " concreteHandler2 ::handle()\n" << std::endl;
		if (req < 10)
		{
			std::cout << "HandledReq request number: " << req << std::endl;
		}
		else if (successor != nullptr)
		{
			successor->handle(req);
		}
	}
};
 

int main() 
{
	Handler* h1 = new concreteHandler1();
	Handler* h2 = new concreteHandler2();
	h1->makeSuccessor(h2);
	h1->handle(4);
	h1->handle(6);
	h1->handle(11);
}
