#include "Doublelinklist.h"
#include <stdlib.h>
#include<stdio.h>
#include <string.h>

/* 状态码 */


/* 静态函数只在本源文件(.c)使用 */
/* 静态前置声明 */
static int DoublelinklistAccordAppointValGetPos(Doublelinklist * pList, ELEMENTTYPE val, int *pPos);

/* 链表初始化 */
int DoublelinklistInit(Doublelinklist **pList)
{
    int ret = 0;
    Doublelinklist *list = (Doublelinklist *)malloc(sizeof(Doublelinklist) * 1);
    if (list == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 清空脏数据 */
    memset(list, 0, sizeof(Doublelinklist) * 1);

    list->head = (DoublelinkNode *)malloc(sizeof(DoublelinkNode) * 1);
    if (list->head == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 清空脏数据 */
    memset(list->head, 0, sizeof(DoublelinkNode) * 1);
    list->head->data = 0;
    list->head->next = NULL;
    /* 初始化的时候, 尾指针 = 头指针 */
    list->tail = list->head;

    /* 链表的长度为0 */
    list->len = 0;

    /* 二级指针 */
    *pList = list;
    return ret;
}

/* 链表头插 */
int DoublelinklistHeadInser(Doublelinklist * pList, ELEMENTTYPE val)
{
    return DoublelinklistAppointPosInsert(pList, 0, val);
}

/* 链表尾插 */
int DoublelinklistTailInsert(Doublelinklist * pList, ELEMENTTYPE val)
{
    /* todo... */
    return DoublelinklistAppointPosInsert(pList, pList->len, val);
}

/* 链表指定位置插入 */
int DoublelinklistAppointPosInsert(Doublelinklist * pList, int pos, ELEMENTTYPE val)
{
    int ret = 0;
    if (pList == NULL)
    {
        return NULL_PTR;
    }
    
    if (pos < 0 || pos > pList->len)
    {
        return INVAILD_ACCESS;
    }

    /* 封装结点 */
    DoublelinkNode * newNode = (DoublelinkNode *)malloc(sizeof(DoublelinkNode) * 1);
    if (newNode == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 清除脏数据 */
    memset(newNode, 0, sizeof(DoublelinkNode) * 1);
#if 1
    newNode->data = 0;
    newNode->next = NULL;
#endif
    /* 赋值 */
    newNode->data = val;

#if 1
    /* 从虚拟头结点开始遍历 */
    DoublelinkNode * travelNode = pList->head;
#else
    DoublelinkNode * travelNode = pList->head->next;
#endif

    int flag = 0;
    /* 这种情况下需要更改尾指针 */
    if (pos == pList->len)
    {
        /* 修改结点指向 */
        travelNode = pList->tail;
#if 0
        newNode->next = travelNode->next;   // 1
        travelNode->next = newNode;         // 2
#endif
        flag = 1;
    }
    else
    {
        while (pos)
        {
            travelNode = travelNode->next;
            pos--;
        }
    }
    newNode->next = travelNode->next;       // 1
    travelNode->next = newNode;             // 2
    if (flag)
    {
        /* 尾指针更新位置 */
        pList->tail = newNode;
    }

    /* 更新链表的长度 */
    (pList->len)++;
    return ret;
}

/* 链表头删 */
int DoublelinklistHeadDel(Doublelinklist * pList)
{
    return DoublelinklistDelAppointData(pList, 1);
}

/* 链表尾删 */
int DoublelinklistTailDel(Doublelinklist * pList)
{
    return DoublelinklistDelAppointData(pList, pList->len);
}

/* 链表指定位置删 */
int DoublelinklistDelAppointPos(Doublelinklist * pList, int pos)
{
    int ret = 0;
    if (pList == NULL)
    {
        return NULL_PTR;
    }
    
    if (pos <= 0 || pos > pList->len)
    {
        return INVAILD_ACCESS;
    }

#if 1
    DoublelinkNode * travelNode = pList->head;
#else
    DoublelinkNode * travelNOde = pList->head->next;
#endif 
     int flag = 0;
    /* 需要修改尾指针 */
    if (pos == pList->len)
    {
        /* 需要修改尾指针 */
        flag = 1;
    }
    DoublelinkNode * needDelNode = NULL;
    while (--pos)
    {
        /* 向后移动位置 */
        travelNode = travelNode->next;
    }   
    // 跳出循环找到的是哪一个结点？
    needDelNode = travelNode->next;
    travelNode->next = needDelNode->next; 

    /* 释放内存 */
    if (needDelNode != NULL)
    {
        free(needDelNode);
        needDelNode = NULL;
    }

    /* 链表长度减一 */
    (pList->len)--;
    return ret;
}

/* 根据指定的元素得到在链表中所在的位置 */
static int DoublelinklistAccordAppointValGetPos(Doublelinklist * pList, ELEMENTTYPE val, int *pPos)
{
    /* 静态函数只给本源文件的函数使用, 不需要判断合法性 */
    int ret;
    
#if 0
    int pos = 0;
    DoublelinkNode *travelNode = pList->head;
#else
    int pos = 1;
    DoublelinkNode *travelNode = pList->head->next;
#endif
    while (travelNode != NULL)
    {
        if (travelNode->data == val)
        {
            /* 解引用 */
            *pPos = pos;
            return pos;
        }
        travelNode = travelNode->next;
        pos++;
    }
    /* 解引用 */
    *pPos = NOT_FIND;
    
    return NOT_FIND;
}

/* 链表删除指定的数据 */
int DoublelinklistDelAppointData(Doublelinklist * pList, ELEMENTTYPE val)
{
    int ret = 0;
    /* 元素在链表中的位置 */
    int pos = 0;

    /* 链表的长度 */
    int size = 0;
    while (DoublelinklistGetlength(pList, &size) && pos != NOT_FIND)
    {
        /* 根据指定的元素得到在链表中所在的位置 */
        DoublelinklistAccordAppointValGetPos(pList, val, &pos);
        DoublelinklistDelAppointPos(pList, pos);
    }
    return ret;
}

/* 获取链表的长度 */
int DoublelinklistGetlength(Doublelinklist * pList, int *pSize)
{
    int ret = 0;
    if (pList == NULL)
    {
        return NULL_PTR;
    }

    if (pSize)
    {
        *pSize = pList->len;
    }
    /* 返回链表的长度 */
    return pList->len;
}

/* 链表的销毁 */
int DoublelinklistDestroy(Doublelinklist * pList)
{
    int ret = 0;
    /* 我们使用头删释放链表 */
    int size = 0;
    while (DoublelinklistGetlength(pList, &size))
    {
        DoublelinklistHeadDel(pList);
    }

    if (pList->head != NULL)
    {
        free(pList->head);
        /* 指针置为NULL. */
        pList->head = NULL;
        pList->tail = NULL;
    }
    return ret;
}

/* 链表遍历接口 */
int DoublelinklistForeach(Doublelinklist * pList, int(*printFunc)(ELEMENTTYPE))
{
    int ret = 0;
    if (pList == NULL)
    {
        return NULL_PTR;
    }

#if 0
    /* travelNode指向虚拟头结点 */
    DoublelinkNode * travelNode = pList->head;
    while (travelNode->next != NULL)
    {
        travelNode = travelNode->next;
        printf("travelNode->data:%d\n", travelNode->data);
    }
#else
    /* travelNode 指向链表第一个元素 */
    DoublelinkNode * travelNode = pList->head->next;
    while (travelNode != NULL)
    {
        #if 0
        printf("travelNode->data:%d\n", travelNode->data);
        #else
        /*包装器，钩子，回调函数*/
        printFunc(travelNode->data);
        #endif
        travelNode = travelNode->next;
    }
#endif
    return ret;
}