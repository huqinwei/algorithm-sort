#include<stdio.h>

void heapAdjust(int *array,int i,int length)
{
        int nChild;
        for(i;i * 2 + 1 < length;i = nChild)
        {
                printf("loop:i:length:%d\n",length);
                nChild = i * 2 + 1;
                printf("array[nChild]:%d\n",array[nChild]);
                printf("array[nChild + 1]:%d\n",array[nChild+1]);

                if(nChild < length - 1 && (array[nChild] < array[nChild + 1]))
                {
                        printf("nChild:%d nChild+1:%d\n",array[nChild],array[nChild+1]);

                        nChild++;
                }
                printf("i:%d nChild:%d\n",i,nChild);
                printf("[nChild]:%d\n",array[nChild]);
                if(array[i] < array[nChild])
                {
                        array[i] = array[i]^array[nChild];
                        array[nChild] = array[i]^array[nChild];
                        array[i] = array[i]^array[nChild];
                }

        }      
}
void heapSort(int *array,int i,int length)
{
//先排序
        //i = 0;
        for(i = length / 2 - 1;i >= 0;i--)
        {
                //heapAdjust(array,i,length);
                heapAdjust(array,i,length);
        }      

        for(i = 0;i < 10;i++)
                printf("m:%d\n",array[i]);
//再逐个调整
        for(i = length;i > 1;i--)
//如果条件是i>1，有一次[1-1]与[0]的交换，自己和自己用^符号会导致清零
        {
                int j = 0;
                array[i - 1] = array[i - 1] ^ array[0];
                array[0] = array[i - 1] ^ array[0];
//              array[i - 1] = array[i - 1] & array[0];//写错符号了&
                array[i - 1] = array[i - 1] ^ array[0];
//              int temp = array[i - 1];
//              array[i - 1] = array[0];
//              array[0] = temp;
                heapAdjust(array,0,i - 1);
                for(j = 0;j < 10;j++)
                        printf("after adjust:%d\n",array[j]);
        }

}
int main()
{
        int array[10] = {23,123,13,14,123,143,53,55,56,523};
        int i = 0;
        for(i = 0;i < 10;i++)
                printf("b:%d\n",array[i]);
        heapSort(array,0,10);
        for(i = 0;i < 10;i++)
                printf("a:%d\n",array[i]);


}
