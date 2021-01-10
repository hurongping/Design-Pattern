//���������ܡ�ģʽ
/*
	�������ܺõؽ���ˡ����󡱵����⣬���Ǳز����ٵ�Ҫ����һ���Ĵ��ۣ�
	����ͨ������������������ĳɱ��󶼿��Ժ��Բ��ơ�����ĳЩ�����
	��������������ĳɱ������������

	����ģʽ��
	1.Singleton
	2.Flyweight����Ԫģʽ
*/

/*
	Motivation
	�����ϵͳ�У����ô�����󷽰����������ڴ���ϸ���ȵĶ����ܿ�����ϵͳ�У�
	�Ӷ������ܸߵ�����ʱ����-----��Ҫָ�ڴ�������Ĵ��ۡ�
	
	����ڱ������ϸ���ȶ��������ͬʱ�����ⲿ�ͻ�������Ȼ�ܹ�͸����ʹ���������
	�ķ�ʽ�����в�����
*/

/*
	ģʽ���壺���ù�������Ч��֧�ִ���ϸ���ȵĶ���
*/

/*
	Ҫ���ܽ᣺
	1.Flyweight��Ҫ����������Ĵ������⣬һ�㲻�����������ĳ��������⡣
	2.Flyweight���ö����������������ϵͳ�ж���ĸ������Ӷ�����ϸ����
	  �����ϵͳ�������ڴ�ѹ�����ھ���ʵ�ַ��棬Ҫע�����״̬�Ĵ���
	3.���������̫��Ӷ����¶����ڴ濪���Ӵ�-----ʲô�����������������Ҫ
	  ������ϸ�ĸ��ݾ���Ӧ���������������������ƾ���ܶϡ�
*/
#include<string>
#include<map>

using std::map;
using std::string;
class Font {
private:
	string key;
public:
	Font(const string& key) {

	}
};

class FontFactory {
private:
	map<string, Font*> fontPool;
public:
	Font* getFont(const string& key) {
		auto item = fontPool.find(key);
		if (item != fontPool.end())return fontPool[key];
		else {
			Font* font = new Font(key);
			fontPool[key] = font;
			return font;
		}
	}

	void clear() {

	}
};
