#include <iostream>
#include <cerrno>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
const uint16_t port = 8080;//计算机上的变量，是主机序列
//udp_server
int main()
{
    //1.创建套接字，打开网络文件
    int sock = socket(AF_INET,SOCK_DGRAM,0);//SOCK_DGRAM--udp
    if(sock < 0)
    {
        std::cerr << "socket create error " << errno << std::endl;
        return 1;
    }

    //2.给该服务器绑定端口和ip
    struct sockaddr_in local;
    local.sin_family = AF_INET;
    local.sin_port = htons(port);//需要主机转网络

    //in_addr_t inet_addr(const char* cp) 将人识别的点分十进制、字符串风格IP地址转化为4字节整数ip,并且考虑大小端
    //local.sin_addr.s_addr = inet_addr("1.12.58.36");//点分十进制，字符串风格
    //如果bind的是确定的IP（主机），意味着只有发送到该IP主机上面的数据才会交给网络进程，
    //但是，一般服务器可能有多张网卡，配置多个IP，我们需要的不是某个IP上面的数据，我们需要的是所有发送到该主机该端口的数据
    local.sin_addr.s_addr = INADDR_ANY;


    if(bind(sock, (struct sockaddr*)&local, sizeof(local)) < 0)
    {
        std::cerr << "bind error " << errno << std::endl;
        return 2;
    }

    //3.提供服务
    bool quit = false;
    #define NUM 1024
    char buffer[NUM];
    while(!quit)
    {
        struct sockaddr_in peer;
        socklen_t len = sizeof(peer);

        recvfrom(sock, buffer, sizeof(buffer)-1, 0, (struct sockaddr*)&peer, &len);
        std::cout << "client# "<< buffer << std::endl;

        std::string echo_hello = "hello";
        sendto(sock, echo_hello.c_str(), echo_hello.size(), 0, (struct sockaddr*)&peer, len);
    }
    return 0;
}