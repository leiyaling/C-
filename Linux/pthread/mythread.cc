
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>
// #include <pthread.h>
// void *thread1(void *arg)
// {
//     printf("thread 1 returning ... \n");
//     int *p = (int *)malloc(sizeof(int));
//     *p = 1;
//     return (void *)p;
// }
// void *thread2(void *arg)
// {
//     printf("thread 2 exiting ...\n");
//     int *p = (int *)malloc(sizeof(int));
//     *p = 2;
//     pthread_exit((void *)p);
// }
// void *thread3(void *arg)
// {
//     while (1)
//     { //
//         printf("thread 3 is running ...\n");
//         sleep(1);
//     }
//     return NULL;
// }
// int main(void)
// {
//     pthread_t tid;
//     void *ret;
//     // thread 1 return
//     pthread_create(&tid, NULL, thread1, NULL);
//     pthread_join(tid, &ret);
//     printf("thread return, thread id %X, return code:%d\n", tid, *(int *)ret);
//     free(ret);
//     // thread 2 exit
//     pthread_create(&tid, NULL, thread2, NULL);
//     pthread_join(tid, &ret);
//     printf("thread return, thread id %X, return code:%d\n", tid, *(int *)ret);
//     free(ret);
//     // thread 3 cancel by other
//     pthread_create(&tid, NULL, thread3, NULL);
//     sleep(3);
//     pthread_cancel(tid);
//     pthread_join(tid, &ret);
//     if (ret == PTHREAD_CANCELED)
//         printf("thread return, thread id %X, return code:PTHREAD_CANCELED\n", tid);
//     else
//         printf("thread return, thread id %X, return code:NULL\n", tid);
// }
// #include <iostream>
// #include <pthread.h>
// #include <unistd.h>

// using namespace std;
// static int retvalue;//线程返回值

// void *threadRun1(void *args)
// {
//     cout << "我是子线程1..." << endl;
//     retvalue = 1;
//     return (void *)&retvalue;
// }
// void *threadRun2(void *args)
// {
//     cout << "我是子线程2..." << endl;
//     retvalue = 2;
//     pthread_exit((void *)&retvalue);
// }
// void *threadRun3(void *arg)
// {
//     while (1)
//     {
//         cout << "我是子线程3..." << endl;
//         sleep(1);
//     }
//     return NULL;
// }
// int main()
// {
//     pthread_t tid;
//     void *ret;

//     // threadRun1 return
//     pthread_create(&tid, NULL, threadRun1, NULL);
//     pthread_join(tid, &ret);
//     cout << "子线程1返回... 返回值：" << *(int *)ret << endl;

//     // threadRun2 exit
//     pthread_create(&tid, NULL, threadRun2, NULL);
//     pthread_join(tid, &ret);
//     cout << "子线程2返回... 返回值：" << *(int *)ret << endl;

//     // threadRun3 cancel by other
//     pthread_create(&tid, NULL, threadRun3, NULL);
//     sleep(3);
//     pthread_cancel(tid);
//     pthread_join(tid, &ret);
//     if (ret == PTHREAD_CANCELED)
//         cout << "子线程3返回... 返回值:PTHREAD_CANCELED" << endl;
//     else
//         cout << "子线程3返回... 返回值:NULL" << endl;

// }
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>
// #include <pthread.h>
// void *thread_run(void *arg)
// {
//     pthread_detach(pthread_self());
//     printf("%s\n", (char *)arg);
//     return NULL;
// }
// int main(void)
// {
//     pthread_t tid;
//     if (pthread_create(&tid, NULL, thread_run, (void *)"thread1 run...") != 0)
//     {
//         printf("create thread error\n");
//         return 1;
//     }
//     int ret = 0;
//     sleep(1); // 很重要，要让线程先分离，再等待
//     if (pthread_join(tid, NULL) == 0)
//     {
//         printf("pthread wait success\n");
//         ret = 0;
//     }
//     else
//     {
//         printf("pthread wait failed\n");
//         ret = 1;
//     }
//     return ret;
// }

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;
int running = 1;//线程运行控制
int cnt = 5;

//生产者
void *producter_f (void *arg)
{
    int semval = 0;
    while (running)
    {
        usleep(1);
        sem_post(&sem);//信号量增加
        sem_getvalue(&sem,&semval);//获取信号量的值
        printf("生产，总数量:%d\n",semval); 
    }
}

//消费者
void *consumer_f (void *arg)
{
    int semval = 0;
    while (running)
    {
        usleep(1);
        sem_wait(&sem);//信号量增加
        sem_getvalue(&sem,&semval);//获取信号量的值
        printf("消费，总数量:%d\n",semval); 
    }
}
int main ()
{
    pthread_t consumer_t;//消费者线程参数
    pthread_t producter_t;//生产者线程参数
    sem_init(&sem , 0, 16);//信号量初始化
    pthread_create(&producter_t, NULL, producter_f, NULL);//建立生产者线程
    pthread_create(&consumer_t, NULL,consumer_f, NULL) ;//建立消费者线程
    usleep(1) ;//等待
    running =0;//设置线程退出值
    pthread_join(consumer_t, NULL);//等待消费者线程退出
    pthread_join (producter_t, NULL) ;//等待生产者线程退出
    sem_destroy(&sem);//信号量销毁
    return 0;

}




