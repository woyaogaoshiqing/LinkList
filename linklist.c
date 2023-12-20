#include "linklist.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
enum STATUSCODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVAILD_ACCESS,
};

int linklistInit( linklist **pList)
{
    int ret = 0;
    linklist *list = (linklist *)malloc(sizeof(linklist) * 1);
    if (list == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(list, 0, sizeof(linklist) * 1);

    list->head = (linklist *)malloc(sizeof(linklist) * 1);
    if (list->head == NULL)
    {
        return MALLOC_ERR;
    }
    memset(list->head, 0, sizeof(linklist) * 1);
    list->head->data = 0;
    list->head->next = NULL;

    /*初始化的时候，尾指针 = 头指针*/
    list->tail = list->head;
    /*链表的长度为0*/
    list->len = 0;
    /*二级指针*/
    *pList = list;
    return ret;
}

/*头插*/
int linklistheadInser(linklist *pList, ELEMENTTYPE val)
{
    return linklistAppointPosInser(pList, 0, val);
}

/*尾插*/
int linklisttaiInser(linklist *pList, ELEMENTTYPE val)
{
    return linklistAppointPosInser(pList, pList->len,val);
}

/*链表指定位置插入*/
int linklistAppointPosInser(linklist *pList,int pos, ELEMENTTYPE val)
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
    /*封装节点*/
    linkNode * nuwNode = (linklist *)malloc(sizeof(linklist) * 1);
    if (nuwNode == NULL)
    {
        return MALLOC_ERR;
    }
    memset(nuwNode, 0, sizeof(linklist) * 1);
    /*赋值*/
    nuwNode->data = val;
#if 1
    linkNode * TravelNode = pList->head;
#else

#endif
    int flag = 0;
    /* 这种情况下需要更改尾指针 */
    if (pos == pList->len)
    {
        /* 修改结点指向 */
        TravelNode = pList->tail;
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
            TravelNode = TravelNode->next;
            pos--;
        }
    }
    nuwNode->next = TravelNode->next;       // 1
    TravelNode->next = nuwNode;             // 2
    if (flag)
    {
        /* 尾指针更新位置 */
        pList->tail = nuwNode;
    }

    /* 更新链表的长度 */
    (pList->len)++;
    return ret;
}


/*链表头删*/
int linklistheadDel(linklist *pList)
{
    return LinkListDelAppointData(pList, 1);
}

/*链表尾删*/
int linklisttaiDel(linklist *pList)
{
    return LinkListDelAppointData(pList, pList->len);
}

/*链表指定位置删*/
int linklistAppointPosDel(linklist *pList, int pos)
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
    linkNode * traveNode = pList->head;
    while (--pos)
    {
        traveNode = traveNode->next;
        //pos--;
    }
    //跳出循环找到的是哪一个节点
    linkNode * needDelNode = traveNode->next;
    traveNode->next = needDelNode->next;

    /*释放内存*/
    if (needDelNode != NULL)
    {
        free(needDelNode);
        needDelNode = NULL;
    }
    
    (pList->len)--;
    return ret;
}

/* 链表删除指定的数据 */
int LinkListDelAppointData(linklist *pList, ELEMENTTYPE val)
{

}

/*获取链表的长度*/
int linklistGetlenght(linklist *pList, int *pSize)
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
    return ret;
}

/*链表的销毁*/
int LinkListDestroy(linklist *pList)
{

}
/*链表遍历接口*/
int linklistForeach(linklist *pList)
{
    int ret = 0;
    if (pList == NULL)
    {
        return NULL_PTR;
    }
#if 0
    linkNode * TraveNode = pList->head;
    while (TraveNode->next != NULL)
    {
        TraveNode = TraveNode->next;
        printf("TraveNode->data:%d\n",TraveNode->data);
    }
#else
    linkNode * TraveNode = pList->head->next;
    while (TraveNode->next != NULL)
    {
        printf("TraveNode->data:%d\n",TraveNode->data);
        TraveNode = TraveNode->next;
    }
    return ret;
#endif 

}