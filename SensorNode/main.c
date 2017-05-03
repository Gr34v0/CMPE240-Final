#include <stdio.h> /* printf, sprf */
#include <unistd.h> /* read, write, close */
#include <string.h> /* memcpy, memset */
#include <pthread.h>
#include "network.h"
#include "sensorinterface.h"
#include "errorhandle.h"

int main(int argc,char *argv[])
{   
    #if debug == 1
        debug_msg("#IF: Debugging initialized\n");
    #endif

    if(debug)
    {
        debug_msg("IF: Debugging initialized\n");
    }


    int portno =        80;
    char *host =        argv[1]; //Must be IP address of host
    char *message_fmt = "POST %s"; //String is meant to be the data we're sending
    int sockfd;
    char message[1024], response[4096];
    double values[360];
    int sendable = 0;

    if (argc < 2) 
    { 
        printf("Parameters: <target ip address>\n");
        return 1;
    }

    printf("IP Address = %s\n\n", host);

    /* fill in the parameters */
    //printf("Request: %s\n\n", message);

    //Start network connection
    sockfd = network_setup(host, portno, sockfd);

    // Collect data...
    pthread_t tid;
    //pthread_create(&tid, NULL, collect_data, NULL);

    while(1){

        #if debug
            debug_msg("Start While Loop\n");
        #endif

        //if()
        //{
            collect_data(values, sendable);
        //}

        #if debug
            debug_msg("Sendable = %d\n", sendable);
        #endif
        // Send data
        //network_send(message, sockfd);

    }
    // Close the network socket
    network_close(sockfd);
    #if debug
            debug_msg("Network Socket Closed\n");
    #endif

    //pthread_exit(NULL);

    return 0;
}
