#include <iostream>
#include <cerrno>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>

void Usage(std::string proc)
{
    std::cout<< "Usage: \n\t" << proc << "server_ip server_port" <<std::endl;
}
int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        Usage(argv[0]);
        return 0;
    }
    //1.创建套接字，打开网络文件
    int sock = socket(AF_INET,SOCK_DGRAM,0);
    if(sock < 0)
    {
        std::cerr << "socket create error " << errno << std::endl;
        return 1;
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    server.sin_addr.s_addr = inet_addr(argv[1]);
             
    //2.使用服务
    while(1)
    {
        std::string message;
        std::cout<< "请输入#：" << std::endl;
        std::cin >> message;

        sendto(sock, message.c_str(), message.size(), 0, (struct sockaddr*)&server, sizeof(server));

        struct sockaddr_in tmp;
        socklen_t len = sizeof(tmp);
        char buffer[1024];
        recvfrom(sock,buffer, sizeof(buffer), 0, (struct sockaddr*)&tmp, &len);
        std::cout << "server# "<< buffer << std::endl;  
    }
    return 0;
}