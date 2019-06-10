#include <iostream>
#include <iomanip>//io代表输入输出，manip是manipulator（操纵器）的缩写。主要是对cin,cout之类的一些操纵运算子，比如setfill,setw,setbase,setprecision等等
#include <ctime>//ctime功能是 把日期和时间转换为字符串
#include <vector>
#include <array>
#include <cstdlib>//因为用了srand,所以需要加一个头文件

using namespace std;

int main()
{

    int chioce,temp1,temp2,temp3;
    /**父亲的名字*/
    string value_father_name;
    /**女儿的名字*/
    string value_daughter_name;
    /**女儿的出生月份*/
    int value_birth_month;
    /**女儿的出生日期*/
    int value_birth_date;
    /**女儿的星座*/
    string value_daughter_constell;
    /**女儿的基本五项信息:体力，智力，魅力，道德，气质*/
    array<int,5> value_array_baseinfo;
    /**女儿的初始金币*/
    int value_daughter_gold = 500;
    /**五项基本属性名*/
    array<string,5> value_array_baseinfo_names = {"体力","智力","魅力","道德","气质"};
    /**星座的二维数组*/
    string constell_names[12][2]={

    {"山羊座","水瓶座"},//一月
    {"水瓶座","双鱼座"},//二月
    {"双鱼座","白羊座"},//三月
    {"白羊座","金牛座"},//四月
    {"金牛座","双子座"},//五月
    {"双子座","巨蟹座"},//六月
    {"巨蟹座","狮子座"},//七月
    {"狮子座","处女座"},//八月
    {"处女座","天秤座"},//九月
    {"天秤座","天蝎座"},//十月
    {"天蝎座","射手座"},//十一月
    {"射手座","山羊座"} //十二月

    };
    cout <<"父亲的姓名:";
    cin >> value_father_name;
    cout << "女儿的姓名：";
    cin >> value_daughter_name;
    cout << "女儿的生日：(M D)";
    cin >> value_birth_month >> value_birth_date;


    /**各月份的跨星座日期*/
    int constell_dates[]{20,19,21,20,21,22,23,23,23,24,23,22};//每个月星座变换的那一天，比如1月20号变为水瓶座

    //cout << constell_ names[value_birth_month-1][value_birth_date/constell_dates[value_birth_month-1]] <<endl;
                                                                                                                /*利用星座的二维数组来根据输入的生日来
                                                                                                                判断并输出星座。[value_birth_month-1]表示你在数组的哪一行，
                                                                                                                [value_birth_date/constell_dates[value_birth_month-1]]表示用你出生的那一天
                                                                                                                来除以你出生那一月星座变换的那一天，除不尽为0就在第一列，除尽为1就是第二列*/

    value_daughter_constell = constell_names[value_birth_month-1][value_birth_date/constell_dates[value_birth_month-1]];//女儿的星座
    cout <<"女儿的信息："<<endl;
    cout <<"女儿的姓名："<<value_daughter_name<<endl;
    cout <<"生日：1659-"<<value_birth_month<<"-"<<value_birth_date<<endl;
    cout <<"星座："<<value_daughter_constell<<endl;

    if(value_daughter_constell == "白羊座"){
        value_array_baseinfo[0] = 80; value_array_baseinfo[1] = 15; value_array_baseinfo[2] = 15; value_array_baseinfo[3] = 25; value_array_baseinfo[4] = 11;
    }else if(value_daughter_constell == "金牛座"){
        value_array_baseinfo[0] = 46; value_array_baseinfo[1] = 30; value_array_baseinfo[2] = 28; value_array_baseinfo[3] = 35; value_array_baseinfo[4] = 20;
    }else if(value_daughter_constell == "双子座"){
        value_array_baseinfo[0] = 50; value_array_baseinfo[1] = 35; value_array_baseinfo[2] = 23; value_array_baseinfo[3] = 26; value_array_baseinfo[4] = 8;
    }else if(value_daughter_constell == "巨蟹座"){
        value_array_baseinfo[0] = 40; value_array_baseinfo[1] = 31; value_array_baseinfo[2] = 33; value_array_baseinfo[3] = 23; value_array_baseinfo[4] = 17;
    }else if(value_daughter_constell == "狮子座"){
        value_array_baseinfo[0] = 85; value_array_baseinfo[1] = 9;  value_array_baseinfo[2] = 11; value_array_baseinfo[3] = 28; value_array_baseinfo[4] = 20;
    }else if(value_daughter_constell == "处女座"){
        value_array_baseinfo[0] = 35; value_array_baseinfo[1] = 28; value_array_baseinfo[2] = 36; value_array_baseinfo[3] = 19; value_array_baseinfo[4] = 18;
    }else if(value_daughter_constell == "天秤座"){
        value_array_baseinfo[0] = 42; value_array_baseinfo[1] = 33; value_array_baseinfo[2] = 25; value_array_baseinfo[3] = 24; value_array_baseinfo[4] = 32;
    }else if(value_daughter_constell == "天蝎座"){
        value_array_baseinfo[0] = 50; value_array_baseinfo[1] = 25; value_array_baseinfo[2] = 40; value_array_baseinfo[3] = 20; value_array_baseinfo[4] = 18;
    }else if(value_daughter_constell == "射手座"){
        value_array_baseinfo[0] = 40; value_array_baseinfo[1] = 31; value_array_baseinfo[2] = 15; value_array_baseinfo[3] = 19; value_array_baseinfo[4] = 20;
    }else if(value_daughter_constell == "山羊座"){
        value_array_baseinfo[0] = 56; value_array_baseinfo[1] = 21; value_array_baseinfo[2] = 16; value_array_baseinfo[3] = 22; value_array_baseinfo[4] = 25;
    }else if(value_daughter_constell == "水瓶座"){
        value_array_baseinfo[0] = 43; value_array_baseinfo[1] = 20; value_array_baseinfo[2] = 29; value_array_baseinfo[3] = 25; value_array_baseinfo[4] = 23;
    }else if(value_daughter_constell == "双鱼座"){
        value_array_baseinfo[0] = 41; value_array_baseinfo[1] = 20; value_array_baseinfo[2] = 29; value_array_baseinfo[3] = 25; value_array_baseinfo[4] = 23;
    }

    for(int i = 0;i < 5;i++)
    {
        cout << value_array_baseinfo[i] << '\t';
    }
    cout << endl;
    //游戏主体循环开始
    for(int year = 1659;year < 1659+7;year++)
    {
        for(int month = (year == 1659)?6:1;month <= 12;month++){
            //判断本月是否是女儿的生日
            if(month == value_birth_month){
                cout << "本月是" << value_daughter_name << "生日，要不要送礼物？" << endl;
            }
        //显示游戏主菜单
        cout << "\n1.查看状态\n2.安排行程\n3.亲自谈话\n4.存档\n5.读档" <<endl;
        cin >>chioce;
        switch(chioce){
        case 1://查看状态
            cout <<"女儿的信息："<<endl;
            cout <<"女儿的姓名："<<value_daughter_name<<endl;
            cout <<"生日：1659-"<<value_birth_month<<"-"<<value_birth_date<<endl;
            cout <<"星座："<<value_daughter_constell<<endl;
            cout <<"金币" <<value_daughter_gold<<endl;
            //打印核心属性
            cout << left;//全体左对齐
            for(int i = 0;i < 5;i++){
                cout << value_array_baseinfo_names[i] << ":" << setw(2) << value_array_baseinfo[i];//setw(2)设置宽度为2
                //计算实心方框的数量
                int SolidCount = value_array_baseinfo[i] / 10;//取商，十位是多少就有多少个实心方框
            for(int j=0;j <= 10;j++){
                if(j < SolidCount){//因为j从0开始，所以此时要j<SolidCount
                    cout << "■";
                }
                else{
                    cout << "□";
                }
              }
              cout <<endl;
            }
            break;
        case 2:{//case里面想定义变量的话，加{}
            string month_parths[] = {"上旬","中旬","下旬"};
            for(int i = 0;i < 3;i++){
                cout << "-- " << month << "月--" << month_parths[i] << endl;
                cout <<"\n1.学习武艺\n2.上私塾\n3.学习礼法\n4.出城修行\n5.打工赚钱"<<endl;
                cout <<"请选择：";
                cin >> chioce;
                //这里需要判断，。没钱的情况，强制打工
                srand(time(NULL));//随机数发生器。可以为rand函数提供不同的种子值，进而产生不同的随机数序列
                if(chioce == 1){//加体力，加魅力，减金钱
                    value_array_baseinfo[0] += temp1 = rand() % 11;//为让显示出随机出现的数值是多少，所以增加了temp1等来表示。
                    value_array_baseinfo[3] += temp2 = rand() % 11;
                    value_daughter_gold -= temp3 = rand() % 51;//因为余数需要从1到10，所以都对11或51(初始金钱为500)取余；
                    cout << "学习张无忌好榜样" <<endl;
                    cout << "体力值加" << temp1 << "魅力增加" << temp2 << "金钱减少" << temp3 <<endl;
                }else if(chioce == 5){
                    value_daughter_gold += temp3 = rand() % 101;//同样，要让金币赚到1到100，所以对101取余。
                    cout << "通过打工赚到了：" << value_daughter_gold << endl;
                }
            }
        }
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;

         }
        }
    }
       //根据属性值，来判定游戏结果
        /*女王 属性总数2000以上
          王妃 1800~2000
          女将军 1600~1800
          皇家学院总裁 1200~1600 智力最高 且魅力>体力
          公主 1200~1600 气质最高 且魅力大于体力
          近卫骑士团长 1200~1600 体力最高 气质大于魅力
          高级祭司 1200~1600 道德最高 且魅力>气质
          国王的宠妃 1200~1600 魅力最高 且气质>道德
        */
        int sum;
        for(int i = 0;i < 5;i++){
            sum += value_array_baseinfo[0];
        }
        if(sum >= 2000){
            cout << "游戏最优结果：登基为女王陛下" << endl;
        }else if(sum >= 1800 && sum < 2000){
            cout << "成为王妃" <<endl;
        }else if(sum >= 1200 && sum <1600){//高级祭司 1200~1600 道德最高 且魅力>气质
            int MaxValue = value_array_baseinfo[0];
            int MaxIndex = 0;
            for(int i =1;i < 5;i++){
                    if(MaxValue < value_array_baseinfo[i]){
                        MaxValue = value_array_baseinfo[i];
                        MaxIndex = i;
                    }

            }
            if("道德" == value_array_baseinfo_names[MaxIndex] && value_array_baseinfo[2] > value_array_baseinfo[4]){
                cout <<value_daughter_name << "成为高级祭司" << endl;
            }

        }

















    return 0;
}
