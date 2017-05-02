#include <stdio.h> /* printf, sprf */
#include <stdlib.h> /* exit */
#include <unistd.h> /* read, write, close */
#include <string.h> /* memcpy, memset */
#include "network.h"
#include "sensor.h"

void error(const char *msg) { perror(msg); exit(0); }

int main(int argc,char *argv[])
{    

    network_setup();

    // Collect data

    

    return 0;
}
