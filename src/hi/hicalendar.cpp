#include "include/hi/hicalendar.hpp"

////::::::::::::::::::::::::::::::::::::::::::: YearMonthDay

YearMonthDay::YearMonthDay(int _Year, int _Month, int _Day, QObject *parent):
QObject(parent),year(_Year),month(_Month),day(_Day) {}

YearMonthDay::YearMonthDay(const YearMonthDay &other):
QObject(other.parent()),year(other.year),month(other.month),day(other.day) {}

YearMonthDay& YearMonthDay::operator=(const YearMonthDay &other) 
{
    this->setParent(other.parent());
    this->year = other.year;
    this->month = other.month;
    this->day = other.day;
    return *this;
}

bool YearMonthDay::operator !=(const YearMonthDay &other)
{
    return (this->parent() != other.parent() || this->year != other.year || this->month != other.month || this->day != other.day);
}

bool YearMonthDay::operator ==(const YearMonthDay &other)
{
    return !(*this != other);
}

YearMonthDay::~YearMonthDay() {}

//////::::::::::::::::::::::::::::::::::::::::::: HiCalendarSelectedDayData

HiCalendarDayModel::HiCalendarDayModel(QDate _Date, int _DayOfCustomMonth, int _DayOfCustomWeek, int _DayInCustomWeekOfMonth, bool _IsHoliday , QObject *parent):
     QObject(parent),
     _date(_Date),
     _is_holiday(_IsHoliday)
{
    _day_of_custom_month = 1;
    _day_of_custom_week = 1;
    _day_in_custom_week_of_month = 1;
    if (_DayOfCustomMonth > 0 && _DayOfCustomMonth <32)
    {
            _day_of_custom_month = _DayOfCustomMonth;
    }
    if(_DayOfCustomWeek > 0 && _DayOfCustomWeek < 8)
    {
            _day_of_custom_week = _DayOfCustomWeek;
    }
    if(_DayInCustomWeekOfMonth > 0 && _DayInCustomWeekOfMonth < 7)
    {
            _day_in_custom_week_of_month = _DayInCustomWeekOfMonth;
    }
    emit dayModifiedSi();
}

HiCalendarDayModel::HiCalendarDayModel(const HiCalendarDayModel& item):
    QObject(item.parent()),
    _date(item.getGeorgianDate()),
    _day_of_custom_month(item.getDayOfCustomMonth()),
    _day_of_custom_week(item.getDayOfCustomWeek()),
    _day_in_custom_week_of_month(item.getDayInCustomWeekNOfMonth()),
    _is_holiday(item.isHoliday())
{
    emit dayModifiedSi();
}

HiCalendarDayModel& HiCalendarDayModel::operator=(const HiCalendarDayModel &other)
{
    this->_day_of_custom_month = other.getDayOfCustomMonth();
    this->_day_of_custom_week = other.getDayOfCustomWeek();
    this->_day_in_custom_week_of_month = other.getDayInCustomWeekNOfMonth();
    this->_date = other.getGeorgianDate();
    emit dayModifiedSi();
    return *this;
}

bool HiCalendarDayModel::operator!=(const HiCalendarDayModel &other) const
{
    return (_date != other.getGeorgianDate()
            || _day_of_custom_month != other.getDayOfCustomMonth()
            || _day_of_custom_week != other.getDayOfCustomWeek()
            || _day_in_custom_week_of_month != other.getDayInCustomWeekNOfMonth());
}

bool HiCalendarDayModel::operator==(const HiCalendarDayModel &other) const
{
    return !(*this != other);
}

YearMonthDay HiCalendarDayModel::getJalaliDateAsYearMonthDay() const
{
    QCalendar calendar(QCalendar::System::Jalali);
    QCalendar::YearMonthDay jalali_date = calendar.partsFromDate(_date);
    YearMonthDay output{jalali_date.year,jalali_date.month,jalali_date.day,this->parent()};
    return output;
}

int HiCalendarDayModel::getJalaliYear() const
{
    QCalendar calendar(QCalendar::System::Jalali);
    QCalendar::YearMonthDay jalali_date = calendar.partsFromDate(_date);
    return jalali_date.year;
}

