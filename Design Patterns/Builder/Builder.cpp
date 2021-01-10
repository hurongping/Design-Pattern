//对象创建模式：motivation
/*
	在软件系统中，有时候面临着“一个复杂对象”的创建工作，其通常由各个部分
	的子对象用一定的算法构成：由于需求的变化，这个复杂对象的各个部分经常面临着
	剧烈的变化，但是将它们组合在一起的算法却相对稳定。
	1.Factory Method
	2.Abstract Factory
	3.Prototype
	4.Builder
*/
/*
	模式定义：
	将一个复杂对象的构建与其表示相分离，使得同样的构建过程（稳定）
	可以创建不同的表示（变化）。
*/

/*
	要点总结：
	1.主要用于“分步骤构建一个复杂的对象”。在这其中“分步骤”是一个稳定的算法，
	  而复杂对象的各个部分则经常变化。

	2.变化在哪里，封装哪里-----builder模式主要在于应对“复杂对象各个部分”的
	  频繁需求变动。其缺点在于难以应对“分步骤构建算法”的需求变动。

	3.需要注意不同语言中构造器内调用虚函数的差别
	 （c++类的构造函数不允许调用自己类的虚函数）。
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
