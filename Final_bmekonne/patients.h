#ifndef PATIENTS_H_INCLUDED
#define PATIENTS_H_INCLUDED
#include "doctors.h"
#include "patients.h"
#include "record.h"
#include "slotse.h"

using namespace std;

class patients{ ///class decloration

private:///class privet members
    int id;
    int doctor_id;
    int record_id;
    string name;
     string phone;
    char gender;
    string email;
    string blood_Type;
    int numOfp;

public:///class public members with get and set functions
    void getNumberOfpatients(ifstream& inFile){inFile>>numOfp;}//
    void getid(ifstream& inFile){inFile>>id;}
    void getDoctor_id(ifstream & inFile){inFile>>doctor_id;}
    void getRecord_id(ifstream & inFile){inFile>>record_id;}
    void getName(ifstream & inFile){inFile>>name;}
    void getPhone(ifstream& inFile){inFile>>phone;}
    void getGender(ifstream&inFile){inFile>>gender;}
    void getEmail(ifstream& inFile){inFile>>email;}
    void getBlood_Type(ifstream&inFile){inFile>>blood_Type;}
    int setid(){return id;}
    void printId(){cout<<id<<endl;}
    void printDid(){cout<<doctor_id<<endl;}
    void printRid(){cout<<record_id<<endl;}
    void printName(){cout<<name<<endl;}
    void printPhone(){cout<<phone<<endl;}
    void printGender(){cout<<gender<<endl;}
    void printEmail(){cout<<email<<endl;}
    void printBlood(){cout<<blood_Type<<endl;}
    int setDoctor_id(){return doctor_id;}
    int setRecord_id(){return record_id;}
    string setName(){return name;}
    string setPhone(){return phone;}
    char setGender(){return gender;}
    string setEmail(){return email;}
    string setBlood_Type(){return blood_Type;}
    int setNumberOfPatients(){return numOfp;}
    void print(){cout<<numOfp<<endl;}
friend void addPatient(ifstream& inFile, vector<patients> &patientType);
friend void delete_pationt(ifstream& inFile, vector<patients> &patientType);
    friend void update_pationt(ifstream& inFile, vector<patients> &patientType);

    patients();
};
///Function decloration
void delete_pationt(ifstream& inFile, vector<patients> &patientType);//function
void readPationt(ifstream& inFile, vector<patients> &patientType);
void openPatient(ifstream& inFile);
void manag_pationts(int choice, ifstream& inFile, ifstream& inFileD, vector<patients> &patientType, vector<doctor> &doctorType);
void print_pationts(ifstream& inFile, ifstream& inFileD, vector<patients> &patientType, vector<doctor> &doctorType);
void searchForPationts(ifstream& inFile, vector<patients> &patientType, vector<doctor> &doctorType);
void addPatient(ifstream&inFile, vector<patients> &patientType);
#endif // PATIENTS_H_INCLUDED
