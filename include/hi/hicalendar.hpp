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

#ifndef HICALENDAR_HPP
#define HICALENDAR_HPP

#include <QDate>
#include <QObject>
#include <QCalendar>
#include <QDebug>
#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QMetaObject>
#include <QQmlContext>
#include <QDebug>
#include <QDateTime>

#include "../common.hpp"

//////::::::::::::::::::::::::::::::::::::: YearMonthDay

/**
 * @brief The YearMonthDay struct: it contains 3 int properties to save year.month.day values
 */
struct YearMonthDay: public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(int Year MEMBER year)//year of custom date
    Q_PROPERTY(int Month MEMBER month)//month of custom date
    Q_PROPERTY(int Day MEMBER day)//day of custom date
    int year;//year of custom date
    int month;//month of custom date
    int day;//day of custom date
    /**
     * @brief YearMonthDay: constructor
     * @param _Year: input year
     * @param _Month: input month
     * @param _Day: input day
     * @param parent: qobject parent
     */
    YearMonthDay(int _Year = 1970,int _Month = 1,int _Day = 1,QObject* parent = nullptr);
    /**
     * @brief YearMonthDay: copy constructor
     * @param other: the object which we wanna copy it
     */
    YearMonthDay(const YearMonthDay& other);
    /**
     * @brief operator =: asign operator
     * @param other: the object which we wanna asign its values to this object
     */
    YearMonthDay& operator=(const YearMonthDay& other);
    /**
     * @brief operator !=: is not equal operator. it's used in conditions
     * @param other: the object that we wanna compare it by this object
     * @return: if this object is not equal to other object, it returns true, otherwise it returns false
     */
    bool operator != (const YearMonthDay& other);
    /**
     * @brief operator == is equal operator. it's used in conditions
     * @param other:  the object that we wanna compare it by this object
     * @return: if this object is equal to other object, it returns true, otherwise it returns false
     */
    bool operator == (const YearMonthDay& other);
    /**
     * @brief : ~YearMonthDay() is destructor
     */
    ~YearMonthDay();
};

////////::::::::::::::::::::::::::::::::::::: Calendar Day Model

class HiCalendarDayModel;
/**
 * @brief The HiCalendarDayModel class: day of calendar
 */
