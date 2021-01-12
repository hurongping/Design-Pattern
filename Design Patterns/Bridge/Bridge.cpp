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
	由于某些类型的固有的实现逻辑，使得它们具有两个变化的维度，乃至多个维度的变化。

	如何应对这种“多维度的变化”？如何利用面向对象技术来使得类型可以轻松地沿着
	两个乃至多个方向变化，而不引入额外的复杂度？
*/

/*
	定义：
	将抽象部分（业务功能）与实现部分（平台实现）分离，使它们都可以独立地变化。
*/

/*
	要点：
	Bridge模式使用“对象间的组合关系”解耦了抽象与实现之间固有的绑定关系，使得
	抽象和实现可以沿着各自的维度来变化。所谓抽象和实现沿着各自维度的变化，即“
	子类化”它们。

	Bridge模式有时候类似于多继承方案，但是多继承方案往往违背单一职责原则（即一个
	类只有一个变化的原因），复用性比较差。Bridge模式是比多继承方案更好的解决方法。

	Bridge模式的应用一般在“两个非常强的变化维度”，有时一个类也有多于两个的变化
	维度，这时可以使用Bridge扩展模式。
*/
#include<string>

using std::string;

class MessageImp {
public:
	virtual void playSound() = 0;
	virtual void drawShape() = 0;
	virtual void writeText() = 0;
	virtual void connect() = 0;

	virtual ~MessageImp() {}
};

class Message {
protected:
	MessageImp* message;
public:
	Message(MessageImp* mip):message(mip){}
	virtual void login(string& username, string& password) = 0;
	virtual void sendMessage(string& message) = 0;
	virtual void sendPicture(string& img) = 0;

	virtual ~Message() {}
};


//平台实现
class PCMessageBase :public MessageImp {
public:
	virtual void playSound() {

	}
	virtual void drawShape() {

	}
	virtual void writeText() {

	}
	virtual void connect() {

	}
};

class MobileMessageBase :public MessageImp {
public:
	virtual void playSound() {

	}
	virtual void drawShape() {

	}
	virtual void writeText() {

	}
	virtual void connect() {

	}
};

//业务抽象 m
class MessageLite :public Message{
public:
	MessageLite(MessageImp* mImp):Message(mImp){}
	virtual void login(string& username, string& password) {
		message->connect();
		//.....
	}
	virtual void sendMessage(string& mge) {
		message->writeText();
		//....
	}
	virtual void sendPicture(string& img) {
		message->drawShape();
		//...
	}
};

class MessagePerfect :public Message {
public:
	MessagePerfect(MessageImp* mImp):Message(mImp){}
	virtual void login(string& username, string& password) {
		message->playSound();
		//*****
		message->connect();
		//.....
	}
	virtual void sendMessage(string& mge) {
		message->playSound();
		//*****
		message->writeText();
		//....
	}
	virtual void sendPicture(string& img) {
		message->playSound();
		//*****
		message->drawShape();
		//...
	}
};

void process() {
	MessageImp* mImp = new PCMessageBase();
	Message* m = new MessageLite(mImp); //PC版本的简化版
}


