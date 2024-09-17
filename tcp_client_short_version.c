/* This is a shorter version without error handling only for easy understanding. Follow the standard code of tcp server and client which include error handling. I have uploaded the standard version of tcp client under the file name : "tcp_client.c"*/
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main()
{
    int socket_desc;
    struct sockaddr_in server_addr;
    char server_message[2000], client_message[2000];
    
    // Create socket:
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    printf("...............Socket created successfully..............\n");
    
    // Set port and IP the same as server-side:
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(2000);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    // Send connection request to server:
    connect(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr));
    printf("..............Connected with server successfully.............\n");
   while(1){ 
    // Clean buffers:
    memset(server_message,'\0',sizeof(server_message));
    memset(client_message,'\0',sizeof(client_message));
    
    // Get input from the user:
    printf("Enter message: ");
    gets(client_message);
    
    // Send the message to server: 
    // if enter "exit" close server and client
    if(strcmp(client_message,"exit")==0)
    {
    send(socket_desc, client_message, strlen(client_message), 0);
    exit(0);
    }
    
    send(socket_desc, client_message, strlen(client_message), 0);
    
    // Receive the server's response:
    recv(socket_desc, server_message, sizeof(server_message), 0); 
    printf("Message from the server: %s\n",server_message);
    }
    // Close the socket:
    close(socket_desc);
    
    return 0;
}

