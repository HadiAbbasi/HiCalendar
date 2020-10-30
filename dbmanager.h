#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "assetsmanager.h"

class DbManager : public QObject
{
    Q_OBJECT
public:
    static DbManager* getInstance(QObject *parent = 0);
    static void deleteInstance();
    QSqlQueryModel& getQuery(QString query);
signals:

public slots:
private:
    static DbManager* _sInstance;
    explicit DbManager(QObject *parent = 0);

};

#endif // DBMANAGER_H
