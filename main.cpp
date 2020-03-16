#include "preprocesseur.h"
using namespace std;

int main()
{
   Departement dpt;

   char dec='N';

     dpt.loadClasse();
     dpt.loadEtudiant();
     dpt.loadMat();
     dpt.loadNote();
    do{

        dpt.operationDepartement();
        cout<<"voulez vous revenir au menu departement oui(0) ou non(N)??"<<endl;
        cin>>dec;
        cin.clear();
        dec=toupper(dec);
    }while(dec!='N');
     dpt.saveClasse();
//     dpt.saveEtudiant();
//     dpt.saveMat();
//     dpt.saveNote();
    return 0;
}
