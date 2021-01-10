//�����ݽṹ��ģʽ
/*
	������һЩ������ڲ������ض������ݽṹ������ÿͻ�����������Щ�ض������ݽṹ��
	��������ƻ�����ĸ��á���ʱ�򣬽���Щ�ض������ݽṹ��װ���ڲ������ⲿ�ṩ
	ͳһ�Ľӿڣ���ʵ�����ض����ݽṹ�޹صķ��ʣ���һ����֮��Ч�Ľ��������

	����ģʽ��
	1.Composite                �����ģʽ
	2.Iterator                 ��������
	3.Chain of Responsibility  ��ְ����
*/

/*
	Motivation:
	��ĳЩ����£��ͻ��������������ڶ����������ӵ��ڲ�ʵ�ֽṹ�����������ڲ�
	ʵ�ֽṹ�����ǳ���ӿڣ��ı仯������ͻ������Ƶ���仯�������˴����ά���ԡ�
	��չ�Եȱ׶ˡ�

	��ν����ͻ������븴�ӵĶ��������ṹ������ö��������Լ���ʵ������ĸ���
	�ṹ���Ӷ�ʹ�ÿͻ����������򵥶���һ���������ӵĶ���������
*/

/*
	���壺��������ϳ����νṹ�Ա�ʾ������--���塱�Ĳ�νṹ��Compositeʹ��
	�û��Ե����������϶����ʹ�þ���һ���ԣ��ȶ�����

*/

/*
	Ҫ�㣺
	1.Compositeģʽ�������νṹ��ʵ���ձ���ڵĶ����������Ӷ�����һ�Զࡱ�Ĺ�ϵ
	  ת��Ϊ��һ��һ���Ĺ�ϵ��ʹ�ÿͻ��������һ�µأ����ã��������Ͷ���������
	  ������Ĵ�����ǵ����Ķ��󣬻�����ϵĶ���������

	2.�����ͻ������븴�ӵĶ��������ṹ��������Composite�ĺ���˼�룬����֮��
	  �ͻ����뽫�봿��ĳ���ӿ�-----���Ƕ����������ڲ�ʵ�ֽṹ----�����������Ӷ�
	  ���ܡ�Ӧ�Ա仯����

	3.Compositeģʽ�ھ���ʵ���У������ø������е��Ӷ�����׷�ݣ������������Ƶ����
	  �������󣬿�ʹ�û��漼��������Ч�ʡ�
*/

#include<string>
#include<list>

using std::list;
using std::string;

class  Component {
public:
	virtual void process() = 0;
	virtual ~Component(){}
};
//���ڵ�
class Composite :public Component {
	string name;
	list<Component*> elements;
public:
	Composite(const string& s):name(s){}

	void add(Component* element) {
		elements.push_back(element);
	}

	void remove(Component* element) {
		elements.remove(element);
	}

	void process() {
		//process current node

		//process leaf nodes
		for (auto& e : elements)e->process();//��̬����
	}
};
//Ҷ�ӽڵ�
class Leaf :public Component {
	string name;
public:
	Leaf(string s):name(s){}
	void process() {
		//process current node
	}
};

void invoke(Component* p) {
	p->process();
}

int main()
{
	Composite root("root");
	Composite treeNode1("treeNode1");
	Composite treeNode2("treeNode2");
	Composite treeNode3("treeNode3");
	Composite treeNode4("treeNode4");

	Leaf leaf1("left1");
	Leaf leaf2("left2");

	root.add(&treeNode1);
	treeNode1.add(&treeNode2);
	treeNode2.add(&leaf1);

	root.add(&treeNode3);
	treeNode1.add(&treeNode4);
	treeNode2.add(&leaf2);

	invoke(&root);
	invoke(&leaf2);
	invoke(&treeNode3);

	return 0;
}