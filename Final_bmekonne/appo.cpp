#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <windows.h>
#include "patients.h"
#include "doctors.h"
#include "appo.h"
#include "slotse.h"
#include "date_time.h"
#include "diagnosis.h"
using namespace std;
appo::appo()///constructor
{

    id=0;
    doctor_id =0;
    patient_id =0;
    slot_id =0;
    reason ="";
    diagnoses_id ="";
    prescribed_medication="";


}







void new_appointment(ifstream&inFileT, vector<patients> &patientType, vector<doctor> &doctorType, vector<slotse> &slotseType,vector<date_time> &date_timeType, vector<appo> &appoType)///Function is used to display appintment and time
{


    int tempIndex;
    int patientId;
    int slotid;
    int temp=0;
    int doctorId=0;
    int index=0;
    int slotIndex =0;
    int dateId =0;
    string reason;
    string avaliblity = "available";
    temp = appoType.size();

    cout<<"Please Enter Patient Id: ";
    cin>>patientId;
    cout<<"available appointment times"<<endl;
    for(int i=0; i<patientType.size(); i++)
    {

        if(patientId == patientType[i].setid())
        {

            doctorId = patientType[i].setDoctor_id();

        }

    }


    for(int i=0; i<slotseType.size(); i++)
    {
        if(doctorId == slotseType[i].setDoctor_id())
        {
            slotIndex =i;
            dateId = slotseType[i].setDate_id();
            cout<<"==============================================="<<endl;
            cout<<"Slot Id: ";
            slotseType[i].printId();
            cout<<"Date Id: ";
            slotseType[slotIndex].printDate_id();



            for(int j=0; j<date_timeType.size(); j++)
            {


                if(dateId == date_timeType[j].setId())
                {

                    printDate(date_timeType, j);
                }

            }


        }



    }

}
void make_new(ifstream& inFileA, vector<appo> &appoType, vector<slotse> &slotseType, vector<diagnosis> &diagnosisType)///Functon is used to make new appintment
{

    int SlotId=0;
    int numOfApt=0;
    int temp =0;
    string reason;
    string medican="";
    cout<<"How many appoinntmets would you like to make? ";
    cin>>numOfApt;
    temp = appoType.size();
    int appointmentId=0;
    for(int i=temp; i<(temp+numOfApt); i++)
    {

        cout<<"==============================================="<<endl;
        appoType.push_back(appo());
        cout<<"Pleas Enter Doctor's Id: ";
        cin>>appoType[i].doctor_id;
        cout<<"Please Enter Patient Id: ";
        cin>>appoType[i].patient_id;
        cout<<"Please Enter Slot Id: ";
        cin>>appoType[i].slot_id;

        cout<<"Please Enter reason for appointment: ";
        cin.ignore();
        getline(cin, appoType[i].reason);
        cout<<"Input the diagnoses Id: "<<endl;
        printDiagnosis(inFileA, diagnosisType);

        cin>>appoType[i].diagnoses_id;
        cout<<"Enter appointment Id:";
        cin>>appoType[i].id;
        cout<<"Enter Medication: ";
        cin>>appoType[i].prescribed_medication;

        SlotId = appoType[i].setSlot_Id();
    }


    for(int i=0; i<slotseType.size(); i++)
    {
        if (SlotId == slotseType[i].setSlot_id())
        {
            slotseType[i].getAva(false);
        }


    }


}





void view_appointmentBypationt(vector<appo> &appoType, vector<patients> &patientType)///Function is used to see apointment by pationt name
{

    string nameOrEmail;
    int temp;
    cout<<"Please Enter patient name or Emile: ";
    cin>>nameOrEmail;

    for(int i=0; i<appoType.size(); i++)
    {
        for(int j=0; j<patientType.size(); j++)
        {
            if(patientType[j].setName() ==nameOrEmail|| nameOrEmail == patientType[j].setEmail())
            {

                temp = patientType[j].setid();





                if(appoType[i].setPatient_Id()==temp)
                {
                    cout<<"==============================================="<<endl;
                    cout<<"Patients Name: ";
                    patientType[j].printName();

                    cout<<"Appointment Id: "<<
                        appoType[i].id<<endl;
                    cout<<"Doctor Id: "<<
                        appoType[i].doctor_id<<endl;
                    cout<<"Patient Id: "<<
                        appoType[i].patient_id<<endl;
                    cout<<"Slot Id: "<<
                        appoType[i].slot_id<<endl;
                    cout<<"Appointment reason: "<<
                        appoType[i].reason<<endl;
                    cout<<"Prescribed Medication: "<<
                        appoType[i].prescribed_medication<<endl;
                    cout<<"==============================================="<<endl;

                }
            }



        }

    }
}

