//“组件协作”模式
/*
	现代软件专业分工之后的第一个结果是“框架与应用程序之间的划分”，“组件协作”
	模式通过晚期绑定，来实现框架与应用之间的松耦合，是二者之间协作时常用的模式。

	典型模式
	1.Template Method
	2.Strategy
	3.Observer/Event
*/

/*
	Motivation:
	在软件构建过程中,某些对象使用的算法可能多种多样，经常改变，如果将这些算法都
	编码到对象中，将会使得对象变得异常复杂；而且有时候支持不使用的算法也是一个
	性能负担。

	如何在运行时根据需要透明地更改对象的算法？将算法与对象本身解耦，从而避免上述
	问题？
*/

/*
	定义：
		定义一系列算法，把它们一个个封装起来，并且使它们可互相替换（变化）。该
		模式使得算法可独立于使用它的客户程序（稳定）而变化（扩展，子类化）。
*/

/*
	Strategy及其子类为组件提供了一系列可重用的算法，从而可以使得类型在运行时
	方便地根据需要在各个算法之间进行切换。

	Strategy模式提供了用条件判断语句以外的另一种选择，消除条件判断语句，就是
	在解耦合。含有许多条件判断语句的代码通常都需要Strategy模式

	如果Strategy对象没有实例变量，那么各个上下文可以共享同一个Strategy对象，
	从而节省对象开销。
*/

class Context {
public:
	int n;
};

class TaxStrategy {	
public:
	virtual double calculate(const Context& context) = 0;
	virtual ~TaxStrategy(){}
};

class StrategyFactory {
public:
	virtual TaxStrategy* newStrategy() = 0;
};

class CNTax :public TaxStrategy {
public:
	virtual double calculate(const Context& context) {

	}
};

class CNStrategyFactory:public StrategyFactory {
public:
	virtual TaxStrategy* newStrategy() {
		return new CNTax();
	}
};

class USTax :public TaxStrategy {
public:
	virtual double calculate(const Context& context) {

	}
};

class USStrategyFactory :public StrategyFactory {
public:
	virtual TaxStrategy* newStrategy() {
		return new USTax();
	}
};

class DETax :public TaxStrategy {
public:
	virtual double calculate(const Context& context) {

	}
};

class DEStrategyFactory :public StrategyFactory {
public:
	virtual TaxStrategy* newStrategy() {
		return new DETax();
	}
};

class SalesOrder {
private:
	TaxStrategy* strategy;
public:
	SalesOrder(StrategyFactory* strategyFactory) {
		strategy = strategyFactory->newStrategy();
	}
	~SalesOrder(){
		delete strategy;
	}
public:
	double calculate() {
		Context context;
		double val = strategy->calculate(context);//多态调用
		//....
	}
};



