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
	��������������У����϶����ڲ��ṹ�����仯���졣��������Щ���϶�������ϣ��
	�ڲ���¶���ڲ��ṹ��ͬʱ���������ⲿ�ͻ�����͸���ط������а�����Ԫ�أ�ͬʱ����
	��͸��������ҲΪ��ͬһ���㷨�ڶ��ּ��϶����Ͻ��в������ṩ�˿��ܡ�

	ʹ����������������ֱ������Ƴ���Ϊ������������Ϊ��Ӧ�Ա仯�еļ��϶���
	�ṩ��һ�����ŵķ�ʽ��
*/

/*
	���壺�ṩһ�ַ���˳�����һ���ۺ϶����еĸ���Ԫ�أ����ֲ���¶���ȶ�����
	������ڲ���ʾ��

*/

/*
	Ҫ�㣺
	1.�������󣺷���һ���ۺ϶�������ݶ����豩¶�����ڲ���ʾ��

	2.������̬��Ϊ������ͬ�ļ��Ͻṹ�ṩһ��ͳһ�Ľӿڣ��Ӷ�֧��ͳһ���㷨��
	  ��ͬ�ļ��Ͻṹ�Ͻ��в�����

	3.�������Ľ�׳�Կ��ǣ�������ͬʱ���ĵ��������ڵļ��Ͻṹ�ᵼ�����⡣
*/

template<typename T>
class Iterator {
public:
	virtual void first() = 0;
	virtual void next() = 0;
	virtual bool isDone()const = 0;
	virtual T& current() = 0;
};

template<typename T>
class MyCollection {
public:
	Iterator<T>* getIterator() {
		//....
	}
};

template<typename T>
class CollectionIterator:public Iterator<T> {
	MyCollection<T> mc;
public:
	CollectionIterator(const MyCollection<T>& c) : mc(c) {}
	void first()override {

	}
	void next()override {

	}
	bool isDone() const override {

	}
	T& current() override{

	}
};

void MyAlgorithm()
{
	MyCollection<int> mc;
	Iterator<int>* iter = mc.getIterator();

	for (iter->first(); !iter->isDone(); iter->next())iter->current();
}





