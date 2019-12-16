#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include "patients.h"
#include "doctors.h"
#include "record.h"
#include "slotse.h"
#include <windows.h>
using namespace std;

patients::patients()///constructor
{

    id =0;
    doctor_id =0;
    record_id =0;
    name ="";
    phone ="";
    gender =' ';
    email ="";
    blood_Type="";
    numOfp =0;

};

void openPatient(ifstream& inFile) ///This function is used to open the file
{

    inFile.open("Patients.txt");

    if (!inFile)
    {
        cout<<"\nError opening file!!!";//this message is displayed if the file is not found
    }
}

void readPationt(ifstream& inFile, vector<patients> &patientType)///functon reads pationts
{
    patients patientAccessor;
    patientAccessor.getNumberOfpatients(inFile);

    int loop = patientAccessor.setNumberOfPatients();
    int i=0;
    while(!inFile.eof())
    {

        patientType.push_back(patients());
        patientType[i].getid(inFile);
        patientType[i].getDoctor_id(inFile);
        patientType[i].getRecord_id(inFile);
        patientType[i].getName(inFile);
        patientType[i].getPhone(inFile);
        patientType[i].getGender(inFile);
        patientType[i].getEmail(inFile);
        patientType[i].getBlood_Type(inFile);


        i++;

    }

}
void print_pationts(ifstream& inFile, ifstream& inFileD, vector<patients> &patientType, vector<doctor> &doctorType)///functon prints pationst
{


    int index;
    int docIn;
    for(int i=0; i<patientType.size(); i++)
    {
        docIn = patientType[i].setDoctor_id();

        cout<<"==============================================="<<endl;
        docIn = patientType[i].setDoctor_id();
        cout<<"Patient Id: ";
        patientType[i].printId();
        cout<<"Patient's Doctor Id: ";
        patientType[i].printDid();
        cout<<"Patient's record Id: ";
        patientType[i].printRid();
        cout<<"Patient Name: ";
        patientType[i].printName();
        cout<<"Patient Gender: ";
        patientType[i].printGender();
        cout<<"Blood Type: ";
        patientType[i].printBlood();
        cout<<"Patient Phone Number: ";
        patientType[i].printPhone();
        cout<<"Patient Email: ";
        patientType[i].printEmail();

        for(int j=0; j<doctorType.size(); j++)
        {
            if(docIn ==doctorType[j].setDoctor_id())
            {
                index =j;
                cout<<"Patient's Doctor Name: ";
                doctorType[index].print_name();
                cout<<"==============================================="<<endl;
            }



        }
    }





}
void searchForPationts(ifstream& inFile, ifstream& inFileD, vector<patients> &patientType, vector<doctor> &doctorType)///Function searches for patients
{
    string s;
    int choice;
    int patientId;
    int doctorId;
    int docIn;
    string pationtsName;
    string patientEmail;
    cout<<"How would you like to search for patient?"<<endl;
    cout<<"Enter 1 to search by patient name: "<<endl;
    cout<<"Enter 2 to search by Email:"<<endl;

    cin>>choice;
    openDoctor(inFileD);
    readDoctor(inFileD, doctorType);
    int index;
    if(choice ==1 )
    {
        cout<<"Please Enter Patents name: ";
        cin >>pationtsName;
        for(int i=0; i<patientType.size(); i++)
        {
            if (pationtsName == patientType[i].setName())
            {
                cout<<"==============================================="<<endl;
                docIn = patientType[i].setDoctor_id();
                cout<<"Patient Id: ";
                patientType[i].printId();
                cout<<"Patient's Doctor Id: ";
                patientType[i].printDid();
                cout<<"Patient's record Id: ";
                patientType[i].printRid();
                cout<<"Patient Name: ";
                patientType[i].printName();
                cout<<"Patient Gender: ";
                patientType[i].printGender();
                cout<<"Blood Type: ";
                patientType[i].printBlood();
                cout<<"Patient Phone Number: ";
                patientType[i].printPhone();
                cout<<"Patient Email: ";
                patientType[i].printEmail();


            }

        }
        for(int j=0; j<doctorType.size(); j++)
        {
            if (docIn == doctorType[j].setDoctor_id())
            {
                index =j;
                cout<<"Patient's doctor: ";
                doctorType[index].print_name();

                cout<<"==============================================="<<endl;
            }
        }

    }
    if (choice ==2)
    {
        cout<<"Please Enter Patents Email: ";
        cin >>patientEmail;
        for(int i=0; i<patientType.size(); i++)
        {
            if (patientEmail == patientType[i].setEmail())
            {
                cout<<"==============================================="<<endl;
                docIn = patientType[i].setDoctor_id();
                cout<<"Patient Id: ";
                patientType[i].printId();
                cout<<"Patient's Doctor Id: ";
                patientType[i].printDid();
                cout<<"Patient's record Id: ";
                patientType[i].printRid();
                cout<<"Patient Name: ";
                patientType[i].printName();
                cout<<"Patient Gender: ";
                patientType[i].printGender();
                cout<<"Blood Type: ";
                patientType[i].printBlood();
                cout<<"Patient Phone Number: ";
                patientType[i].printPhone();
                cout<<"Patient Email: ";
                patientType[i].printEmail();

            }
        }
        for(int j=0; j<doctorType.size(); j++)
        {
            if (docIn == doctorType[j].setDoctor_id())
            {
                index =j;
                cout<<"Patient's doctor: ";
                doctorType[index].print_name();

                cout<<"==============================================="<<endl;
            }
        }


    }



}

