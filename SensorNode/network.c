#include <stdio.h> /* printf, sprf */
#include <stdlib.h> /* exit */
#include <unistd.h> /* read, write, close */
#include <string.h> /* memcpy, memset */
#include <sys/socket.h> /* socket, connect */
#include <netinet/in.h> /* struct sockaddr_in, struct sockaddr */
#include <netdb.h> /* struct hostent, gethostbyname */

#include "network.h"
#include "errorhandle.h"

int bytes, sent, total; //I know, I know... Ew. Whatever

int network_setup(char* host, int portno, int sockfd)
{
    #if debug
        debug_msg("Enter Network Setup\n");
    #endif

    struct hostent *server;
    struct sockaddr_in serv_addr;

    /* create the socket */
    #if debug
        debug_msg("Creating socket\n");
    #endif
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error_handle("ERROR opening socket\n");

    /* lookup the ip address */
    server = gethostbyname(host);
    printf("%s", server->h_addr);
    if (server == NULL) error_handle("ERROR, no such host\n");

    /* fill in the structure */
    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    memcpy(&serv_addr.sin_addr.s_addr,server->h_addr,server->h_length);

    /* connect the socket */
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
        error_handle("ERROR connecting");

    #if debug
        debug_msg("sockfd Returned\n");
    #endif

    return sockfd;
}

void network_send(char* message, int sockfd)
{
    #if debug
        debug_msg("Initialize network_send\n");
    #endif
    /* send the request */
    total = strlen(message);
    sent = 0;
    #if debug
        debug_msg("Start network_send While Loop\n")
    #endif
    do {
        bytes = write(sockfd,message+sent,total-sent);
        if (bytes < 0)
            error_handle("ERROR writing message to socket\n");
        if (bytes == 0)
            break;
        sent+=bytes;
    } while (sent < total);

    #if debug
        debug_msg("Sent complete\n")
    #endif
    
}

void network_close(int sockfd)
{
    #if debug
            debug_msg("Network Socket Closing\n");
    #endif
    close(sockfd);
}