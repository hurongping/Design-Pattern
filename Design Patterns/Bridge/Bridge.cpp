//����һְ��ģʽ
/*
	��������������У�������λ��ֵĲ�������ʹ�ü̳еõ��Ľ�����������������
	�仯�����༱�����ͣ�ͬʱ������ظ����룬��ʱ��Ĺؼ��ǻ������Ρ�

	����ģʽ��
	1.Decorator
	2.Bridge
*/

/*
	Motivation:
	����ĳЩ���͵Ĺ��е�ʵ���߼���ʹ�����Ǿ��������仯��ά�ȣ��������ά�ȵı仯��

	���Ӧ�����֡���ά�ȵı仯����������������������ʹ�����Ϳ������ɵ�����
	���������������仯�������������ĸ��Ӷȣ�
*/

/*
	���壺
	�����󲿷֣�ҵ���ܣ���ʵ�ֲ��֣�ƽ̨ʵ�֣����룬ʹ���Ƕ����Զ����ر仯��
*/

/*
	Ҫ�㣺
	Bridgeģʽʹ�á���������Ϲ�ϵ�������˳�����ʵ��֮����еİ󶨹�ϵ��ʹ��
	�����ʵ�ֿ������Ÿ��Ե�ά�����仯����ν�����ʵ�����Ÿ���ά�ȵı仯������
	���໯�����ǡ�

	Bridgeģʽ��ʱ�������ڶ�̳з��������Ƕ�̳з�������Υ����һְ��ԭ�򣨼�һ��
	��ֻ��һ���仯��ԭ�򣩣������ԱȽϲBridgeģʽ�Ǳȶ�̳з������õĽ��������

	Bridgeģʽ��Ӧ��һ���ڡ������ǳ�ǿ�ı仯ά�ȡ�����ʱһ����Ҳ�ж��������ı仯
	ά�ȣ���ʱ����ʹ��Bridge��չģʽ��
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


//ƽ̨ʵ��
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

//ҵ����� m
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
	Message* m = new MessageLite(mImp); //PC�汾�ļ򻯰�
}


