#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED
using namespace std;

class record {///class decloration
private:
    int id;
    int patient_id;
    string notes;
public:
    int setId(){return id;}
    int setPationt_id(){return patient_id;}
    string setnotes(){return notes;}
    void printId(){cout<<id<<endl;}
    void print_pId(){cout<<patient_id<<endl;}
    void print_notes(){cout<<notes<<endl;}
record();
friend void delet_record(vector<record> &recordType);
friend void update_record(vector<record> &recordType);
friend void show_records(vector<record> &recordType);
friend void manage_records(int choice, vector<record> &recordType);
friend void add_record(vector<record> &recordType);
};
///function decloration
void delet_record(vector<record> &recordType);
void update_record(vector<record> &recordType);
void add_record(vector<record> &recordType);
void manage_records(int choice, vector<record> &recordType);
void show_records(vector<record> &recordType);

#endif // RECORD_H_INCLUDED
