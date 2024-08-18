#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void reverse(int s, int e, char* str)
{
	if (s >= e)
		return;
	else
	{
		reverse(s+1, e-1, str);
		char temp = str[s];
		str[s] = str[e];
		str[e] = temp;
	}
}

int main(void)
{
	int socketDesc;
	int clientSocket;
	int clientSize;
	struct sockaddr_in serverAddress, clientAddress;
	char serverMSG[2000];
	char clientMSG[2000];
	int i = 0, j = 0, flag = 0;
	
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
		
		printf("Client sends: %s\n", clientMSG);
		
		
		
		while(1)
		{
			if (clientMSG[i] == '\0')
				flag = 1;
				
			
			if(!flag)
			{
				while(clientMSG[i + 1] != ' ' && clientMSG[i + 1] != '\0')
				{
					i++;
				}
				
				reverse(j, i, clientMSG);
				i++;
				if(clientMSG[i] != '\0')
					i++;
				else
					break;
					
				j = i;
			}
			
			if (flag)
				break;
		}
        
        strcpy(serverMSG, clientMSG);
	
		if (send(clientSocket, serverMSG, strlen(clientMSG),0)<0)
		{
		    printf("Sending message Failed\n");
		    return -1;
		}
		
		memset(serverMSG,'\0',sizeof(serverMSG));
		memset(clientMSG,'\0',sizeof(clientMSG));
    
    }
    
    close(clientSocket);
    close(socketDesc);
    return 0;
}




