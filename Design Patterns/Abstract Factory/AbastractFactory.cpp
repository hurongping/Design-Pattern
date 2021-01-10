//对象创建模式：motivation
/*
	在软件系统中，经常面临着“一系列相互依赖的对象”的创建工作；
	同时由于需求的变化，往往存在更多系列对象的创建工作。
	1.Factory Method
	2.Abstract Factory
	3.Prototype
	4.Builder
*/
/*
	模式定义：
	提供一个接口，让该接口负责创建一系列“相关或者相互依赖的对象”，
	无需指定它们具体的类。
*/

/*
	要点总结：
	1.如果没有应对“多系列对象构建”的需求变化，则没有必要使用Abstract 
	  Factory模式，这时使用简单的工厂完全可以。

	2.“系列对象”指的是在某一特定系列下的对象之间有相互依赖、或作用的关系。
	  不同系列的对象之间不能相互依赖。

	3.主要在于应对“新系列”的需求变动。其缺点在于难以应对“新对象”的需求变动。
*/
#include<vector>

using std::vector;
//业务抽象基类
class IDBConnection {

};

class IDBCommand {

};

class IDBDataReader {

};

//三个抽象基类存在紧密联系，合成一个抽象工厂，创建这些基类
class IDBFactory {
public:
	virtual IDBConnection* createDBConnection() = 0;
	virtual IDBCommand* createDBCommand() = 0;
	virtual IDBDataReader* createDataReader() = 0;
};

//专门隶属于Orancle的具体业务类型
class OrancleConnection :public IDBConnection {

};

class OrancleCommand :public IDBCommand {

};

class OrancleDataReader :public IDBDataReader {

};

//用于创建orancle对象的工厂
class OrancleDBFactory :public IDBFactory {
public:
	virtual IDBConnection* createDBConnection() {
		return new OrancleConnection();
	}
	virtual IDBCommand* createDBCommand(){
		return new OrancleCommand();
	}
	virtual IDBDataReader* createDataReader() {
		return new OrancleDataReader();
	}
};

//专门隶属于sql的具体业务类型
class SqlConnection :public IDBConnection {

};

class SqlCommand :public IDBCommand {

};

class SqlDataReader :public IDBDataReader {

};

//用于创建sql对象的工厂
class SqlDBFactory :public IDBFactory {
public:
	virtual IDBConnection* createDBConnection() {
		return new SqlConnection();
	}
	virtual IDBCommand* createDBCommand() {
		return new SqlCommand();
	}
	virtual IDBDataReader* createDataReader() {
		return new SqlDataReader();
	}
};


class EmployeeDAO {
	IDBFactory* dbFactory;
public:
	vector<EmployeeDAO> GetEmployees() {
		IDBConnection* connection = dbFactory->createDBConnection();
		//connection->ConnectionString("...")

		IDBCommand* command = dbFactory->createDBCommand();
		//command->CommandText("...")
		//command->SetConnection(connection);

		//IDBDataReader* reader = command->ExecuteReader();
	}
};

