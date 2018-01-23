#include<stdlib.h>
#include<string.h>
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
void link_init(link *p_link){
    p_link->head.p_next = &(p_link->tail);
    p_link->tail.p_next = NULL;
}
//链表的清理函数
void link_deinit(link *p_link){
    while(p_link->head.p_next!=&(p_link->tail)){
        node *p_first = &(p_link->head);
        node *p_mid = p_first->p_next;
        node *p_last = p_mid->p_next;
        p_first->p_next = p_last; 
        free(p_mid);
        p_mid = NULL;
    }
}
//判断函数是否为空的
int link_empty(const link *p_link){
   return(p_link->head.p_next == &(p_link->tail));
}
//判断链表是否为满
int  link_full(const link *p_link){
    return 0;
}   
//统计链表中有效个数的函数
int link_size(const link *p_link){
    int cnt = 0 ;
    const node *p_node = NULL;
    for(p_node = &(p_link->head);p_node!=&(p_link->tail);p_node=p_node->p_next){
        const node *p_first = p_node;
        const node *p_mid = p_first->p_next;
        const node *p_last = p_mid->p_next;
        if(p_mid!=&(p_link->tail)){
            cnt++;
        }
    }
    return cnt;
}
/* 按照豆瓣评分从小到大的顺序把新电影加入到链表的函数*/
int link_insert(link *p_link,int num,char *name,float score){
    node *p_node = NULL;
    node *p_tmp = (node *)malloc(sizeof(node));
    if(!p_tmp){
        return 0;
    }
    p_tmp->num = num;
    p_tmp->score= score;
    strcpy(p_tmp->name,name);
    p_tmp->p_next = NULL;
    for(p_node=&(p_link->head);p_node!=&(p_link->tail);p_node = p_node->p_next){
        node *p_first = p_node;
        node *p_mid = p_first->p_next;
        node *p_last =p_mid->p_next;
        if(p_mid==&(p_link->tail)||p_mid->score > p_tmp->score){
            p_first->p_next = p_tmp;
            p_tmp->p_next = p_mid;
            break; 
        }   
    }
    return 1; 
}
/*删除某个编号所在结点的函数*/
int link_remove(link *p_link,int num){
    node *p_node = NULL;
    for(p_node=&(p_link->head);p_node!=&(p_link->tail);p_node=p_node->p_next){
        node *p_first = p_node;
        node *p_mid = p_node->p_next;
        node *p_last =p_mid->p_next;
        if(p_mid!=&(p_link->tail) && p_mid->num == num){
            p_first->p_next = p_last;
            free(p_mid);
            p_mid = NULL;
            return 1;  
        }
    }  
    return 0;
}
/*根据编号找到对应的数字的函数*/
const node *link_get(const link *p_link,int num){
    const node *p_node = NULL;
    for (p_node = &(p_link->head);p_node != &(p_link->tail);p_node = p_node->p_next) {
        const node *p_first = p_node;
        const node *p_mid = p_first->p_next;
        const node *p_last = p_mid->p_next;
        if (p_mid != &(p_link->tail) && p_mid->num == num){
             return p_mid;
             break;
        }
    }
     return NULL;
}










