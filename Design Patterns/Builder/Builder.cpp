//���󴴽�ģʽ��motivation
/*
	�����ϵͳ�У���ʱ�������š�һ�����Ӷ��󡱵Ĵ�����������ͨ���ɸ�������
	���Ӷ�����һ�����㷨���ɣ���������ı仯��������Ӷ���ĸ������־���������
	���ҵı仯�����ǽ����������һ����㷨ȴ����ȶ���
	1.Factory Method
	2.Abstract Factory
	3.Prototype
	4.Builder
*/
/*
	ģʽ���壺
	��һ�����Ӷ���Ĺ��������ʾ����룬ʹ��ͬ���Ĺ������̣��ȶ���
	���Դ�����ͬ�ı�ʾ���仯����
*/

/*
	Ҫ���ܽ᣺
	1.��Ҫ���ڡ��ֲ��蹹��һ�����ӵĶ��󡱡��������С��ֲ��衱��һ���ȶ����㷨��
	  �����Ӷ���ĸ��������򾭳��仯��

	2.�仯�������װ����-----builderģʽ��Ҫ����Ӧ�ԡ����Ӷ���������֡���
	  Ƶ������䶯����ȱ����������Ӧ�ԡ��ֲ��蹹���㷨��������䶯��

	3.��Ҫע�ⲻͬ�����й������ڵ����麯���Ĳ��
	 ��c++��Ĺ��캯������������Լ�����麯������
*/

class House {

};

class HouseDirector;

class HouseBuilder {
	friend class HouseDirector;
public:
	House* getResult() {
		return pHouse;
	}
	virtual ~HouseBuilder(){}
protected:
	House* pHouse;
	virtual void buildPart1() = 0;
	virtual void buildPart2() = 0;
	virtual bool buildPart3() = 0;
	virtual void buildPart4() = 0;
	virtual void buildPart5() = 0;
};

class StoneHouse :public House {

};

class StoneHouseBuilder :public HouseBuilder {
protected:
	virtual void buildpart1() {

	}
	virtual void buildpart2() {

	}
	virtual void buildpart3() {

	}
	virtual void buildpart4() {

	}
	virtual void buildpart5() {

	}
};

class HouseDirector {
public:
	HouseBuilder* pHouseBuilder;
	HouseDirector(HouseBuilder* phb):pHouseBuilder(phb){}
	House* construct() {
		pHouseBuilder->buildPart1();
		for (int i = 0; i < 4; i++) {
			pHouseBuilder->buildPart2();
		}
		bool flag = pHouseBuilder->buildPart3();
		if (flag) {
			pHouseBuilder->buildPart4();
		}
		pHouseBuilder->buildPart5();
		return pHouseBuilder->getResult();
	}
};