class HI_CALENDAR_EXPORT HiCalendarDayModel : public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(int  jalali_year READ getJalaliYear NOTIFY dayModifiedSi)//get jalali year of this day
    Q_PROPERTY(int  jalali_month READ getJalaliMonth NOTIFY dayModifiedSi)//get jalali month of this day
    Q_PROPERTY(int  jalali_day READ getJalaloDay NOTIFY dayModifiedSi)//get jalali day of this day
    Q_PROPERTY(YearMonthDay georgian_yearmonthday READ getGeorgianDateAsYearMonthDay NOTIFY dayModifiedSi)//get georgian year_month_day struct of this day
    Q_PROPERTY(int  georgian_year READ getGeorgianYear NOTIFY dayModifiedSi)//get georgian year of this day
    Q_PROPERTY(int  georgian_month READ getGeorgianMonth NOTIFY dayModifiedSi)//get georgian month of this day
    Q_PROPERTY(int  georgian_day READ getGeorgianDay NOTIFY dayModifiedSi)//get georgian day of this day
    Q_PROPERTY(int  islamic_year READ getIslamicYear NOTIFY dayModifiedSi)//get islamic year of this day
    Q_PROPERTY(int  islamic_month READ getIslamicMonth NOTIFY dayModifiedSi)//get islamic month of this day
    Q_PROPERTY(int  islamic_day READ getIslamicDay NOTIFY dayModifiedSi)//get islamic day of this day
    Q_PROPERTY(bool is_day_over READ isDayOver NOTIFY dayModifiedSi)//is this day over? returns true if this day is passed
    Q_PROPERTY(bool is_today READ isToday NOTIFY dayModifiedSi)//is this day today?
    Q_PROPERTY(bool is_holiday READ isHoliday NOTIFY dayModifiedSi)//is this day holiday in selected calendar type?
    Q_PROPERTY(int  day_of_custom_month READ getDayOfCustomMonth NOTIFY dayModifiedSi)//day of custom month in selcted calendar type
    Q_PROPERTY(int  day_of_custom_week READ getDayOfCustomWeek NOTIFY dayModifiedSi)//day of custom week in selected calendar type
    Q_PROPERTY(int  day_in_custom_week_n_of_month READ getDayInCustomWeekNOfMonth NOTIFY dayModifiedSi)//day is in week number n of current custom month in selected calendar type! it return n
    Q_PROPERTY(QDate georgian_date READ getGeorgianDate NOTIFY dayModifiedSi)//this is the base georgian date for this day and it converts it to other calendar types
    /**
     * @brief HiCalendarDayModel: main & default constructor
     * @param _Date: georgian date of day
     * @param _DayOfCustomMonth: this day is in X day of month in selected style
     * @param _DayOfCustomWeek: this day is the X day of week of month in selected style
     * @param _DayInCustomWeekOfMonth: this day in in X week of month
     * @param _IsHoliday: is day holiday?
     * @param parent as qobject hierarchy
     */
    explicit HiCalendarDayModel(QDate _Date = QDate::currentDate(),
                                int _DayOfCustomMonth = 1,
                                int _DayOfCustomWeek = 1,
                                int _DayInCustomWeekOfMonth = 1,
                                bool _IsHoliday = false,
                                QObject *parent = nullptr);
    /**
     * @brief HiCalendarDayModel: copy constructor
     * @param item: reference item to be copied
     */
    explicit HiCalendarDayModel(const HiCalendarDayModel& item);

    /**
      * @brief operator = asign operator
      * @param other: the value which will be asigned with
      * @return final data
      */
     HiCalendarDayModel& operator=(const HiCalendarDayModel& other);
     /**
      * @brief operator != operator is not equeal to this
      * @param other: the object that will be compared by this object
      * @return  if other object is not equal to this object, it return true, otherwise it returns false
      */
     bool operator!=(const HiCalendarDayModel& other) const;
     /**
      * @brief operator == operator is equal to this
      * @param other: the object that will be compared by this object
      * @return  if other object is equal to this object, it returns true, otherwise it returns false
      */
     bool operator==(const HiCalendarDayModel& other) const;
     /**
       * @brief getJalaliDateAsYearMonthDay: it returns jalali date of this day as year_month_day struct
       * @return: jalali year_mont_day struct object of this day
       */
      Q_INVOKABLE [[maybe_unused]] YearMonthDay getJalaliDateAsYearMonthDay() const;
     /**
       * @brief getJalaliYear: getter for jalali year
       * @return: int jalali year
       */
      Q_INVOKABLE [[maybe_unused]] int getJalaliYear() const;
     /**
       * @brief getJalaliMonth: getter for jalali month
       * @return: int jalali month
       */
      Q_INVOKABLE [[maybe_unused]] int getJalaliMonth() const;
     /**
       * @brief getJalaloDay: getter for jalali day
       * @return: int jalali day
       */
      Q_INVOKABLE [[maybe_unused]] int getJalaloDay() const;
     /**
      * @brief getGeorgianDateAsYearMonthDay: get georgian date as year month day object
      * @return: year month day struct object
      */
     Q_INVOKABLE [[maybe_unused]] YearMonthDay getGeorgianDateAsYearMonthDay() const;
     /**
       * @brief getGeorgianYear: get the georgian year of this day
       * @return: int georgian year of this day
       */
      Q_INVOKABLE [[maybe_unused]] int getGeorgianYear() const;
     /**
       * @brief getGeorgianMonth: get the georgian month of this day
       * @return: int georgian month of this day
       */
      Q_INVOKABLE [[maybe_unused]] int getGeorgianMonth() const;
     /**
       * @brief getGeorgianDay: get the georgian day of this day
       * @return: int georgian day of this day
       */
      Q_INVOKABLE [[maybe_unused]] int getGeorgianDay() const;
     /**
       * @brief getIslamicDateAsYearMonthDay: getter for islamic year_month_day struct object of this day
       * @return: year_month_day struct object of this day
       */
      Q_INVOKABLE [[maybe_unused]] YearMonthDay getIslamicDateAsYearMonthDay() const;
     /**
       * @brief getIslamicYear: getter for the year of islamic calendar
       * @return islamic year number of this day
       */
      Q_INVOKABLE [[maybe_unused]] int getIslamicYear() const;
     /**
       * @brief getIslamicMonth: getter for the month of islamic calendar
       * @return islamic month number of this day
       */
      Q_INVOKABLE [[maybe_unused]] int getIslamicMonth() const;
     /**
       * @brief getIslamicDay: getter for the day of islamic calendar
       * @return islamic day number of this day
       */
      Q_INVOKABLE [[maybe_unused]] int getIslamicDay() const;
     /**
       * @brief getDayOfCustomMonth: day in custom month (according to the week/calendar type which was selected)
       * @return: the day number of custom month
       */
      Q_INVOKABLE [[maybe_unused]] int getDayOfCustomMonth() const;
     /**
       * @brief getDayOfCustomWeek: get day of custom week (according to the week/calendar type which was selected)
       * @return day number of custom week
       */
      Q_INVOKABLE [[maybe_unused]] int getDayOfCustomWeek() const;
     /**
       * @brief getDayInCustomWeekNOfMonth: get the number of week in custom month of this day
       * @return: returns the number of the week of this day in custom month
       */
      Q_INVOKABLE [[maybe_unused]] int getDayInCustomWeekNOfMonth() const;
     /**
       * @brief isDayOver: returns the result of the question: is this day passed?
       * @return if the day is past, return true , otherwise returns false
       */
      Q_INVOKABLE [[maybe_unused]] bool isDayOver() const;
     /**
       * @brief isToday: return true if this day is today
       * @return: true -> if day equals today , false: if day is not equal today
       */
      Q_INVOKABLE [[maybe_unused]] bool isToday() const;
     /**
      * @brief isHoliday in selected calendar type?
      * @return: returns true if this day is holiday, otherwise it returns false
      */
     Q_INVOKABLE [[maybe_unused]] bool isHoliday() const;
     /**
       * @brief getGeorgianDate: get date of day as QDate
       * @return georgian QDate of day
       */
      Q_INVOKABLE [[maybe_unused]] QDate getGeorgianDate() const;

     /**
       * @brief toString: it return georgian,jalali,islamic info of this day as json format
       * @return: json string of this day
       */
      Q_INVOKABLE [[maybe_unused]] QString toString() const;
     /**
       * ~HiCalendarDayModel: destructor for the day of calendar
       * */
     ~HiCalendarDayModel();
