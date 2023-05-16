#include "comm.hpp"
#include <unistd.h>
int main()
{
    Init init(SERVER);
    char* start = init.getStart();

    int n = 0;
    while(n <= 26)
    {
        cout<<"client -> server#"<<start<<endl;
        sleep(1);
        n++;
    }
    // //1.创建key
    // key_t k = getKey();
    // cout<<"server key:"<<toHex(k)<<endl;

    // //2.创建共享内存
    // int shmid = createShm(k,gsize);
    // cout<<"server shmid:"<<shmid<<endl;

    // //3.将自己和共享内存关联起来
    // char* start = attachShm(shmid); 
    // sleep(5);
    // //4.将自己和共享内存去关联
    // detachShm(start);
    // //删除共享内存
    // delShm(shmid);
    return 0;
}
