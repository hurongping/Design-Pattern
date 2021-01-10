//“数据结构”模式
/*
	常常有一些组件在内部具有特定的数据结构，如果让客户程序依赖这些特定的数据结构，
	将极大地破坏组件的复用。这时候，将这些特定的数据结构封装在内部，在外部提供
	统一的接口，来实现与特定数据结构无关的访问，是一种行之有效的解决方案。

	典型模式：
	1.Composite                ：组合模式
	2.Iterator                 ：迭代器
	3.Chain of Responsibility  ：职责链
*/

/*
	Motivation:
	在软件构建过程中，一个请求可能被多个对象处理，但是每个请求在运行时只能有一个
	接受者，如果显示指定，将必不可少地带来请求发送者与接受者的紧耦合。

	如何使请求的发送者不需要指定具体的接受者？让请求的接受者自己在运行时决定来
	处理请求，从而使两者解耦。
*/

/*
	定义：使多个对象都有机会处理请求，从而避免请求的发送者和接收者之间的耦合关系。
	将这些对象连成一条链，并沿着这条链传递请求，直到有一个对象处理它为止。
*/

/*
	要点：
	1.Chain of Responsibility模式的应用场合在于“一个请求可能有多个接受者，但是
	  最后真正的接受者只有一个”，这时候请求发送者与接受者的耦合有可能出现“变化
	  脆弱”的症状，职责链的目的就是将二者解耦，从而更好地应对变化。

	2.应用了Chain of Responsibility模式后，对象的职责分派将更具灵活性。我们可以在
	  运行时动态添加/修改请求的处理职责。

	3.如果请求传递到职责链的末尾仍得不到处理，应该有一个合理的缺省机制。这也是
	  每一个接受对象的责任，而不是发出请求的对象的责任。
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
