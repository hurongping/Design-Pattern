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
	���������������,ĳЩ����ʹ�õ��㷨���ܶ��ֶ����������ı䣬�������Щ�㷨��
	���뵽�����У�����ʹ�ö������쳣���ӣ�������ʱ��֧�ֲ�ʹ�õ��㷨Ҳ��һ��
	���ܸ�����

	���������ʱ������Ҫ͸���ظ��Ķ�����㷨�����㷨����������Ӷ���������
	���⣿
*/

/*
	���壺
		����һϵ���㷨��������һ������װ����������ʹ���ǿɻ����滻���仯������
		ģʽʹ���㷨�ɶ�����ʹ�����Ŀͻ������ȶ������仯����չ�����໯����
*/

/*
	Strategy��������Ϊ����ṩ��һϵ�п����õ��㷨���Ӷ�����ʹ������������ʱ
	����ظ�����Ҫ�ڸ����㷨֮������л���

	Strategyģʽ�ṩ���������ж�����������һ��ѡ�����������ж���䣬����
	�ڽ���ϡ�������������ж����Ĵ���ͨ������ҪStrategyģʽ

	���Strategy����û��ʵ����������ô���������Ŀ��Թ���ͬһ��Strategy����
	�Ӷ���ʡ��������
*/

class Context {
public:
	int n;
};

class TaxStrategy {	
public:
	virtual double calculate(const Context& context) = 0;
	virtual ~TaxStrategy(){}
};

class StrategyFactory {
public:
	virtual TaxStrategy* newStrategy() = 0;
};

class CNTax :public TaxStrategy {
public:
	virtual double calculate(const Context& context) {

	}
};

class CNStrategyFactory:public StrategyFactory {
public:
	virtual TaxStrategy* newStrategy() {
		return new CNTax();
	}
};

class USTax :public TaxStrategy {
public:
	virtual double calculate(const Context& context) {

	}
};

class USStrategyFactory :public StrategyFactory {
public:
	virtual TaxStrategy* newStrategy() {
		return new USTax();
	}
};

class DETax :public TaxStrategy {
public:
	virtual double calculate(const Context& context) {

	}
};

class DEStrategyFactory :public StrategyFactory {
public:
	virtual TaxStrategy* newStrategy() {
		return new DETax();
	}
};

class SalesOrder {
private:
	TaxStrategy* strategy;
public:
	SalesOrder(StrategyFactory* strategyFactory) {
		strategy = strategyFactory->newStrategy();
	}
	~SalesOrder(){
		delete strategy;
	}
public:
	double calculate() {
		Context context;
		double val = strategy->calculate(context);//��̬����
		//....
	}
};