void addPatient(ifstream& inFile, vector<patients> &patientType)///Function is used to add new patients
{

    int temp=0;
    int numOfPationt;
    cout<<"How many patients would you like to add? ";
    cin>>numOfPationt;
    temp = patientType.size();


    for(int i=temp; i<(temp+numOfPationt); i++)
    {
        cout<<"==============================================="<<endl;
        patientType.push_back(patients());
        cout<<"Enter New patient Id: ";
        cin>>patientType[i].id;
        cout<<"Enter New patient Doctors Id :";
        cin>>patientType[i].doctor_id;
        cout<<"Enter New patient record Id: ";
        cin>>patientType[i].record_id;
        cout<<"Enter New patient Name: ";
        cin>>patientType[i].name;
        cout<<"Enter New patient Phone Number: ";
        cin>>patientType[i].phone;
        cout<<"Enter New patient Gender: ";
        cin>>patientType[i].gender;
        cout<<"Enter New patient Email: ";
        cin>>patientType[i].email;
        cout<<"Enter New Patient blood type: ";
        cin>>patientType[i].blood_Type;
        cout<<"==============================================="<<endl;
    }



}
void delete_pationt(ifstream& inFile, vector<patients> &patientType)///Functon delets pationts
{
    string pationtsName;
    int index;
    cout<<"Please Enter the name of the patient you want to delete: ";
    cin >>pationtsName;
    for(int i=0; i<patientType.size(); i++)
    {
        if (pationtsName == patientType[i].setName())
        {
            index =i;
        }
    }
    patientType.erase(patientType.begin()+index);
}
void update_pationt(ifstream& inFile, vector<patients> &patientType)///Function updates pationts to vector
{

    string pationtsName;
    cout<<"Please Enter the name of the patient you would like to update: ";
    cin >>pationtsName;
    for(int i=0; i<patientType.size(); i++)
    {
        if (pationtsName == patientType[i].setName())
        {
            cout<<"==============================================="<<endl;
            cout<<"Enter Patient's new id: ";
            cin>>patientType[i].id;
            cout<<"Enter Patient's new Doctor Id: ";
            cin>>patientType[i].doctor_id;
            cout<<"Enter Patient's new record Id: ";
            cin>>patientType[i].record_id;
            cout<<"Enter Patient new Name: ";
            cin>> patientType[i].name;
            cout<<"Enter Patient new phone: ";
            cin>>patientType[i].phone;
            cout<<"Enter Patient's new Gender: ";
            cin>>patientType[i].gender;
            cout<<"Enter Patient's new Blood Type: ";
            cin>>patientType[i].blood_Type;
            cout<<"Enter Patient new Email: ";
            cin>>patientType[i].email;
            cout<<"==============================================="<<endl;

        }
    }




}
void search_by_doctorname(ifstream& inFile, ifstream& inFileD, vector<patients> &patientType, vector<doctor> &doctorType)///Function searches for pation by doctor name
{
    openDoctor(inFileD);
    readDoctor(inFileD, doctorType);
    string doctorName;
    cout<<"Please Enter doctor's name: ";
    cin>>doctorName;
    int docId;
    int index;
    for(int i=0; i<doctorType.size(); i++)
    {
        if(doctorName == doctorType[i].setDoctors_name())
        {
            docId = doctorType[i].setDoctor_id();
            cout<<"Doctor's Name: ";
            doctorType[i].print_name();
            cout<<"=================================================="<<endl;
        }
    }
    for(int i=0; i<patientType.size(); i++)
    {
        if(docId == patientType[i].setDoctor_id())
        {
            index =i;
            cout<<"=================================================="<<endl;
            cout<<"Patient Id: ";
            patientType[i].printId();
            cout<<"Patient's Doctor Id: ";
            patientType[i].printDid();
            cout<<"Patient's record Id: ";
            patientType[i].printRid();
            cout<<"Patient Name: ";
            patientType[i].printName();
            cout<<"Patient Gender: ";
            patientType[i].printGender();
            cout<<"Blood Type: ";
            patientType[i].printBlood();
            cout<<"Patient Phone Number: ";
            patientType[i].printPhone();
            cout<<"Patient Email: ";
            patientType[i].printEmail();
            cout<<"=================================================="<<endl;
        }

    }



}




void manag_pationts(int choice, ifstream& inFile, ifstream& inFileD, vector<patients> &patientType, vector<doctor> &doctorType)///Function is used to manage patients
{

    openPatient(inFile);
    readPationt(inFile, patientType);


    switch(choice)
    {
    case 1:
        ///function call to add patients
        system("CLS");
        addPatient(inFile, patientType);
        cout<<"Patient has been added!"<<endl;
        system("PAUSE");
        system("CLS");
        break;
    case 2:
        ///function call to update patient's info
        system("CLS");
        update_pationt(inFile, patientType);
        cout<<"Patient info has been updated!!!"<<endl;
        system("PAUSE");
        system("CLS");
        break;
    case 3:
        ///function call to delete patient
        system("CLS");
        delete_pationt(inFile, patientType);
        cout<<"The patient has been Deleted!!!!"<<endl;
        system("PAUSE");
        system("CLS");
        break;
    case 4:
        ///function call to View all patients
        system("CLS");
        openDoctor(inFileD);
        readDoctor(inFileD, doctorType);
        print_pationts(inFile, inFileD, patientType, doctorType);
        system("PAUSE");
        system("CLS");
        break;
    case 5:
        ///function call to search for patients
        system("CLS");
        searchForPationts(inFile, inFileD, patientType, doctorType);
        system("PAUSE");
        system("CLS");
        break;
    case 6:
        ///function call to search patients by doctor's name
        system("CLS");
        search_by_doctorname(inFile, inFileD, patientType, doctorType);
        system("PAUSE");
        system("CLS");
        break;
    case 7:
        ///function call to Show patient's appointments by time range
        system("CLS");
        break;
    case 8:
        ///function call to go back to main menu
        system("CLS");

        break;


    }
}
