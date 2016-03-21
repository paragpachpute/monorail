#include"mysql.h"

class sqlconnect{

    QString ip = "127.0.0.1";
    int port = 3306;
    QString user = "root";
    QString pass = "";
    QString dbase = "railway";
public:
    bool createConnection(){
         QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
         db.setHostName(ip);
         db.setDatabaseName(dbase);
         db.setPort(port);
         db.setUserName(user);
         db.setPassword(pass);

         if (!db.open()) {
             qDebug() << "Database error occurred"<<db.lastError();
             return false;
         }
         return true;
     }
};