int HiCalendarDayModel::getJalaliMonth() const
{
    QCalendar calendar(QCalendar::System::Jalali);
    QCalendar::YearMonthDay jalali_date = calendar.partsFromDate(_date);
    return jalali_date.month;
}

int HiCalendarDayModel::getJalaloDay() const
{
    QCalendar calendar(QCalendar::System::Jalali);
    QCalendar::YearMonthDay jalali_date = calendar.partsFromDate(_date);
    return jalali_date.day;
}

YearMonthDay HiCalendarDayModel::getGeorgianDateAsYearMonthDay() const
{
    YearMonthDay output{_date.year(),_date.month(),_date.day(),this->parent()};
    return output;
}

int HiCalendarDayModel::getGeorgianYear() const
{
    return _date.year();
}

int HiCalendarDayModel::getGeorgianMonth() const
{
    return _date.month();
}

int HiCalendarDayModel::getGeorgianDay() const
{
    return _date.day();
}

YearMonthDay HiCalendarDayModel::getIslamicDateAsYearMonthDay() const
{
    QCalendar calendar(QCalendar::System::IslamicCivil);
    QCalendar::YearMonthDay islamic_date = calendar.partsFromDate(_date);
    YearMonthDay output{islamic_date.year,islamic_date.month,islamic_date.day,this->parent()};
    return output;
}

int HiCalendarDayModel::getIslamicYear() const
{
    QCalendar calendar(QCalendar::System::IslamicCivil);
    QCalendar::YearMonthDay islamic_date = calendar.partsFromDate(_date);
    return islamic_date.year;
}

int HiCalendarDayModel::getIslamicMonth() const
{
    QCalendar calendar(QCalendar::System::IslamicCivil);
    QCalendar::YearMonthDay islamic_date = calendar.partsFromDate(_date);
    return islamic_date.month;
}

int HiCalendarDayModel::getIslamicDay() const
{
    QCalendar calendar(QCalendar::System::IslamicCivil);
    QCalendar::YearMonthDay islamic_date = calendar.partsFromDate(_date);
    return islamic_date.day;
}

bool HiCalendarDayModel::isDayOver() const
{
    return (QDate::currentDate()  > _date);
}

bool HiCalendarDayModel::isToday() const
{
    return (_date == QDate::currentDate());
}

bool HiCalendarDayModel::isHoliday() const
{
    return _is_holiday;
}

int HiCalendarDayModel::getDayOfCustomMonth() const
{
    return _day_of_custom_month;
}

int HiCalendarDayModel::getDayOfCustomWeek() const
{
    return _day_of_custom_week;
}

int HiCalendarDayModel::getDayInCustomWeekNOfMonth() const
{
    return _day_in_custom_week_of_month;
}

QDate HiCalendarDayModel::getGeorgianDate() const
{
    return _date;
}

QString HiCalendarDayModel::toString() const
{
    QString output = "{\"jalali_year\":"+ QString::number(getJalaliYear()) + ",\"jalali_month\":"+ QString::number(getJalaliMonth()) + ",\"jalali_day\":"+ QString::number(getJalaloDay()) + ",\"georgian_year\":"+ QString::number(getGeorgianYear()) + ",\"georgian_month\":"+ QString::number(getGeorgianMonth()) + ",\"georgian_day\":"+ QString::number(getGeorgianDay()) + ",\"islamic_year\":"+ QString::number(getIslamicYear()) + ",\"islamic_month\":"+ QString::number(getIslamicMonth()) + ",\"islamic_day\":"+ QString::number(getIslamicDay()) + ",\"is_day_over\":"+ (isDayOver()? "true" : "false") + ",\"is_today\":"+ (isToday()? "true" : "false") + ",\"day_of_custom_month\":"+ QString::number(getDayOfCustomMonth())  + ",\"day_of_custom_week\":"+ QString::number(getDayOfCustomWeek()) + ",\"day_in_custom_week_n_of_month\":"+ QString::number(getDayInCustomWeekNOfMonth())+",\"is_holiday_in_calendar_selected_type\":"+ (isHoliday()?"true":"false") + "}";
    return output;
}

