#include<iostream>
using namespace std;
int main()
{
        int array[10] = {1,3,6,7,9,2,23,53,23,10};
        int min = 0;
        int temp = 0;
        for(int i = 0;i < sizeof(array) / sizeof(int);i++)
        {
                min = i;
                for(int j = i;j < sizeof(array) / sizeof(int);j++)
                {
                        if(array[j] < array[min])
                                min = j;
                }
                temp = array[i];
                array[i] = array[min];
                array[min] = temp;
        }
        for(int i = 0;i < sizeof(array) / sizeof(int);i++)
                cout << array[i] << endl;

}
