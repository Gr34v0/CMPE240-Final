#include <stdio.h> /* printf, sprf */
#include <stdlib.h> /* exit */
#include <unistd.h> /* read, write, close */
#include <string.h> /* memcpy, memset */
#include <pthread.h>
#include "network.h"
#include "sensor.h"

void error(const char *msg) { perror(msg); exit(0); }

int main(int argc,char *argv[])
{    

    int portno =        80;
    char *host =        argv[1]; //Must be IP address of host
    char *message_fmt = "POST %s"; //String is meant to be the data we're sending
    int sockfd;
    char message[1024],response[4096];
    double values[360];
    int sendable = 0;

    if (argc < 2) { puts("Parameters: <target ip address>"); }

    printf("IP Address = %s", host);

    /* fill in the parameters */
    printf("Request: %s\n",message);

    //Start network connection
    sockfd = network_setup(host, portno);

    // Collect data...
    pthread_t tid;
    //pthread_create(&tid, NULL, collect_data, NULL);

    while(1){

        if(1 == 1)
        {
            collect_data(values, sendable);
        }

        // Send data
        //network_send(message, sockfd);

    }
    // Close the network socket
    network_close(sockfd);

    //pthread_exit(NULL);

    return 0;
}
