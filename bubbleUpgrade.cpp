#include<iostream>
using namespace std;
int main()
{
        int array[10] = {5,13,545,123,464,434,124,4,999,1111};
        int temp;
        cout << "before bubble sort: " << endl;
        for(int i = 0; i < sizeof(array) / sizeof(int); i++)
                cout << array[i] << endl;
        //优化思路，最后一位换不动，i额外自减
        for(int i = sizeof(array) / sizeof(int) - 1;i > 0;i--)
        {
                for(int j = 0;j < i;j++)
                {
                        if(array[j] > array[j + 1])//swap
                        {
                                temp = array[j];
                                array[j] = array[j + 1];
                                array[j + 1] = temp;
                        }else if(j + 1 == i)
                        //can't swap and final number
                        {
                                i--;
                        }

                }
        }
        cout << "after bubble sort: " << endl;
        for(int i = 0; i < sizeof(array) / sizeof(int); i++)
                cout << array[i] << endl;
}
