//“行为变化”模式
/*
	在组件的构建过程中，组件行为的变化经常导致组件本身剧烈的变化。“行为变化”模式
	将组件的行为和组件本身进行解耦，从而支持组件行为的变化，实现两者之间的松耦合。

	典型模式：
	1.Command	：命令模式
	2.Visitor	：访问器
*/

/*
	Motivation
	在软件构建过程中，“行为请求者”与“行为实现者”通常呈现一种“紧耦合”。但在
	某些场合----比如需要对行为进行“记录、撤消/重做（undo/redo）、事务”等处理，
	这种无法抵御变化的紧耦合是不合适的。

	在这种情况下，如何将“行为请求者”与“行为实现者”解耦？将一组行为抽象为对象，
	可以实现二者之间的松耦合。

*/

/*
	定义：将一个请求（行为）封装为一个对象，从而使你可用不同的请求对客户进行参数化；
	      对请求排队或者记录请求日志，以及支持可撤销的操作。
*/

/*
	要点：
	Command模式的根本目的在于将“行为请求者”与“行为实现者”解耦，在面向对象预言
	中，常见的实现手段是“行为抽象为对象”。

	实现Command接口的具体命令对象ConcreteCommand有时候根据需要可能会保存一些额外
	状态信息，通过使用Composite模式，可以将多个“命令”封装为一个复合命令
	“MacroCommand”

	Command模式与C++中的函数对象有些类似。但两者定义行为接口的规范有所区别：
	Command以面向对象中的“接口--实现”来定义行为接口规范，更严格，但有性能损失；
	C++函数对象以函数签名来定义行为接口规范，更灵活，性能更高。
*/

#include<string>
#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Command {
public:
	virtual void execute() = 0;

};

class ConcreteCommand1 :public Command {
	string arg;
public:
	ConcreteCommand1(const string& a) : arg(a) {}
	void execute()override {
		cout << "#1 process..." << arg << endl;
	}
};

class ConcreteCommand2 :public Command {
	string arg;
public:
	ConcreteCommand2(const string& a) : arg(a) {}
	void execute()override {
		cout << "#2 process..." << arg << endl;
	}
};

class MacroCommand :public Command {
	vector<Command*> commands;
public:
	void addCommand(Command* c) { commands.push_back(c); }
	void execute()override {
		for (auto& c : commands)c->execute();
	}
};

int main()
{
	ConcreteCommand1 command1("Arg ###");
	ConcreteCommand2 command2("Arg $$$");
	MacroCommand macro;
	macro.addCommand(&command1);
	macro.addCommand(&command2);

	macro.execute();
	return 0;
}