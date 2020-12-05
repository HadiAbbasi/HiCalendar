#include "include/assetsmanager.hpp"

QString AssetsManager::getAssetsAddress(AssetsManager::AssetType _AssetType,QString _Offset)
{
    QString output="";
    if(_AssetType == AssetType::file_asset)
    {
#ifdef Q_OS_ANDROID
    output = "assets:/";
#else
     output = "file:/"+QDir::currentPath()+"/assets/";
#endif
    }
    else if(_AssetType == AssetType::db_asset)
    {
#ifdef Q_OS_ANDROID
    output = "";
#else
     output = "assets/";
#endif
    }
    else if(_AssetType == AssetType::qrc_asset)
    {
        output = "qrc:/";
    }
    output+=_Offset;
    return output;
}
