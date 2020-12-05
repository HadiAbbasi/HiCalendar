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

#ifndef COMMON_HPP
#define COMMON_HPP

#if defined(__WINNT) || defined(__WINNT__) || defined(WIN32) || defined(_WIN32) \
    || defined(__WIN32) || defined(__WIN32__) || defined(WIN64) || defined(_WIN64) \
    || defined(__WIN64) || defined(__WIN64__)
//!Microsoft Windows
#define HI_CALENDAR_EXPORT __declspec(dllexport)
#define HI_CALENDAR_IMPORT __declspec(dllimport)
#elif defined(__GNUC__)
//!Define for Unix base OS such as: Linux, macOS, FreeBSD, etc...
#define HI_CALENDAR_EXPORT __attribute__((visibility("default")))
#define HI_CALENDAR_IMPORT __attribute__((visibility("default")))
#define KAVENEGAR_HIDDEN __attribute__((visibility("hidden")))
#else
//  do nothing and hope for the best?
#define HI_CALENDAR_EXPORT
#define HI_CALENDAR_IMPORT
#pragma warning Unknown dynamic link import / export semantics.
#endif

#define QML_REGISTER(classname,packagename,MAJORVERSION,minorversion) \
qmlRegisterType<classname>(packagename, MAJORVERSION, minorversion, #classname);

#endif // COMMON_HPP