signals:
     /**
      * @brief dayModifiedSi: signal for the while that the object is modified (just with constructors and = operator)
      */
     void dayModifiedSi();
 private:
     QDate _date;//qdate object of this day which contains georgian date of this day
     int _day_of_custom_month;//day of custom month in selcted calendar type
     int _day_of_custom_week;//day of custom week in selcted calendar type
     int _day_in_custom_week_of_month;//day is in week number N in selcted calendar type
     bool _is_holiday;//is this day a holiday in selcted calendar type?
};

////////::::::::::::::::::::::::::::::::::::: Calendar Controller

class HiCalendarController;
/**
 * @brief The HiCalendarController class
 */
class HI_CALENDAR_EXPORT HiCalendarController : public QObject
{
    Q_OBJECT
public:
    Q_ENUMS(CalendarTypes)// calendar type enum define to use in qml
    Q_PROPERTY(CalendarTypes calendartype READ getCalendarType NOTIFY calendarTypeChanged)//getter for calendar type
    Q_PROPERTY(const QVariantList daysofcurrentmonth READ getDaysOfCurrentMonth NOTIFY refreshCalendarSi)//list of days of current selected month
    Q_PROPERTY(QString headerinfo READ currentMonthHeaderInfo NOTIFY refreshCalendarSi)//header of current selected month which will be shown at the top of calendar
    enum CalendarTypes {UsGeorgian = 1 , EuroGeorgian = 2 , Jalali = 3 /*, IslamicCivil = 4*/};//enum define for supported calendar types
    /**
     * @brief HiCalendarController: default constructor for calendar main controller
     * @param _CalendarType: your desired calendar type
     * @param _Parent: qobject parent
     */
    explicit HiCalendarController(CalendarTypes _CalendarType = CalendarTypes::UsGeorgian, QObject* _Parent = 0);//main & default constructor
    /**
     * @brief HiCalendarController: copy constructor
     * @param _Input: the object which will be copied
     */
    explicit HiCalendarController(const HiCalendarController &_Input);
    /**
     * @brief getCalendarType: getter for calendar type
     * @return the current calendar type of this calendar
     */
    Q_INVOKABLE CalendarTypes getCalendarType() const;
    /**
     * @brief currentMonthHeaderInfo: getter for header of calendar for current selcted month
     * @return the header string value
     */
    Q_INVOKABLE [[maybe_unused]] QString currentMonthHeaderInfo() const;
    /**
     * @brief getDaysOfCurrentMonth: getter for the list of days of current selected month
     * @return QVariantList of current days
     */
    Q_INVOKABLE [[maybe_unused]] const QVariantList getDaysOfCurrentMonth() const;
    /**
     * @brief getCurrentSelectedDay: getter for current selcted day
     * @return the selected day of this calendar
     */
    Q_INVOKABLE [[maybe_unused]] HiCalendarDayModel* getCurrentSelectedDay() const;
    /**
     * @brief showCurrentSelectedYearMonthDay: update the screen of calendar to input georgian qdate
     * @param _SelectedDate: input georgian date
     */
    Q_INVOKABLE [[maybe_unused]] void showCurrentSelectedYearMonthDay(QDate _SelectedDate = QDate(1,1,1));
    /**
     * @brief nextDay: select next day
     */
    Q_INVOKABLE [[maybe_unused]] void nextDay();
    /**
     * @brief prevDay: select prev day
     */
    Q_INVOKABLE [[maybe_unused]] void prevDay();
    /**
     * @brief nextMonth: select next month
     */
    Q_INVOKABLE [[maybe_unused]] void nextMonth();
    /**
     * @brief prevMonth: select prev month
     */
    Q_INVOKABLE [[maybe_unused]] void prevMonth();
    /**
     * @brief nextYear: select next year
     */
    Q_INVOKABLE [[maybe_unused]] void nextYear();
    /**
     * @brief prevYear: select prev year
     */
    Q_INVOKABLE [[maybe_unused]] void prevYear();
    /**
     * @brief addDayItem: adder for a new day in current month
     * @param _Day: new day object
     */
    Q_INVOKABLE [[maybe_unused]] void addDayItem(HiCalendarDayModel* _Day);
    /**
     * @brief selectDayByClick: it selects input day
     * @param _Day: select input day
     */
    Q_INVOKABLE [[maybe_unused]] void selectDayByClick(HiCalendarDayModel *_Day);
    /**
     * @brief clearCurrentDays: clear the screen of calendar for change day, month, year of calendar
     */
    Q_INVOKABLE [[maybe_unused]] void clearCurrentDays();
    /**
      * @brief operator = asign operator
      * @param other: the value which will be asigned with
      * @return final data
      */
     HiCalendarController& operator=(const HiCalendarController& other);
     /**
      * @brief operator != operator is not equeal
      * @param other: compare with
      * @return  the result
      */
     bool operator!=(const HiCalendarController& other) const;
     /**
      * @brief operator == operator is equal to
      * @param other: compare with
      * @return  the result
      */
     bool operator==(const HiCalendarController& other) const;
    /**
    * @brief ~HiCalendarController: is destructor
    * */
    ~HiCalendarController();
signals:
    /**
     * @brief calendarTypeChanged
     */
    void calendarTypeChanged(CalendarTypes);
    /**
     * @brief refreshCalendarSi: signal for change and refresh calendar screen
     */
    void refreshCalendarSi();
    /**
     * @brief daySelectedSi: signal for selecting new day
     */
    void daySelectedSi(HiCalendarDayModel*);
private:
    QVariantList _days_of_current_month_list;//qvariantlist of current days of selected month
    CalendarTypes _calendar_type;//calendar type of this calendar
    HiCalendarDayModel* _current_selected_day;//current selected day
    QString _current_month_header_info;//string header of current selected year, month
};

