#include <iostream>
#include <cerrno>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <signal.h>
std::string Usage(std::string proc)
{
    std::cout << "Usage: \n\t" << proc << "port" << std::endl;
}

void ServiceIO(int new_sock)
{
    // 提供服务
        while (true)
        {
            char buffer[1024];
            memset(buffer, 0, sizeof(buffer));
            ssize_t s = read(new_sock, buffer, sizeof(buffer) - 1);
            if (s > 0)
            {
                buffer[s] = 0;//将获取的内容当成字符串
                std::cout << "client# " << buffer << std::endl;

                std::string echo_string = ">>>server<<<,";
                echo_string += buffer;

                write(new_sock, echo_string.c_str(), echo_string.size());
            }
            else if(s == 0)
            {
                std::cout << "client quit ..." << std::endl;
                break;
            }
            else
            {
                std::cerr << "read error" << std::endl;
                break;
            }
        }
}
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        Usage(argv[0]);
        return 1;
    }
    // 1.创建套接字
    int listen_sock = socket(AF_INET, SOCK_STREAM, 0); // SOCK_STREAM---tcp
    if (listen_sock < 0)
    {
        std::cerr << "socket error " << errno << std::endl;
        return 2;
    }

    // 2.bind:绑定
    struct sockaddr_in local;
    memset(&local, 0, sizeof(local));
    local.sin_family = AF_INET;
    local.sin_port = htons(atoi(argv[1]));
    local.sin_addr.s_addr = INADDR_ANY;

    if (bind(listen_sock, (struct sockaddr *)&local, sizeof(local)) < 0)
    {
        std::cerr << "bind error " << errno << std::endl;
        return 3;
    }
    // 3.tcp是面向连接的，在通信前需要建立连接然后才能通信
    // 设置套接字是listen状态，本质是允许用户连接
    const int back_log = 5;
    if (listen(listen_sock, back_log) < 0)
    {
        std::cerr << "listen error" << std::endl;
        return 4;
    }
    //signal(SIGCHLD,SIG_IGN);//父进程忽略子进程的SIGCHLD信号，子进程会自动退出释放资源
    for (;;)
    {
        struct sockaddr_in peer;
        socklen_t len = sizeof(peer);
        int new_sock = accept(listen_sock, (struct sockaddr *)&peer, &len); // accept返回值是一个文件描述符
        if (new_sock < 0)
            continue;

        uint16_t cli_port = ntohs(peer.sin_port);
        std::string cli_ip = inet_ntoa(peer.sin_addr);

        std::cout << "get a new link-> : [" << cli_ip << ":" << cli_port <<"]# "<< new_sock << std::endl;

        pid_t id = fork();
        if(id < 0)
        {
            continue;
        }
        else if(id == 0)//曾经被父进程打开的fd，会被子进程继承，无论父子进程的哪一个，需要关闭文件描述符
        {
            //child
            close(listen_sock);
            if(fork() > 0) exit(0);
            ServiceIO(new_sock);
            close(new_sock);
            exit(0);
        }
        else
        {
            //parent
        }

        //ServiceIO(new_sock);
    }
    return 0;
}