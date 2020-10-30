#include "assetsmanager.h"

QString AssetsManager::getAssetsAddress(AssetsManager::assetType _AssetType,QString _Offset)
{
    QString output="";
    if(_AssetType == assetType::file_asset)
    {
#ifdef Q_OS_ANDROID
    output = "assets:/";
#else
     output = "file:/"+QDir::currentPath()+"/assets/";
#endif
    }
    else if(_AssetType == assetType::db_asset)
    {
#ifdef Q_OS_ANDROID
    output = "";
#else
     output = "assets/";
#endif
    }
    else if(_AssetType == assetType::qrc_asset)
    {
        output = "qrc:/";
    }
    output+=_Offset;
    return output;
}
