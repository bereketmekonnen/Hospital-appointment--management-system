#ifndef APPO_H_INCLUDED
#define APPO_H_INCLUDED
#include "patients.h"
#include "doctors.h"
#include "appo.h"
#include "slotse.h"
#include "date_time.h"
#include "diagnosis.h"
using namespace std;


class appo{///class decloration

private:
    int id;
    int doctor_id;
    int patient_id;
    int slot_id;
    string reason;
    string diagnoses_id;
    string prescribed_medication;


public:
    int setId(){return id;}
    int setDoctor_Id(){return doctor_id;}
    int setPatient_Id(){return patient_id;}
    int setSlot_Id(){return slot_id;}
    string setReason(){return reason;}
    string setDiagnoses_id(){return diagnoses_id;}
    string setPrescribe_medication(){return prescribed_medication;}
    void printId(){cout<<id<<endl;}
    void printDId(){cout<<doctor_id<<endl;}
    void printPId(){cout<<patient_id<<endl;}
    void printSId(){cout<<slot_id<<endl;}
    void printReason(){cout<<reason<<endl;}
    bool setAvaliblity(){return true;}
    void printMeds(){cout<<prescribed_medication<<endl;}
    friend void update_appointment(vector<appo> &appoType);
    friend void view_All_app(vector<appo> &appoType);
    friend void view_appointmen_by_DoctorName(vector<doctor> &doctorType, vector<appo> &appoType, vector<patients> &patientType);
    friend void view_appointmentBypationt(vector<appo> &appoType, vector<patients> &patientType);
 friend void appointment(vector<appo> &appoType, vector<slotse> & slotseType);
 friend void make_new(ifstream& inFileA, vector<appo> &appoType, vector<slotse> &slotseType, vector<diagnosis> &diagnosisType);
friend void showAppointments(vector<appo> &appoType);
friend void new_appointment(ifstream&inFileT, vector<patients> &patientType, vector<doctor> &doctorType, vector<slotse> &slotseType,vector<date_time> &date_timeType, vector<appo> &appoType);
friend void match_Doc_patientId(vector<patients> &patientType, vector<doctor> &doctorType, vector<slotse> &slotesType, int patientId, int doctorId);
friend void mange_appointment(int choice,ifstream& inFile, ifstream& inFileD, ifstream&inFileS, ifstream& inFileT, ifstream& inFileA, vector<patients> &patientType, vector<doctor> &doctorType, vector<slotse> &slotseType,vector<date_time> &date_timeType, vector<appo> &appoType, vector<diagnosis> &diagnosisType); ; ///what ever vec
appo();
};
///function decloration
void appointment(vector<appo> &appoType, vector<slotse> & slotseType);
void mange_appointment(int choice,ifstream& inFile, ifstream& inFileD, ifstream&inFileS, ifstream& inFileT, ifstream& inFileA, vector<patients> &patientType, vector<doctor> &doctorType, vector<slotse> &slotseType,vector<date_time> &date_timeType, vector<appo> &appoType, vector<diagnosis> &diagnosisType);  ///what ever vec
void printDate(vector<date_time> &date_timeType, int index);
void new_appointment(ifstream&inFileT, vector<patients> &patientType, vector<doctor> &doctorType, vector<slotse> &slotseType,vector<date_time> &date_timeType);
void showAppointments(vector<appo> &appoType);
void make_new(ifstream& inFileA, vector<appo> &appoType, vector<slotse> &slotseType, vector<diagnosis> &diagnosisType);
void deletAppointment(vector<appo> &appoType);
void view_appointmen_by_DoctorName(vector<doctor> &doctorType, vector<appo> &appoType, vector<patients> &patientType);
void view_appointmentBypationt(int counterA, vector<appo> &appoType, vector<patients> &patientType);
#endif // APPO_H_INCLUDED
