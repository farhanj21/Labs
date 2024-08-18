#include <stdio.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 

int main(void)
{
        char arr[10][1000]; 
        int arrPtr = 9;
        int sCapacity = 10;
        int socket_desc;
        struct sockaddr_in server_addr, client_addr;
        char serverMSG[2000], clientMSG[2000]; 
        int client_struct_length = sizeof(client_addr);
        
        
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
        
        if(bind(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr))<0)
        {
                printf("Error Binding Failed\n");
                return -1;
        }        
        
        printf("Binding Done\n");
        
        while(1)
        {
        printf("Listening for Messages\n");

        
        if (recvfrom(socket_desc, clientMSG, sizeof(clientMSG), 0, (struct sockaddr*)&client_addr,&client_struct_length) < 0)
        {
                printf("Error Receiving Failed\n");
                return -1;
        }
  	
  	 if(clientMSG[strlen(clientMSG) - 1] == 'I') 
  	 {
  	 	int i = arrPtr;
  	 	int exists = 0;
  	 	if(arrPtr == 0)
  	 	{
  	 		strcpy(serverMSG, "Server Full!");
  	 	}
  	 	for(; i <= sCapacity; i++)
  	 	{
  	 		if(strcmp(arr[i], clientMSG) == 0)
  	 		{
  	 			strcpy(serverMSG, "You are already checked in!");
  	 			exists = 1;
  	 		}
  	 	}
  	 	if(exists == 0)
  	 	{
  	 		strcpy(arr[arrPtr], clientMSG);
  	 		strcpy(serverMSG, "Check In Successful!");
  	 		arrPtr--;
  	 	}
  	 }
  	 else if(clientMSG[strlen(clientMSG) - 1] == 'O')
  	 {
  	 	int i = arrPtr;
  	 	int notExists = 1;
  	 	for(; i < sCapacity; i++)
  	 	{
  	 		char pseudo[100];
  	 		strcpy(pseudo, clientMSG);
  	 		pseudo[strlen(pseudo) - 1] = 'I';
  	 		if(strcmp(arr[i], pseudo) == 0)
  	 		{
  	 			strcpy(serverMSG, "GoodBye");
  	 			strcpy(arr[i], "no");
  	 			notExists = 0;
  	 			arrPtr++;
  	 			break;
  	 		}
  	 	}
  	 	if(notExists == 0 && i != 0)
  	 	{
	  	 	int j = i;
	  	 	for(; j > arrPtr; j--)
	  	 	{
	  	 		bzero(arr[j], 0);
	  	 		strcpy(arr[j], arr[j - 1]);
	  	 	}
	  	}
  	 	if(notExists == 1)
  	 	{
  	 		strcpy(serverMSG, "You Did not check in today! Contact Administrator");
  	 	}
  	 }
  	 else
  	 {
  	 	strcpy(serverMSG, "Wrong Input Format");
  	 }
        printf("Received Message from IP: %s and Port No: %i\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));

        printf("Client Message: %s\n",clientMSG);
        
        
        if (sendto(socket_desc, serverMSG, strlen(serverMSG), 0, (struct sockaddr*)&client_addr,client_struct_length)<0)
        {
                printf("Send Failed. Error!!!!!\n");
                return -1;
        }
        
        memset(serverMSG,'\0',sizeof(serverMSG));
        memset(clientMSG,'\0',sizeof(clientMSG));
              
        }
        close(socket_desc);
        return 0;       
}
