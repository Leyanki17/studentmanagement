#ifndef Departement_H_INCLUDED
#define Departement_H_INCLUDED
#include "fstream"
///liste doublement chaine
//Departement liste doublement chainée
    class Departement{

        private:
        Classroom* tete;
        Student*  teteEtudiant;
        Subject*  teteMatiere;
        Mark* teteNote;

        public:
            // constructeur par default;
            Departement();
            /***gestion de classe*****/
            // permet de d'inserer une classe dans la dans la liste des classe du departement
            void insertClassDepartement();
            void readClasseFile(std::string codeClasse,std::string nomClasse);
            void insertQueueDepartement();
            // void makeDepartement(int taille);
            //permet d'afficher les differente classe d'un departement
            void displayClassDepartement();
            //permet de faire un choi sur l'operation à executer sa executer le departement
            void operationDepartement();
            //searchLC permet de chercher une classe dans le departement et renvoie true si elle existe ou  faux sinon
            bool searchClassDepartement(std::string searchValue);
            Classroom* searchClass();
            void searchClassDepartement();
            void setClassInfo();
            void delClassrom();
            /*** gestion des etudiants******/
            void gestionEtudiant();
            void insertStudent();
            void readStudentFile(std::string matricule,std::string nom,std::string prenom,std::string dateDeNaissance,char genre,std::string codeClasse,float moy );
            bool searchStudent(std::string matricule);
            void searchStudent();
            Student* searchStudentDepart();
             Student* searchStudentDepart(std::string searchValue);
            int getOccurrence(std::string searchValue);
            void displayStudent();
            void displayStudent(std::string matricule);
            void StudentOfClass();
            void setStudentInfo();
            void delStudent();
            void MoyStudentOfClass();
            void noteAndMoyOfStudent();

            /***gestion des matiere******/
            void insertMatiere();

            void gestionMatiere();
            void displayMatiere();
            void subjectOfClass();
            void setMatInfo();
            void readMatFile(std::string codeMat,std::string nomMat,std::string codeClasse,int coef);
            void searchMat();
            void delMat();
            bool searchMatDepartement(std::string codeMatiere);
            Subject* searchMatDepart();
             Subject* searchMatDepart(std::string codeMatiere);
             void averageNote();

            /***gestion des notes********/
            void gestionNote();
           void insertNote();
           void displayNote();
           void noteOfSubject();
           bool searchNote(std::string matricule,std::string codeMat);
            Mark* searchNoteDepart(std::string matricule,std::string codeMat);
            void setNoteInfo(std::string matricule,std::string codeMat,float val);
            void noteOfStudent();
            void readNoteFile(std::string matricule,std::string codeMat,float val);
            /*****gestion des fichiers*********/

            void saveMat();
            void saveClasse();
            void saveEtudiant();
            void saveNote();

            void loadMat();
            void loadClasse();
            void loadEtudiant();
            void loadNote();
            void gestionClasse();
};




#endif // DEPARTEMENT_H_INCLUDED
