//“状态变化”模式
/*
	在组件构建过程中，某些对象的状态经常面临变化，如何对这些变化进行有效的管理？
	同时又维持高层模块的稳定？“状态变化”模式为这一问题提供了一种解决方案。

	典型模式：
	1.State          ：状态模式
	2.Memento        ：备忘录
*/

/*
	在软件构建过程中，某些对象的状态如果改变，其行为也会随之而变化，比如文档处于
	只读状态，其支持的行为和读写状态支持的行为就可能完全不同。

	如何在运行时根据对象的状态来透明地更改对象的行为？而不是为对象操作和状态转化
	之间引入紧耦合。
*/

/*
	定义：允许一个对象在其内部状态改变时改变它的行为。从而使对象看起来似乎修改了
	其行为
*/

/*
	要点总结：
	1.State模式将所有与一个特定状态相关的行为都放入一个State的子类对象中，在对象
	  状态切换时，切换相应的对象；但同时维持State的接口，这样实现了具体操作与状态
	  转换之间的解耦。

	2.为不同状态引入不同的对象使得状态转换变得更加明确，而且可以保证不会出现状态
	  不一致的情况，因为状态转换是原子性的------即要么彻底转换过来，要么不转换。

	3.如果State对象没有实例变量，那么各个上下文可以共享同一个State对象，从而节省
	  对象开销。
*/

class NetworkState {
public:
	NetworkState* pNext;
	virtual void operator1() = 0;
	virtual void operator2() = 0;
	virtual void operator3() = 0;

	virtual ~NetworkState(){}
};

class OpenState :public NetworkState {
	//singleton的常见写法
	static NetworkState* m_instance;
	OpenState(){}
public:
	static NetworkState* getInstance() {
		if (m_instance == nullptr)m_instance = new OpenState();
		return m_instance;
	}
	//singleton常见写法
	void operator1() {
		//**********************
		pNext = CloseState::getInstance();
	}

	void operator2() {
		pNext = ConnectState::getInstance();
	}

	void operator3() {
		//$$$$$$$$$$$$$
		pNext = OpenState::getInstance();
	}
};
NetworkState* OpenState::m_instance = nullptr;

class CloseState :public NetworkState {
	//singleton的常见写法
	static NetworkState* m_instance;
	CloseState() {}
public:
	static NetworkState* getInstance() {
		if (m_instance == nullptr)m_instance = new CloseState();
		return m_instance;
	}
	//singleton常见写法
	void operator1() {
		//**********************
		pNext = CloseState::getInstance();
	}

	void operator2() {
		pNext = ConnectState::getInstance();
	}

	void operator3() {
		//$$$$$$$$$$$$$
		pNext = OpenState::getInstance();
	}
};
NetworkState* CloseState::m_instance = nullptr;

class ConnectState :public NetworkState {
	//singleton的常见写法
	static NetworkState* m_instance;
	ConnectState() {}
public:
	static NetworkState* getInstance() {
		if (m_instance == nullptr)m_instance = new ConnectState();
		return m_instance;
	}
	//singleton常见写法
	void operator1() {
		//**********************
		pNext = CloseState::getInstance();
	}

	void operator2() {
		pNext = ConnectState::getInstance();
	}

	void operator3() {
		//$$$$$$$$$$$$$
		pNext = OpenState::getInstance();
	}
};
NetworkState* ConnectState::m_instance = nullptr;

