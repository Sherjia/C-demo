#include <iostream>
#include <iomanip>

using namespace std;
//string chatTo(const string& toName,const string& content);

/*
void Sort(int[],int);//���أ���������ͬ�������б�(������)��ͬ
void Sort(float[],int);
void Sort(double[],double);
void show(int[],int);
void show(float[],int);
void show(double[],double);
*/
template<typename T>void Sort (T [],int);//ʹ�ú���ģ�弼����������
template<typename G>void show (G [],int);
int main()
{
    int iNums[] = {56,54,12,89,43};
    float fNums[] = {78.0f,5.7f,42.8f,99.1f};
    double dNums[] = {45.5,66.23,89.41,52.31};

    cout << "����ǰ";
    show(iNums,sizeof(iNums)/sizeof(int));//����ʱֻд����������
    Sort(iNums,sizeof(iNums)/sizeof(int));
    cout << "�����";
    show(iNums,sizeof(iNums)/sizeof(int));


    /*
    cout << "����ǰ��" ;
    show(iNums,sizeof(iNums)/sizeof(int));
    Sort(iNums,sizeof(iNums)/sizeof(int));
    cout << "�����";
    show(iNums,sizeof(iNums)/sizeof(int));

    cout << "����ǰ��" ;
    show(fNums,sizeof(fNums)/sizeof(int));
    Sort(fNums,sizeof(fNums)/sizeof(int));
    cout << "�����";
    show(fNums,sizeof(fNums)/sizeof(int));

    cout << "����ǰ��" ;
    show(dNums,sizeof(dNums)/sizeof(dNums[0]));
    Sort(dNums,sizeof(dNums)/sizeof(dNums[0]));
    cout << "�����";
    show(dNums,sizeof(dNums)/sizeof(dNums[1]));
    */
    /*
    string toName,content,chatMsg;
    cout << "������Է������֣�";
    getline(cin,toName);//�ӱ�׼�������У��������룩��ȡһ���ַ������洢���ַ���string(����)��

    cout <<"������Ի����ݣ�";
    getline(cin,content);

    chatMsg = chatTo(toName,content);
    cout << endl << chatMsg << endl;
    */

    return 0;
}
template<typename T> void Sort (T arr[],int len)//���庯��
{
    T temp;//��֪�����ݵ���ʲô���͵Ĳ���������tempҲ��T��
    for(int i = 0;i < len - 1;i++)
    {
        for(int j = 0;j < len - 1 - i;j++)
        {
            if (arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] =  temp;
            }
        }
    }
}
template<typename G> void show (G arr[],int len)
{
    for(int i = 0;i < len;i++)
    {
        cout << arr[i] << ",";
    }
    cout << endl;
}
//����������ʱ�����Զ���Ϊָ�룡������
void Sort(int nums[],int len)
{
    int temp;
    for(int i = 0;i < len - 1;i++)
    {
        for(int j = 0;j < len - 1 - i;j++)
        {
            if(nums[j]>nums[j+1])
            {
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] =  temp;
            }
        }
    }
}
void show(int nums[],int len)
{
    for(int i = 0;i < len;i++)
    {
        cout << nums[i] << ",";
    }
    cout << endl;
}
void Sort(float nums[],int len)
{
     int temp;
    for(int i = 0;i < len - 1;i++)
    {
        for(int j = 0;j < len - 1 - i;j++)
        {
            if(nums[j]>nums[j+1])
            {
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] =  temp;
            }
        }
    }
}
void show(float nums[],int len)
{
    for(int i = 0;i < len;i++)
    {
        cout << nums[i] << ",";
    }
    cout << endl;
}
void Sort(double nums[],double len)
{
    int temp;
    for(int i = 0;i < len - 1;i++)
    {
        for(int j = 0;j < len - 1 - i;j++)
        {
            if(nums[j]>nums[j+1])
            {
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] =  temp;
            }
        }
    }
}
void show(double nums[],double len)
{
    for(int i = 0;i < len;i++)
    {
        cout << setprecision(4) << nums[i] << ",";
    }
    cout << endl;
}
/*
string chatTo(const string& toName,const string& content)
{
    string message = "�����ĵض�["+ toName + "]˵��" + content;//�ַ���ƴ��ʱֱ����+�ţ�string���ͺ�ǿ�󣡣�
    return message;
}
*/