HiCalendarDayModel::~HiCalendarDayModel() {}

//////////::::::::::::::::::::::::::::::::::::: Calendar Controller

HiCalendarController::HiCalendarController(HiCalendarController::CalendarTypes _CalendarType, QObject *_Parent):
    QObject(_Parent),
    _calendar_type(_CalendarType),
    _current_selected_day(nullptr)
{
    emit calendarTypeChanged(_calendar_type);
}

HiCalendarController::HiCalendarController(const HiCalendarController &_Input):
    QObject(_Input.parent()),
    _days_of_current_month_list(_Input.getDaysOfCurrentMonth()),
    _calendar_type(_Input.getCalendarType()),
    _current_selected_day(nullptr)
{
    emit calendarTypeChanged(_calendar_type);
}

HiCalendarController::CalendarTypes HiCalendarController::getCalendarType() const
{
    return _calendar_type;
}

QString HiCalendarController::currentMonthHeaderInfo() const
{
    return _current_month_header_info;
}

const QVariantList HiCalendarController::getDaysOfCurrentMonth() const
{
    return _days_of_current_month_list;
}

HiCalendarDayModel* HiCalendarController::getCurrentSelectedDay() const
{
    return _current_selected_day;
}

void HiCalendarController::showCurrentSelectedYearMonthDay(QDate _SelectedDate)
{
    QStringList jalali_months = {"فروردین" , "اردیبهشت", "خرداد", "تیر", "اَمرداد", "شهریور", "مهر", "آبان", "آذر", "دی", "بهمن", "اسفند"};
    QStringList georgian_months = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    QStringList islamic_months = {"محرم" , "صفر", "ربیع‌الاول", "ربیع‌الثانی", "جمادی‌الاول", "جمادی‌الثانی", "رجب", "شعبان", "رمضان", "شوال", "ذیقعده", "ذیحجه"};
    int day_of_week = 1;
    int day_is_in_week_N_of_month = 0;
    int year = 1;
    int month = 1;
    int day = 1;
    if(_SelectedDate ==  QDate(1,1,1))
    {
        _SelectedDate = QDate::currentDate();
    }
    QDate newDate = _SelectedDate;
    if(_current_selected_day != nullptr)//is not first
    {
        clearCurrentDays();
        _current_selected_day =  nullptr;
    }
    if (getCalendarType() == HiCalendarController::CalendarTypes::Jalali)
    {
        QCalendar jalali_calendar(QCalendar::System::Jalali);
        QCalendar islamic_calendar(QCalendar::System::IslamicCivil);
        int first_georgian_month = 0;
        int second_georgian_month = 0;
        int first_islamic_month = 0;
        int second_islamic_month = 0;
        int first_georgian_year = 0;
        int second_georgian_year = 0;
        int first_islamic_year = 0;
        int second_islamic_year = 0;
        QCalendar::YearMonthDay jalali_date = jalali_calendar.partsFromDate(_SelectedDate);
        year = jalali_date.year;//current selected year as jalali
        month = jalali_date.month;//current selected month as jalali
        day = jalali_date.day;//current selected day as jalali
        if (day > 1)
        {
            newDate = _SelectedDate.addDays(-(day-1));//first day of selected month as georgian
        }
        QCalendar::YearMonthDay islamic_date = islamic_calendar.partsFromDate(newDate);
        first_georgian_month = newDate.month();
        first_georgian_year = newDate.year();
        first_islamic_month = islamic_date.month;
        first_islamic_year = islamic_date.year;
        int day_counter = 1;
        while ( jalali_calendar.partsFromDate(newDate).month == month)
        {
            bool is_holiday = false;
            if ( newDate.dayOfWeek() < 6)
            {
                day_of_week = newDate.dayOfWeek()+2;
            }
            else
            {
                day_of_week = newDate.dayOfWeek() % 6 +1;
            }
            if(day_of_week == 1 || day_is_in_week_N_of_month == 0)
            {
                day_is_in_week_N_of_month++;
            }
            islamic_date = islamic_calendar.partsFromDate(newDate);
            if(islamic_date.month != first_islamic_month)
            {
                second_islamic_month = islamic_date.month;
            }
            if(islamic_date.year != first_islamic_year)
            {
                second_islamic_year = islamic_date.year;
            }
            if(newDate.month() != first_georgian_month)
            {
                second_georgian_month = newDate.month();
            }
            if(newDate.year() != first_georgian_year)
            {
                second_georgian_year = newDate.year();
            }
            //jalali holidays
            if (newDate.dayOfWeek() == 5) is_holiday = true;
            if (month == 1)
            {
                if (day_counter >= 1 && day_counter <  5) is_holiday = true;
                if (day_counter == 12 || day_counter == 13) is_holiday = true;
            }
            if (month == 3)
            {
                if (day_counter == 14 || day_counter == 15) is_holiday = true;
            }
            if (month == 11 && day_counter == 22)  is_holiday = true;
            if (month == 12 && (day_counter == 29 || day_counter == 30)) is_holiday = true;
            //islamic holidays
            if (islamic_date.month == 1)
            {
                if (islamic_date.day == 9 || islamic_date.day == 10) is_holiday = true;//tasua-ashura
            }
            if (islamic_date.month == 2)
            {
                qDebug()<<"=============2";
                if (islamic_date.day == 20 || islamic_date.day == 28 || islamic_date.day == 30) is_holiday = true;
                if (islamic_date.day == 29)
                {
                    qDebug()<<newDate.toString();
                    QDate tmpDate = newDate.addDays(1);
                    qDebug()<<newDate<<" ====> ttt " << tmpDate.toString();
                    QCalendar::YearMonthDay islamic_date_tmp = islamic_calendar.partsFromDate(tmpDate);
                    if (islamic_date_tmp.month != 2)
                    {
                        is_holiday = true;
                    }
                }
            }
            if (islamic_date.month == 3)
            {
                if (islamic_date.day == 8 || islamic_date.day == 17) is_holiday = true;
            }
            if (islamic_date.month == 6)
            {
                if (islamic_date.day == 3 ) is_holiday = true;
            }
            if (islamic_date.month == 7)
            {
                if (islamic_date.day == 13 || islamic_date.day == 27) is_holiday = true;
            }
            if (islamic_date.month == 8)
            {
                if (islamic_date.day == 15) is_holiday = true;
            }
            if (islamic_date.month == 9)
            {
                if (islamic_date.day == 19 || islamic_date.day == 21) is_holiday = true;
            }
            if (islamic_date.month == 10)
            {
                if (islamic_date.day == 1 || islamic_date.day == 2 || islamic_date.day == 25) is_holiday = true;
            }
            if (islamic_date.month == 12)
            {
                if (islamic_date.day == 10 || islamic_date.day == 18) is_holiday = true;
            }

            HiCalendarDayModel* newDay = new HiCalendarDayModel(newDate, day_counter, day_of_week, day_is_in_week_N_of_month,is_holiday ,this);
            this->addDayItem(newDay);
            if(newDate == _SelectedDate)
            {
                _current_selected_day = newDay;
            }
            newDate = newDate.addDays(1);
            day_counter++;
        }
        _current_month_header_info = jalali_months[month-1] +" "+ QString::number(year) + "\n";
        if(second_georgian_year == 0) //same georgian year
        {
            _current_month_header_info += georgian_months[first_georgian_month-1] + " - " + georgian_months[second_georgian_month-1] + " " + QString::number(first_georgian_year)+"\n";
        }
        else // different georgian years
        {
            _current_month_header_info += georgian_months[first_georgian_month-1] + " " + QString::number(first_georgian_year);
            _current_month_header_info += " - " + georgian_months[second_georgian_month-1] + " " + QString::number(second_georgian_year)+"\n";
        }
        if(second_islamic_year == 0) //same islamic year
        {
            _current_month_header_info += islamic_months[first_islamic_month-1] + " - " + islamic_months[second_islamic_month-1] + " " + QString::number(first_islamic_year);
        }
        else // different islamic years
        {
            _current_month_header_info += islamic_months[first_islamic_month-1] + " " + QString::number(first_islamic_year);
            _current_month_header_info += " - " + islamic_months[second_islamic_month-1] + " " + QString::number(second_islamic_year);
        }
    }
    else
    {
        year = _SelectedDate.year();
        month = _SelectedDate.month();
        day = _SelectedDate.day();
        QDate newDate(year,month,1);
        int days_of_week_count[8] = {0,0,0,0,0,0,0,0};
        while (newDate.month() == month)
        {
            bool is_holiday = false;
            if(getCalendarType() == HiCalendarController::CalendarTypes::EuroGeorgian)
            {
                day_of_week = newDate.dayOfWeek();
            }
            else if (getCalendarType() == HiCalendarController::CalendarTypes::UsGeorgian)
            {
                day_of_week = (newDate.dayOfWeek() % 7) + 1;
            }
            if(day_of_week == 1 || day_is_in_week_N_of_month == 0)
            {
                day_is_in_week_N_of_month++;
            }
            //georgian holidays
            days_of_week_count[newDate.dayOfWeek()]++;
            if (newDate.dayOfWeek() == 7) is_holiday = true;
            if (newDate.month() == 1)
            {
                if (newDate.day() == 1) is_holiday = true;
                if (newDate.dayOfWeek() == 1 && days_of_week_count[newDate.dayOfWeek()] == 3) is_holiday = true;
            }
            if (newDate.month() == 2)
            {
                if (newDate.day() == 12) is_holiday = true;
                if (newDate.dayOfWeek() == 1 && days_of_week_count[newDate.dayOfWeek()] == 3) is_holiday = true;
            }
            if (newDate.month() == 5)
            {
                if (newDate.day() == 5) is_holiday = true;
                if (newDate.dayOfWeek() == 1 && (31 - newDate.day() <7)) is_holiday = true;
            }
            if (newDate.month() == 7)
            {
                if (newDate.day() == 4) is_holiday = true;
            }
            if (newDate.month() == 9)
            {
                if (newDate.day() == 4) is_holiday = true;
                if (newDate.dayOfWeek() == 1 && days_of_week_count[newDate.dayOfWeek()] == 1) is_holiday = true;
            }
            if (newDate.month() == 11)
            {
                if (newDate.day() == 11) is_holiday = true;
                if (newDate.dayOfWeek() == 3 && (30 - newDate.day() <7)) is_holiday = true;
            }
            if (newDate.month() == 12)
            {
                if (newDate.day() == 25) is_holiday = true;
            }
            HiCalendarDayModel* newDay = new HiCalendarDayModel(newDate, newDate.day(), day_of_week, day_is_in_week_N_of_month ,is_holiday,this);
            this->addDayItem(newDay);
            if(newDate == _SelectedDate)
            {
                _current_selected_day = newDay;
            }
            newDate = newDate.addDays(1);
        }
        _current_month_header_info = georgian_months[month-1] +" - "+ QString::number(year);
    }
    if (_current_selected_day != nullptr)
    {
        emit daySelectedSi(_current_selected_day);
    }
    emit refreshCalendarSi();
}

