#ifndef DATABASEHELPER_H
#define DATABASEHELPER_H

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

class DatabaseHelper
{
public:
    DatabaseHelper();
    QString getAllBooks();
    QString userLogin(QString username, QString password);
    QString userRegister(QString username, QString password);
    QString getAuthor(QString param);
    QString getGenre(QString param);
    QString getBook(QString param);


private:
    QSqlDatabase db;
};

#endif // DATABASEHELPER_H
