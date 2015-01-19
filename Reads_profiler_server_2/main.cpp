#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include <databasehelper.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>

using namespace std;

/* portul folosit */
#define PORT 2022

/* codul de eroare returnat de anumite apeluri */
extern int errno;

DatabaseHelper *database;

void signal_handler( int sig );
int TreatClient(int clientSocket, int nr);

int main(int argc, char *argv[])
{
    struct sockaddr_in server;	// structura folosita de server
    struct sockaddr_in from;
    int sd; 			//descriptorul de socket
    int on, status, nr = 0;

    QCoreApplication a(argc, argv);

    qDebug() << "===>>>   READS PROFILER SERVER   <<<==" << endl;

    database =  new DatabaseHelper();

    qDebug() << "Starting server on port: " << PORT << "..." << endl;

    // inregistram a procedura de tratare a semnalelor de tipul SIGCHLD
    if( signal(SIGCHLD, signal_handler) < 0 )
    {
        printf("[Server]Error on signal() : %d\n", errno);
        exit(-5);
    }
    qDebug() << ".....";
    /* crearea unui socket */
    if ((sd = socket (AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror ("[server]Eroare la socket().\n");
        return errno;
    }
    qDebug() << ".....";

    // adaugam optiunea SO_REUSEADDR socketului pentru a putea refolosi portul
    on = 1;
    status = setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, (const char *) &on, sizeof(on));

    if ( status == -1 )
    {
        printf("[server]Eroare la setsockopt() : %d\n", errno);
        exit(-1);
    }
    qDebug() << ".....";

    /* pregatirea structurilor de date */
    bzero (&server, sizeof (server));
    bzero (&from, sizeof (from));

    /* umplem structura folosita de server */
    /* stabilirea familiei de socket-uri */
    server.sin_family = AF_INET;
    /* acceptam orice adresa */
    server.sin_addr.s_addr = htonl (INADDR_ANY);
    /* utilizam un port utilizator */
    server.sin_port = htons (PORT);

    /* atasam socketul */
    if (bind (sd, (struct sockaddr *) &server, sizeof (struct sockaddr)) == -1)
    {
        printf("[server]Eroare la bind() : %d.\n", errno);
        exit(-2);
    }
    qDebug() << ".....";

    /* punem serverul sa asculte daca vin clienti sa se conecteze */
    if (listen (sd, 5) == -1)
    {
        printf ("[server]Eroare la listen() : %d.\n", errno);
        exit(-3);
    }
    qDebug() << ".....";

    /* servim in mod iterativ clientii... */
    while (1)
    {
        int client;
        int length = sizeof (from);

        printf ("[server]Asteptam la portul %d...\n",PORT);
        fflush (stdout);

        /* acceptam un client (stare blocanta pina la realizarea conexiunii) */
        client = accept (sd, (struct sockaddr *) &from, (socklen_t*)&length);
        nr++;

        /* eroare la acceptarea conexiunii de la un client */
        if (client < 0)
        {
            printf ("[server]Eroare la accept() : %d.\n", errno);
            continue;
        }

        printf("[server]Client number %d connected\n", nr);
        // tratam clientul
        TreatClient(client, nr);
    }



    return a.exec();
}

// handler ce va trata semnalele de tipul SIGCHLD, pentru a inchide procese copil suspendate
void signal_handler( int sig )
{
    printf("[Server]Cought signal SIGCHLD\n");
    while( waitpid(-1, NULL, WNOHANG) > 0 )
    {
    }
}

// functie ce trateaza indivitual un client
// <clientSocket> reprezinta descriptorul de socket care va fi folosit
// in comunicarea cu clientul
// <nr> reprezinta numarul de ordine al clientului
int TreatClient(int clientSocket, int nr)
{
    pid_t pid;

    // pentru a putea servi concurent clientii trebuie sa cream un proces copil
    // care va servi un client
    if( ( pid = fork() ) == -1 )
    {
        printf("[server]Eroare la fork() : %d\n", errno);
        exit(-1);
    }
    if( pid == 0 )
    {
        // process copil
        // tratam clientul
        int count, size = 0;
        char message[256], answer[256];
        char *pmsg = message;

        bzero(message, 256);
        bzero(answer, 256);

        qDebug() << "aici1";
        // citim dimensiunea mesajului
        if( ( count = read(clientSocket, &size, sizeof(int))) < 0 )
        {
            printf("[Child %d]Read error : %d\n", nr, errno);
            exit(-3);
        }

        qDebug() << size <<"; aici2";
        // citim mesajul in totalitate
        while( ( count = read(clientSocket, pmsg, size)) > 0 )
        {
            pmsg += count;
            size -= count;
            printf("count %d\n", count);
        }


        qDebug() << database->getAllBooks();


        exit(0);
    }
    if( pid > 0 )
    {
        close(clientSocket);
    }

}
