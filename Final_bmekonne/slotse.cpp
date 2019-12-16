#include <fstream>
#include <algorithm>
#include <vector>
#include <iostream>
#include <iomanip>
#include <windows.h>
#include "slotse.h"
#include "date_time.h"

using namespace std;

slotse::slotse()
{

    id=0;
    date_id=0;
    doctor_id=0;
    numOfslot =0;
    slotAvalible = true;

}
/*
bool slotse::setAva(vector<slotse> &slotseType)
{
    for(int i=0; i<slotseType.size(); i++)
   {


   if (slotseType[i].setAvaleble() == "available")
   {
      return true;
   }
  if (slotseType[i].setAvaleble()=="unavailable")
   {
       return false;
   }
}

}*/


void openSlot(ifstream& inFileS) ///This function is used to open the file
{

    inFileS.open("Slots.txt");

    if (!inFileS)
    {
        cout<<"\nError opening file!!";//this message is displayed if the file is not found
    }
}


void readSlot(ifstream& inFileS, vector<slotse> &slotseType)///read slots
{
    slotse slotAccessor;

    slotAccessor.getNumberOfSlots(inFileS);
    int loop = slotAccessor.setNumberOfSlots();
    for(int i=0; i<loop; i++)
    {
        slotseType.push_back(slotse());
        slotseType[i].getSlot_id(inFileS);
        slotseType[i].getDate_id(inFileS);
        slotseType[i].getDoctor_id(inFileS);
        slotseType[i].getAva(inFileS);
    }

}
void show_avalible_slots(ifstream& inFileS, vector<slotse> &slotseType)///show all avalible slots
{

    string s;
    string avaliblity ="available";
    cout<<"=================*All Available Slots*======================="<<endl;

    for(int i=0; i<slotseType.size(); i++)
    {

        if(slotseType[i].setAvaleble())
        {
            cout<<"==============================================="<<endl;
            cout<<"Slot Id: "<<
                slotseType[i].setSlot_id()<<endl;
            cout<<"Date Id: "<<
                slotseType[i].setDate_id()<<endl;
            cout<<"Doctor Id: "<<
                slotseType[i].setDoctor_id()<<endl;
            cout<<"availability: "<<
                slotseType[i].setAvaleble()<<endl;
            cout<<"==============================================="<<endl;
        }
    }

}
void show_unavalible_slots(ifstream& inFileS, vector<slotse> &slotseType)///show unavalible slots
{


    string avaliblity ="available";
    cout<<"=================*All Unavailable Slots*======================="<<endl;

    for(int i=0; i<slotseType.size(); i++)
    {

        if( !slotseType[i].setAvaleble() )
        {
            cout<<"Slot Id: "<<
                slotseType[i].setSlot_id()<<endl;
            cout<<"Date Id: "<<
                slotseType[i].setDate_id()<<endl;
            cout<<"Doctor Id: "<<
                slotseType[i].setDoctor_id()<<endl;
            cout<<"availability: "<<
                slotseType[i].setAvaleble()<<endl;
        }
    }

}
void show_all_slots(ifstream& inFileS, vector<slotse> &slotseType)///show all slots
{


    cout<<"=================*All Slots*==================="<<endl;

    for(int i=0; i<slotseType.size(); i++)
    {

        cout<<"==============================================="<<endl;
        cout<<"Slot Id: ";
        slotseType[i].printId();
        cout<<"Date Id: ";
        slotseType[i].printDate_id();
        cout<<"Doctor Id: ";
        slotseType[i].printdoctor_id();
        cout<<"availability: ";
        slotseType[i].printAvalibilty();
        cout<<"==============================================="<<endl;
    }

}

void add_slot(ifstream& inFileS, vector<slotse> &slotseType)///add new slots
{
    int temp =0;
    int numOfSlots;
    cout<<"How many slots would you like to add? ";
    cin>>numOfSlots;
    temp = slotseType.size();
    for(int i=temp; i<(temp+numOfSlots); i++)
    {
        cout<<"==============================================="<<endl;
        slotseType.push_back(slotse());
        cout<<"Enter New slot Id: ";
        cin>>slotseType[i].id;
        cout<<"Enter New date Id: ";
        cin>>slotseType[i].date_id;
        cout<<"Enter New doctor Id: ";
        cin>>slotseType[i].doctor_id;
        cout<<"Enter Availability: ";
        cin>>slotseType[i].avalible;
        cout<<"==============================================="<<endl;

    }
    cout<<"The new slot has been added!!!"<<endl;
}

