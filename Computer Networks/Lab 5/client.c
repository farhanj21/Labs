#include <stdio.h>
#include <string.h>
#include <sys/socket.h> 
#include <arpa/inet.h> 

int main(void)
{
        int socket_desc;
        struct sockaddr_in server_addr;
        char serverMSG[2000], clientMSG[2000];   
        int server_struct_length = sizeof(server_addr);
        
        
        memset(serverMSG,'\0',sizeof(serverMSG));
        memset(clientMSG,'\0',sizeof(clientMSG));
        
        
        socket_desc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        
        if(socket_desc < 0)
        {
                printf("Error creating Socket\n");
                return -1;
        }
        
        printf("Socket Created\n");

        
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(2000);
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  

        
        printf("Enter Message: ");
        gets(clientMSG);
        
        
        if(sendto(socket_desc, clientMSG, strlen(clientMSG), 0, (struct sockaddr*)&server_addr, server_struct_length) < 0)
        {
                printf("Error Sending Failed\n");
                return -1;
        }

        
        if(recvfrom(socket_desc, serverMSG, sizeof(serverMSG),0, (struct sockaddr*)&server_addr, &server_struct_length) < 0)
        {
                printf("Error Receiving Failed\n");
                return -1;
        }
        
        printf("Server Message: %s\n",serverMSG);
        
        memset(serverMSG,'\0',sizeof(serverMSG));
        memset(clientMSG,'\0',sizeof(clientMSG));
        
        
        close(socket_desc);
        
        return 0;
}
