//��״̬�仯��ģʽ
/*
	��������������У�ĳЩ�����״̬�������ٱ仯����ζ���Щ�仯������Ч�Ĺ���
	ͬʱ��ά�ָ߲�ģ����ȶ�����״̬�仯��ģʽΪ��һ�����ṩ��һ�ֽ��������

	����ģʽ��
	1.State          ��״̬ģʽ
	2.Memento        ������¼
*/

/*
	��������������У�ĳЩ�����״̬����ı䣬����ΪҲ����֮���仯�������ĵ�����
	ֻ��״̬����֧�ֵ���Ϊ�Ͷ�д״̬֧�ֵ���Ϊ�Ϳ�����ȫ��ͬ��

	���������ʱ���ݶ����״̬��͸���ظ��Ķ������Ϊ��������Ϊ���������״̬ת��
	֮���������ϡ�
*/

/*
	���壺����һ�����������ڲ�״̬�ı�ʱ�ı�������Ϊ���Ӷ�ʹ���������ƺ��޸���
	����Ϊ
*/

/*
	Ҫ���ܽ᣺
	1.Stateģʽ��������һ���ض�״̬��ص���Ϊ������һ��State����������У��ڶ���
	  ״̬�л�ʱ���л���Ӧ�Ķ��󣻵�ͬʱά��State�Ľӿڣ�����ʵ���˾��������״̬
	  ת��֮��Ľ��

	2.Ϊ��ͬ״̬���벻ͬ�Ķ���ʹ��״̬ת����ø�����ȷ�����ҿ��Ա�֤�������״̬
	  ��һ�µ��������Ϊ״̬ת����ԭ���Ե�------��Ҫô����ת��������Ҫô��ת����

	3.���State����û��ʵ����������ô���������Ŀ��Թ���ͬһ��State���󣬴Ӷ���ʡ
	  ��������
*/

class NetworkState {
public:
	NetworkState* pNext;
	virtual void operator1() = 0;
	virtual void operator2() = 0;
	virtual void operator3() = 0;

	virtual ~NetworkState(){}
};

class OpenState :public NetworkState {
	//singleton�ĳ���д��
	static NetworkState* m_instance;
	OpenState(){}
public:
	static NetworkState* getInstance() {
		if (m_instance == nullptr)m_instance = new OpenState();
		return m_instance;
	}
	//singleton����д��
	void operator1() {
		//**********************
		pNext = CloseState::getInstance();
	}

	void operator2() {
		pNext = ConnectState::getInstance();
	}

	void operator3() {
		//$$$$$$$$$$$$$
		pNext = OpenState::getInstance();
	}
};
NetworkState* OpenState::m_instance = nullptr;

class CloseState :public NetworkState {
	//singleton�ĳ���д��
	static NetworkState* m_instance;
	CloseState() {}
public:
	static NetworkState* getInstance() {
		if (m_instance == nullptr)m_instance = new CloseState();
		return m_instance;
	}
	//singleton����д��
	void operator1() {
		//**********************
		pNext = CloseState::getInstance();
	}

	void operator2() {
		pNext = ConnectState::getInstance();
	}

	void operator3() {
		//$$$$$$$$$$$$$
		pNext = OpenState::getInstance();
	}
};
NetworkState* CloseState::m_instance = nullptr;

class ConnectState :public NetworkState {
	//singleton�ĳ���д��
	static NetworkState* m_instance;
	ConnectState() {}
public:
	static NetworkState* getInstance() {
		if (m_instance == nullptr)m_instance = new ConnectState();
		return m_instance;
	}
	//singleton����д��
	void operator1() {
		//**********************
		pNext = CloseState::getInstance();
	}

	void operator2() {
		pNext = ConnectState::getInstance();
	}

	void operator3() {
		//$$$$$$$$$$$$$
		pNext = OpenState::getInstance();
	}
};
NetworkState* ConnectState::m_instance = nullptr;

