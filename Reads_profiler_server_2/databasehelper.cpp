#include "databasehelper.h"
#include <QtTest/qtest.h>
#include <unistd.h>

DatabaseHelper::DatabaseHelper()
{
    db = QSqlDatabase::addDatabase("QSQLITE", "library");
    db.setDatabaseName("/home/calincrist/Reads_Profiler/Reads_profiler_server_2/library.db");

    if (db.open()) {
        qDebug() << "Loading...";
        for (int i = 0; i < 5; i++) {
            qDebug() << ".";
            sleep(0.5);
        }
        qDebug() << endl;
        qDebug() << "Library database opened successfully." << endl;
    } else {
        qDebug() << "Library database failed to open." << endl;
    }
}

QString DatabaseHelper::userLogin(QString username, QString password)
{
    QSqlQuery query;
    QString result = "";

    qDebug() << "User logging in...";
    if(!db.open()) {
        qDebug() << "Failed to open the database.";
    }

    if (query.exec("SELECT * FROM USER WHERE username='" + username + "' AND password='" + password +"'")){

        int count = 0;

        while (query.next()){
            count++;
        }

        if (count == 1) {
            qDebug() << "Username and password is correct.";



        } else if (count < 1) {
            qDebug() << "Username and/or password is incorrect.";
        } else if (count > 1) {
            qDebug() << "Duplicates.";
        }
    } else {
        qDebug() << "Error: " << db.lastError().text() << endl;
    }

    db.close();

    return result;

    /*
     SimpleCrypt crypto(Q_UINT64_C(0x0c2ad4a4acb9f023)); //some random number
     QString testString("Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
     QString result = crypto.encryptToString(testString);
     QString decrypted = crypto.decryptToString(result);
     qDebug() << testString << endl << result << endl << decrypted;
    */

}

QString DatabaseHelper::getAllBooks() {

    QString result = "";
    QString genreId = "";
    QString authorId = "";
    QSqlQuery query(db);

    qDebug() << "Getting books...";
    if (!db.open()) {
        qDebug() << "Failed to open the database.";
    }

    if (query.exec("SELECT b.title, a.name, b.isbn, b.year, g.name from book b, author a, genre g where b.author_id = a.id and b.genre_id=g.id ")){

        int count = 0;

        while (query.next()){

            qDebug() << query.value(0).toString() << " " << query.value(1).toString() << " " << query.value(2).toString() << " "
                     << query.value(3).toString() << " " << query.value(4).toString() << " " << query.value(5).toString();
            count++;
        }
    } else {
           qDebug() << "Error: " << db.lastError().text() << endl;
    }


    db.close();

//    QString author = getAuthor(authorId);
//    QString genre = getGenre(genreId);
//    qDebug() << authorId << " " << author;
//    qDebug() << genreId << " " << genre;

    return result;

}

QString DatabaseHelper::getAuthor(QString param)
{
    QSqlQuery query(db);
    QString result = "";

    qDebug() << "Getting author...";
    if(!db.open()) {
        qDebug() << "Failed to open the database.";
    }

    if (query.exec("SELECT name FROM AUTHOR WHERE id=" + param)) {

        while (query.next()) {
            result = query.value(0).toString();
        }

    } else {
        qDebug() << "Error: " << db.lastError().text() << endl;
    }


    db.close();
    return result;
}

QString DatabaseHelper::getGenre(QString param)
{
    QSqlQuery query(db);
    QString result = "";

    qDebug() << "Getting genre...";
    if(!db.open()) {
        qDebug() << "Failed to open the database.";
    }

    if (query.exec("SELECT name FROM GENRE WHERE id=" + param)) {

        while (query.next()) {
            result = query.value(0).toString();
        }

    } else {
        qDebug() << "Error: " << db.lastError().text() << endl;
    }


    db.close();
    return result;
}
