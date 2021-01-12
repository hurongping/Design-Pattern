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
	在软件构建过程中，我们需要为某些对象建立一种“通知依赖关系”--------一个对象（
	目标对象）的状态发生改变，所有的依赖对象（观察者对象）都将得到通知。如果这样的
	依赖关系过于紧密，将使得软件不能很好地抵御变化。

	使用面向对象技术，可以将这种依赖关系弱化，并形成一种稳定的依赖关系。从而实现
	软件体系结构的松耦合。
*/

/*
	定义：
		定义对象间的一种一对多的依赖关系，以便当一个对象的状态发生改变时，所有
		依赖它的对象都得到通知并自动更新。
*/

/*
	使用面向对象的抽象，Observer模式使得我们可以独立地改变目标与观察者，从而
	使二者之间的依赖关系达到松耦合

	目标发送通知时，无需指定观察者，通知（可以携带通知信息作为参数）会自动传播

	观察者自己决定是否需要订阅通知，目标对象对此一无所知。

	Observer模式是基于事件的UI框架中非常常用的设计模式，也是MVC模式的一个
	重要组成部分。
*/
#include<string>
#include<vector>

using std::vector;
using std::string;

class Iprogress {
public:
	virtual void doProgress(double value) = 0;
	virtual ~Iprogress(){}
};

class FileSplitter {
	int m_fileNumber;
	string m_filePath;
	vector<Iprogress*> m_iprogressVector;
public:
	FileSplitter(const string& filePath,int fileNumber):m_fileNumber(fileNumber),
		m_filePath(filePath){}
	void add_iprogress(Iprogress* p) {
		m_iprogressVector.push_back(p);
	}
	void remove_iprogress(Iprogress* p) {
		auto iter = find(m_iprogressVector.begin(), m_iprogressVector.end(), p);
		if(iter != m_iprogressVector.end())
			m_iprogressVector.erase(iter);
	}
	void split() {
		//1.读取大文件

		//2.分批次向小文件中写入
		for (int i = 0; i <= m_fileNumber; i++) {
			if (!m_iprogressVector.empty()) {
				double value = (i + 1) / m_fileNumber;
				for (auto p : m_iprogressVector)p->doProgress(value);
			}
		}
	}
};

class Form {
	int a;
};

class MainForm :public Form ,public Iprogress{
	string textFilePath;
	int textFileNumber;
	//ProgreeBar* progressBar;
public:
	void button_click() {
		FileSplitter splitter(textFilePath, textFileNumber);
		ConsoleNotifier cn;

		splitter.add_iprogress(this);
		splitter.add_iprogress(&cn);
		
		splitter.split();
	}
	virtual void doProgress(double value) {
		//progressBar->setValue(value);
	}
};

class ConsoleNotifier :public Iprogress {
public:
	virtual void doProgress(double value) {

	}
};


