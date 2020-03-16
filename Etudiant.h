
#ifndef ETUDIANT_H_INCLUDED
#define ETUDIANT_H_INCLUDED

class Etudiant{

    public:
        Etudiant();
        Etudiant(std::string matricule,std::string nom,std::string prenom,std::string dateDeNaissance,char genre,std::string codeClasse);

        //recupere le matricule de l'etudiant
         std::string getMatricule();
        //recupere  le nom de l'etudiant
        std::string getNom();
        //modifie le prenom de l'etudiant
        std::string getPrenom();
        //recupere la date de naissance
        std::string getDateDENaissance();
        //recupere le code la classe
        std::string getcodeClasseEtudiant();

        //recupere le genre de l'etudiant
        char getGenre();
        float getMoyenne();
        void  setInfoEtudiant(std::string matricule,std::string nom,std::string prenom,std::string dateDeNaissance,char genre,std::string codeClasse);
        void setMatricule(std::string matricule);
        //modifie  le nom de l'etudiant
        void setNom(std::string nom);
        //modifie le prenom de l'etudiant
        void setPrenom(std::string prenom);
        //modifie la date de naissance
        void setDateDeNaissance(std::string date);
        //modifie le code la classe
        void setCodeClasseEtudiant(std::string codeClasseEtudiant);

        //modifie le genre de l'etudiant
        void setGenre(char genre);
         void setMoyenne(float moyenne);
        //afficher les informationsur un etudiant
        void displayStudent();
        void displayStudentMoy();
        std::string dataEtudiant();
        private:
        std::string matricule;
        std::string nom;
        std::string prenom;
        std::string dateDeNaissance;
        std::string codeClasseEtudiant;
        char genre;
        float moyenne;
};


#endif // ETUDIANT_H_INCLUDED