void HiCalendarController::nextDay()
{
    if (_current_selected_day != nullptr && _days_of_current_month_list.length() >0)
    {
        this->showCurrentSelectedYearMonthDay(_current_selected_day->getGeorgianDate().addDays(1));
    }
}

void HiCalendarController::prevDay()
{
    if (_current_selected_day != nullptr && _days_of_current_month_list.length() >0)
    {
        this->showCurrentSelectedYearMonthDay(_current_selected_day->getGeorgianDate().addDays(-1));
    }
}

void HiCalendarController::nextMonth()
{
    if (_current_selected_day != nullptr && _days_of_current_month_list.length() >0)
    {
        if (getCalendarType() == HiCalendarController::CalendarTypes::Jalali)
        {
            QCalendar jalali_calendar(QCalendar::System::Jalali);
            QDate newDate = _current_selected_day->getGeorgianDate();
            QCalendar::YearMonthDay jalali_date = jalali_calendar.partsFromDate(newDate);
            int year = jalali_date.year;
            int month = jalali_date.month + 1;
            if (month > 12)
            {
                month = 1;
                year++;
            }
            newDate = jalali_calendar.dateFromParts(year,month,1);
            this->showCurrentSelectedYearMonthDay(newDate);
        }
        else
        {
            QDate newDate = _current_selected_day->getGeorgianDate().addMonths(1);
            newDate.setDate(newDate.year(),newDate.month(),1);
            this->showCurrentSelectedYearMonthDay(newDate);
        }
    }
}

