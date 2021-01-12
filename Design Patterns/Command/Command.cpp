//����Ϊ�仯��ģʽ
/*
	������Ĺ��������У������Ϊ�ı仯�����������������ҵı仯������Ϊ�仯��ģʽ
	���������Ϊ�����������н���Ӷ�֧�������Ϊ�ı仯��ʵ������֮�������ϡ�

	����ģʽ��
	1.Command	������ģʽ
	2.Visitor	��������
*/

/*
	Motivation
	��������������У�����Ϊ�����ߡ��롰��Ϊʵ���ߡ�ͨ������һ�֡�����ϡ�������
	ĳЩ����----������Ҫ����Ϊ���С���¼������/������undo/redo�������񡱵ȴ���
	�����޷������仯�Ľ�����ǲ����ʵġ�

	����������£���ν�����Ϊ�����ߡ��롰��Ϊʵ���ߡ������һ����Ϊ����Ϊ����
	����ʵ�ֶ���֮�������ϡ�

*/

/*
	���壺��һ��������Ϊ����װΪһ�����󣬴Ӷ�ʹ����ò�ͬ������Կͻ����в�������
	      �������Ŷӻ��߼�¼������־���Լ�֧�ֿɳ����Ĳ�����
*/

/*
	Ҫ�㣺
	Commandģʽ�ĸ���Ŀ�����ڽ�����Ϊ�����ߡ��롰��Ϊʵ���ߡ�������������Ԥ��
	�У�������ʵ���ֶ��ǡ���Ϊ����Ϊ���󡱡�

	ʵ��Command�ӿڵľ����������ConcreteCommand��ʱ�������Ҫ���ܻᱣ��һЩ����
	״̬��Ϣ��ͨ��ʹ��Compositeģʽ�����Խ�����������װΪһ����������
	��MacroCommand��

	Commandģʽ��C++�еĺ���������Щ���ơ������߶�����Ϊ�ӿڵĹ淶��������
	Command����������еġ��ӿ�--ʵ�֡���������Ϊ�ӿڹ淶�����ϸ񣬵���������ʧ��
	C++���������Ժ���ǩ����������Ϊ�ӿڹ淶���������ܸ��ߡ�
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