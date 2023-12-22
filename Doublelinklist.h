#ifndef __Doublelinklist_H_
#define __Doublelinklist_H_
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
typedef struct Doublelinklist
{
    
    DoublelinkNode * head;
    DoublelinkNode * tail; 
    int len;
}Doublelinklist;
/*链表初始化*/
int DoublelinklistInit( Doublelinklist **pList);

/*头插*/
int DoublelinklistHeadInser(Doublelinklist *pList, ELEMENTTYPE val);

/*尾插*/
int DoublelinklisttaiInser(Doublelinklist *pList, ELEMENTTYPE val);

/*链表指定位置插入*/
int DoublelinklistAppointPosInsert(Doublelinklist *pList,int pos, ELEMENTTYPE val);

/*链表头删*/
int DoublelinklistheadDel(Doublelinklist *pList);

/*链表尾删*/
int DoublelinklisttaiDel(Doublelinklist *pList);

/*链表指定位置删*/
int DoublelinklistAppointPosDel(Doublelinklist *pList, int pos);

/* 链表删除指定的数据 */
int DoublelinklistDelAppointData(Doublelinklist *pList, ELEMENTTYPE val);

/*获取链表的长度*/
int DoublelinklistGetlength(Doublelinklist *pList, int *pSize);

/*链表的销毁*/
int DoublelinklistDestroy(Doublelinklist *pList);

/*链表遍历接口*/
int DoublelinklistForeach(Doublelinklist *pList, int(*printFunc)(ELEMENTTYPE));
#endif  //__Doublelinklist_H_