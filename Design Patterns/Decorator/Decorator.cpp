//����һְ��ģʽ
/*
	��������������У�������λ��ֵĲ�������ʹ�ü̳еõ��Ľ�����������������
	�仯�����༱�����ͣ�ͬʱ������ظ����룬��ʱ��Ĺؼ��ǻ������Ρ�

	����ģʽ��
	1.Decorator
	2.Bridge
*/

/*
	Motivation:
	��ĳЩ��������ǿ��ܻᡰ���ȵ�ʹ�ü̳�����չ����Ĺ��ܡ������ڼ̳�Ϊ���������
	��̬���ʣ�ʹ��������չ��ʽȱ������ԣ�����������������ࣨ��չ���ܵ����ࣩ��
	�����������ϣ���չ���ܵ���ϣ��ᵼ�¸�����������͡�

	���ʹ�������ܵ���չ���ܹ�������Ҫ����̬��ʵ�֣�ͬʱ���⡰��չ���ܵ����ࡱ
	�����������������⣿�Ӷ�ʹ���κΡ�������չ�仯�������µ�Ӱ�콵Ϊ��ͣ�
*/

/*
	���壺
	��̬�ظ�һ����������һЩ�����ְ�𡣾����ӹ��ܶ��ԣ�Decoratorģʽ����������
	���̳У���Ϊ�������ظ�����&���������������
*/

/*
	Ҫ�㣺
	ͨ��������϶��Ǽ̳е��ַ���Decoratorģʽʵ����������ʱ��̬����չ�����ܵ�
	���������ҿ��Ը�����Ҫ��չ������ܡ��Ӷ�������ʹ�ü̳д����ġ�����Բ��
	���������������⡱��

	Decorator���ڽӿ��ϱ���ΪIS-A Component�ļ̳й�ϵ����Decorator��̳���
	Component�������еĽӿڡ�����ʵ�����ֱ���Ϊhas-a Component����Ϲ�ϵ����
	Decorator����ʹ��������һ��Component�ࡣ

	Decoratorģʽ��Ŀ�Ĳ��ǽ���������������Ķ�̳С����⣬DecoratorģʽӦ�õ�
	Ҫ�����ڽ�����������ڶ�������ϵ���չ���ܡ�-----��Ϊ��װ�Ρ��ĺ��塣
*/

class Stream {
public:
	virtual void read(int number) = 0;
	virtual void seek(int position) = 0;
	virtual void write(char data) = 0;
};

class FileStream :public Stream {
public:
	virtual void read(int number) {

	}
	virtual void seek(int position) {

	}
	virtual void write(char data) {

	}
};


class MemoryStream :public Stream {
public:
	virtual void read(int number) {

	}
	virtual void seek(int position) {

	}
	virtual void write(char data) {

	}
};

class NetworkStream :public Stream {
public:
	virtual void read(int number) {

	}
	virtual void seek(int position) {

	}
	virtual void write(char data) {

	}
};

class DecoratorStream :public Stream {
protected:
	Stream* stream;
	DecoratorStream(Stream* stm):stream(stm){}
};

//װ������չ����
class CryptoStream:public DecoratorStream {
public:
	CryptoStream(Stream* stm) :DecoratorStream(stm) {}

	virtual void read(int number) {
		//����ļ��ܲ���
		stream->read(number);
	}
	virtual void seek(int position) {
		//����ļ��ܲ���
		stream->seek(position);
		//����ļ��ܲ���
	}
	virtual void write(char data) {
		//����ļ��ܲ���
		stream->write(data);
		//����ļ��ܲ���
	}
};

class BufferedStream :public DecoratorStream {
public:
	BufferedStream(Stream* stm):DecoratorStream(stm){}
	virtual void read(int number) {
		//����ļ��ܲ���
		stream->read(number);
	}
	virtual void seek(int position) {
		//����ļ��ܲ���
		stream->seek(position);
		//����ļ��ܲ���
	}
	virtual void write(char data) {
		//����ļ��ܲ���
		stream->write(data);
		//����ļ��ܲ���
	}
};

void process() {
	FileStream* fs = new FileStream();
	CryptoStream* cs = new CryptoStream(fs); //�����ļ���
	BufferedStream* bs = new BufferedStream(fs);//�����ļ���
	BufferedStream* cbs = new BufferedStream(bs);//���ܻ����ļ���
}



