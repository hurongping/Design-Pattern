//“单一职责”模式
/*
	在软件组件的设计中，如果责任划分的不清晰，使用继承得到的结果往往是随着需求的
	变化，子类急剧膨胀，同时充斥着重复代码，这时候的关键是划清责任。

	典型模式：
	1.Decorator
	2.Bridge
*/

/*
	Motivation:
	在某些情况下我们可能会“过度地使用继承来扩展对象的功能”，由于继承为类型引入的
	静态特质，使得这种扩展方式缺乏灵活性，并且随着子类的增多（扩展功能的增多），
	各种子类的组合（扩展功能的组合）会导致更多子类的膨胀。

	如何使“对象功能的扩展”能够根据需要来动态地实现？同时避免“扩展功能的增多”
	带来的子类膨胀问题？从而使得任何“功能扩展变化”所导致的影响降为最低？
*/

/*
	定义：
	动态地给一个对象增加一些额外的职责。就增加功能而言，Decorator模式比生成子类
	（继承）更为灵活（消除重复代码&减少子类个数）。
*/

/*
	要点：
	通过采用组合而非继承的手法，Decorator模式实现了在运行时动态地扩展对象功能的
	能力，而且可以根据需要扩展多个功能。从而避免了使用继承带来的“灵活性差”和
	“多子类衍生问题”。

	Decorator类在接口上表现为IS-A Component的继承关系，即Decorator类继承了
	Component类所具有的接口。但在实现上又表现为has-a Component的组合关系，即
	Decorator类又使用了另外一个Component类。

	Decorator模式的目的并非解决“多子类衍生的多继承”问题，Decorator模式应用的
	要点在于解决“主体类在多个方向上的扩展功能”-----是为“装饰”的含义。
*/

class Stream {
public:
	virtual void read(int number) = 0;
	virtual void seek(int position) = 0;
	virtual void write(char data) = 0;
};

class FileStream :public Stream {
public:
	virtual void read(int number) {

	}
	virtual void seek(int position) {

	}
	virtual void write(char data) {

	}
};


class MemoryStream :public Stream {
public:
	virtual void read(int number) {

	}
	virtual void seek(int position) {

	}
	virtual void write(char data) {

	}
};

class NetworkStream :public Stream {
public:
	virtual void read(int number) {

	}
	virtual void seek(int position) {

	}
	virtual void write(char data) {

	}
};

class DecoratorStream :public Stream {
protected:
	Stream* stream;
	DecoratorStream(Stream* stm):stream(stm){}
};

//装饰类扩展操作
class CryptoStream:public DecoratorStream {
public:
	CryptoStream(Stream* stm) :DecoratorStream(stm) {}

	virtual void read(int number) {
		//额外的加密操作
		stream->read(number);
	}
	virtual void seek(int position) {
		//额外的加密操作
		stream->seek(position);
		//额外的加密操作
	}
	virtual void write(char data) {
		//额外的加密操作
		stream->write(data);
		//额外的加密操作
	}
};

class BufferedStream :public DecoratorStream {
public:
	BufferedStream(Stream* stm):DecoratorStream(stm){}
	virtual void read(int number) {
		//额外的加密操作
		stream->read(number);
	}
	virtual void seek(int position) {
		//额外的加密操作
		stream->seek(position);
		//额外的加密操作
	}
	virtual void write(char data) {
		//额外的加密操作
		stream->write(data);
		//额外的加密操作
	}
};

void process() {
	FileStream* fs = new FileStream();
	CryptoStream* cs = new CryptoStream(fs); //加密文件流
	BufferedStream* bs = new BufferedStream(fs);//缓冲文件流
	BufferedStream* cbs = new BufferedStream(bs);//加密缓冲文件流
}



