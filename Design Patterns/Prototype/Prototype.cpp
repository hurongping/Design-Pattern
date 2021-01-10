//���󴴽�ģʽ��motivation
/*
	�����ϵͳ�У����������š�ĳЩ�ṹ���ӵĶ��󡱵Ĵ���������
	ͬʱ��������ı仯����Щ���󾭳������ž��ҵı仯����������ȴӵ�бȽ�
	�ȶ�һ�µĽӿڡ�
	1.Factory Method
	2.Abstract Factory
	3.Prototype
	4.Builder
*/
/*
	ģʽ���壺
	ʹ��ԭ��ʵ��ָ��������������࣬Ȼ��ͨ��������Щԭ���������µĶ���
*/

/*
	Ҫ���ܽ᣺
	1.���ڸ���������ʹ���ߺ;�������֮�����Ϲ�ϵ����ͬ��Ҫ����Щ���ױ��ࡱ
	  ӵ���ȶ��Ľӿڡ�

	2.Prototype���ڡ���δ����ױ����ʵ����󡱲��á�ԭ�Ϳ�¡���ķ���������
	  ��ʹ�����ǿ��Էǳ����ض�̬������ӵ��ĳЩ�ȶ��ӿڡ����¶���----���蹤��
	  ������ע��һ������Ķ��󣨼�ԭ�ͣ���Ȼ�����κ���Ҫ�ĵط�clone��

	3.Prototypeģʽ�е�clone������������ĳЩ����е����л���ʵ�������
*/

//����ĳ������
class ISplitter {
public:
	virtual void split() = 0;
	virtual ISplitter* clone() = 0;
	virtual ~ISplitter() {}
};

//������
class BinarySplitter :public ISplitter {
public:
	BinarySplitter() = default;
	void split() {

	}
	virtual ISplitter* clone() {
		return new BinarySplitter(*this);
	}
};

class TextSplitter :public ISplitter {
public:
	TextSplitter() = default;
	void split() {

	}
	virtual ISplitter* clone() {
		return new TextSplitter(*this);
	}
};

class PictureSplitter :public ISplitter {
public:
	PictureSplitter() = default;
	void split() {

	}
	virtual ISplitter* clone() {
		return new PictureSplitter(*this);
	}
};

class VideoSplitter :public ISplitter {
public:
	VideoSplitter() = default;
	void split() {

	}
	virtual ISplitter* clone() {
		return new VideoSplitter(*this);
	}
};

//����ӿ�
class Form {
	int a;
};

class SplitterFactory;
class MainForm :public Form {
	ISplitter* prototype;//ԭ�Ͷ���
public:
	MainForm(ISplitter* pte) :prototype(pte) {}
	void buttonClick() {
		ISplitter* splitter = prototype->clone();
		splitter->split();
	}
};
