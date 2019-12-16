#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include "patients.h"
#include "doctors.h"
#include "record.h"


using namespace std;
doctor::doctor()///constructor
{

    id=0;
    username="";
    password="";
    name="";
    phone="";
    skill="";
    numOfDoctors=0;

}
void openDoctor(ifstream& inFileD) ///This function is used to open the doctor file
{

    inFileD.open("Doctors.txt");


}

void readDoctor(ifstream& inFileD, vector<doctor> &doctorType)///fucntion is used to read doctors file
{

    doctor doctorAccessor;
    doctorAccessor.getNumberofDoctors(inFileD);
    int loop = doctorAccessor.setNumberofDoctors();

    for(int i=0; i<loop; i++)
    {

        doctorType.push_back(doctor());
        doctorType[i].getDoctor_Id(inFileD);
        doctorType[i].getDoctor_username(inFileD);
        doctorType[i].getDoctor_password(inFileD);
        doctorType[i].getDoctor_name(inFileD);
        doctorType[i].getDoctor_phone(inFileD);
        doctorType[i].getSkill(inFileD);

    }

}


void print_Doctors(ifstream& inFileD, vector<doctor> &doctorType)///function is used to print all doctors
{

    for(int i=0; i<doctorType.size(); i++)//for loop prints doctors until it riches the size of docters vector
    {
        cout<<"==================================="<<endl;
        cout<<"Doctor's ID: ";
        doctorType[i].print_id();
        cout<<"Doctor name: ";
        doctorType[i].print_name();
        cout<<"Doctors Phone: ";
        doctorType[i].print_phone();
        cout<<"Doctors skill: ";
        doctorType[i].print_skill();
        cout<<"==================================="<<endl;
    }

}
void searchForDoctor(ifstream& inFileD, vector<doctor> &doctorType)///fucntion is used to search for doctors
{

    string s;

    string doctorsName;
    cout<<"Please Enter Doctors Name:  ";
    cin>>doctorsName;
    for(int i=0; i<doctorType.size(); i++)//For loop is used to compare user input with doctorType vector
    {
        s = doctorType[i].setDoctors_name();
        if(doctorsName == s )
        {
            cout<<"=================================================="<<endl;
            cout<<"Doctor's ID: ";
            doctorType[i].print_id();
            cout<<"Doctor's Name: ";
            doctorType[i].print_name();
            cout<<"Doctor's Phone: ";
            doctorType[i].print_phone();
            cout<<"Doctor's Skill: ";
            doctorType[i].print_skill();
            cout<<"=================================================="<<endl;
        }

    }

}
void update_Doctor(ifstream& inFileD, vector<doctor> &doctorType)///this function is used to update doctorType vector
{
    string doctorName;
    cout<<"Please Enter the name of the Doctor you would like to update: ";
    cin>>doctorName;
    for(int i=0; i<doctorType.size(); i++)
    {

        if(doctorName == doctorType[i].setDoctors_name())
        {
            cout<<"==============================================="<<endl;
            cout<<"Enter Doctor's new Id: ";
            cin>>doctorType[i].id;
            cout<<"Enter Doctor's new username: ";
            cin>>doctorType[i].username;
            cout<<"Enter Doctor's new password: ";
            cin>>doctorType[i].password;
            cout<<"Enter Doctor's new name: ";
            cin>>doctorType[i].name;
            cout<<"Enter Doctor's new phone: ";
            cin>>doctorType[i].phone;
            cout<<"Enter Doctor's new skill: ";
            cin>>doctorType[i].skill;
            cout<<"==============================================="<<endl;
        }




    }





}
void delet_doctor(ifstream& inFileD, vector<doctor> &doctorType)///This function is used to delete doctor
{
    string doctorName;
    int index;
    cout<<"Please Enter the mane the doctor you want to delete: ";
    cin>>doctorName;
    for(int i=0; i<doctorType.size(); i++)
    {
        if(doctorName == doctorType[i].setDoctors_name())
        {
            index =i;
        }
    }
    doctorType.erase(doctorType.begin()+index);

}

void manage_Doctors(int choice, ifstream& inFileD, vector<doctor> &doctorType)///This functionis used to manage doctors it call s all the functions that are needed to the menu oppetions
{

    openDoctor(inFileD);//
    readDoctor(inFileD, doctorType);
    switch(choice)
    {
    case 1:
        ///function call to Show all Doctors
        system("CLS");

        print_Doctors(inFileD, doctorType);
        system("PAUSE");
        system("CLS");

        break;
    case 2:
        ///function call to Update Doctors's info
        system("CLS");

        update_Doctor(inFileD, doctorType);
        cout<<"Doctor's info has been updated!!!"<<endl;
        system("PAUSE");
        system("CLS");
        break;
    case 3:
        ///function call to delete a doctor
        system("CLS");

        delet_doctor(inFileD, doctorType);
        cout<<"The Doctor has been Deleted!!!!"<<endl;
        system("PAUSE");
        system("CLS");
        break;
    case 4:
        ///function call to search for a doctor
        system("CLS");

        searchForDoctor(inFileD, doctorType);
        system("PAUSE");
        system("CLS");
        break;
    case 5:
        ///function call to go to main menu
        system("CLS");
        break;
    }

}
