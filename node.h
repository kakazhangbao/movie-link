#ifndef __NODE_H__
#define __NODE_H__
typedef struct node{
    int num;
    char name[20];
    float score;
    struct node *p_next;   
}node;
typedef struct{
    node head,tail;
}link;
//链表的初始化
void link_init(link *p_link);
//链表的清理函数
void link_deinit(link *p_link);
//判断函数是否为空的
int link_empty(const link *p_link);
//判断链表是否为满
int  link_full(const link *p_link);
//统计链表中有效个数的函数
int link_size(const link *p_link);
/* 按照豆瓣评分从小到大的顺序把新电影加入到链表的函数*/
int link_insert(link *p_link,int num,char *name,float score);
/*删除某个编号所在结点的函数*/
int link_remove(link *p_link,int num);
/*根据编号找到对应的数字的函数*/
node *link_get(const link *p_link,int num);
#endif









