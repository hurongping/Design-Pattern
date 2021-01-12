//�����Э����ģʽ
/*
	�ִ����רҵ�ֹ�֮��ĵ�һ������ǡ������Ӧ�ó���֮��Ļ��֡��������Э����
	ģʽͨ�����ڰ󶨣���ʵ�ֿ����Ӧ��֮�������ϣ��Ƕ���֮��Э��ʱ���õ�ģʽ��

	����ģʽ
	1.Template Method
	2.Strategy
	3.Observer/Event
*/

/*
	Motivation:
	��������������У�������ҪΪĳЩ������һ�֡�֪ͨ������ϵ��--------һ������
	Ŀ����󣩵�״̬�����ı䣬���е��������󣨹۲��߶��󣩶����õ�֪ͨ�����������
	������ϵ���ڽ��ܣ���ʹ��������ܺܺõص����仯��

	ʹ����������������Խ�����������ϵ���������γ�һ���ȶ���������ϵ���Ӷ�ʵ��
	�����ϵ�ṹ������ϡ�
*/

/*
	���壺
		���������һ��һ�Զ��������ϵ���Ա㵱һ�������״̬�����ı�ʱ������
		�������Ķ��󶼵õ�֪ͨ���Զ����¡�
*/

/*
	ʹ���������ĳ���Observerģʽʹ�����ǿ��Զ����ظı�Ŀ����۲��ߣ��Ӷ�
	ʹ����֮���������ϵ�ﵽ�����

	Ŀ�귢��֪ͨʱ������ָ���۲��ߣ�֪ͨ������Я��֪ͨ��Ϣ��Ϊ���������Զ�����

	�۲����Լ������Ƿ���Ҫ����֪ͨ��Ŀ�����Դ�һ����֪��

	Observerģʽ�ǻ����¼���UI����зǳ����õ����ģʽ��Ҳ��MVCģʽ��һ��
	��Ҫ��ɲ��֡�
*/
#include<string>
#include<vector>

using std::vector;
using std::string;

class Iprogress {
public:
	virtual void doProgress(double value) = 0;
	virtual ~Iprogress(){}
};

class FileSplitter {
	int m_fileNumber;
	string m_filePath;
	vector<Iprogress*> m_iprogressVector;
public:
	FileSplitter(const string& filePath,int fileNumber):m_fileNumber(fileNumber),
		m_filePath(filePath){}
	void add_iprogress(Iprogress* p) {
		m_iprogressVector.push_back(p);
	}
	void remove_iprogress(Iprogress* p) {
		auto iter = find(m_iprogressVector.begin(), m_iprogressVector.end(), p);
		if(iter != m_iprogressVector.end())
			m_iprogressVector.erase(iter);
	}
	void split() {
		//1.��ȡ���ļ�

		//2.��������С�ļ���д��
		for (int i = 0; i <= m_fileNumber; i++) {
			if (!m_iprogressVector.empty()) {
				double value = (i + 1) / m_fileNumber;
				for (auto p : m_iprogressVector)p->doProgress(value);
			}
		}
	}
};

class Form {
	int a;
};

class MainForm :public Form ,public Iprogress{
	string textFilePath;
	int textFileNumber;
	//ProgreeBar* progressBar;
public:
	void button_click() {
		FileSplitter splitter(textFilePath, textFileNumber);
		ConsoleNotifier cn;

		splitter.add_iprogress(this);
		splitter.add_iprogress(&cn);
		
		splitter.split();
	}
	virtual void doProgress(double value) {
		//progressBar->setValue(value);
	}
};

class ConsoleNotifier :public Iprogress {
public:
	virtual void doProgress(double value) {

	}
};


