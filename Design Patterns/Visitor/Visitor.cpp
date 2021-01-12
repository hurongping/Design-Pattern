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
	���������������,��������ĸı䣬ĳЩ���νṹ�г�����Ҫ�����µ���Ϊ����������
	���ֱ���ڻ������������ĸ��ģ��������������ܷ��صı�������������ƻ�ԭ��
	��ơ�

	����ڲ��������νṹ��ǰ���£�������ʱ������Ҫ͸����Ϊ���νṹ�ϵĸ�����
	��̬����µĲ������Ӷ������������⣿
*/

/*
	���壺��ʾһ��������ĳ����ṹ�еĸ�Ԫ�صĲ�����ʹ�ÿ����ڲ��ı䣨�ȶ���
	      ��Ԫ�ص����ǰ���¶��壨��չ����������ЩԪ�ص��²������仯����
*/

/*
	Ҫ�㣺
	Visitorģʽͨ����ν˫�طַ���double dispatch����ʵ���ڲ����ģ�������µ�
	����--����ʱ��Element���νṹ��ǰ���£�������ʱ͸����Ϊ���νṹ�ϵĸ�����
	��̬����µĲ�����֧�ֱ仯����

	��ν˫�طַ���Visitorģʽ�м������������̬�ַ���ע�����еĶ�̬���ƣ�����һ��
	Ϊaccept�����Ķ�̬�������ڶ���ΪvisitElementX�����Ķ�̬������

	Visitorģʽ�����ȱ��������չ���νṹ�������µ�Element���ࣩ���ᵼ��Visitor
	��ĸı䡣���Visitorģʽ�����ڡ�Element���νṹ�ȶ��������еĲ���ȴ��������
	Ƶ���Ķ�����
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
