//���󴴽�ģʽ��motivation
/*
	�����ϵͳ�У����������Ŵ�������Ĺ���������������ı仯��
	��Ҫ�����ľ������;����仯
	1.Factory Method
	2.Abstract Factory
	3.Prototype
	4.Builder
*/
/*
	ģʽ���壺
	����һ�����ڴ�������Ľӿڣ����������ʵ������һ���ࡣ
*/

/*
	Ҫ���ܽ᣺
	1.���ڸ���������ʹ���ߺ;�������֮�����Ϲ�ϵ�����һ��
	�����仯�ľ������ͣ�����Ϲ�ϵ�ᵼ������Ĵ�����

	2.ͨ�����������ַ�������Ҫ�����������Ĺ����ӳٵ����࣬�Ӷ�ʵ��
	һ����չ�Ĳ��ԣ��Ϻõؽ�������ֽ���Ϲ�ϵ��

	3.������������󡱵�����仯��ȱ������Ҫ�󴴽�����/������ͬ��
*/


//����ĳ������
class ISplitter {
public:
	virtual void split() = 0;
	virtual ~ISplitter(){}
};
//��������Ĺ�������
class SplitterFactory {
public:
	virtual ISplitter* createSplitter() = 0;
	virtual ~SplitterFactory(){}
};

//������
class BinarySplitter :public ISplitter {
public:
	BinarySplitter() = default;
	void split() {

	}
};

class TextSplitter :public ISplitter {
public:
	TextSplitter() = default;
	void split() {

	}
};

class PictureSplitter :public ISplitter {
public:
	PictureSplitter() = default;
	void split() {

	}
};

class VideoSplitter :public ISplitter {
public:
	VideoSplitter() = default;
	void split() {

	}
};

//���幤��
class BinarySplitterFactory :public SplitterFactory {
public:
	virtual ISplitter* createSplitter() {
		return new BinarySplitter();
	}
};

class TextSplitterFactory :public SplitterFactory {
public:
	virtual ISplitter* createSplitter() {
		return new TextSplitter();
	}
};

class PictureSplitterFactory :public SplitterFactory {
public:
	virtual ISplitter* createSplitter() {
		return new PictureSplitter();
	}
};

class VideoSplitterFactory :public SplitterFactory {
public:
	virtual ISplitter* createSplitter() {
		return new VideoSplitter();
	}
};

//����ӿ�
class Form {
	int a;
};

class SplitterFactory;
class MainForm :public Form {
	SplitterFactory* factory;//��ָ̬��
public:
	MainForm(SplitterFactory* fty):factory(fty){}
	void buttonClick() {
		ISplitter* splitter = factory->createSplitter();
		splitter->split();
	}
};


