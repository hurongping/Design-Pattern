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
	在软件构建过程中,由于需求的改变，某些类层次结构中常常需要增加新的行为（方法），
	如果直接在基类中做这样的更改，将会给子类带来很繁重的变更负担，甚至破坏原有
	设计。

	如何在不更改类层次结构的前提下，在运行时根据需要透明地为类层次结构上的各个类
	动态添加新的操作，从而避免上述问题？
*/

/*
	定义：表示一个作用于某对象结构中的各元素的操作。使得可以在不改变（稳定）
	      各元素的类的前提下定义（扩展）作用于这些元素的新操作（变化）。
*/

/*
	要点：
	Visitor模式通过所谓双重分发（double dispatch）来实现在不更改（不添加新的
	操作--编译时）Element类层次结构的前提下，在运行时透明地为类层次结构上的各个类
	动态添加新的操作（支持变化）。

	所谓双重分发即Visitor模式中间包括了两个多态分发（注意其中的多态机制）：第一个
	为accept方法的多态辨析；第二个为visitElementX方法的多态辨析。

	Visitor模式的最大缺点在于扩展类层次结构（增添新的Element子类），会导致Visitor
	类的改变。因此Visitor模式适用于“Element类层次结构稳定，而其中的操作却经常面临
	频繁改动”。
*/

#include<iostream>

using std::cout;
using std::endl;

class Visitor {
public:
	virtual void visitElementA(ElementA& element) = 0;
	virtual void visitElementB(ElementB& element) = 0;
	~Visitor() {}
};

class Element {
public:
	virtual void accept(Visitor& visitor) = 0;
	virtual ~Element(){}
};

class ElementA :public Element {
public:
	void accept(Visitor& visitor)override {
		visitor.visitElementA(*this);
	}
};

class ElementB :public Element {
public:
	void accept(Visitor& visitor)override {
		visitor.visitElementB(*this);
	}
};

class Visitor1 :public Visitor {
public:
	void visitElementA(ElementA& element)override {
		cout << "Visitor1 is processing ElementA" << endl;
	}
	void visitElementB(ElementB& element)override {
		cout << "Visitor1 is processing ElementB" << endl;
	}
};

class Visitor2 :public Visitor {
public:
	void visitElementA(ElementA& element)override {
		cout << "Visitor2 is processing ElementA" << endl;
	}
	void visitElementB(ElementB& element)override {
		cout << "Visitor2 is processing ElementB" << endl;
	}
};

int main()
{
	Visitor2 visitor;
	ElementB elementB;
	elementB.accept(visitor);

	ElementA elementA;
	elementA.accept(visitor);

	return 0;
}
