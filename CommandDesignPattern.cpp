#include <iostream>
#include <vector>
 
class Receiver
{
public:
	void Action()
	{
		std::cout << "Inside Receiver::Action()" << std::endl;
	}
};

class Command
{
public:
	virtual void execute() = 0;
};

class ConcreteCommand :public Command
{
private:
	Receiver* receiver = nullptr;
public:
	ConcreteCommand(Receiver* recv)
	{
		receiver = recv;
	}

	void execute() override
	{
		receiver->Action();
	}
};

class Invoker
{
private:
	Command* _cmd;
public:
	Invoker(Command* cmd)
	{
		_cmd = cmd;
	}

	void ExecuteCmd()
	{
		_cmd->execute(); 
	}
};

int main() 
{
	Receiver* receiver = new Receiver();
	Command* cmd = new ConcreteCommand(receiver);
	Invoker* invoker = new Invoker(cmd);
	invoker->ExecuteCmd();
	
	return 0;
}
