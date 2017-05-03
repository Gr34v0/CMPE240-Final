
int network_setup(char host, int portno);

void network_send(char message, int* sockfd);

void network_close(int sockfd);