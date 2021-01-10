//���������ܡ�ģʽ
/*
	�������ܺõؽ���ˡ����󡱵����⣬���Ǳز����ٵ�Ҫ����һ���Ĵ��ۣ�
	����ͨ������������������ĳɱ��󶼿��Ժ��Բ��ơ�����ĳЩ�����
	��������������ĳɱ������������

	����ģʽ��
	1.Singleton
	2.Flyweight
*/

/*
	Motivation
	�����ϵͳ�У�����������һЩ������࣬���뱣֤������ϵͳ��ֻ����һ��ʵ����
	����ȷ�����ǵ��߼���ȷ�ԡ��Լ����õ�Ч�ʡ�

	��Ӧ����������ߵ����Σ�������ʹ���ߵ�����
*/

/*
	ģʽ���壺��֤һ�������һ��ʵ�������ṩһ����ʵ����ȫ�ַ��ʵ㡣
*/

/*
	Ҫ���ܽ᣺
	1.Singletonģʽ�е�ʵ����������������Ϊprotected����������������
	2.Singletonģʽһ�㲻Ҫ֧�ֿ������캯����clone�ӿڣ���Ϊ����
	  ���ܵ��¶������ʵ��.
	3.���ʵ�ֶ��̻߳����°�ȫ��Singleton?ע���˫���������ȷʵ�֡�
*/

class Singleton {
private:
	Singleton();
	Singleton(const Singleton& other);
public:
	static Singleton* getInstance();
	static Singleton* m_instance;
};

Singleton* Singleton::m_instance = nullptr;

//�̷߳ǰ�ȫ�汾
Singleton* Singleton::getInstance() {
	if (m_instance == nullptr) {
		m_instance = new Singleton();
	}
	return m_instance;
}

//�̰߳�ȫ�汾�������Ĵ��۹���
Singleton* Singleton::getInstance() {
	//Lock lock;
	if (m_instance == nullptr) {
		m_instance = new Singleton();
	}
	return m_instance;
}

//˫��������������ڴ��дreorder����ȫ
Singleton* Singleton::getInstance() {
	if (m_instance == nullptr) {
		//Lock lock;
		if (m_instance == nullptr) {
			m_instance = new Singleton();
		}
	}
	return m_instance;
}

//c++ 11�汾֮��Ŀ�ƽ̨ʵ�֣�volatile)
/*
	std::atomic<Singleton*> Singleton::m_instance;
	std::mutex Singleton::m_mutex;
	
	Singleton* Singleton::getInstance(){
		Singleton* tmp = m_instance.load(std::memory_order_relaxed);
		std::atomic_thread_fence(std::memory_order_acquire);//��ȡ�ڴ�fence
		if(tmp == nullptr){
			std::lock_guard<std::mutex> lock(m_mutex);
			tmp = m_instance.load(std::memory_order_relaxed);
			if(tmp == nullptr){
				tmp = new Singleton;
				std::atomic_thread_fence(std::memory_order_release);//�ͷ��ڴ�fence
				m_instance.store(tmp,std::memory_order_relaxed);
			}
		}
		return tmp;
	}
*/