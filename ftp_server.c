#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
int main(){
int socket_desc, client_sock,client_size;
struct sockaddr_in server_addr,client_addr;
char server_message[20000],client_message[2000];

FILE *fp1;
char s[100],f[100];

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

recv(client_sock,client_message,sizeof(client_message),0);
printf("Enter destination file : ");
scanf("%s",f);
fp1=fopen(f,"w");
fprintf(fp1,"%s",client_message);


}
