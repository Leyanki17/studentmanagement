#include "preprocesseur.h"
using namespace std;
Note::Note(){
    this->codeEtudiant="";
    this->codeMat="";
    this->noteVal=0;
}
Note::Note(string codeEtudiant,string codeMat,float noteVal){
     this->codeEtudiant=codeEtudiant;
    this->codeMat=codeMat;
    this->noteVal=noteVal;
}

//    string Note::dataNote(){
//        string donne="";
//        donne+=this->codeEtudiant+"#"+this->codeMat+"#"+this->noteVal;
//        return donne;
//    }
    //setter
    void Note::setAllNoteInfo(string codeEtudiant,string codeMat,float noteVal){
     this->codeEtudiant=codeEtudiant;
    this->codeMat=codeMat;
    this->noteVal=noteVal;
}

    void Note ::setCodeEtudiant(string codeEtudiant){
         this->codeEtudiant=codeEtudiant;
    }
    void Note ::setCodeMat(string codeMat){
        this->codeMat=codeMat;
    }
    void Note ::setNoteVal(float NoteVal){
        this->noteVal=noteVal;
    }
    //getter
    string Note:: getCodeEtudiant(){
        return this->codeEtudiant;
    }
    string Note::getCodeMat(){
        return this->codeMat;
    }
    float Note::getNoteVal(){
        return this->noteVal;
    }
    void Note::displayNote(){
        cout<<this->codeEtudiant<<" |"<<" |"<<this->codeMat<<" |"<<this->noteVal<<endl;
    }
    string Note::dataNote(){
        string donne="";
        donne+=this->codeEtudiant+"#"+this->codeMat+"#"+float2string(this->noteVal);
        return donne;
    }
