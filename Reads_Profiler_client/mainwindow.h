#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>
#include "utils.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //methods
    void connectToServer();
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //variables
    QString ip_address;
    int port;
    int socket_descriptor;
    struct sockaddr_in server; // structura pentru conectare


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
