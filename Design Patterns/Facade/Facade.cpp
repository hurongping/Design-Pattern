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

	如何简化外部客户程序和系统间的交互接口？如何将外部客户程序的演化和内部子系统
	的变化之间的依赖相互解耦？
*/

/*
	模式定义：为子系统中的一组接口提供一个一致（稳定）的界面，Facade模式定义了一个
	高层接口，这个接口使得这一子系统更加容易使用（复用）。
*/

/*
	要点总结：
	1.从客户程序的角度来看，Facade模式简化了整个组件系统的接口，对于组件内部与外部
	  客户程序来说，达到了一种“解耦”的效果-----内部子系统的任何变化不会影响到
	  Facade接口的变化。
	2.Facade设计模式更注重从架构的层次去看整个系统，而不是单个类的层次。Facade很多
	  时候更是一种架构设计模式。
	3.Facade设计模式并非一个集装箱，可以任意地放进任何多个对象。Facade模式中组件的
	  内部应该是“相互耦合关系比较大的一系列组件”，而不是一个简单的功能集合。
*/