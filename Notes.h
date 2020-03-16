#ifndef NOTES_H_INCLUDED
#define NOTES_H_INCLUDED

class Note{
    private:
    std::string codeEtudiant;
    std::string codeMat;
    float noteVal;
    public:
    //constructeur
    Note();
    Note(std ::string codeEtudiant,std::string codeMat,float noteVal);


    //setter
    void setAllNoteInfo(std ::string codeEtudiant,std::string codeMat,float noteVal);
    void setCodeEtudiant(std::string codeEtudiant);
    void setCodeMat(std::string codeMat);
    void setNoteVal(float NoteVal);
    //getter
    std::string getCodeMat();
    std::string getCodeEtudiant();
    float getNoteVal();
    void displayNote();
     std::string dataNote();

};


#endif // NOTES_H_INCLUDED
