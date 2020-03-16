#ifndef MATIERE_H_INCLUDED
#define MATIERE_H_INCLUDED

class Matiere{
    private:
    std::string codeMat;
    std::string nomMat;
    std::string codeClasseMat;
    int coef;
    public:
    //constructeur
    Matiere();
    Matiere(std ::string code,std::string nom,std::string codeClasse,int coef);


    //setter
    void setAllMatInfo(std ::string code,std::string nom,std::string codeClasse,int coef);
    void setCodeMat(std::string code);
    void setNomMat(std::string nom);
    void setCodeClasseMat(std::string codeClasse);
    void setCoef(int coef);
    //getter
    std::string getCodeMat();
    std::string getNomMat();
    std::string getCodeClasseMat();
    int getCoef();
    void displayMat();
    std::string dataMat();

};

#endif // MATIERE_H_INCLUDED
