#include <iostream>

using namespace std;

int main()
{
    int array[] {15,25,35,45,55,65};
    int * p_start = array;
    int * p_end = array + 5;
    int temp;

    while(p_start < p_end)
    {
        temp = *p_start;
        *p_start = *p_end;
        *p_end = temp;
        p_start++;
        p_end--;
    }
    for(int i =0;i < 5;i++)
    {
        cout << *(array+i) <<endl;//����д��array[i]
    }











    /*
    int* p_nums = new int[10];//��ָ�붨����һ��һά����
    int (*p2)[3] = new int[5][3];//ָ�붨���ά����ķ�ʽ����������һ��ָ����и���ʾ�ˣ������˽�ά

    p2[1][3] = 998;

    for(int i =0;i < 5;i++)
    {
        for(int j =0;j < 3;j++)
        {
            cout << p2[i][j] <<',';//����д��*(*(p2+i)+j)Ҳ����ȷ��
        }
        cout << endl;
    }*/






    /*
    int arrays[] {15,25,35,45,55};
    int* p_arrays = arrays;

    for(int i = 0;i < 5;i++)
    {
        cout << *(p_arrays+i) << endl;

    }

    for(int i = 0;i < 5;i++)
    {

        cout << *p_arrays++ << endl;    //�����д��*p_arrays++����Ȼ��ӡ��ȷ���������ָ���ƶ�����Ϊ���һ��++�Ժ�
                                        //�ͻᵽ����ĵ�6��Ԫ�أ�����6��Ԫ��û�У�ָ�������ָ��һ���ڴ��ַ��
                                        //����һ�����������ͬ�����ӡʱ���ͻ��������һЩ����
    } */






    /*char ch = 'a';
    char * ptr_ch = &ch;

    cout << (void *)ptr_ch << "\t" << *ptr_ch << endl;//char��ָ����C/C++�����Ѿ�����Ϊ���ַ����ˣ�����*ptr_ch = a

    double num = 1024.5;
    double* ptr_num = &num;

    cout << "ptr_num��ֵ�ǣ�" << ptr_num << &num << endl;
    cout << "ptr_numָ��ռ��ֵ�ǣ�" << *ptr_num << endl;*/

    return 0;
}
