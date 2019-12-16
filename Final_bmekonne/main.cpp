#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <windows.h>
#include "slotse.h"
#include "appo.h"
#include "patients.h"
#include "doctors.h"
#include "record.h"
#include "date_time.h"
#include "diagnosis.h"

using namespace std;




int main()
{
///decloration of vectors
    vector<record>recordType;
    vector<patients> patientType;
    vector<doctor> doctorType;
    vector<appo>appoType;
    vector<slotse> slotseType;
    vector<date_time> date_timeType;
    vector<diagnosis> diagnosisType;
///end of vector decloration

    ifstream inFile;
    ifstream inFileD;
    ifstream inFileS;
    ifstream inFileT;
    ifstream inFileA;
    openDiagnosis(inFileA);//calling diagnosis opening function
    ReadDiagnosis(inFileA, diagnosisType);//calling diagnosis reading function

mainMenu://main menu
    cout<<"Welcome to HMS. Please choose an action:"<<endl;
    cout<<endl;
    cout<<"1. Manage Appointments"<<endl;
    cout<<"2. Manage Slots"<<endl;
    cout<<"3. Manage Doctors"<<endl;
    cout<<"4. Manage Patients"<<endl;
    cout<<"5. Manage Patients' records"<<endl;
    cout<<"6. Manage lab"<<endl;
    cout<<"7. Exit"<<endl;

    int choice;
    cin>>choice;

    switch(choice)
    {
    case 1:///Manage Appointments
        system("CLS");
        cout<<"1. Schedule a new Appointment"<<endl;
        cout<<"2. View appointments by patine's name or email"<<endl;
        cout<<"3. view appointments by Doctors name"<<endl;
        cout<<"4. View all appointments"<<endl;
        cout<<"5. Modify/Reschedule an existing appointment"<<endl;
        cout<<"6. Remove an appointment"<<endl;
        cout<<"7. Main menu:"<<endl;
        int A;
        cin>>A;
        mange_appointment(A, inFile, inFileD, inFileS, inFileT, inFileA, patientType, doctorType, slotseType, date_timeType, appoType, diagnosisType);///function call to manage appointments
        goto mainMenu;///takes user back to main menu
        break;
    case 2:/// Manage slots
        system("CLS");
        cout<<"1. View available slots"<<endl;
        cout<<"2. View unavailable slots"<<endl;
        cout<<"3. Add new slot(s)"<<endl;
        cout<<"4. View slots between two times"<<endl;
        cout<<"5. View all slots"<<endl;
        cout<<"6. View all slots for a certain doctor"<<endl;
        cout<<"7. Modify slot information"<<endl;
        cout<<"8. Remove a Slot"<<endl;
        cout<<"9. Main menu:"<<endl;
        int B;
        cin>>B;
        manage_slots(B, inFileS, slotseType);///function call to manage slots
        goto mainMenu;///takes user back to main menu
        break;
    case 3:///Manage doctors
        system("CLS");
        cout<<"1. View all Doctors"<<endl;
        cout<<"2. Update Doctors's info"<<endl;
        cout<<"3. delete a doctor"<<endl;
        cout<<"4. Search for a doctor"<<endl;
        cout<<"5. Main menu"<<endl;
        int C;
        cin>>C;
        manage_Doctors(C, inFileD, doctorType);///function call to manage doctors

        goto mainMenu;///takes user back to main menu
        break;
    case 4:
        system("CLS");///clear screen
        ///case options
        cout<<"1. Add patient"<<endl;
        cout<<"2. update patient's info"<<endl;
        cout<<"3. Delete patient"<<endl;
        cout<<"4. View all patients"<<endl;
        cout<<"5. Search for patients"<<endl;
        cout<<"6. Search for patients by doctor's name"<<endl;
        cout<<"7. Show patient's appointments by time range"<<endl;
        cout<<"8. Go Back"<<endl;
        int D;
        cin>>D;
        manag_pationts(D, inFile, inFileD, patientType, doctorType);///function call to manage patients
        goto mainMenu;///takes user back to main menu
        break;
    case 5:
        system("CLS");
        cout<<"1. Add new record"<<endl;
        cout<<"2. update record"<<endl;
        cout<<"3. show all records"<<endl;
        cout<<"4. Delete a record"<<endl;
        cout<<"5. Main menu"<<endl;
        int E;
        cin>>E;
        manage_records(E, recordType);
        goto mainMenu;///takes user back to main menu
        break;


        inFile.close();
        inFileD.close();
        inFileS.close();
        inFileT.close();
        inFileA.close();

        return 0;
    }
}


