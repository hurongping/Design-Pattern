//��״̬�仯��ģʽ
/*
	��������������У�ĳЩ�����״̬�������ٱ仯����ζ���Щ�仯������Ч�Ĺ���
	ͬʱ��ά�ָ߲�ģ����ȶ�����״̬�仯��ģʽΪ��һ�����ṩ��һ�ֽ��������

	����ģʽ��
	1.State          ��״̬ģʽ
	2.Memento        ������¼
*/

/*
	��������������У�ĳЩ�����״̬��ת�������У���������ĳ����Ҫ��Ҫ������ܹ�
	���ݵ�����֮ǰ����ĳ����ʱ��״̬�����ʹ��һЩ���нӿ�������������õ������
	״̬����ᱩ¶�����ϸ��ʵ�֡�

	���ʵ�ֶ���״̬�����ñ�����ָ�?��ͬʱ�ֲ�����˶��ƻ�������ķ�װ�ԡ�
*/

/*
	���壺�ڲ��ƻ���װ�Ե�ǰ���£�����һ��������ڲ�״̬�����ڸö���֮�Ᵽ��
	      ���״̬�������Ժ�Ϳ��Խ��ö���ָ���ԭ�ȱ����״̬��
*/

/*
	Ҫ���ܽ᣺
	1.����¼��Memento)�洢ԭ������originator��������ڲ�״̬������Ҫʱ�ָ�ԭ����
	  ״̬��

	2.Mementoģʽ�ĺ�������Ϣ���أ���Originator��Ҫ�����������Ϣ���������װ�ԡ�
	  ��ͬʱ����Ҫ��״̬���ֵ���磨Memento����

	3.�����ִ���������ʱ�������൱�Ķ������л�֧�֣������������Ч�ʽϸߡ��ֽ�
	  ������ȷʵ�ֵ����л�������ʵ��Mementoģʽ��
*/
#include<string>

using std::string;

class Memento {
	string state;
public:
	Memento(const string& s):state(s){}
	string getState()const { return state; }
	void setState(const string& s) { state = s; }
};

class Originator {
	string state;
public:
	Originator(){}
	Memento createMemento() {
		Memento m(state);
		return m;
	}
	void setMemento(const Memento& m) {
		state = m.getState();
	}
};

int main()
{
	Originator orginator;
	//����������¼
	Memento mem = orginator.createMemento();

	//�ı�orginator��״̬

	//�ӱ���¼�ָ���֮ǰ��״̬
	orginator.setMemento(mem);

	return 0;
}