void HiCalendarController::prevMonth()
{
    if (_current_selected_day != nullptr && _days_of_current_month_list.length() >0)
    {
        if (getCalendarType() == HiCalendarController::CalendarTypes::Jalali)
        {
            QCalendar jalali_calendar(QCalendar::System::Jalali);
            QDate newDate = _current_selected_day->getGeorgianDate();
            QCalendar::YearMonthDay jalali_date = jalali_calendar.partsFromDate(newDate);
            int year = jalali_date.year;
            int month = jalali_date.month - 1;
            if (month < 1)
            {
                month = 12;
                year--;
            }
            newDate = jalali_calendar.dateFromParts(year,month,1);
            this->showCurrentSelectedYearMonthDay(newDate);
        }
        else
        {
            QDate newDate = _current_selected_day->getGeorgianDate().addMonths(-1);
            newDate.setDate(newDate.year(),newDate.month(),1);
            this->showCurrentSelectedYearMonthDay(newDate);
        }
    }
}

void HiCalendarController::nextYear()
{
    if (_current_selected_day != nullptr && _days_of_current_month_list.length() >0)
    {
        if (getCalendarType() == HiCalendarController::CalendarTypes::Jalali)
        {
            QCalendar jalali_calendar(QCalendar::System::Jalali);
            QDate newDate = _current_selected_day->getGeorgianDate();
            QCalendar::YearMonthDay jalali_date = jalali_calendar.partsFromDate(newDate);
            int year = jalali_date.year + 1;
            int month = jalali_date.month;
            newDate = jalali_calendar.dateFromParts(year,month,1);
            this->showCurrentSelectedYearMonthDay(newDate);
        }
        else
        {
            QDate newDate = _current_selected_day->getGeorgianDate().addYears(1);
            newDate.setDate(newDate.year(),newDate.month(),1);
            this->showCurrentSelectedYearMonthDay(newDate);
        }
    }
}

