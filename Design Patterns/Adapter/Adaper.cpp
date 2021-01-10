//“接口隔离”模式
/*
	在组件构建过程中，某些接口之间直接的依赖常常会带来很多问题、甚至根本无法实现。
	采用添加一层间接（稳定）接口，来隔离本来互相紧密关联的接口是一种常见的解决
	方案。

	典型模式：
	1.Facade   ：门面模式
	2.Proxy    ：代理模式
	3.Adapter  ：适配器
	4.Mediator ：中介者
*/

/*
	Motivation
	在软件系统中，由于应用环境的变化，常常需要将“一些现存的对象”放在新的环境中
	应用，但是新环境要求的接口是这些现存对象所不能满足的。

	如何应用这种“迁移的变化”？如何既能利用现有的对象的良好实现，同时又能满足
	新的应用环境所要求的接口？。
*/

/*
	模式定义：将一个类的接口转换成客户希望的另一个接口。Adapter模式使得原本
	由于接口不兼容而不能一起工作的那些类可以一起工作。
*/

/*
	要点总结：
	1.Adapter模式主要应用于“希望复用一些现存的类，但是接口又与复用环境要求不一致。
	  在遗留代码复用、类库迁移等方面非常有用。

	2.GOF 23定义了两种Adapter模式的实现结构：对象适配器和类适配器。但类适配器采用
	  “多继承”的实现方式，一般不推荐使用。但对象适配器采用“对象组合”的方式，更
	  符合松耦合精神。

	3.Adapter模式可以实现的非常灵活，不必拘泥于GOF 23中定义的两种结构。例如，完全
	  可以将Adapter模式中的“现存对象”作为新的接口方法参数，来达到适配器的目的。
*/
//目标接口（新接口）
class ITarget {
public:
	virtual void process() = 0;
};
//遗留接口（老接口）
class IAdaptee {
public:
	virtual void foo(int data) = 0;
	virtual int bar() = 0;
};

class Adaper :public ITarget {
protected:
	IAdaptee* pAdaptee;
public:
	virtual void process() {
		int data = pAdaptee->bar();
		pAdaptee->foo(data);
	}
};
