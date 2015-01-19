#ifndef NETWORKCONNECTION_H
#define NETWORKCONNECTION_H

#include <QString>
#include <QDebug>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <pthread.h>
#include "netdb.h"
#include "utils.h"

typedef struct threadData{
    int idThread; //id-ul thread-ului tinut in evidenta de acest program
    int client; //descriptorul intors de accept
}threadData;

class NetworkConnection
{
public:
    //methods
    NetworkConnection();
    void startServer();
    void *treat(void*);
    void response(void*);


    //variables
    int port;
    struct sockaddr_in server; //structura folosita de server
    struct sockaddr_in from;
    int socket_descriptor;
    int client;
    pthread_t threads[100];
};

#endif // NETWORKCONNECTION_H