void HiCalendarController::prevYear()
{
    if (_current_selected_day != nullptr && _days_of_current_month_list.length() >0)
    {
        if (getCalendarType() == HiCalendarController::CalendarTypes::Jalali)
        {
            QCalendar jalali_calendar(QCalendar::System::Jalali);
            QDate newDate = _current_selected_day->getGeorgianDate();
            QCalendar::YearMonthDay jalali_date = jalali_calendar.partsFromDate(newDate);
            int year = jalali_date.year - 1;
            int month = jalali_date.month;
            newDate = jalali_calendar.dateFromParts(year,month,1);
            this->showCurrentSelectedYearMonthDay(newDate);
        }
        else
        {
            QDate newDate = _current_selected_day->getGeorgianDate().addYears(-1);
            newDate.setDate(newDate.year(),newDate.month(),1);
            this->showCurrentSelectedYearMonthDay(newDate);
        }
    }
}

void HiCalendarController::addDayItem(HiCalendarDayModel *_Day)
{
    if (!_days_of_current_month_list.contains(QVariant::fromValue(_Day)))
    {
        _days_of_current_month_list.append(QVariant::fromValue(_Day));
    }
}

void HiCalendarController::selectDayByClick(HiCalendarDayModel *_Day)
{
    QDate selected_date = _Day->getGeorgianDate();
    if (_days_of_current_month_list.length() >0)
    {
        this->showCurrentSelectedYearMonthDay(selected_date);
        for (QVariantList::iterator j = _days_of_current_month_list.begin(); j != _days_of_current_month_list.end(); j++)
        {
            QObject* object = qvariant_cast<QObject*>(*j);
            HiCalendarDayModel* day = qobject_cast<HiCalendarDayModel*>(object);
            if (day->getGeorgianDate() == selected_date)
            {
                _current_selected_day = day;
                emit daySelectedSi(_current_selected_day);
                break;
            }
        }
    }
}

