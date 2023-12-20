#ifndef __LINKLIST_H_
#define __LINKLIST_H_
#define ELEMENTTYPE int
/*链表节点*/
typedef  struct linkNode
{
    ELEMENTTYPE data;
    /*指向下一个节点的指针*/
    struct linkNode *next;  /*指针的类型为什么是节点*/
}linkNode;

/* 状态码 */
enum STATUSCODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERR,
    INVAILD_ACCESS,
};

/*链表*/
typedef struct linklist
{
    
    linkNode * head;
    linkNode * tail; 
    int len;
}linklist;
/*链表初始化*/
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

/*链表遍历接口*/
int linklistForeach(linklist *pList);
#endif  //__LINKLIST_H_