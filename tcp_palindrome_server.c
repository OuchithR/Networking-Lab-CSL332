/* Code for checking palindrome or not using tcp connection.
This is the server side program code.
client side program is in the file named "tcp_client.c" and "tcp_client_short_vesrion.c" either of this can be used */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
int main(){
int socket_desc,client_sock,client_size;
struct sockaddr_in server_addr,client_addr;
char server_message[2000],client_message[2000];

socket_desc = socket(AF_INET,SOCK_STREAM,0);
printf("\n..........socket created successfully.........\n");

server_addr.sin_family = AF_INET;
server_addr.sin_port = htons(2000);
server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

bind(socket_desc,(struct sockaddr*)&server_addr,sizeof(server_addr));
printf("\n...........binding done........................\n");

listen(socket_desc,1);
printf("\n.............listening............................\n");

client_size = sizeof(client_addr);
client_sock = accept(socket_desc,(struct sockaddr*)&client_addr,&client_size);
printf("\n...............accepting incoming messages..........\n");
while(1){

int i,j,flag;
flag=1;
memset(server_message,'\0',sizeof(server_message));
memset(client_message,'\0',sizeof(client_message));

recv(client_sock,client_message,sizeof(client_message),0);

printf("\n Message from client : %s ",client_message);

if(strcmp(client_message,"exit")==0)
{
exit(0);
}
for(i=strlen(client_message)-1,j=0;i>j;i--,j++)
{
  if(client_message[i]!=client_message[j])
  {
    flag=0;
    break;
  }
}
if(flag==1)
{
  strcpy(server_message,"Palindrome");
}
else
{
strcpy(server_message,"Not palindrome");
}

send(client_sock,server_message,strlen(server_message),0);
}

}
