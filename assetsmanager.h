#ifndef ASSETSMANAGER_H
#define ASSETSMANAGER_H

#include <iostream>
using namespace std;
#include <QString>
#include <QObject>
#include <QDir>

class AssetsManager
{
public:
    enum assetType{db_asset,file_asset,qrc_asset};
    static QString getAssetsAddress(assetType _AssetType, QString _Offset="");
private:
    AssetsManager()
    {}
    AssetsManager(AssetsManager&)
    {}
    AssetsManager(AssetsManager*)
    {}
};

#endif // ASSETSMANAGER_H
