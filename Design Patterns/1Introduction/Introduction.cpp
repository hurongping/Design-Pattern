/*
	课程目标：
	1.理解松耦合设计思想

	2.掌握面向对象设计原则

	3.掌握重构技法改善设计

	4.掌握GOF核心设计模式
*/

/*
	设计模式定义：
	每一个模式描述了一个在我们周围不断重复发生的以及该问题的解决方案的核心。这样，
	你就能一次性地使用该方案而不必做重复劳动。
*/

/*
	底层思维：语言构造、编译转换、内存模型、运行时机制

	抽象思维：面向对象、组件封装、设计模式、架构模式
*/

/*
	深入理解面向对象
	向下：深入理解三大面向对象机制：封装、继承、多态
	向上：深刻把握面向对象机制所带来的抽象意义，理解如何使用这些机制来表达现实
	      世界，掌握什么是“好的面向对象设计”。
*/

/*
	软件设计复杂的根本原因：变化
	客户需求的变化
	技术平台的变化
	开发团队的变化
	市场环境的变化
*/

/*
	如何解决复杂性：
	分解：人们面对复杂性有一个常见的做法：即分而治之，将大问题分解为多个小问题，
	      将复杂问题分解为多个简单问题。

	抽象：更高层次来讲，人们处理复杂性有一个通用的技术，即抽象。由于不能掌握全部
	      的复杂对象，我们选择忽视它的非本质细节而去处理泛化和理想化了的对象模型。
*/

/*
	什么是好的软件设计？软件设计的金科玉律：复用
*/

#include<vector>

using std::vector;

class Shape {
public:
	//virtual void Draw(const Graphics& g) = 0;
	virtual ~Shape(){}
};

class Point {
public:
	int x;
	int y;
};

class Line :public Shape {
public:
	Point start;
	Point end;

	Line(const Point& start_, const Point& end_):start(start_),end(end_){}
	/*
	virtual void Draw(const Graphics& g) {
		g.DrawLine(Pens.Red,start.x,start.y,end.x,end.y);
	}
	*/
};

class Rect :public Shape {
public:
	Point leftUp;
	int width;
	int height;

	Rect(const Point& leftUp_, int width_, int height_) :leftUp(leftUp_),
		width(width_),height(height_){}

	/*
	virtual void Draw(const Graphics& g){
		g.DrawRectangle(Pens.Red,leftUp,width,height);
	}
	*/
};

class Form {
	int x;
};
class MainForm :public Form {
private:
	Point p1;
	Point p2;

	vector<Shape*> shapeVector;
public:
	MainForm() = default;
protected:
	/*
	virtual void OnMouseDown(const MouseEventArgs& e);
	virtual void OnMouseUp(const MouseEventArgs& e);
	virtual void OnPaint(const PaintEventArgs& e);
	*/
};

/*
void MainForm::OnMouseDown(const MouseEventArgs& e){
	p1.x = e.x;
	p1.y = e.y;

	//...
	Form::OnMouseDown(e);
}

void MainForm::OnMouseUp(const MouseEventArgs& e){
	p2.x = e.x;
	p2.y = e.y;

	if(rdoLine.Checked){
		shapeVector.push_back(new Line(p1,p2));
	}
	else if(rdoRect.Checked){
		int width = abs(p2.x - p1.x);
		int height = abs(p2.y - p1.y);
		shapeVector.push_back(new Rect(p1,width,height));
	}

	//...
	this->Refresh();

	Form::OnMouseUp(e);
}
*/

