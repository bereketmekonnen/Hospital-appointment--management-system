#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <windows.h>
#include "diagnosis.h"
using namespace std;


void openDiagnosis(ifstream& inFileA)///open diagnosei file
{
    inFileA.open("Diagnosis.txt");
    if(!inFileA)
    {
        cout<<"\Errore opening File!!!"<<endl;
    }
}

void ReadDiagnosis(ifstream& inFileA, vector<diagnosis> &diagnosisType)///reads diagnosis file
{


    diagnosis diagnosissAccesor;

    diagnosissAccesor.getNumOfDiagnosis(inFileA);
    int loop = diagnosissAccesor.setNumberOfDiagnosis();
    for(int i=0; i<loop; i++)
    {
        diagnosisType.push_back(diagnosis());///info is loded in vector
        diagnosisType[i].getDiagnosis(inFileA);
    }


}

void printDiagnosis(ifstream& inFileA, vector<diagnosis> &diagnosisType)///Function prints diagnoses
{
    // openDiagnosis(inFileA);
    // ReadDiagnosis(inFileA, diagnosisType);
    int j=0;
    for(int i=0; i<diagnosisType.size(); i++)

    {
        j++;
        cout<<"Diagnosis Id: "<<j<<" ";

        diagnosisType[i].printDiagnosis();
        cout<<endl;
    }

}




