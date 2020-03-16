#include "preprocesseur.h"
 using namespace std;

    Classe::Classe(){
        this->nameClassroom="";
        this->codeClassroom="";
    }
    Classe::Classe (string code,string name){
        this->nameClassroom=name;
        this->codeClassroom=code;
    }
    //recupere le nom de la salle de classe;
    string Classe::getNameClassroom(){
        return this->nameClassroom;
    }
    //recupere  le code de la salle de classe
    string Classe::getCodeClassroom(){
        return this->codeClassroom;
    }
    //modifie le nom de la salle de classe
    void Classe::setNameClassroom(string name){
        this->nameClassroom=name;
    }
    //modifie le code de la classe
    void Classe::setCodeClassroom(string code){
        this->codeClassroom=code;
    }

    void Classe::display(int effec){
        cout<<this->codeClassroom<<" | "<<this->nameClassroom<<" | "<<effec<<endl;
    }
     void Classe::display(){
        cout<<this->codeClassroom<<" | "<<this->nameClassroom<<endl;
    }
    string Classe::dataClasse(){
        string donnee="";
        donnee+=this->codeClassroom+"#"+this->nameClassroom;
        return donnee;
    }


