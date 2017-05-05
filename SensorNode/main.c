#include <stdio.h> /* printf, sprf */
#include <unistd.h> /* read, write, close, sleep */
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


    int portno =        80;
    char *host =        argv[1]; //Must be IP address of host
    char *message_fmt = "POST %s"; //String is meant to be the data we're sending
    int sockfd;
    char message[3072];
    char response[4096];
    double values[360];

    if (argc < 2) 
    { 
        printf("Parameters: <target ip address>\n");
        return 1;
    }

    printf("IP Address = %s\n\n", host);

    /* fill in the parameters */
    //printf("Request: %s\n\n", message);

    //Start network connection 
    #if !nonetwork
        sockfd = network_setup(host, portno, sockfd);
    #endif
    
    //pthread_t tid;
    //pthread_create(&tid, NULL, collect_data, NULL);

    // Collect data...
    while(1){

        int sendable = 0;

        while(!sendable){

            #if debug
                debug_msg("Start While Loop\n");
            #endif

            collect_data(values, &sendable);

            #if debug
                printf("Sendable: %d\n", sendable);
            #endif

            for(int x = 0; x < 360; x++){
                sprintf(&message[x*7], "%1.6f", values[x]);
            }

        }

        #if debug
            debug_msg("Sleeping or 5 Seconds\n");
        #endif
        sleep(5);

        // Send data
        #if !nonetwork
            network_send(message, sockfd);
        #endif
    }

    // Close the network socket
    #if !nonetwork
        network_close(sockfd);
    #endif

    #if debug
            debug_msg("Network Socket Closed\n");
    #endif

    //pthread_exit(NULL);

    return 0;
}
