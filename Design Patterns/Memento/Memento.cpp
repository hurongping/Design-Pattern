//“状态变化”模式
/*
	在组件构建过程中，某些对象的状态经常面临变化，如何对这些变化进行有效的管理？
	同时又维持高层模块的稳定？“状态变化”模式为这一问题提供了一种解决方案。

	典型模式：
	1.State          ：状态模式
	2.Memento        ：备忘录
*/

/*
	在软件构建过程中，某些对象的状态在转换过程中，可能由于某种需要，要求程序能够
	回溯到对象之前处于某个点时的状态。如果使用一些共有接口来让其他对象得到对象的
	状态，便会暴露对象的细节实现。

	如何实现对象状态的良好保存与恢复?但同时又不会因此而破坏对象本身的封装性。
*/

/*
	定义：在不破坏封装性的前提下，捕获一个对象的内部状态，并在该对象之外保存
	      这个状态。这样以后就可以将该对象恢复到原先保存的状态。
*/

/*
	要点总结：
	1.备忘录（Memento)存储原发器（originator）对象的内部状态，在需要时恢复原发器
	  状态。

	2.Memento模式的核心是信息隐藏，即Originator需要向外界隐藏信息，保持其封装性。
	  但同时又需要将状态保持到外界（Memento）。

	3.由于现代语言运行时都具有相当的对象序列化支持，因此往往采用效率较高、又较
	  容易正确实现的序列化方案来实现Memento模式。
*/
#include<string>

using std::string;

class Memento {
	string state;
public:
	Memento(const string& s):state(s){}
	string getState()const { return state; }
	void setState(const string& s) { state = s; }
};

class Originator {
	string state;
public:
	Originator(){}
	Memento createMemento() {
		Memento m(state);
		return m;
	}
	void setMemento(const Memento& m) {
		state = m.getState();
	}
};

int main()
{
	Originator orginator;
	//创建到备忘录
	Memento mem = orginator.createMemento();

	//改变orginator的状态

	//从备忘录恢复到之前的状态
	orginator.setMemento(mem);

	return 0;
}
