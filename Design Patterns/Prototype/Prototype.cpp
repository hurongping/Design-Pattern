//对象创建模式：motivation
/*
	在软件系统中，经常面临着“某些结构复杂的对象”的创建工作；
	同时由于需求的变化，这些对象经常面临着剧烈的变化，但是它们却拥有比较
	稳定一致的接口。
	1.Factory Method
	2.Abstract Factory
	3.Prototype
	4.Builder
*/
/*
	模式定义：
	使用原型实例指定创建对象的种类，然后通过拷贝这些原型来创建新的对象。
*/

/*
	要点总结：
	1.用于隔离类对象的使用者和具体类型之间的耦合关系，它同样要求这些“易变类”
	  拥有稳定的接口。

	2.Prototype对于“如何创建易变类的实体对象”采用“原型克隆”的方法来做，
	  它使得我们可以非常灵活地动态创建“拥有某些稳定接口”的新对象----所需工作
	  仅仅是注册一个新类的对象（即原型），然后在任何需要的地方clone。

	3.Prototype模式中的clone方法可以利用某些框架中的序列化来实现深拷贝。
*/

//对象的抽象基类
class ISplitter {
public:
	virtual void split() = 0;
	virtual ISplitter* clone() = 0;
	virtual ~ISplitter() {}
};

//具体类
class BinarySplitter :public ISplitter {
public:
	BinarySplitter() = default;
	void split() {

	}
	virtual ISplitter* clone() {
		return new BinarySplitter(*this);
	}
};

class TextSplitter :public ISplitter {
public:
	TextSplitter() = default;
	void split() {

	}
	virtual ISplitter* clone() {
		return new TextSplitter(*this);
	}
};

class PictureSplitter :public ISplitter {
public:
	PictureSplitter() = default;
	void split() {

	}
	virtual ISplitter* clone() {
		return new PictureSplitter(*this);
	}
};

class VideoSplitter :public ISplitter {
public:
	VideoSplitter() = default;
	void split() {

	}
	virtual ISplitter* clone() {
		return new VideoSplitter(*this);
	}
};

//抽象接口
class Form {
	int a;
};

class SplitterFactory;
class MainForm :public Form {
	ISplitter* prototype;//原型对象
public:
	MainForm(ISplitter* pte) :prototype(pte) {}
	void buttonClick() {
		ISplitter* splitter = prototype->clone();
		splitter->split();
	}
};
