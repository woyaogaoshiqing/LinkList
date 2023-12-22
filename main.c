/*静态数组：在栈区开辟一块连续内存
动态数组：在堆区开辟一块连续内存 坏处：在指定位置插入元素，会使得后面的元素后移：浪费时间
                               好处：插到末尾速度很快*/

/*链表是不连续的内存空间，每个节点在需要的时候分配空间 好处：节省内存空间，插入删除快
坏处：查找元素的时候慢（效率低）相较与数组array【500】能够快速的拿到数据*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Doublelinklist.h"
#define BUFFER_SIZE 3


/* 自定义打印 */
int printStruct(void *arg)
{
    stuInfo *info = (stuInfo*)arg;

    printf("age:%d\t, sex:%d\n", info->age, info->sex);
    
}

int printBasicData(void *arg)
{
    int data = *(int *)arg;
    printf("data:%d\n", data);

}
int main()
{
#if 1

    Doublelinklist * list = NULL;
    DoublelinklistInit(&list);
#else    
    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
    DoublelinklistHeadInser(list,idx);
    }
    /*获取链表的长度*/
    int size = 0;
    DoublelinklistGetlength(list, &size);
    printf("%d\n",size);

    
#endif
#if 1
stuInfo stu1, stu2, stu3;
    memset(&stu1, 0, sizeof(stu1));
    memset(&stu2, 0, sizeof(stu2));
    memset(&stu3, 0, sizeof(stu3));

    stu1.age = 10;
    stu1.sex = 'm';

    stu2.age = 20;
    stu2.sex = 'f';

    stu3.age = 30;
    stu3.sex = 'm';
    stuInfo buffer[BUFFER_SIZE] = {stu1, stu2, stu3};

    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        DoublelinklistHeadInser(list,(void*)&buffer[idx]);
    }
    /**/
    DoublelinklistForeach(list, printStruct);
   
#endif
    return 0;
}