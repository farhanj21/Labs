#include <stdio.h>
#include <string.h>
#include <sys/socket.h> 
#include <arpa/inet.h> 

int main(void)
{
        int socketDesc;
        struct sockaddr_in serverAddress;
        char serverMSG[2000];
        char clientMSG[2000];
        
        memset(serverMSG,'\0',sizeof(serverMSG));
        memset(clientMSG,'\0',sizeof(clientMSG));
         
        socketDesc = socket(AF_INET, SOCK_STREAM, 0);
        
        if(socketDesc < 0)
        {
                printf("Error creating socket\n");
                return -1;
        }
        
        serverAddress.sin_family = AF_INET;
        serverAddress.sin_port = htons(2000);
        serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
        
        if(connect(socketDesc, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0)
        {
                printf("Connection to server failed");
                return -1;
        }
        
        printf("Connected to Server\n");
        
        printf("Enter Message: ");
        gets(clientMSG);                                     
        
        if(send(socketDesc, clientMSG, strlen(clientMSG),0) < 0)
        {
                printf("Sending Message Failed\n");
                return -1;
        }
        
        
        if(recv(socketDesc, serverMSG, sizeof(serverMSG),0) < 0)
        {
                printf("Receiving Message Failed\n");
                return -1;
        }
        
        printf("Server Message: %s\n",serverMSG);
        
        memset(serverMSG,'\0',sizeof(serverMSG));
        memset(clientMSG,'\0',sizeof(clientMSG));
        
        close(socketDesc);
        
        return 0;
}