void remove_slot(ifstream& inFileS, vector<slotse> &slotseType)///delete slots
{

    int slotId;
    int index;
    cout<<"Please Enter the slot Id of the slot you would like to remove: ";
    cin>>slotId;
    for(int i=0; i<slotseType.size(); i++)
    {
        if(slotId == slotseType[i].setSlot_id())
        {

            slotseType.erase(slotseType.begin()+i);
        }

    }







}
void modify_slot(ifstream& inFileS, vector<slotse> &slotseType)///update slots
{
    cout<<"=================*Modify Slots*================="<<endl;

    int slotId;
    cout<<"Please Enter the slot Id of the slot you would like to modify: ";
    cin>>slotId;
    for(int i=0; i<slotseType.size(); i++)
    {

        if(slotId == slotseType[i].setSlot_id())
        {

            cout<<"Enter updated slot Id: ";
            cin>>slotseType[i].id;
            cout<<"Enter updated date Id: ";
            cin>>slotseType[i].date_id;
            cout<<"Enter updated doctor Id: ";
            cin>>slotseType[i].doctor_id;
            cout<<"Enter updated Availability: ";
            cin>>slotseType[i].avalible;
        }



    }

    cout<<"==============================================="<<endl;
    cout<<"Slot has been modified!!!"<<endl;



}
void doctor_slots(ifstream& inFileS, vector<slotse> & slotseType)///see avaliblity
{
    string avalible ="available";
    int doctorId;
    cout<<"Please enter the Id of the doctor you would like to see: ";
    cin>>doctorId;
    for(int i=0; i<slotseType.size(); i++)
    {
        if(doctorId == slotseType[i].setDoctor_id() && slotseType[i].setAvaleble())
        {
            cout<<"==============================================="<<endl;
            cout<<"Slot Id: ";
            slotseType[i].printId();
            cout<<"Date Id: ";
            slotseType[i].printDate_id();
            cout<<"Doctor Id: ";
            slotseType[i].printdoctor_id();
            cout<<"availability: ";
            slotseType[i].printAvalibilty();
            cout<<"==============================================="<<endl;

        }

    }
}












void manage_slots(int choice, ifstream& inFileS, vector<slotse> &slotseType)///don't forget to include needed vectors a a perametire
{
    openSlot(inFileS);
    readSlot(inFileS, slotseType);

    switch(choice)
    {
    case 1:
        ///function call to Show available slots
        system("CLS");
        show_avalible_slots(inFileS, slotseType);
        system("PAUSE");
        system("CLS");
        break;
    case 2:
        ///function call to Show unavailable slots
        system("CLS");
        show_unavalible_slots(inFileS, slotseType);
        system("PAUSE");
        system("CLS");
        break;
    case 3:
        ///function call to Add new slot
        system("CLS");
        add_slot(inFileS, slotseType);
        system("PAUSE");
        system("CLS");

        break;
    case 4:
        ///function call to Show slots between two time

        break;
    case 5:
        ///function call to Show all slots
        system("CLS");
        show_all_slots(inFileS, slotseType);
        system("PAUSE");
        system("CLS");
        break;
    case 6:
        ///function call to Show all slots for a certain doctor
        system("CLS");
        doctor_slots(inFileS, slotseType);
        system("PAUSE");
        system("CLS");
        break;
    case 7:
        ///function call to Modify slot information
        system("CLS");
        modify_slot(inFileS, slotseType);
        system("PAUSE");
        system("CLS");
        break;
    case 8:
        ///Function call to Remove a Slot
        system("CLS");
        remove_slot(inFileS, slotseType);
        system("PAUSE");
        system("CLS");
        break;
    case 9:
        ///function call to Go to Main menu
        break;
    }

}


