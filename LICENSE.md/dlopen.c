#include <stdio.h>
#include <dlfcn.h>
#include"node.h"
int main(){
    void *handle=dlopen("movie/libmovie.so",RTLD_NOW);
    if(handle==NULL){
        perror("dlopen");
        return -1;
    }
    printf("loaded success...\n");
    link lnk;
    void (*p)(link *);//声明一个初始化链表的函数指针
    p=dlsym(handle,"link_init");//在动态库中找到要初始化的函数名字
    p(&lnk);//对这个函数进行初始化
    int (*p1)(link *);
    p1=dlsym(handle,"link_size");
    printf("size:%d\n",p1(&lnk));
    dlclose(handle);
return 0;
}
