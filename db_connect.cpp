#include <QApplication>
#include <QtSql>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");//this is the driver for SQL LITE
    mydb.setDatabaseName("C:/SQLite/sqlite-tools-win32-x86-3250200/IPark.db");//we need the path of the database
    mydb.open();

    if(mydb.isOpen())
    {
        qDebug() << "DB OPENED";
    }

    else
    {
        qDebug() << "DB NOY OPENED" << mydb.lastError();//to get the error
    }


    return a.exec();
}
