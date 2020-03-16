#include "preprocesseur.h"
using namespace std;
Matiere::Matiere(){
    this->codeMat="";
    this->nomMat="";
    this->codeClasseMat="";
    this->coef=0;
}
Matiere::Matiere(string code,string nom,string codeClasse,int coef){
     this->codeMat=code;
    this->nomMat=nom;
    this->codeClasseMat=codeClasse;
    this->coef=coef;
}


    //setter
    void Matiere::setAllMatInfo(string code,string nom,string codeClasse,int coef){
        this->codeMat=code;
        this->nomMat=nom;
        this->codeClasseMat=codeClasse;
        this->coef=coef;
    }
    void Matiere ::setCodeMat(string code){
         this->codeMat=code;
    }
    void Matiere ::setNomMat(string nom){
        this->nomMat=nom;
    }
    void Matiere ::setCodeClasseMat(string codeClasse){
        this->codeClasseMat=codeClasse;
    }
    void Matiere ::setCoef(int coef){
        this->coef=coef;
    }
    //getter
    string Matiere:: getCodeMat(){
        return this->codeMat;
    }
    string Matiere::getNomMat(){
        return this->nomMat;
    }
    string Matiere::getCodeClasseMat(){
        return this->codeClasseMat;
    }
    int Matiere::getCoef(){
        return this->coef;
    }
    void Matiere::displayMat(){
    cout<<this->codeMat<<" |"<<this->nomMat<<" |"<<this->coef<<" |"<<this->codeClasseMat<<endl;
    }

     string Matiere::dataMat(){
        string donne="";
        donne+=this->codeMat+"#"+this->nomMat+"#"+float2string(this->coef)+"#"+this->codeClasseMat;
        return donne;
    }
