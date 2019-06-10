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
        cout << *(array+i) <<endl;//或者写成array[i]
    }











    /*
    int* p_nums = new int[10];//用指针定义了一个一维数组
    int (*p2)[3] = new int[5][3];//指针定义二维数组的方式，就是先用一个指针把列给表示了，进行了降维

    p2[1][3] = 998;

    for(int i =0;i < 5;i++)
    {
        for(int j =0;j < 3;j++)
        {
            cout << p2[i][j] <<',';//或者写成*(*(p2+i)+j)也是正确的
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

        cout << *p_arrays++ << endl;    //如果你写成*p_arrays++，虽然打印正确，但会造成指针移动；因为最后一个++以后
                                        //就会到数组的第6个元素，但第6个元素没有，指针会随意指向一个内存地址；
                                        //你下一才再用这段相同代码打印时，就会是随机的一些数字
    } */






    /*char ch = 'a';
    char * ptr_ch = &ch;

    cout << (void *)ptr_ch << "\t" << *ptr_ch << endl;//char型指针在C/C++里面已经被认为是字符串了，所以*ptr_ch = a

    double num = 1024.5;
    double* ptr_num = &num;

    cout << "ptr_num的值是：" << ptr_num << &num << endl;
    cout << "ptr_num指向空间的值是：" << *ptr_num << endl;*/

    return 0;
}