void view_appointmen_by_DoctorName(vector<doctor> &doctorType, vector<appo> &appoType, vector<patients> &patientType)
{

    string name;
    int temp;
    cout<<"Please Enter Doctor's name: ";
    cin>>name;

    for(int i=0; i<appoType.size(); i++)
    {
        for(int j=0; j<doctorType.size(); j++)
        {
            if( name==doctorType[j].setDoctors_name())
            {
                temp =doctorType[j].setDoctor_id();


                if(appoType[i].setDoctor_Id()==temp)
                {
                    cout<<"==============================================="<<endl;

                    for(int k=0; k<patientType.size(); k++)
                    {
                        if(appoType[i].setPatient_Id() == patientType[k].setid())
                        {
                            cout<<"Patients Name: ";
                            patientType[k].printName();
                        }
                    }
                    cout<<"Appointment Id: "<<
                        appoType[i].id<<endl;
                    cout<<"Doctor Id: "<<
                        appoType[i].doctor_id<<endl;
                    cout<<"Patient Id: "<<
                        appoType[i].patient_id<<endl;
                    cout<<"Slot Id: "<<
                        appoType[i].slot_id<<endl;
                    cout<<"Appointment reason: "<<
                        appoType[i].reason<<endl;
                    cout<<"Prescribed Medication: "<<
                        appoType[i].prescribed_medication<<endl;
                    cout<<"==============================================="<<endl;

                }
            }
        }
    }

}






void deletAppointment(vector<appo> &appoType)///Delet functon
{

    int appointmentId;
    int index;
    cout<<"Please Enter the Appointment Id of the appointment you would like to delete: ";
    cin>>appointmentId;
    for(int i=0; i<appoType.size(); i++)
    {
        if(appointmentId == appoType[i].setId())
        {

            appoType.erase(appoType.begin()+i);


        }
    }
    cout<<"Appointment Has been deleted!!!"<<endl;








}

void view_All_app(vector<appo> &appoType)///view all pationt
{

    for(int i=0; i<appoType.size(); i++)
    {

        cout<<"==============================================="<<endl;
        cout<<"Appointment Id: "<<
            appoType[i].id<<endl;
        cout<<"Doctor Id: "<<
            appoType[i].doctor_id<<endl;
        cout<<"Patient Id: "<<
            appoType[i].patient_id<<endl;
        cout<<"Slot Id: "<<
            appoType[i].slot_id<<endl;
        cout<<"Appointment reason: "<<
            appoType[i].reason<<endl;
        cout<<"Prescribed Medication: "<<
            appoType[i].prescribed_medication<<endl;
        cout<<"==============================================="<<endl;

    }



}

void update_appointment(vector<appo> &appoType)
{

    int slot;
    int doctor;
    cout<<"Enter the Doctor id of the appointnt you want to update:";
    cin>>doctor;
    cout<<"Enter the slot id of the appointment :";
    cin>>slot;


    for(int i=0; i<appoType.size(); i++)
    {

        if(slot == appoType[i].setSlot_Id())
        {
            cout<<"Appointment Id: "<<
                appoType[i].id<<endl;
            cout<<"Doctor Id: "<<
                appoType[i].doctor_id<<endl;
            cout<<"Patient Id: "<<
                appoType[i].patient_id<<endl;
            cout<<"Slot Id: "<<
                appoType[i].slot_id<<endl;
            cout<<"Appointment reason: "<<
                appoType[i].reason<<endl;
            cout<<"Prescribed Medication: "<<
                appoType[i].prescribed_medication<<endl;
        }



    }


}

void mange_appointment(int choice,ifstream& inFile, ifstream& inFileD, ifstream&inFileS, ifstream& inFileT, ifstream& inFileA, vector<patients> &patientType, vector<doctor> &doctorType, vector<slotse> &slotseType,vector<date_time> &date_timeType, vector<appo> &appoType, vector<diagnosis> &diagnosisType) ///used to manage appointments
{


    switch(choice)
    {
    case 1:
        ///function call to schedule a new appointment
        openPatient(inFile);
        readPationt(inFile, patientType);
        openDoctor(inFileD);
        readDoctor(inFileD, doctorType);
        openSlot(inFileS);
        readSlot(inFileS, slotseType);
        openDate_time(inFileT);
        readDate_time(inFileT, date_timeType);
        system("CLS");
        new_appointment(inFileT, patientType, doctorType, slotseType, date_timeType, appoType);
        make_new(inFileA, appoType, slotseType, diagnosisType);
        system("PAUSE");
        system("CLS");

        break;
    case 2:
        ///function call to show appointments by patient name
        system("CLS");
        view_appointmentBypationt(appoType, patientType);
        system("PAUSE");
        system("CLS");

        break;
    case 3:
        ///function call to show appointment by doctor name
        system("CLS");
        view_appointmen_by_DoctorName(doctorType, appoType, patientType);
        system("PAUSE");
        system("CLS");
        break;
    case 4:
        ///function call to show all appointments
        system("CLS");
        view_All_app(appoType);
        system("PAUSE");
        system("CLS");
        break;
    case 5:
        ///function call to modify appointment
        system("CLS");
        update_appointment(appoType);
        system("PAUSE");
        system("CLS");

        break;
    case 6:
        ///function call to Remove an appointment"
        system("CLS");
        deletAppointment(appoType);
        system("PAUSE");
        system("CLS");
        break;
    case 7:
        ///function call to go back to main menu
        break;

    }

}

