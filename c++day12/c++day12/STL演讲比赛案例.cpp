#include <iostream>
using namespace std;

#include "string"
#include "set"
#include "functional"
#include <vector>
#include <algorithm>
#include <list>
#include "iterator"
#include <numeric>
#include <map>
#include <deque>

class Speaker
{
public:
	string m_name;
	int m_score[3];
protected:
private:
};

//产生选手
int GenSpeaker(map<int, Speaker> &mapSpeaker, vector<int> &v)
{
	string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	random_shuffle(str.begin(), str.end());

	for (int i = 0; i < 24; i++)
	{
		Speaker tmp;
		tmp.m_name = "选手";
		tmp.m_name = tmp.m_name + str[i];
		mapSpeaker.insert(pair<int, Speaker>(100 + i, tmp));//把选手的名字和编号放入容器里
	}

	for (int i = 0; i < 24; i++)//参加比赛的人员
	{
		v.push_back(100 + i);
	}
	return 0;
}

//选手抽签
int speech_contest_draw(vector<int> &v)
{
	random_shuffle(v.begin(), v.end());
	return 0;
}

//选手比赛
int speech_contest(int index, vector<int> &v1, map<int, Speaker> &mapSpeaker, vector<int> &v2)
{
	//小组的比赛得分给记录下来；求出前三名和后三名
	multimap<int, int, greater<int>> multmapGroup;//小组成绩 得分,编号
	int tmpCount = 0;//记录正在比赛的人数
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
	{
		tmpCount++;
		//打分
		{
			deque<int> dscore;
			for (int j = 0; j < 10; j++)//10位老师打分
			{
				int score = 50 + rand() % 50;
				dscore.push_back(score);
			}
			sort(dscore.begin(), dscore.end());
			dscore.pop_back();
			dscore.pop_front();//去除最低分和去除最高分

			//求平均分
			int scoresum = accumulate(dscore.begin(), dscore.end(), 0);
			int scoravg = scoresum / dscore.size();//去掉最高分和最低分后，剩下8位老师，此时dscore.size()为8
			mapSpeaker[*it].m_score[index] = scoravg;//选手得分 存入容器中
			multmapGroup.insert(pair<int, int>(scoravg, *it));//选手在这一轮比赛中的得分和编号
		}

		//处理分组
		if (tmpCount%6 == 0)
		{
			cout << "小组的比赛成绩" << endl;
			for (multimap<int, int, greater<int>>::iterator mit = multmapGroup.begin(); mit != multmapGroup.end(); mit++)
			{
				//编号 名字 得分
				cout << mit->second << "\t" << mapSpeaker[mit->second].m_name << "\t" << mit->first << endl;
			}
		}

		//前三名晋级
		while (multmapGroup.size() > 3)
		{
			multimap<int, int, greater<int>>::iterator it1 = multmapGroup.begin();
			v2.push_back(it1->second);//把前三名放到v2中，就是晋级名单
			multmapGroup.erase(it1);
		}

		multmapGroup.clear();//清空本小组 比赛成绩
		
	}

	return 0;
}

//查看比赛结果
int speech_contest_print(int index, vector<int> &v, map<int, Speaker> &mapSpeaker)
{
	printf("第%d轮 晋级名单\n", index + 1);
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << "参赛编号" << *it << "\t" << mapSpeaker[*it].m_name << "\t" << mapSpeaker[*it].m_score[index] << endl;
	}
	return 0;
}

void main()
{
	//容器的设计
	map<int, Speaker> mapSpeaker;//参加比赛的选手
	vector<int> v1;//第1轮参加比赛名单
	vector<int> v2;//第2轮参加比赛名单
	vector<int> v3;//第3轮参加比赛名单
	vector<int> v4;//最终参加比赛名单

	//产生选手 得到第一轮选手的比赛名单
	GenSpeaker(mapSpeaker, v1);

	//第1轮选手抽签 得到选手名单 查看比赛结果
	cout << "\n\n\n任意键，开始第一轮比赛" << endl;
	cin.get();
	speech_contest_draw(v1);
	speech_contest(0, v1, mapSpeaker, v2);
	speech_contest_print(0,v2, mapSpeaker);

	//第2轮选手抽签 得到选手名单 查看比赛结果
	cout << "\n\n\n任意键，开始第二轮比赛" << endl;
	cin.get();
	speech_contest_draw(v2);
	speech_contest(1, v2, mapSpeaker, v3);
	speech_contest_print(1, v3, mapSpeaker);

	//第3轮选手抽签 得到选手名单 查看比赛结果
	cout << "\n\n\n任意键，开始第三轮比赛" << endl;
	cin.get();
	speech_contest_draw(v3);
	speech_contest(2, v3, mapSpeaker, v4);
	speech_contest_print(2, v4, mapSpeaker);
	
	
	cout << "hello..." << endl;
	return;
}