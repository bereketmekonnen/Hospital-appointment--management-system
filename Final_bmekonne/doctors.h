#ifndef DOCTORS_H_INCLUDED
#define DOCTORS_H_INCLUDED
#include "patients.h"
#include "record.h"


using namespace std;



class doctor
{///class declaration

private:///private memebers
    int id;
    string username;
    string password;
    string name;
    string phone;
    string skill;
    int numOfDoctors;

public:///get and set functions
    void getNumberofDoctors (ifstream& inFileD)
    {
        inFileD>>numOfDoctors;
    }
    int setNumberofDoctors()
    {
        return numOfDoctors;
    }
    void getDoctor_Id(ifstream& inFileD)
    {
        inFileD>>id;
    }
    void getDoctor_username(ifstream& inFileD)
    {
        inFileD>>username;
    }
    void getDoctor_password(ifstream& inFileD)
    {
        inFileD>>password;
    }
    void getDoctor_phone(ifstream& inFileD)
    {
        inFileD>>phone;
    }
    void getDoctor_name(ifstream& inFileD)
    {
        inFileD>>name;
    }
    void getSkill(ifstream& inFileD)
    {
        inFileD>>skill;
    }
    int setDoctor_id()
    {
        return id;
    }
    string setDoctor_username()
    {
        return username;
    }
    string setDoctor_password()
    {
        return password;
    }
    string setDoctors_name()
    {
        return name;
    }
    string setDoctors_phone()
    {
        return phone;
    }
    string setSkill()
    {
        return skill;
    }
    void print()
    {
        cout<<numOfDoctors<<endl;
    }
    void print_id()
    {
        cout<<id<<endl;
    }
    void print_name()
    {
        cout<<name<<endl;
    }
    void print_phone()
    {
        cout<<phone<<endl;
    }
    void print_skill()
    {
        cout<<skill<<endl;
    }
    ///Friend functions so they can access private members
    friend void delet_doctor(ifstream& inFileD, vector<doctor> &doctorType);
    friend void manage_Doctors(int choice, ifstream& inFileD, vector<doctor> &doctorType);
    friend void readDoctor(ifstream& inFileD, vector<doctor> &doctorType);
    friend void print_Doctors(ifstream& inFileD, vector<doctor> &doctorType);
    friend void update_Doctor(ifstream& inFileD, vector<doctor> &doctorType);
    doctor();
};
///Function decloration
void delet_doctor(ifstream& inFileD, vector<doctor> &doctorType);
void update_Doctor(ifstream& inFileD, vector<doctor> &doctorType);
void manage_Doctors(int choice, ifstream& inFileD, vector<doctor> &doctorType);
void readDoctor(ifstream& inFileD, vector<doctor> &doctorType);
void print_Doctors(ifstream& inFileD, vector<doctor> &doctorType);
void searchForDoctor(ifstream& inFileD, vector<doctor> &doctorType);
void openDoctor(ifstream& inFileD);
#endif // DOCTORS_H_INCLUDED