////////:::::::::::::::::::::::::::::::::::: Hi Calendar Context

class HiCalendarContext;
/**
 * @brief The HiCalendarContext class: it's required as we need to change calendar types
 */
class HI_CALENDAR_EXPORT HiCalendarContext : public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(HiCalendarController* calendar_ctrl READ getCalendar NOTIFY calendarChangedSi )//get calendar controller object of this context
    /**
     * @brief HiCalendarContext: default constructor
     * @param parent: qobject parent object
     */
    explicit HiCalendarContext(QObject *parent = nullptr);
    /**
     * @brief renewCalendar: update calendar type
     * @param calendar_type:
     * //if calendar_type is "us" or "us_calendar" or "us_georgian_calendar": it will change to us georgian
     * //if calendar_type is "euro" or "euro_calendar" or "euro_georgian_calendar": it will change to euro georgian
     * //if calendar_type is "jalali" or "jalali_calendar": it will change to jalali,islamic calendar
     */
    Q_INVOKABLE [[maybe_unused]] void renewCalendar(QString calendar_type);
    /**
     * @brief renewCalendar: update calendar type
     * @param calendar_type: input calendar type
     */
    Q_INVOKABLE [[maybe_unused]] void renewCalendar(HiCalendarController::CalendarTypes calendar_type);
    /**
     * @brief getCalendar: getter for calendar controller
     * @return current calendar controller of this context
     */
    Q_INVOKABLE [[maybe_unused]] HiCalendarController* getCalendar();
    /**
     * @brief ~HiCalendarContext: destructor
     */
    ~HiCalendarContext();
signals:
    /**
     * @brief calendarChangedSi: signal for the while that calendar type is changed
     */
    void calendarChangedSi();

private:
    HiCalendarController* _calendar;//main calendar controller object
};

Q_DECLARE_METATYPE(YearMonthDay)
Q_DECLARE_METATYPE(HiCalendarDayModel)
Q_DECLARE_METATYPE(HiCalendarController)

#endif // HICALENDAR_HPP
