/* This is a shorter version without error handling only for easy understanding. Follow the standard code of tcp server and client which include error handling. I have uploaded the standard version of tcp server under the file name : "tcp_server.c"*/
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(void)
{
    int socket_desc, client_sock, client_size;
    struct sockaddr_in server_addr, client_addr;
    char server_message[2000], client_message[2000];
    
    // Create socket:
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    printf("Socket created successfully\n");
    
    // Set port and IP:
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(2000);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    // Bind to the set port and IP:
    bind(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr));
    printf("Done with binding\n");
    
    // Listen for clients:
    listen(socket_desc, 1);
    printf("\n Listening for incoming connections.....\n");
    
    // Accept an incoming connection:
    client_size = sizeof(client_addr);
    client_sock = accept(socket_desc, (struct sockaddr*)&client_addr, &client_size);
    
    while(1){
      // Clean buffers:
      memset(server_message, '\0', sizeof(server_message));
      memset(client_message, '\0', sizeof(client_message));
      
    // Receive client's message:
    recv(client_sock, client_message, sizeof(client_message), 0);
    if(strcmp(client_message,"exit")==0)
      {
      exit(0);
      }
    else{  
    printf("Msg from client: %s\n", client_message);
    }
    
   // Get input from the user:
    printf("Enter message: ");
    gets(server_message);
    send(client_sock, server_message, strlen(server_message), 0);
    }
    
    // Closing the socket:
    close(client_sock);
    close(socket_desc);
    
    return 0;
}

