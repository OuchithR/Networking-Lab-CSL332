#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
int main()
{
FILE *fp1;
char s[100],f[100];
printf("Enter file name : ");
scanf("%s",f);
fp1=fopen(f,"r");

int socket_desc;
struct sockaddr_in server_addr;
char server_message[2000],client_message[2000];

socket_desc = socket(AF_INET,SOCK_STREAM,0);
printf("\n..............socket created successfully................\n");

server_addr.sin_family = AF_INET;
server_addr.sin_port = htons(2000);
server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

connect(socket_desc,(struct sockaddr*)&server_addr,sizeof(server_addr));
printf("\n..............connected to server..............\n");

fgets(server_message, sizeof(server_message), fp1);
//fscanf(fp1,"%s",s);
//strcpy(server_message,s);

send(socket_desc,server_message,strlen(server_message),0);



}
