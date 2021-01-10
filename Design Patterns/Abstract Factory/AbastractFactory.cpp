//���󴴽�ģʽ��motivation
/*
	�����ϵͳ�У����������š�һϵ���໥�����Ķ��󡱵Ĵ���������
	ͬʱ��������ı仯���������ڸ���ϵ�ж���Ĵ���������
	1.Factory Method
	2.Abstract Factory
	3.Prototype
	4.Builder
*/
/*
	ģʽ���壺
	�ṩһ���ӿڣ��øýӿڸ��𴴽�һϵ�С���ػ����໥�����Ķ��󡱣�
	����ָ�����Ǿ�����ࡣ
*/

/*
	Ҫ���ܽ᣺
	1.���û��Ӧ�ԡ���ϵ�ж��󹹽���������仯����û�б�Ҫʹ��Abstract 
	  Factoryģʽ����ʱʹ�ü򵥵Ĺ�����ȫ���ԡ�

	2.��ϵ�ж���ָ������ĳһ�ض�ϵ���µĶ���֮�����໥�����������õĹ�ϵ��
	  ��ͬϵ�еĶ���֮�䲻���໥������

	3.��Ҫ����Ӧ�ԡ���ϵ�С�������䶯����ȱ����������Ӧ�ԡ��¶��󡱵�����䶯��
*/
#include<vector>

using std::vector;
//ҵ��������
class IDBConnection {

};

class IDBCommand {

};

class IDBDataReader {

};

//�������������ڽ�����ϵ���ϳ�һ�����󹤳���������Щ����
class IDBFactory {
public:
	virtual IDBConnection* createDBConnection() = 0;
	virtual IDBCommand* createDBCommand() = 0;
	virtual IDBDataReader* createDataReader() = 0;
};

//ר��������Orancle�ľ���ҵ������
class OrancleConnection :public IDBConnection {

};

class OrancleCommand :public IDBCommand {

};

class OrancleDataReader :public IDBDataReader {

};

//���ڴ���orancle����Ĺ���
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

//ר��������sql�ľ���ҵ������
class SqlConnection :public IDBConnection {

};

class SqlCommand :public IDBCommand {

};

class SqlDataReader :public IDBDataReader {

};

//���ڴ���sql����Ĺ���
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

