#include "networkconnection.h"

extern int errno;

NetworkConnection::NetworkConnection()
{
    port = 2021;

    if ((socket_descriptor = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        qDebug() << "Eroare la socket()." << endl;
        qDebug() << errno;
    }

    int on = 1;
    int status = setsockopt(socket_descriptor, SOL_SOCKET, SO_REUSEADDR, (const char*)&on, sizeof(on));
    if (status == -1)
    {
        qDebug() << "Eroare la setsockopt()." << endl;
    }

    bzero(&server, sizeof(server));
    bzero(&from, sizeof(from));

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(port);

    if (bind(socket_descriptor, (struct sockaddr*)&server, sizeof(struct sockaddr)) == -1)
    {
        qDebug() << "Eroare la bind()." << endl;
    }

}

void NetworkConnection::startServer()
{
    int i = 0;

    if (listen(socket_descriptor, 5) == -1)
    {
        qDebug() << "Eroare la listen()." << endl;
    }

    while (1)
    {
        threadData *td;
        socklen_t len = sizeof(from);

        client = accept(socket_descriptor, (struct sockaddr*)&from, &len);
        if (client < 0)
        {
            qDebug() << "Eroare la accept()." << endl;

        }
        else
        {
            qDebug() << "s-a conectat." << endl;
            qDebug() << "IP: " << inet_ntoa(from.sin_addr) << endl ;
            qDebug() << "Port: " << ntohs(from.sin_port) << endl ;

            struct hostent *he;
            he = gethostbyaddr(&from, sizeof(from), AF_INET);
            qDebug() << he->h_name << " " << he->h_aliases << he->h_addr_list << endl;

            int idThread;
            int cl;

            td = (struct threadData*) malloc(sizeof(struct threadData));
            td->client = client;
            td->idThread = i++;

            pthread_create(&threads[i], NULL, &NetworkConnection::treat, td);
        }
    }
}

void* NetworkConnection::treat(void *arg)
{
    struct threadData tdL;
    tdL = *((struct threadData*) arg);

    qDebug() << "thread " << tdL.idThread << endl;
    pthread_detach(pthread_self());

    response((struct threadData*)arg);

    close((int)arg);
    return(NULL);
}

void NetworkConnection::response(void *)
{

}
