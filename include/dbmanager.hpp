/*
  The MIT License (MIT)
  Copyright (c) 2020 Hadi Abbasi & Kambiz Asadzadeh
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
 */

#ifndef DBMANAGER_HPP
#define DBMANAGER_HPP

#include <QObject>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "assetsmanager.hpp"

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

#endif // DBMANAGER_HPP
