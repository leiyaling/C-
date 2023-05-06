#include <iostream>
#include <cerrno>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <strings.h>
std::string Usage(std::string proc)
{
    std::cout << "Usage: \n\t" << proc << "server_ip server_port" << std::endl;
}
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        Usage(argv[0]);
        return 1;
    }

    std::string svr_ip = argv[1];
    uint16_t svr_port = atoi(argv[2]);
    // 1.创建套接字
    int sock = socket(AF_INET, SOCK_STREAM, 0); // SOCK_STREAM---tcp
    if (sock < 0)
    {
        std::cerr << "socket error " << errno << std::endl;
        return 2;
    }

    //2.bind
    struct sockaddr_in server;
    bzero(&server,sizeof(server));
    server.sin_family = AF_INET;
    //将点分十进制的字符串风格deip转化为4字节ip
    //将4字节由主机序列转化为网络序列
    server.sin_addr.s_addr = inet_addr(svr_ip.c_str());
    server.sin_port = htons(svr_port);
    //发起连接
    if(connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0)
    {
        std::cout << "connect server failed!" <<std::endl;
        return 3;
    }
    std::cout << "connect success!" << std::endl;

    //进行正常的业务请求
    while(true)
    {
        std::cout << "Please Enter# " ;
        char buffer[1024];
        fgets(buffer,sizeof(buffer)-1, stdin);

        write(sock, buffer, strlen(buffer));

        ssize_t s = read(sock, buffer, sizeof(buffer)-1);
        if(s > 0)
        {
            buffer[s] = 0;
            std::cout << "server echo# " << buffer << std::endl;
        }

    }
}