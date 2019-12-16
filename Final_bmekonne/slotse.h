#ifndef SLOTSE_H_INCLUDED
#define SLOTSE_H_INCLUDED
#include "date_time.h"


using namespace std;
class slotse{///class

private:
    int id;
    int date_id;
    int doctor_id;
    bool slotAvalible;
    int numOfslot;
     string avalible;
public:///get and set functons
    void getNumberOfSlots(ifstream& inFileS){inFileS>>numOfslot;}
    int setNumberOfSlots(){return numOfslot;}
    void getSlot_id(ifstream& inFileS){inFileS>>id;}
    int setSlot_id(){return id;}
    void getDate_id(ifstream& inFileS){inFileS>>date_id;}
    int setDate_id(){return date_id;}
    void getDoctor_id(ifstream&inFileS){inFileS>>doctor_id;}
    int setDoctor_id(){return doctor_id;}
    void getAva(ifstream&inFileS){inFileS>>avalible; if(avalible[0]=='a'){slotAvalible=true;}else{slotAvalible=false;}}
    void getAva( bool b){slotAvalible=b;}
    bool setAvaleble(){return slotAvalible;}
    bool setAva(){return slotAvalible;}
    void printId(){cout<<id<<endl;}
    void printDate_id(){cout<<date_id<<endl;}
    void printdoctor_id(){cout<<doctor_id<<endl;}
    void printAvalibilty(){cout<<slotAvalible<<endl;}
    ///Friend functions so they can acces privet members
    friend void show_unavalible_slots(ifstream& inFileS, vector<slotse> &slotseType);
    friend void show_avalible_slots(ifstream& inFileS, vector<slotse> &slotseType);

  friend void manage_slots(int choice, ifstream& inFileS, vector<slotse> &slotseType);
  friend void add_slot(ifstream& inFileS, vector<slotse> &slotseType);
  friend void modify_slot(ifstream& inFileS, vector<slotse> &slotseType);
    slotse();
};
///Function decloration
void show_avalible_slots(ifstream& inFileS, vector<slotse> &slotseType);
void manage_slots(int choice, ifstream& inFileS, vector<slotse> &slotseType);
void readSlot(ifstream& inFileS, vector<slotse> &slotseType);
void openSlot(ifstream& inFileS);
void show_unavalible_slots(ifstream& inFileS, vector<slotse> &slotseType);
void show_all_slots(ifstream& inFileS, vector<slotse> &slotseType);
void add_slot(ifstream& inFileS, vector<slotse> &slotseType);
void remove_slot(ifstream& inFileS, vector<slotse> &slotseType);
void modify_slot(ifstream& inFileS, vector<slotse> &slotseType);
void doctor_slots(ifstream& inFileS, vector<slotse> & slotseType);
#endif // SLOTSE_H_INCLUDED
