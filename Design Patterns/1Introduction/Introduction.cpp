/*
	�γ�Ŀ�꣺
	1.�����������˼��

	2.��������������ԭ��

	3.�����ع������������

	4.����GOF�������ģʽ
*/

/*
	���ģʽ���壺
	ÿһ��ģʽ������һ����������Χ�����ظ��������Լ�������Ľ�������ĺ��ġ�������
	�����һ���Ե�ʹ�ø÷������������ظ��Ͷ���
*/

/*
	�ײ�˼ά�����Թ��졢����ת�����ڴ�ģ�͡�����ʱ����

	����˼ά��������������װ�����ģʽ���ܹ�ģʽ
*/

/*
	��������������
	���£���������������������ƣ���װ���̳С���̬
	���ϣ���̰��������������������ĳ������壬������ʹ����Щ�����������ʵ
	      ���磬����ʲô�ǡ��õ����������ơ���
*/

/*
	�����Ƹ��ӵĸ���ԭ�򣺱仯
	�ͻ�����ı仯
	����ƽ̨�ı仯
	�����Ŷӵı仯
	�г������ı仯
*/

/*
	��ν�������ԣ�
	�ֽ⣺������Ը�������һ�����������������ֶ���֮����������ֽ�Ϊ���С���⣬
	      ����������ֽ�Ϊ��������⡣

	���󣺸��߲�����������Ǵ���������һ��ͨ�õļ��������������ڲ�������ȫ��
	      �ĸ��Ӷ�������ѡ��������ķǱ���ϸ�ڶ�ȥ�����������뻯�˵Ķ���ģ�͡�
*/

/*
	ʲô�Ǻõ������ƣ������ƵĽ�����ɣ�����
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

