#ifndef DATE_TIME_H_INCLUDED
#define DATE_TIME_H_INCLUDED
using namespace std;
class date_time{///class

private:
    int numOfDate_time;
    int id;
    int day;
    int month;
    int year;
    int hours;
    int minutes;
    char am_pm;

public:///get and set function
    void getNumOfDate_time(ifstream& inFileT){inFileT>>numOfDate_time;}
    int setNumOfDate(){return numOfDate_time;}
    void getId(ifstream& inFileT){inFileT>>id;}
    void getDay(ifstream& inFileT){inFileT>>day;}
    void getMonth(ifstream& inFileT){inFileT>>month;}
    void getYear(ifstream& inFileT){inFileT>>year;}
    void getHours(ifstream& inFileT){inFileT>>hours;}
    void getMinuts(ifstream& inFileT){inFileT>>minutes;}
    void getAm_Pm(ifstream& inFileT){inFileT>>am_pm;}
    int setId(){return id;}
    int setDay(){return day;}
    int setMonth(){return month;}
    int setYear(){return year;}
    int setHours(){return hours;}
    int setMinutes(){return minutes;}
    int setAm_Pm(){return am_pm;}
    void printDay(){cout<<day;}
    void printMonth(){cout<<month;}
    void printYear(){cout<<year;}
    void printHours(){cout<<hours;}
    void printMinutes(){cout<<minutes;}
    void printAM_PM(){cout<<am_pm;}
date_time();
    friend void readDate_time(ifstream& inFileT, vector<date_time> &date_timeType);

};
///Function decloration
void openDate_time(ifstream& inFileT);
void readDate_time(ifstream& inFileT, vector<date_time> &date_timeType);
void printDate(vector<date_time> &date_timeType, int index);
#endif // DATE_TIME_H_INCLUDED
