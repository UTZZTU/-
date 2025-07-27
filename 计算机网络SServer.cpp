#include <stdio.h> // Needed for printf()
#include <string.h> // Needed for memcpy() and strcpy()
#include <windows.h> // Needed for all Winsock stuff
//-----------------------------------------------------
#define PORT_NUM 1050 // �������˿ں�
#define MAX_LISTEN 3 // ��������
//������
int main(void)
{ WORD wVersionRequested = MAKEWORD(1,1); // Stuff for WSA functions
 WSADATA wsaData; // Stuff for WSA functions
 unsigned int server_s; // Server socket ��ʾ��
 struct sockaddr_in server_addr; // Server ��ַ
 unsigned int client_s; // Client socket ��ʾ��
 struct sockaddr_in client_addr; // Client Internet address
 struct in_addr client_ip_addr; // Client IP address
 int addr_len; // Internet address length
 char out_buf[100]; // 100-byte ���������
 char in_buf[100]; // 100-byte ���ջ�����
 // ��ʼ�� winsock
 WSAStartup(wVersionRequested, &wsaData);
 // ���� socket
 server_s = socket(AF_INET,SOCK_STREAM, 0);
 // ���� socket
 server_addr.sin_family = AF_INET; // Address family to use
 server_addr.sin_port = htons(PORT_NUM); // ʹ�ö˿ں�
 server_addr.sin_addr.s_addr = htonl(INADDR_ANY); //������һ IP ��ַ
 bind(server_s,(struct sockaddr *)&server_addr, sizeof(server_addr));
 // ��������
 listen(server_s, MAX_LISTEN);
 // ��������
 addr_len = sizeof(client_addr);
 client_s = accept(server_s, (struct sockaddr *)&client_addr, &addr_len);
 memcpy(&client_ip_addr, &client_addr.sin_addr.s_addr, 4);
 // ���һ��������ɵ���Ϣ
 printf("Accept completed!!! IP address of client = %s port = %d \n", 
inet_ntoa(client_ip_addr), ntohs(client_addr.sin_port));
 // ��ͻ��˷���һ����Ϣ
 strcpy(out_buf, "Message -- server to client  12357896");
 send(client_s, out_buf, (strlen(out_buf) + 1), 0);
 // ���մӿͻ��˷��ص���Ϣ
 recv(client_s, in_buf, sizeof(in_buf), 0);
 printf("Received from client... data = '%s' \n", in_buf);
 // �ر� sockets
 closesocket(server_s);
 closesocket(client_s);
 // �ͷ� winsock
 WSACleanup();
}
