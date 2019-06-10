#include <iostream>
using namespace std;

//HeroFihgter AdvHeroFighter EnemyFighter

class HeroFighter
{
public:
	virtual int power()//��virtual�ؼ��֣�c++�������������⴦��
	{
		return 10;
	}
};

class EnemyFighter
{
public:
	int attack()
	{
		return 15;
	}
};

class AdvHeroFighter : public HeroFighter
{
public:
	virtual int power()
	{
		return 20;
	}
};

class AdvAdvHeroFighter : public HeroFighter
{
public:
	virtual int power()
	{
		return 30;
	}
};

//��̬������
//1.PlayObj��������̨ ��������һ�����
void PlayObj(HeroFighter *hf, EnemyFighter *ef)
{
	//��дvirtual�ؼ��ֻ��Ǿ�̬���� c++����������HeroFighter�࣬ȥִ��������power���� �ڱ���������׶ξ;����˺����ĵ���
	//��̬���࣬�ٰ󶨣������е�ʱ�򣬸��ݾ�����󣨾�������ͣ���ִ�в�ͬ����ĺ��������ֳɶ�̬
	if (hf->power() > ef->attack()) //hf->power()�������û��ж�̬����
	{
		printf("����win\n");
	}
	else
	{
		printf("���ǹ���\n");
	}
}

//��̬��˼��
//��������3�����
//��װ��ͻ����c���Ժ����ĸ���...����������������ʱ�򣬿���ʹ�ö�������ԣ��Ͷ���ķ���
//�̳У�A�� B��̳�A����Դ��븴��
//��̬�������̳У�������ʹ��δ��

//��̬����Ҫ
//c���� ��Ӹ�ֵ ��ָ����ڵ��������
//��c�������е�����1.������������ 2.�������� 3.*p�ڱ����ú�����ȥ��ӵ��޸�ʵ�ε�ֵ��


//ʵ�ֶ�̬��3����������������������õ�������
//1.Ҫ�м̳�
//2.Ҫ���麯����д
//3.�ø���ָ�루�������ã�ָ���������

void main()
{
	HeroFighter		hf;
	AdvHeroFighter	Advhf;
	EnemyFighter	ef;

	PlayObj(&hf, &ef);
	PlayObj(&Advhf, &ef);

	AdvAdvHeroFighter advadvhf;
	
	PlayObj(&advadvhf, &ef);//�����ܿ��԰����Ǻ�����д�Ĵ��룬����������
	

	cout << "hello..." << endl;
	return;

}

void main1401()
{
	HeroFighter		hf;
	AdvHeroFighter	Advhf;
	EnemyFighter	ef;

	if (hf.power() > ef.attack())
	{
		printf("����win\n");
	}
	else
	{
		printf("���ǹ���\n");
	}

	if (Advhf.power() > ef.attack())
	{
		printf("Advhf����win\n");
	}
	else
	{
		printf("Advhf���ǹ���\n");
	}

	cout << "hello..." << endl;
	
	return;
}
