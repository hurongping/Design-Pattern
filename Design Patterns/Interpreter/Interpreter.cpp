//���������ģʽ
/*
	���ض������У�ĳЩ�仯��ȻƵ���������Գ���Ϊĳ�ֹ�����ʱ�򣬽���ض����򣬽�
	�������Ϊ�﷨���򣬴Ӷ������ڸ������µ�һ���Խ��������

	����ģʽ��
	Interpreter		��������
*/

/*
	Motivation
	��������������У����ĳһ�ض����������Ƚϸ��ӣ����ƵĽṹ�����ظ����֣����
	ʹ����ͨ�ı�̷�ʽ��ʵ�ֽ����ٷǳ�Ƶ���ı仯��

	����������£����ض������������Ϊĳ���﷨�����µľ��ӣ�Ȼ�󹹽�һ����������
	���������ľ��ӣ��Ӷ��ﵽ��������Ŀ�ġ�
*/

/*
	���壺����һ�����ԣ����������ķ���һ�ֱ�ʾ��������һ�ֽ����������������ʹ��
	�ñ�ʾ�����������еľ��ӡ�
*/

/*
	Ҫ�㣺
	Interpreterģʽ��Ӧ�ó�����InterpreterģʽӦ���е��ѵ㣬ֻ�����㡰ҵ��
	����Ƶ���仯�������ƵĽṹ�����ظ����֣��������׳���Ϊ�﷨��������⡰���ʺ�
	ʹ��Interpreterģʽ��

	ʹ��Interpreterģʽ����ʾ�ķ����򣬴Ӷ�����ʹ�����������������ء���չ��
	�ķ�

	Interperterģʽ�Ƚ��ʺϼ򵥵��ķ���ʾ�����ڸ��ӵ��ķ���ʾ��Interpreterģʽ
	������Ƚϴ�����νṹ����Ҫ�������﷨���������������ı�׼���ߡ�
*/

#include<iostream>
#include<map>
#include<stack>
#include<string>

using std::cout;
using std::endl;
using std::string;
using std::map;
using std::stack;

class Expression {
public:
	virtual int interpreter(map<char, int> var) = 0;
	virtual ~Expression(){}
};

//�������ʽ
class VarExpression :public Expression {
	char key;
public:
	VarExpression(const char& c):key(c){}
	int interpreter(map<char, int> var)override {
		return var[key];
	}
};
//���ű��ʽ
class SymbolExpression :public Expression {
protected:
	Expression* left;
	Expression* right;
public:
	SymbolExpression(Expression* l, Expression* r) :left(left), right(r){}
};

class AddExpression :public SymbolExpression {
public:
	AddExpression(Expression* l,Expression* r):SymbolExpression(l,r){}
	int interpreter(map<char, int> var) override{
		return left->interpreter(var) + right->interpreter(var);
	}
};

class SubExpression :public SymbolExpression {
public:
	SubExpression(Expression* l, Expression* r) :SymbolExpression(l, r) {}
	int interpreter(map<char, int> var) override {
		return left->interpreter(var) - right->interpreter(var);
	}
};

Expression* analyse(string expStr) {
	stack<Expression*> expStack;
	Expression* left = nullptr;
	Expression* right = nullptr;

	for (int i = 0; i < expStr.size(); i++) {
		switch (expStr[i]) {
			case '+':
				left = expStack.top();
				right = new VarExpression(expStr[++i]);
				expStack.push(new AddExpression(left, right));
				break;
			case '-':
				left = expStack.top();
				right = new VarExpression(expStr[++i]);
				expStack.push(new SubExpression(left, right));
				break;
			default:
				expStack.push(new VarExpression(expStr[i]));
		}
	}
	Expression* expression = expStack.top();
	return expression;
}

void release(Expression* expression) {
	//�ͷű��ʽ���Ľڵ��ڴ�....
}

int main()
{
	string expStr = "a+b-c+d";
	map<char, int> var;
	var.insert({ 'a',5 });
	var.insert({ 'b',2 });
	var.insert({ 'c',1 });
	var.insert({ 'd',6 });

	Expression* expression = analyse(expStr);
	
	int result = expression->interpreter(var);

	cout << result << endl;
	release(expression);

	return 0;
}
