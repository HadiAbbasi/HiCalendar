#include "include/dbmanager.hpp"

DbManager *DbManager::getInstance(QObject *parent)
{
    if(!_sInstance)
    {
        _sInstance=new DbManager(parent);
    }
    return _sInstance;
}

void DbManager::deleteInstance()
{
    if(_sInstance)
    {
        _sInstance->deleteLater();
        _sInstance=nullptr;
    }


}

DbManager::DbManager(QObject *parent) : QObject(parent) {}

QSqlQueryModel& DbManager::getQuery(QString query)
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName(AssetsManager::getAssetsAddress(AssetsManager::db_asset,"myFile.db"));
    QString output="";
    QSqlQuery qry;
    QSqlQueryModel qrym;
    if(db.open())
    {
        //qDebug() << db.tables()<<" , "<<db.tables().size();
        output=QString::number(db.tables().size());
        if(db.tables().contains( "person"))
        {
            output+="have table\n";
            qrym.setQuery("SELECT * FROM person");
            qrym.setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
            qrym.setHeaderData(1, Qt::Horizontal, QObject::tr("firstName"));
            qrym.setHeaderData(2, Qt::Horizontal, QObject::tr("lastName"));
            for (int i = 0; i < qrym.rowCount(); ++i)
            {
                   int id = qrym.record(i).value("id").toInt();
                   QString name = qrym.record(i).value("firstname").toString();
                   QString lastname = qrym.record(i).value("lastname").toString();
                   output+="id: "+QString::number(id)+" name: "+name+"  last name: "+lastname+"\n";
            }
        }
        else
        {
            output="create\n";
            qry.prepare("CREATE TABLE IF NOT EXISTS person (id int primary key, firstname varchar(20), lastname varchar(20))");
            if(qry.exec())
            {
                if(!qry.exec( "INSERT INTO person (id, firstname, lastname) VALUES (1, 'John', 'Doe')" ))
                {
                    output+="Error-insert1\n";
                }
                if(!qry.exec( "INSERT INTO person (id, firstname, lastname) VALUES (2, 'Jane', 'Doe')" ))
                {
                    output+="Error-insert2\n";
                }
            }
            else
            {
                output+="Error create table "+qry.lastError().text();
            }
        }
        db.close();
    }
    else
    {
        output="can't open!";
    }
    //return qrym;
}

DbManager* DbManager::_sInstance=nullptr;
