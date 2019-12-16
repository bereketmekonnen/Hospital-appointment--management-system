#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include "patients.h"
#include "doctors.h"
#include "record.h"

using namespace std;

record::record()
{
    id =0;
    patient_id =0;
    notes ="";




}
void add_record(vector<record> &recordType)///function is used to add new records
{

    int a =0;
    int numberOfRecords;
    cout<<"How many records would you like to create? ";
    cin>>numberOfRecords;

    a=recordType.size();
    for(int i=0; i<(a+numberOfRecords); i++)
    {
        cout<<"==============================================="<<endl;
        recordType.push_back(record());
        cout<<"Please enter record Id: ";
        cin>>recordType[i].id;
        cout<<"Please enter patient's Id: ";
        cin>>recordType[i].patient_id;
        cout<<"Please enter note: ";
        cin.ignore();
        getline(cin, recordType[i].notes);
        cout<<"==============================================="<<endl;
    }

}
void update_record(vector<record> &recordType)///Function is used to update records
{
    int recordId;
    cout<<"Please enter the record Id of the record you would like to update: ";
    cin>>recordId;
    for(int i=0; i<recordType.size(); i++)
    {
        if(recordId == recordType[i].setId())
        {
            cout<<"==============================================="<<endl;
            cout<<"Enter updated record Id: ";
            cin>>recordType[i].id;
            cout<<"Enter updated patient Id: ";
            cin>>recordType[i].patient_id;
            cout<<"Enter updated Note: ";
            cin.ignore();
            getline(cin, recordType[i].notes);
            cout<<"==============================================="<<endl;
        }
    }
}

void show_records(vector<record> &recordType)///fucntion is used to show all records
{
    cout<<"==============================================="<<endl;
    cout<<"                     Records                   "<<endl;
    cout<<"==============================================="<<endl;
    for(int i=0; i<recordType.size(); i++)
    {
        cout<<"==============================================="<<endl;
        cout<<"Record Id: ";
        recordType[i].printId();
        cout<<"Patient Id: ";
        recordType[i]. print_pId();
        cout<<"Notes: ";
        recordType[i].print_notes();
        cout<<"==============================================="<<endl;
    }






}

void delet_record(vector<record> &recordType)///function is used to delete records
{
    int recordId;
    int index;
    cout<<"Please Enter the record Id of the recored you would like to delete: ";
    cin>>recordId;
    for(int i=0; i<recordType.size(); i++)
    {
        if(recordId == recordType[i].setId())
        {
            index =i;
        }
    }
    recordType.erase(recordType.begin()+index);
}












void manage_records(int choice, vector<record> &recordType)
{

    switch(choice)
    {
    case 1:
        system("CLS");
        ///function call to add a new record
        add_record(recordType);
        cout<<"Record has been created!"<<endl;
        system("PAUSE");


        break;

    case 2:
        system("CLS");
        ///function call to update record
        update_record(recordType);
        cout<<"Record has been Updated!"<<endl;
        system("PAUSE");

        break;
    case 3:
        system("CLS");
        ///function call to show all records
        show_records(recordType);
        system("PAUSE");
        system("CLS");
        break;
    case 4:
        system("CLS");
        ///function call to delete a record
        delet_record(recordType);
        cout<<"The record has been deleted"<<endl;
        system("PAUSE");
        system("CLS");
        break;
    case 5:
        system("CLS");
        break;

    }

}
