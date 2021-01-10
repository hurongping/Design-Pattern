//�����ݽṹ��ģʽ
/*
	������һЩ������ڲ������ض������ݽṹ������ÿͻ�����������Щ�ض������ݽṹ��
	��������ƻ�����ĸ��á���ʱ�򣬽���Щ�ض������ݽṹ��װ���ڲ������ⲿ�ṩ
	ͳһ�Ľӿڣ���ʵ�����ض����ݽṹ�޹صķ��ʣ���һ����֮��Ч�Ľ��������

	����ģʽ��
	1.Composite                �����ģʽ
	2.Iterator                 ��������
	3.Chain of Responsibility  ��ְ����
*/

/*
	Motivation:
	��������������У�һ��������ܱ��������������ÿ������������ʱֻ����һ��
	�����ߣ������ʾָ�������ز����ٵش�����������������ߵĽ���ϡ�

	���ʹ����ķ����߲���Ҫָ������Ľ����ߣ�������Ľ������Լ�������ʱ������
	�������󣬴Ӷ�ʹ���߽��
*/

/*
	���壺ʹ��������л��ᴦ�����󣬴Ӷ���������ķ����ߺͽ�����֮�����Ϲ�ϵ��
	����Щ��������һ��������������������������ֱ����һ����������Ϊֹ��
*/

/*
	Ҫ�㣺
	1.Chain of Responsibilityģʽ��Ӧ�ó������ڡ�һ����������ж�������ߣ�����
	  ��������Ľ�����ֻ��һ��������ʱ����������������ߵ�����п��ܳ��֡��仯
	  ��������֢״��ְ������Ŀ�ľ��ǽ����߽���Ӷ����õ�Ӧ�Ա仯��

	2.Ӧ����Chain of Responsibilityģʽ�󣬶����ְ����ɽ���������ԡ����ǿ�����
	  ����ʱ��̬���/�޸�����Ĵ���ְ��

	3.������󴫵ݵ�ְ������ĩβ�Եò�������Ӧ����һ�������ȱʡ���ơ���Ҳ��
	  ÿһ�����ܶ�������Σ������Ƿ�������Ķ�������Ρ�
*/

#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;
enum RequestType {
	REQ_HANDLER1,
	REQ_HANDLER2,
	REQ_HANDLER3
};

class Request {
	string description;
	RequestType reqType;
public:
	Request(const string &desc, RequestType type):description(desc),
		reqType(type){}
	RequestType getReqType()const { return reqType; }
	const string& getDescription()const { return description; }
};

class ChainHandler {
	ChainHandler* nextChain;
	void sendRequestToNextHandler(const Request& req) {
		if (nextChain != nullptr)nextChain->handle(req);
	}
protected:
	virtual bool canHandleRequest(const Request& req) = 0;
	virtual void processRequest(const Request& req) = 0;
public:
	ChainHandler() { nextChain = nullptr; }
	void setNextChain(ChainHandler* next) { nextChain = next; }
	void handle(const Request& req) {
		if (canHandleRequest(req))
			processRequest(req);
		else
			sendRequestToNextHandler(req);
	}
};

class Handler1 :public ChainHandler {
protected:
	virtual bool canHandleRequest(const Request& req)override {
		return req.getReqType() == RequestType::REQ_HANDLER1;
	}
	virtual void processRequest(const Request& req) {
		cout << "handle1 is handle request: " << req.getDescription() << endl;
	}
};

class Handler2 :public ChainHandler {
protected:
	virtual bool canHandleRequest(const Request& req)override {
		return req.getReqType() == RequestType::REQ_HANDLER2;
	}
	virtual void processRequest(const Request& req) {
		cout << "handle2 is handle request: " << req.getDescription() << endl;
	}
};

class Handler3 :public ChainHandler {
protected:
	virtual bool canHandleRequest(const Request& req)override {
		return req.getReqType() == RequestType::REQ_HANDLER3;
	}
	virtual void processRequest(const Request& req) {
		cout << "handle3 is handle request: " << req.getDescription() << endl;
	}
};

int main()
{
	Handler1 h1;
	Handler2 h2;
	Handler3 h3;
	h1.setNextChain(&h2);
	h2.setNextChain(&h3);

	Request req("process task ...", RequestType::REQ_HANDLER3);
	h1.handle(req);
	
	return 0;
}