void HiCalendarController::clearCurrentDays()
{
    for (QVariantList::iterator j = _days_of_current_month_list.begin(); j != _days_of_current_month_list.end(); j++)
    {
        QObject* object = qvariant_cast<QObject*>(*j);
        HiCalendarDayModel* day = qobject_cast<HiCalendarDayModel*>(object);
        day->deleteLater();
    }
    _days_of_current_month_list.clear();
    emit refreshCalendarSi();
}

HiCalendarController &HiCalendarController::operator=(const HiCalendarController &other)
{
    this->_days_of_current_month_list = other.getDaysOfCurrentMonth();
    this->_calendar_type = other.getCalendarType();
    this->_current_selected_day = other.getCurrentSelectedDay();
    this->_current_month_header_info = other.currentMonthHeaderInfo();
    return *this;
}

bool HiCalendarController::operator!=(const HiCalendarController &other) const
{
    return (this->_days_of_current_month_list != other.getDaysOfCurrentMonth()
            || this->_calendar_type != other.getCalendarType()
            || this->_current_selected_day != other.getCurrentSelectedDay()
            || this->_current_month_header_info != other.currentMonthHeaderInfo());
}

bool HiCalendarController::operator==(const HiCalendarController &other) const
{
    return !(*this != other);
}

HiCalendarController::~HiCalendarController()
{
    this->clearCurrentDays();
}

//////////:::::::::::::::::::::::::::::::::::::::::::::: Hi Calendar Context

HiCalendarContext::HiCalendarContext(QObject *parent) : QObject(parent),_calendar (nullptr) {}

void HiCalendarContext::renewCalendar(QString calendar_type)
{
    calendar_type = calendar_type.toLower();
    if (calendar_type == "us" || calendar_type == "us_calendar" || calendar_type == "us_georgian_calendar")
    {
        this->renewCalendar(HiCalendarController::CalendarTypes::UsGeorgian);
    }
    else if(calendar_type == "euro" || calendar_type == "euro_calendar" || calendar_type == "euro_georgian_calendar")
    {
        this->renewCalendar(HiCalendarController::CalendarTypes::EuroGeorgian);
    }
    else if (calendar_type == "jalali" || calendar_type == "jalali_calendar")
    {
         this->renewCalendar(HiCalendarController::CalendarTypes::Jalali);
    }
}

void HiCalendarContext::renewCalendar(HiCalendarController::CalendarTypes calendar_type)
{
    bool changed = false;
    if (calendar_type == HiCalendarController::CalendarTypes::UsGeorgian)
    {
        changed = true;
        if (_calendar != nullptr) _calendar->deleteLater();
        _calendar = new  HiCalendarController(HiCalendarController::CalendarTypes::UsGeorgian , this);
    }
    else if(calendar_type == HiCalendarController::CalendarTypes::EuroGeorgian)
    {
        changed = true;
        if (_calendar != nullptr) _calendar->deleteLater();
        _calendar = new  HiCalendarController(HiCalendarController::CalendarTypes::EuroGeorgian, this);
    }
    else if (calendar_type == HiCalendarController::CalendarTypes::Jalali)
    {
        changed =  true;
        if (_calendar != nullptr) _calendar->deleteLater();
        _calendar = new  HiCalendarController(HiCalendarController::CalendarTypes::Jalali, this);
    }
    if (changed == true && _calendar != nullptr)
    {
        _calendar->showCurrentSelectedYearMonthDay();
        emit calendarChangedSi();
    }
}

HiCalendarController* HiCalendarContext::getCalendar()
{
    return _calendar;
}

HiCalendarContext::~HiCalendarContext()
{
    if (_calendar != nullptr)
    {
        _calendar->deleteLater();
    }
}
