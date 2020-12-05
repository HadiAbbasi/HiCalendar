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

#ifndef ASSETSMANAGER_HPP
#define ASSETSMANAGER_HPP

#include <QString>
#include <QObject>
#include <QDir>

#include <iostream>
using namespace std;

#include "common.hpp"

class AssetsManager;
/*!
 * \brief The AssetsManager class
 */
class HI_CALENDAR_EXPORT AssetsManager
{
public:
    enum AssetType{db_asset,file_asset,qrc_asset};
    static QString getAssetsAddress(AssetType _AssetType, QString _Offset="");
private:
    AssetsManager() {}
    AssetsManager(AssetsManager&) {}
    explicit AssetsManager(AssetsManager*) {}
};

#endif // ASSETSMANAGER_HPP
