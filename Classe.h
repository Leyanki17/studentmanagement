#ifndef CLASSE_H_INCLUDED
#define CLASSE_H_INCLUDED
#include "Etudiant.h"
    class Classe{
        private:
        //code de la salle de classe
        std::string codeClassroom;
        //nom de la salle de classe
        std:: string nameClassroom;
        public:
        //constructeuur de la salle de classe
        Classe(std::string code,std::string name);
         Classe();
        //recupere le nom de la salle de classe;
        std::string getNameClassroom();
        //recupere  le code de la salle de classe
        std::string getCodeClassroom();
        //modifie le nom de la salle de classe
        void setNameClassroom(std::string name);
        //modifie le code de la classe
        void setCodeClassroom(std::string code);
        std::string dataClasse();
        void display(int effec);
        void display();

    };
#endif // CLASSE_H_INCLUDED
