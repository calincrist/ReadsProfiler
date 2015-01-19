#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->ip_address = "127.0.0.1";
    this->port = 2022;

    /* cream socketul */
    if ((this->socket_descriptor = socket (AF_INET, SOCK_STREAM, 0)) == -1)
    {
        printf ("Eroare la socket() : %d.\n", errno);
        exit(-1);
    }

    // connecting to server
    this->connectToServer();
}

void MainWindow::connectToServer() {
    /* umplem structura folosita pentru realizarea conexiunii cu serverul */
    this->server.sin_family = AF_INET; // familia socket-ului
    this->server.sin_addr.s_addr = inet_addr(Utils::qtStringToChar(this->ip_address)); // adresa IP a serverului
    this->server.sin_port = htons(this->port); // portul de conectare

    /* ne conectam la server */
    if (::connect (socket_descriptor, (struct sockaddr *) &server,sizeof (struct sockaddr)) == -1)
    {
        printf ("[client]Eroare la connect() : %d.\n", errno);
        exit(-2);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
