#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(void)
{
	int socketDesc;
	int clientSocket;
	int clientSize;
	struct sockaddr_in serverAddress, clientAddress;
	char serverMSG[2000];
	char clientMSG[2000];
	
	memset(serverMSG, '\0', sizeof(serverMSG));
	memset(clientMSG, '\0', sizeof(clientMSG));
	
	socketDesc = socket(AF_INET, SOCK_STREAM, 0);
	
	if (socketDesc < 0)
	{
		printf("Error in creating Socket\n");
		return -1;
	}
	
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(2000);
	serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	if (bind(socketDesc, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0)
	{
		printf("Error in binding Socket\n");
		return -1;
	}

	
	while(1)
	{
	
		if(listen(socketDesc, 1) < 0)
		{
			printf("Error in listening from Client\n");
		}
	
		printf("Waiting for Client Message\n");
	
		clientSize = sizeof(clientAddress);
	
		clientSocket = accept(socketDesc, (struct sockaddr*)&clientAddress, &clientSize);
	
		if (clientSocket < 0)
		{
		    printf("Accepting Message failed\n");
		    return -1;
		}
		
		printf("Client Connected with IP: %s and Port No: %i\n",inet_ntoa				       (clientAddress.sin_addr),ntohs(clientAddress.sin_port));
		
		if (recv(clientSocket, clientMSG, sizeof(clientMSG),0) < 0)
		{
		    printf("Receiving Message Failed\n");
		    return -1;
		}
		
		printf("Client sends: %s\n",clientMSG);
	
		
		char sendMSG[2000] = "Hello I am server. Your received id is  ";
        sendMSG[strlen(sendMSG) - 1] = clientMSG[strlen(clientMSG) - 1];

        strcpy(serverMSG, sendMSG);
	
		if (send(clientSocket, serverMSG, strlen(sendMSG),0)<0)
		{
		    printf("Sending message failed\n");
		    return -1;
		}
		
		memset(serverMSG,'\0',sizeof(serverMSG));
		memset(clientMSG,'\0',sizeof(clientMSG));
    
    }
    
    close(clientSocket);
    close(socketDesc);
    return 0;
}
