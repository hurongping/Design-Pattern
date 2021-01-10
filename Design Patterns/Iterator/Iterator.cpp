//“数据结构”模式
/*
	常常有一些组件在内部具有特定的数据结构，如果让客户程序依赖这些特定的数据结构，
	将极大地破坏组件的复用。这时候，将这些特定的数据结构封装在内部，在外部提供
	统一的接口，来实现与特定数据结构无关的访问，是一种行之有效的解决方案。

	典型模式：
	1.Composite                ：组合模式
	2.Iterator                 ：迭代器
	3.Chain of Responsibility  ：职责链
*/

/*
	Motivation:
	在软件构建过程中，集合对象内部结构常常变化各异。但对于这些集合对象，我们希望
	在不暴露其内部结构的同时，可以让外部客户代码透明地访问其中包含的元素；同时这种
	“透明遍历”也为“同一种算法在多种集合对象上进行操作”提供了可能。

	使用面向对象技术将这种遍历机制抽象为“迭代器对象”为“应对变化中的集合对象”
	提供了一种优雅的方式。
*/

/*
	定义：提供一种方法顺序访问一个聚合对象中的各个元素，而又不暴露（稳定）该
	对象的内部表示。

*/

/*
	要点：
	1.迭代抽象：访问一个聚合对象的内容而无需暴露它的内部表示。

	2.迭代多态：为遍历不同的集合结构提供一个统一的接口，从而支持统一的算法在
	  不同的集合结构上进行操作。

	3.迭代器的健壮性考虑：遍历的同时更改迭代器所在的集合结构会导致问题。
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





