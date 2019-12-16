#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <windows.h>
#include "date_time.h"
using namespace std;
date_time::date_time()///constractor
{
    numOfDate_time =0;
    id=0;
    day=0;
    month=0;
    year =0;
    hours =0;
    minutes=0;
    am_pm =' ';
}




void openDate_time(ifstream& inFileT) ///This function is used to open the file
{

    inFileT.open("Date_Time.txt");

    if (!inFileT)
    {
        cout<<"\nError opening file!"<<endl;//this message is displayed if the file is not found
    }
}

void readDate_time(ifstream& inFileT, vector<date_time> &date_timeType)///reads date time input file
{

    date_time date_timeAccesor;
    date_timeAccesor.getNumOfDate_time(inFileT);

    int loop = date_timeAccesor.setNumOfDate();


    for(int i=0; i<loop; i++)
    {

        date_timeType.push_back(date_time());
        date_timeType[i].getId(inFileT);
        date_timeType[i].getDay(inFileT);
        date_timeType[i].getMonth(inFileT);
        date_timeType[i].getYear(inFileT);
        date_timeType[i].getHours(inFileT);
        date_timeType[i].getMinuts(inFileT);
        date_timeType[i].getAm_Pm(inFileT);
    }


}
void printDate(vector<date_time> &date_timeType, int index)///function is used to print date and time
{



    cout<<"Date: ";
    date_timeType[index].printMonth();
    cout<<"/";
    date_timeType[index].printDay();
    cout<<"/";
    date_timeType[index].printYear();
    cout<<"\t";
    cout<<"Time: ";
    date_timeType[index].printHours();
    cout<<":";
    date_timeType[index].printMinutes();
    cout<<":";
    date_timeType[index].printAM_PM();


    cout<<endl;

}


