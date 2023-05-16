#include "comm.hpp"
#include <unistd.h>
#include <string>
#include <vector>
int main()
{
    Init init(CLIENT);
    char* start = init.getStart();

    char c = 'A';

    while(c <= 'Z')
    {
        start[c - 'A'] = c;
        c++;
        start[c - 'A'] = '\0';
        sleep(1);
    }
    // //1.创建key
    // key_t k = getKey();
    // cout<<"client key:"<<toHex(k)<<endl;

    // //2.创建共享内存
    // int shmid = createShm(k,gsize);
    // cout<<"client shmid:"<<shmid<<endl;

    // //3.将自己和共享内存关联起来
    // char* start = attachShm(shmid);

    // sleep(10);
    // //4.将自己和共享内存去关联
    // detachShm(start);
    return 0;
}