/*
	重构关键技法
		静态--->动态
		早绑定--->晚绑定
		继承--->组合
		编译时依赖--->运行时依赖
		紧耦合--->松耦合
*/

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
	在软件构建过程中，对于某一项任务，它常常有稳定的整体操作结构，但各个子步骤却有
	很多改变的需求，或者由于固有的原因（比如框架与应用之间的关系）而无法和任务的
	整体结构同时实现。

	如何在确定稳定操作结构的前提下，来灵活应对各个子步骤的变化或者晚期实现需求？
*/

/*
	定义：
		定义一个操作中的算法的骨架（稳定），而将一些步骤延迟（变化）到子类中。
		Template Method使得子类可以不改变（复用）一个算法的结构即可重定义该算法
		的某些特定步骤。
*/

/*
	Template Method模式是一种非常基础性的设计模式，在面向对象系统中有大量的应用。
	它用最简洁的机制（虚函数的多态性）为很多应用程序框架提供了灵活的扩展点，是
	代码复用方面的基本实现结构。

	除了可以灵活应对子步骤的变化外，“不要调用我，让我来调用你”的反向控制结构
	是Template Method的典型应用。

	在具体实现方面，被Template Method调用的虚方法可以有实现，也可以没有任何实现
	（抽象方法、纯虚方法），一般推荐把它们设置为protected方法。
*/

//程序库开发人员
class Library {
public:
	void run(){
		step1();
		
		if(step2())
			step3();
		for (int i = 0; i < 4; i++)
			step4();
		step5();
	}
	virtual ~Library(){}
protected:
	void step1() {//稳定
		//...
	}
	void step3() {//稳定
		//...
	}
	void step5() {//稳定
		//...
	}
	virtual bool step2() = 0;//变化
	virtual void step4() = 0;//变化
};

//应用程序开发人员
class Application :public Library {
protected:
	virtual bool step2() {

	}
	virtual void step4() {

	}
};

int main() 
{
	Library* pLib = new Application();
	pLib->run();

	delete pLib;

	return 0;
}

