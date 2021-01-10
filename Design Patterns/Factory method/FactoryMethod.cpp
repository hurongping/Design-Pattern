//对象创建模式：motivation
/*
	在软件系统中，经常面临着创建对象的工作；但由于需求的变化，
	需要创建的具体类型经常变化
	1.Factory Method
	2.Abstract Factory
	3.Prototype
	4.Builder
*/
/*
	模式定义：
	定义一个用于创建对象的接口，让子类决定实例化哪一个类。
*/

/*
	要点总结：
	1.用于隔离类对象的使用者和具体类型之间的耦合关系。面对一个
	经常变化的具体类型，紧耦合关系会导致软件的脆弱。

	2.通过面向对象的手法，将所要创建具体对象的工作延迟到子类，从而实现
	一种扩展的策略，较好地解决了这种紧耦合关系。

	3.解决“单个对象”的需求变化。缺点在于要求创建方法/参数相同。
*/


//对象的抽象基类
class ISplitter {
public:
	virtual void split() = 0;
	virtual ~ISplitter(){}
};
//创建对象的工厂基类
class SplitterFactory {
public:
	virtual ISplitter* createSplitter() = 0;
	virtual ~SplitterFactory(){}
};

//具体类
class BinarySplitter :public ISplitter {
public:
	BinarySplitter() = default;
	void split() {

	}
};

class TextSplitter :public ISplitter {
public:
	TextSplitter() = default;
	void split() {

	}
};

class PictureSplitter :public ISplitter {
public:
	PictureSplitter() = default;
	void split() {

	}
};

class VideoSplitter :public ISplitter {
public:
	VideoSplitter() = default;
	void split() {

	}
};

//具体工厂
class BinarySplitterFactory :public SplitterFactory {
public:
	virtual ISplitter* createSplitter() {
		return new BinarySplitter();
	}
};

class TextSplitterFactory :public SplitterFactory {
public:
	virtual ISplitter* createSplitter() {
		return new TextSplitter();
	}
};

class PictureSplitterFactory :public SplitterFactory {
public:
	virtual ISplitter* createSplitter() {
		return new PictureSplitter();
	}
};

class VideoSplitterFactory :public SplitterFactory {
public:
	virtual ISplitter* createSplitter() {
		return new VideoSplitter();
	}
};

//抽象接口
class Form {
	int a;
};

class SplitterFactory;
class MainForm :public Form {
	SplitterFactory* factory;//多态指针
public:
	MainForm(SplitterFactory* fty):factory(fty){}
	void buttonClick() {
		ISplitter* splitter = factory->createSplitter();
		splitter->split();
	}
};


