#include "linklist.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int linklistInit( linklist **pList);

/*头插*/
int linklistheadInser(linklist *pList, ELEMENTTYPE val);

/*尾插*/
int linklisttaiInser(linklist *pList, ELEMENTTYPE val);

/*链表指定位置插入*/
int linklistAppointPosInser(linklist *pList,int pos, ELEMENTTYPE val);

/*链表头删*/
int linklistheadDel(linklist *pList);

/*链表尾删*/
int linklisttaiDel(linklist *pList);

/*链表指定位置删*/
int linklistAppointPosDel(linklist *pList, int pos);

/* 链表删除指定的数据 */
int LinkListDelAppointData(linklist *pList, ELEMENTTYPE val);

/*获取链表的长度*/
int linklistGetlenght(linklist *pList, int *pSize);

/*链表的销毁*/
int LinkListDestroy(linklist *pList);