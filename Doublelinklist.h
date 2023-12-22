#ifndef __LINKLIST_H_
#define __LINKLIST_H_
#define ELEMENTTYPE void*
/*链表节点*/
typedef  struct  DoublelinkNode
{
    ELEMENTTYPE data;
    /*指向前一个节点的指针*/
    struct DoublelinkNode * prve;
    
    /*指向下一个节点的指针*/
    struct DoublelinkNode *next;  /*指针的类型为什么是节点*/
}DoublelinkNode;




/* 状态码 */
enum STATUSCODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVAILD_ACCESS,
    NOT_FIND,
};
typedef struct stuInfo
{
    int age;
    char sex;
} stuInfo;
/*链表*/
typedef struct linklist
{
    
    DoublelinkNode * head;
    DoublelinkNode * tail; 
    int len;
}linklist;
/*链表初始化*/
int linklistInit( linklist **pList);

/*头插*/
int linklistHeadInser(linklist *pList, ELEMENTTYPE val);

/*尾插*/
int linklisttaiInser(linklist *pList, ELEMENTTYPE val);

/*链表指定位置插入*/
int linklistAppointPosInsert(linklist *pList,int pos, ELEMENTTYPE val);

/*链表头删*/
int linklistheadDel(linklist *pList);

/*链表尾删*/
int linklisttaiDel(linklist *pList);

/*链表指定位置删*/
int linklistAppointPosDel(linklist *pList, int pos);

/* 链表删除指定的数据 */
int linklistDelAppointData(linklist *pList, ELEMENTTYPE val);

/*获取链表的长度*/
int linklistGetlength(linklist *pList, int *pSize);

/*链表的销毁*/
int LinkListDestroy(linklist *pList);

/*链表遍历接口*/
int linklistForeach(linklist *pList, int(*printFunc)(ELEMENTTYPE));
#endif  //__LINKLIST_H_