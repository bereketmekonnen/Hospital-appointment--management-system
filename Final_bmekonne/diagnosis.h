#ifndef DIAGNOSIS_H_INCLUDED
#define DIAGNOSIS_H_INCLUDED

using namespace std;
class diagnosis{///class

private:

    int numberOfDiagnosis;
    string diagnosis;


public:

void getNumOfDiagnosis(ifstream& inFileA){inFileA>>numberOfDiagnosis;}
void getDiagnosis(ifstream& inFileA){inFileA>>diagnosis;}
int setNumberOfDiagnosis(){return numberOfDiagnosis;}
string setdiagnosis(){return diagnosis;}
void printNumOfD(){cout<<numberOfDiagnosis<<endl;}
void printDiagnosis(){cout<<diagnosis<<endl;}





};
///function decloration
void printDiagnosis(ifstream& inFileA, vector<diagnosis> &diagnosisType);
void ReadDiagnosis(ifstream& inFileA, vector<diagnosis> &diagnosisType);
void openDiagnosis(ifstream& inFileA);
#endif // DIAGNOSIS_H_INCLUDED
