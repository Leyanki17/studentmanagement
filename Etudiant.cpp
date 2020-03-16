#include "preprocesseur.h"
#include "Etudiant.h"
using namespace std;
Etudiant:: Etudiant(string matricule,string nom,string prenom,string dateDeNaissance,char genre,string codeClasse){
    this->matricule=toupper(matricule);
    this->nom=toupper(nom);
    this->prenom=toupper(prenom);
    this->dateDeNaissance=toupper(dateDeNaissance);
    this->genre=genre;
    this->codeClasseEtudiant=toupper(codeClasse);
    this->moyenne=0;
}

Etudiant:: Etudiant(){
    this->matricule="";
    this->nom="";
    this->prenom="";
    this->dateDeNaissance="";
    this->genre=' ';
    this->codeClasseEtudiant="";
}


//recupere le matricule de l'etudiant
       string Etudiant:: getMatricule(){
            return this->matricule;
       }
        //recupere  le nom de l'etudiant
        string Etudiant:: getNom(){
            return this->nom;
        }
        //modifie le prenom de l'etudiant
        string Etudiant:: getPrenom(){
            return this->prenom;
        }
        //recupere la date de naissance
        string Etudiant:: getDateDENaissance(){
            return this->dateDeNaissance;
        }
        //recupere le code la classe
        string Etudiant:: getcodeClasseEtudiant(){
            return this->codeClasseEtudiant;
        }

        //recupere le genre de l'etudiant
        char Etudiant::getGenre(){
            return this->genre;
        }
        float Etudiant::getMoyenne(){
            return this->moyenne;
        }

        void Etudiant::setMatricule(string matricule){
            this->matricule=matricule;
        }
        //modifie  le nom de l'etudiant
        void Etudiant::setNom(std::string nom){
            this->nom=nom;
        }
        //modifie le prenom de l'etudiant
        void Etudiant::setPrenom(std::string prenom){
            this->prenom=prenom;
        }
        //modifie la date de naissance
        void Etudiant::setDateDeNaissance(std::string date){
            this->dateDeNaissance=date;
        }
        //modifie le code la classe
        void Etudiant::setCodeClasseEtudiant(std::string codeClasseEtudiant){
            this->codeClasseEtudiant=codeClasseEtudiant;
        }

        //modifie le genre de l'etudiant
        void Etudiant::setGenre(char genre){
            this->genre=genre;
        }
         void Etudiant::setMoyenne(float moyenne){
            this->moyenne=moyenne;
        }
        //afficher les informationsur un etudiant
        void Etudiant::displayStudent(){
            cout<<endl<<this->matricule<<" |"<<this->nom<<" |"<<this->prenom<<" |"
            <<this->genre<<" |"<<this->dateDeNaissance<<" |"<<this->codeClasseEtudiant;
        }
         void Etudiant::displayStudentMoy(){
            cout<<endl<<this->matricule<<" |"<<this->nom<<" |"<<this->prenom
            <<" |"<<this->genre<<" |"<<this->dateDeNaissance<<" |"<<this->codeClasseEtudiant<<" | "<<this->moyenne<<endl;
        }
        string Etudiant::dataEtudiant(){
            string donne="";
            donne+=this->matricule+"#"+this->nom+"#"+this->prenom+"#"+this->dateDeNaissance+"#"+this->genre+"#"+this->codeClasseEtudiant+"#"+float2string(this->moyenne);
            return donne;
        }
void Etudiant:: setInfoEtudiant(string matricule,string nom,string prenom,string dateDeNaissance,char genre,string codeClasse){
    this->genre=genre;
    this->codeClasseEtudiant=codeClasse;
    this->dateDeNaissance=dateDeNaissance;
    this->prenom=prenom;
    this->matricule=matricule;
    this->nom=nom;
    this->moyenne=0;
}

