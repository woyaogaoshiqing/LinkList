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
    /*链表的长度为0*/
    list->len = 0;
    *pList = list;
    return ret;
}

/*头插*/
int linklistheadInser(linklist *pList, ELEMENTTYPE val)
{

}

/*尾插*/
int linklisttaiInser(linklist *pList, ELEMENTTYPE val)
{

}

/*链表指定位置插入*/
int linklistAppointPosInser(linklist *pList,int pos, ELEMENTTYPE val)
{

}

/*链表头删*/
int linklistheadDel(linklist *pList)
{

}

/*链表尾删*/
int linklisttaiDel(linklist *pList)
{

}

/*链表指定位置删*/
int linklistAppointPosDel(linklist *pList, int pos)
{

}

/* 链表删除指定的数据 */
int LinkListDelAppointData(linklist *pList, ELEMENTTYPE val)
{

}

/*获取链表的长度*/
int linklistGetlenght(linklist *pList, int *pSize)
{

}

/*链表的销毁*/
int LinkListDestroy(linklist *pList)
{

}
/*链表遍历接口*/
int linklistForeach(linklist *pList)
{

}