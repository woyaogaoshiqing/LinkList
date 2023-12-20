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

    int len;
}linklist;
/*链表初始化*/
int linklistInit();

/*头插*/
int linklistheadInser();

/*尾插*/
int linklisttaiInser();

/*链表指定位置插入*/
int linklistAppointPosInser();

/*链表头删*/
int linklistheadDel();

/*链表尾删*/
int linklisttaiDel();

/*链表指定位置删*/
int linklistAppointPosDel();

/* 链表删除指定的数据 */
int LinkListDelAppointData();

/*获取链表的长度*/
int linklistGetlenght();

/*链表的销毁*/
int LinkListDestroy();
#endif  //__LINKLIST_H_