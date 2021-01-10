//“对象性能”模式
/*
	面向对象很好地解决了“抽象”的问题，但是必不可少地要付出一定的代价，
	对于通常情况来讲，面向对象的成本大都可以忽略不计。但是某些情况，
	面向对象所带来的成本必须谨慎处理。

	典型模式：
	1.Singleton
	2.Flyweight：享元模式
*/

/*
	Motivation
	在软件系统中，采用纯粹对象方案的问题在于大量细粒度的对象会很快充斥在系统中，
	从而带来很高的运行时代价-----主要指内存需求方面的代价。
	
	如何在避免大量细粒度对象问题的同时，让外部客户程序仍然能够透明地使用面向对象
	的方式来进行操作？
*/

/*
	模式定义：运用共享技术有效地支持大量细粒度的对象。
*/

/*
	要点总结：
	1.Flyweight主要解决面向对象的代价问题，一般不触及面向对象的抽象性问题。
	2.Flyweight采用对象共享的做法来降低系统中对象的个数，从而降低细粒度
	  对象给系统带来的内存压力。在具体实现方面，要注意对象状态的处理。
	3.对象的数量太大从而导致对象内存开销加大-----什么样的数量才算大？这需要
	  我们仔细的根据具体应用情况进行评估，而不是凭空臆断。
*/
#include<string>
#include<map>

using std::map;
using std::string;
class Font {
private:
	string key;
public:
	Font(const string& key) {

	}
};

class FontFactory {
private:
	map<string, Font*> fontPool;
public:
	Font* getFont(const string& key) {
		auto item = fontPool.find(key);
		if (item != fontPool.end())return fontPool[key];
		else {
			Font* font = new Font(key);
			fontPool[key] = font;
			return font;
		}
	}

	void clear() {

	}
};
