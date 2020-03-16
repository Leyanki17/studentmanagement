#include "preprocesseur.h"
using namespace std;
Departement::Departement(){
     tete=0;
     teteEtudiant=0;
     teteMatiere=0;
     teteNote=0;
}
/**
* insertClassDepartement() insere un nouvelle classe dans le departement si elle n'existe pas encore
* inserClassDepartement ne prend rien en parametre
* insertClassDepartement ne renvoie rien
*/
void Departement::insertClassDepartement(){
    Classroom* p=new Classroom; // on cree une nouvelle classe
        string name,code;
         bool use;
        //on entre le code tant que celui est deja utilisé
        do{
            use=false;
            cout <<"entrer le code de la classe"<<endl;
            cin>>ws; //pour changer la valeur de l'espace blanc
            getline(cin, code);
            code=toupper(code);//on met le code en majuscule;
            cout<<"vous avez entrer "<<code<<endl;
            if(searchClassDepartement(code)){
                cout<<"le code est deja utiliser pour une autre classe"<<endl;
                use=true;
            }
        }while(use==true);
        cout<<"entrer lenom de la classe"<<endl;
        cin>>ws;//pour changer la valeur de l'espace blanc
        getline(cin , name);
        name=toupper(name);//on met le nom en majusculec
        p->val.setNameClassroom(name);
        p->val.setCodeClassroom(code);
    if(tete==0){
        p->precedent=0;
        p->suivant=0;
        tete=p;
    }else{
        p->precedent=0; // vue que l'elt est inserer en tête son precedent pointer vers rien
        tete->precedent=p;// le precedent de l'actuelle tete est la noubvelle tete que l'on souhaite inserer
        p->suivant=tete;//le suivant de la nouvelle tete pointe vers l'ancienne tete
        tete=p;//la tete pointe mtn sur mon element inserer;
    }
}
void Departement::readClasseFile(string codeClasse,string nomClasse){
 Classroom* p=new Classroom(); // on cree une nouvelle classe
        codeClasse=toupper(codeClasse);
        nomClasse=toupper(nomClasse);
        p->val.setNameClassroom(nomClasse);
        p->val.setCodeClassroom(codeClasse);
    if(tete==0){
        p->precedent=0;
        p->suivant=0;
        tete=p;
    }else{
        p->precedent=0; // vue que l'elt est inserer en tête son precedent pointer vers rien
        tete->precedent=p;// le precedent de l'actuelle tete est la noubvelle tete que l'on souhaite inserer
        p->suivant=tete;//le suivant de la nouvelle tete pointe vers l'ancienne tete
        tete=p;//la tete pointe mtn sur mon element inserer;
    }
}
void Departement::searchClassDepartement(){
    bool found=false;
    Classroom *current=tete;
    cout<<"entrer le code de la classe a chercher dans la liste"<<endl;
    string searchValue="";
    cin>>ws;
    getline(cin,searchValue);
    searchValue=toupper(searchValue);
   if( tete!=0){
        while(found!=true && current!=0){
            cout<<searchValue;
            if(current->val.getCodeClassroom()==searchValue){
                found=true;
            }else{
                current=current->suivant;
            }
        }
        if(found){
            cout<<"la classe est dans le depatement"<<endl;
            current->val.display(getOccurrence(current->val.getCodeClassroom()));
        }else{
            cout<<"la classe n'est pas dans le departement"<<endl;
        }
    }else{
        cout<<"il n'y a aucune classe dans le departement"<<endl;
    }
}
bool Departement::searchClassDepartement(string searchValue){
    int i=0;
    bool found=false;
    Classroom *current=tete;
    searchValue=toupper(searchValue);
    if(tete!=0){
        while(current!=0 && found!=true){
//          cout<<current->val.getCodeClassroom();
            cout<<(searchValue==current->val.getCodeClassroom())<<endl;;
            if(current->val.getCodeClassroom()==searchValue){
                found=true;
            }else{
                current=current->suivant;
            }
            i++;

        }
        return found;
    }else{
        cout<<"la liste est vide"<<endl;
        return false;
    }
}
Classroom* Departement::searchClass(){
    bool found=false;
    Classroom *current;
    current=tete;
    cout<<"entrer le code de la classe a chercher dans la liste"<<endl;
    string searchValue="";
    cin>>ws;
    getline(cin,searchValue);
    searchValue=toupper(searchValue);
   if( tete!=0){
        current=tete;
        while(found!=true && current!=0){
            if(current->val.getCodeClassroom()==searchValue){
                found=true;
            }else{
                current=current->suivant;
            }
        }
    }
    return current;
}
void Departement:: setClassInfo(){
    bool use;
    string name,nc;
    Classroom* current=new Classroom();
    current=searchClass();
    if(current!=0){
        cout <<"operation sur le departement"<<endl;
        cout<<"1-modifier le nom de la classe \n2-modifier son nom\n"<<endl;
        int choix=0;
        cout<<"choisir une des operation ci-dessus"<<endl;
        cin >> choix;
        switch (choix){
            case 1:
                cout<<"entrer le nouveau nom de la classe"<<endl;
                cin>>ws;
                getline(cin,name);
                name=toupper(name);
                current->val.setNameClassroom(name);
            break;
            case 2:
                do{
                    use=false;
                    cout <<"entrer le code de la classe"<<endl;
                    cin>>ws; //pour changer la valeur de l'espace blanc
                    getline(cin, nc);
                    nc=toupper(nc);//on met le code en majuscule;
                    if(searchClassDepartement(nc)){
                        cout<<"le code est deja utiliser pour une autre classe"<<endl;
                        use=true;
                    }
                }while(use==true);
                current->val.setCodeClassroom(nc);
            break;
            default:
                cout<<"choix indisponible"<<endl;
            break;
        }
    }else{
        cout<<"cette classe n'existe pas"<<endl;
    }

}
void Departement::delClassrom(){
    Classroom* current;
    current=searchClass();
    cout<<current<<endl;
    if(current!=0){
        if(current->precedent!=0 ){

            current->precedent->suivant=current->suivant;
            if(current->suivant!=0){
                current->suivant->precedent=current->precedent;
                delete current;
            }else{
               delete current;
            }

        }else{
            if(current->suivant!=0){
                tete=current->suivant;
                delete current;
            }else{
                delete current;
                 tete=0;
            }

        }
    }else{
        cout<<"cette classe n'existe pas dans le departement "<<endl;
    }
}
int  Departement::getOccurrence(std::string searchValue){
    int i=0;
    Student* current=teteEtudiant;
    searchValue=toupper(searchValue);
    if( current!=0){
        while(current!=0){
            if(current->val.getcodeClasseEtudiant()==searchValue){
                i++;
            }
            current=current->suivant;
        }
        return i;
    }else{
        return 0;
    }
}
void Departement::displayClassDepartement(){
     Classroom* current=tete;
    if(tete==0){
        cout<<"votre liste est vide en cet instant"<<endl;
    }else{
        do{
//          current->val.display(getOccurrence(current->val.getCodeClassroom()));
            current->val.display();
//          cout<<getOccurrence(current->val.getCodeClassroom());
            current=current->suivant;//l'element courent  devient son suivant
        }while(current!=0);//si le courrent pointe vers 0 alors on sort de la boucle
    }
}
void Departement:: operationDepartement(){
//    cout<<"veuiller entrer la taille du liste"<<endl;
//    cin>>Taille;
//    makeDepartement(Taille);//on creer une liste avec une taille min

    char dec='N';
    cout <<"operation sur le departement"<<endl;
    cout<<"1-gestion des classe \n2-gestion des etudiants\n3-gestion des Matieres\n4-gestion des notes"<<endl;
    int choix=0;
    cout<<"choisir une des operation ci-dessus"<<endl;
    cin >> choix;
    cin.clear();
    switch(choix){
        case 1:
                cout<<"bienvenu sur la gestion des classe du departement"<<endl;
                 do{
                    gestionClasse();
                   cout<<"souhaiter vous toujour gerer le classe??"<<endl;
                   cin>>dec;
                   dec=toupper(dec);
                }while(dec!='N');

        break;
        case 2:
           cout<<"bienvenu sur la gestion des Etudiants du departement"<<endl;
                 do{
                    gestionEtudiant();
                   cout<<"souhaiter vous toujour gerer les Etudiants??"<<endl;
                   cin>>dec;
                   dec=toupper(dec);
                }while(dec!='N');

        break;
        case 3:
             do{
                    gestionMatiere();
                   cout<<"souhaiter vous toujour gerer les matieres??"<<endl;
                   cin>>dec;
                   dec=toupper(dec);
             }while(dec!='N');
        break;
        case 4:
            do{
                cout<<"bienvenu  sur la gestion des notes"<<endl;
                gestionNote();
                cout<<"voulez vous  toujour gerer les notes des  oui(0) ou non(N)"<<endl;
                cin>>dec;
                dec=toupper(dec);
            }while(dec!='N');
        default:
            cout <<"choix indisponible"<<endl;
        break;
    }
}
/** gestion de l'etudiant**/

void Departement::insertStudent(){
    Student* p=new Student;
    bool use;
    string matricule,nom,prenom,dn,codeClasse;
    char genre;
    cout<<"entrer le nom de l'etudiant"<<endl;
    cin>>ws;
    getline(cin,nom);
    nom=toupper(nom);
    cout<<"entrer le prenom de l'etudiant"<<endl;
    cin>>ws;
    getline(cin,prenom);
    prenom=toupper(prenom);
     cout<<"entrer la date de naissance de l'etudiant"<<endl;
    cin>>ws;
    getline(cin,dn);
    dn=toupper(dn);
    cout<<"entrer le genrede l'etudiant"<<endl;
    cin>>genre;
    genre=toupper(genre);
    do{
        use=false;
        cout<<"entrer le matricule de l'etudiant"<<endl;
        cin>>ws;
        getline(cin,matricule);
        if(searchStudent(matricule)){
            cout<<"ce matricule est deja utiliser"<<endl;
            use=true;
        }
    }while(use==true);
    do{
        use=true;
        cout<<"entrer la classe de l'etudiant"<<endl;
        cin>>ws;
        getline(cin,codeClasse);
        codeClasse=toupper(codeClasse);
        if(!searchClassDepartement(codeClasse)){
            cout<<"cette classe n'existe pas voici la liste des classe existante"<<endl;
            displayClassDepartement();
            use=false;
        }
    }while(use==false);
    matricule=toupper(matricule);
    codeClasse=toupper(codeClasse);
    p->val.setInfoEtudiant(matricule,nom,prenom,dn,genre,codeClasse);
    if(teteEtudiant==0){
        p->precedent=0;
        p->suivant=0;
        teteEtudiant=p;
    }else{
        p->precedent=teteEtudiant; // vue que l'elt est inserer en tête son precedent pointer vers rien
        teteEtudiant->precedent=p;// le precedent de l'actuelle tete est la noubvelle tete que l'on souhaite inserer
        p->suivant=teteEtudiant;//le suivant de la nouvelle tete pointe vers l'ancienne tete
        teteEtudiant=p;//la tete pointe mtn sur mon element inserer;
    }
}
 void Departement::readStudentFile(string matricule,string nom,string prenom,string dateDeNaissance,char genre,string codeClasse,float moy ){
    Student* p=new Student; // on cree une nouvelle classe

        p->val.setInfoEtudiant(matricule,nom,prenom,dateDeNaissance,genre,codeClasse);
        p->val.setMoyenne(moy);
    if(teteEtudiant==0){
        p->precedent=0;
        p->suivant=0;
        teteEtudiant=p;
    }else{
        p->precedent=0; // vue que l'elt est inserer en tête son precedent pointer vers rien
        teteEtudiant->precedent=p;// le precedent de l'actuelle tete est la noubvelle tete que l'on souhaite inserer
        p->suivant=teteEtudiant;//le suivant de la nouvelle tete pointe vers l'ancienne tete
        teteEtudiant=p;//la tete pointe mtn sur mon element inserer;
    }
}
bool Departement::searchStudent(string matricule){
    bool trouver=false;
    Student* current=0;
    current=teteEtudiant;
    matricule=toupper(matricule);
    while(current!=0 && trouver!=true){
        if(matricule==current->val.getMatricule()){
            trouver=true;
        }else{
            current=current->suivant;
        }
    }
    return trouver;
}
void Departement::StudentOfClass(){
    bool use;
    Student* current=0;
    current=teteEtudiant;
    string code;
     do{
            use=false;
            cout <<"entrer le code de la classe dont on veu obtenir la liste des  etudiants"<<endl;
            cin>>ws; //pour changer la valeur de l'espace blanc
            getline(cin, code);
            code=toupper(code);//on met le code en majuscule
            if(!searchClassDepartement(code)){
                cout<<"la classe n'existe pas dans le departement"<<endl;
                displayClassDepartement();
                use=true;
            }
        }while(use==true);
    while(current!=0){
        if(code==current->val.getcodeClasseEtudiant()){
            current->val.displayStudent();
        }
        current=current->suivant;
    }
}
void Departement::displayStudent(){
    Student* current=teteEtudiant;
    if(current!=0){
        while(current!=0){
            current->val.displayStudent();
            current=current->suivant;
        }
    }else{
        cout<<"aucun n'etudiant ne s'est deja inscrit"<<endl;
    }
 }
void Departement::setStudentInfo(){
    bool use;
    string newVal;
    Student* current=new Student();
    current=searchStudentDepart();
    if(current!=0){
        cout <<"operation sur le departement"<<endl;
        cout<<"1-modifier le matricule de l'etudiant\n2-modifier le nom de l'etudiant \n3-modifierle prenom de l'etudiant"
        "\n4-date de naissance de naissance de l'etudiant\n5-modifier le sexe de l'etudiant"
        <<"\6-modifier la classe de l'etudiant"<<endl;
        int choix=0;
        cout<<"choisir une des operation ci-dessus"<<endl;
        cin >> choix;
        switch (choix){
            case 1:
               do{
                    use=false;
                    cout<<"entrer le nouveau matricule de la classe"<<endl;
                    cin>>ws; //pour changer la valeur de l'espace blanc
                    getline(cin, newVal);
                    newVal=toupper(newVal);//on met le code en majuscule;
                    if(searchStudent(newVal)){
                        cout<<"ce matricule est deja utiliser pour une autre classe"<<endl;
                        use=true;
                    }
                }while(use==true);
                current->val.setMatricule(newVal);
            break;
            case 2:
                cout<<"entrer le nouveau nom de la classe"<<endl;
                cin>>ws;
                getline(cin,newVal);
                newVal=toupper(newVal);
                current->val.setNom(newVal);
            break;
            case 3:
                cout<<"entrer le nouveau nom de la classe"<<endl;
                cin>>ws;
                getline(cin,newVal);
                newVal=toupper(newVal);
                current->val.setPrenom(newVal);
            break;
            case 4:
                cout<<"entrer le nouveau nom de la classe"<<endl;
                cin>>ws;
                getline(cin,newVal);
                newVal=toupper(newVal);
                current->val.setDateDeNaissance(newVal);
            break;
            case 5:
                cout<<"entrer le nouveau nom de la classe"<<endl;
                cin>>ws;
                getline(cin,newVal);
                newVal=toupper(newVal);
                current->val.setGenre(newVal[0]);
            break;
            case 6:
                do{
                    use=false;
                    cout <<"entrer le code de la classe"<<endl;
                    cin>>ws; //pour changer la valeur de l'espace blanc
                    getline(cin, newVal);
                    newVal=toupper(newVal);//on met le code en majuscule;
                    if(searchClassDepartement(newVal)){
                        cout<<"le code est deja utiliser pour une autre classe"<<endl;
                        use=true;
                    }
                }while(use==true);
                current->val.setCodeClasseEtudiant(newVal);
            break;
            default:
                cout<<"choix indisponible"<<endl;
            break;
        }
    }else{
        cout<<"cette classe n'existe pas"<<endl;
    }

}

void Departement::displayStudent(std::string matricule){
     bool trouver=false;
    Student* current=0;
    current=teteEtudiant;
    matricule=toupper(matricule);
    while(current!=0 && trouver!=true){
        if(matricule==current->val.getMatricule()){
            trouver=true;
            current->val.displayStudent();
        }else{
            current=current->suivant;
        }
    }
}
Student* Departement::searchStudentDepart(std::string searchValue){
      bool trouver=false;
    Student* current=0;
    current=teteEtudiant;
    searchValue=toupper(searchValue);
    while(current!=0 && trouver!=true){
        if(searchValue==current->val.getMatricule()){
            trouver=true;
        }else{
            current=current->suivant;
        }
    }
    return current;
}
Student* Departement::searchStudentDepart(){
    bool trouver=false;
    Student* current=0;
    current=teteEtudiant;
    string mat;
    cout<<"entrer le matricule de l'eleve dont on veu modifier les info"<<endl;
    cin>>ws;
    getline(cin,mat);
    mat=toupper(mat);
    while(current!=0 && trouver!=true){
        if(mat==current->val.getMatricule()){
            trouver=true;
        }else{
            current=current->suivant;
        }
    }
    return current;
}
void Departement::delStudent(){
    string mat;
    Student* current=new Student;
    current=searchStudentDepart();
    if(current!=0){
        if(current->precedent!=0){
             current->precedent->suivant=current->suivant;
            if(current->suivant!=0){
                current->suivant->precedent=current->precedent;
                delete current;
            }else{
               delete current;
            }

        }else{
            if(current->suivant!=0){
                teteEtudiant=current->suivant;
                delete current;
            }else{
                delete current;
                 teteEtudiant=0;
            }
        }
    }else{
        cout<<"Cet etudiant n'existe pas dans le departement"<<endl;
    }

}
void Departement::searchStudent(){
     bool found=false;
    Student* current=teteEtudiant;
    cout<<"entrer le matricule de l'eleve a chercher chercher dans la liste"<<endl;
    string searchValue="";
    cin>>ws;
    getline(cin,searchValue);
    searchValue=toupper(searchValue);
   if( teteEtudiant!=0){
        while(found!=true && current!=0){
            if(current->val.getMatricule()==searchValue){
                found=true;
            }else{
                current=current->suivant;
            }
        }
        if(found){
            cout<<"l'etudiant est dans le departement est dans le depatement"<<endl;
            current->val.displayStudent();
        }else{
            cout<<"l'etudiant n'est pas dans le departement"<<endl;
        }
    }else{
        cout<<"il n'y a aucun etudiant dens le departement dans le departement"<<endl;
    }
}
void Departement::MoyStudentOfClass(){
    bool use;
    Student* current=0;
    current=teteEtudiant;
    string code;
     do{
            use=false;
            cout <<"entrer le code de la classe dont on veu obtenir la liste des  etudiants et leur moyenne"<<endl;
            cin>>ws; //pour changer la valeur de l'espace blanc
            getline(cin, code);
            code=toupper(code);//on met le code en majuscule
            if(!searchClassDepartement(code)){
                cout<<"la classe n'existe pas dans le departement"<<endl;
                displayClassDepartement();
                use=true;
            }
        }while(use==true);
    while(current!=0){
        if(code==current->val.getcodeClasseEtudiant()){
            current->val.displayStudentMoy();
        }
        current=current->suivant;
    }
}

void Departement:: noteAndMoyOfStudent(){
    bool use;
    Mark* current=0;
    current=teteNote;
    Student* eleve=0;
    string code;
     do{
            use=false;
            cout <<"entrer le matricule de l'etudiant dont on veut obtenir la liste des notes"<<endl;
            cin>>ws; //pour changer la valeur de l'espace blanc
            getline(cin, code);
            code=toupper(code);//on met le code en majuscule
            if(!searchStudent(code)){
                cout<<"la cet etudiant n'existe pas "<<endl;
                displayMatiere();
                use=true;
            }
        }while(use==true);
    while(current!=0){
        if(code==current->val.getCodeEtudiant()){
            current->val.displayNote();
        }
        current=current->suivant;
    }
    eleve=searchStudentDepart(code);
    if(eleve != 0){
        eleve->val.displayStudentMoy();
    }

}

/****************gestion des matieres***************/

void Departement::insertMatiere(){
    Subject* p=new Subject;
    bool use;
    string codeMatiere,codeClasse,codeEtudiant,nom;
    int coef;
    cout<<"entrer le  nom de la matiere"<<endl;
    cin>>ws;
    getline(cin,nom);
    nom=toupper(nom);
    cout<<"entrer le coefficient de la matiere"<<endl;
    cin>>coef;
    do{
        use=false;
        cout<<"entrer le code  de la matiere"<<endl;
        cin>>ws;
        getline(cin,codeMatiere);
        if(searchMatDepartement(codeMatiere)){
            cout<<"cette matiere n'existe"<<endl;
            use=true;
        }
    }while(use==true);
    do{
        use=true;
        cout<<"entrer la classe ou est enseigne la matiere"<<endl;
        cin>>ws;
        getline(cin,codeClasse);
        codeClasse=toupper(codeClasse);
        if(!searchClassDepartement(codeClasse)){
            cout<<"cette classe n'existe pas voici la liste des classe existante"<<endl;
            displayClassDepartement();
            use=false;
        }
    }while(use==false);
    codeMatiere=toupper(codeMatiere);
    codeClasse=toupper(codeClasse);
    p->val.setAllMatInfo(codeMatiere,nom,codeClasse,coef);
    if(teteMatiere==0){
        p->precedent=0;
        p->suivant=0;
        teteMatiere=p;
    }else{
        p->precedent=teteMatiere; // vue que l'elt est inserer en tête son precedent pointer vers rien
        teteMatiere->precedent=p;// le precedent de l'actuelle tete est la noubvelle tete que l'on souhaite inserer
        p->suivant=teteMatiere;//le suivant de la nouvelle tete pointe vers l'ancienne tete
        teteMatiere=p;//la tete pointe mtn sur mon element inserer;
    }
}
 void Departement::readMatFile(std::string codeMat,std::string nomMat,std::string codeClasse,int coef){
    Subject* p=new Subject;
    nomMat=toupper(nomMat);
    codeMat=toupper(codeMat);
    codeClasse=toupper(codeClasse);
    if(teteMatiere==0){
        p->precedent=0;
        p->suivant=0;
        teteMatiere=p;
    }else{
        p->precedent=teteMatiere; // vue que l'elt est inserer en tête son precedent pointer vers rien
        teteMatiere->precedent=p;// le precedent de l'actuelle tete est la noubvelle tete que l'on souhaite inserer
        p->suivant=teteMatiere;//le suivant de la nouvelle tete pointe vers l'ancienne tete
        teteMatiere=p;//la tete pointe mtn sur mon element inserer;
    }
 }

void Departement:: displayMatiere(){
    Subject* current=teteMatiere;
    if(current!=0){
        while(current!=0){
            current->val.displayMat();
            current=current->suivant;
        }
    }else{
        cout<<"aucun le pmatiere "<<endl;
    }
}
void Departement:: subjectOfClass(){
    bool use;
    Subject* current=0;
    current=teteMatiere;
    string code;
     do{
            use=false;
            cout <<"entrer le code de la classe dont on veu obtenir la liste des matieres"<<endl;
            cin>>ws; //pour changer la valeur de l'espace blanc
            getline(cin, code);
            code=toupper(code);//on met le code en majuscule
            if(!searchClassDepartement(code)){
                cout<<"la classe n'existe pas dans le departement"<<endl;
                displayClassDepartement();
                use=true;
            }
        }while(use==true);
    while(current!=0){
        if(code==current->val.getCodeClasseMat()){
            current->val.displayMat();
        }
        current=current->suivant;
    }
}
void Departement::setMatInfo(){
       bool use;
    string newVal;
    int tmp;
    Subject* current=new Subject();
    current=searchMatDepart();
    if(current!=0){
        cout <<"modification des information sur les matiére"<<endl;
        cout<<"1-modifier le code de la Matiere\n2-modifier le nom de l'etudiant "<<"3-modifier la classe de l'etudiant"
        <<"4-modifier le nouveau code de classe"<<endl;
        int choix=0;
        cout<<"choisir une des operation ci-dessus"<<endl;
        cin >> choix;
        switch (choix){
            case 1:
               do{
                    use=false;
                    cout<<"entrer le nouveau code de la matiere"<<endl;
                    cin>>ws; //pour changer la valeur de l'espace blanc
                    getline(cin, newVal);
                    newVal=toupper(newVal);//on met le code en majuscule;
                    if(searchMatDepartement(newVal)){
                        cout<<"ce matricule est deja utiliser pour une autre classe"<<endl;
                        use=true;
                    }
                }while(use==true);
                current->val.setCodeMat(newVal);
            break;
            case 2:
                cout<<"entrer le nouveau nom de la classe"<<endl;
                cin>>ws;
                getline(cin,newVal);
                newVal=toupper(newVal);
                current->val.setNomMat(newVal);
            break;
            case 3:
                do{
                    use=false;
                    cout <<"entrer le code de la classe"<<endl;
                    cin>>ws; //pour changer la valeur de l'espace blanc
                    getline(cin, newVal);
                    newVal=toupper(newVal);//on met le code en majuscule;
                    if(searchClassDepartement(newVal)){
                        cout<<"le code est deja utiliser pour une autre classe"<<endl;
                        use=true;
                    }
                }while(use==true);
                current->val.setCodeClasseMat(newVal);
            break;
            case 4:
                cout<<"entrer le nouveau coef"<<endl;
                cin>>tmp;
                current->val.setCoef(tmp);
            default:
                cout<<"choix indisponible"<<endl;
            break;
        }
    }else{
        cout<<"cette classe n'existe pas"<<endl;
    }

}
bool Departement::searchMatDepartement(string codeMatiere){
    bool trouver=false;
    Subject* current=0;
    current=teteMatiere;
    codeMatiere=toupper(codeMatiere);
    while(current!=0 && trouver!=true){
        if(codeMatiere==current->val.getCodeClasseMat()){
            trouver=true;
        }else{
            current=current->suivant;
        }
    }
    return trouver;
}
void Departement::searchMat(){
     bool found=false;
    Subject* current=teteMatiere;
    cout<<"entrer le code de la matiere a chercher chercher dans la liste"<<endl;
    string searchValue="";
    cin>>ws;
    getline(cin,searchValue);
    searchValue=toupper(searchValue);
   if( teteMatiere!=0){
        while(found!=true && current!=0){
            if(current->val.getCodeMat()==searchValue){
                found=true;
            }else{
                current=current->suivant;
            }
        }
        if(found){
            cout<<"la matiere exixte dans le departement est dans le depatement"<<endl;
            current->val.displayMat();
        }else{
            cout<<"la matiere n'est pas dans le departement"<<endl;
        }
    }else{
        cout<<"il n'y a aucune matiere dans le departement dans le departement"<<endl;
    }
}
Subject* Departement::searchMatDepart(){
    bool trouver=false;
    Subject* current=0;
    current=teteMatiere;
    string mat;
    cout<<"entrer le matricule de l'eleve dont on veu modifier les info"<<endl;
    cin>>ws;
    getline(cin,mat);
    mat=toupper(mat);
    while(current!=0 && trouver!=true){
        if(mat==current->val.getCodeMat()){
            trouver=true;
        }else{
            current=current->suivant;
        }
    }
    return current;
}
 Subject* Departement::searchMatDepart(std::string codeMatiere){
    bool trouver=false;
    Subject* current=0;
    current=teteMatiere;
    codeMatiere=toupper(codeMatiere);
    while(current!=0 && trouver!=true){
        if(codeMatiere==current->val.getCodeMat()){
            trouver=true;
            return current;
        }else{
            current=current->suivant;
        }
    }
    return 0;
 }
void Departement::delMat(){
    Subject* current;
    current=searchMatDepart();
    cout<<current<<endl;
    if(current!=0){
        if(current->precedent!=0 ){

            current->precedent->suivant=current->suivant;
            if(current->suivant!=0){
                current->suivant->precedent=current->precedent;
                delete current;
            }else{
               delete current;
            }

        }else{
            if(current->suivant!=0){
                teteMatiere=current->suivant;
                delete current;
            }else{
                delete current;
                 teteEtudiant=0;
            }

        }
    }else{
        cout<<"cette matiere n'existe pas dans le departement "<<endl;
    }
}
/*******menu*****/
void Departement::gestionClasse(){
    char dec='N';
    cout <<"menu departement"<<endl;
    cout<<"1-inserer une classe\n2-afficher une classe\n3-rechercher une classe dans le departement\n4-modifier une classe\n5-suppression d'une classe"<<endl;
    int choix=0;
    cout<<"choisir une des operation ci-dessus"<<endl;
    cin >> choix;
    cin.clear();
     switch(choix){
        case 1:
            cout<<"vous avez choisi l'insertion d'une classe"<<endl<<endl;
            do{
                cout<<"avant l'insertion de la classe"<<endl;
                displayClassDepartement();
                insertClassDepartement();
                cout<<"\napres l'insertion de la classe"<<endl;
                displayClassDepartement();
                cout<<"souhaiter vous effectuer la meme operation"<<endl;
                cin>>dec;
                dec=toupper(dec);
            }while(dec!='N');
        break;
        case 2:
            cout <<"liste des classe du departement"<<endl;
            displayClassDepartement();
        break;
        case 3:
            do{
               cout<<" recherche chercher une classe dans le departement"<<endl;
                searchClassDepartement();
               cout<<"souhaiter vous effectuer la meme operation"<<endl;
               cin>>dec;
               dec=toupper(dec);
            }while(dec!='N');
        break;
        case 4:
            do{
               cout<<" recherche chercher une classe dans le departement"<<endl;
                setClassInfo();
                cout<<"souhaiter vous effectuer la meme operation"<<endl;;
                cin>>dec;
                dec=toupper(dec);
            }while(dec!='N');
        break;
        case 5:
             do{
                cout<<" supprimer une classe du departement"<<endl;
                delClassrom();
                cout<<"souhaiter vous effectuer la meme operation"<<endl;;
                cin>>dec;
                dec=toupper(dec);
            }while(dec!='N');
        break;
        default:
        cout<<"choix indisponible"<<endl;
        break;

}
}

void Departement::gestionEtudiant(){
    char dec='N';
    cout <<"menu gestion des Etudiants"<<endl;
    cout<<"1-inserer un Etudiant\n2-afficher les tous Etudiants\n"<<
    "3-afficher la liste des Etudiant d'une classe \n4-liste des etudiant et leur moyenne pour une classe donne\
    n5-liste des notes et la moyenne obtenu par un etudiant\n6-rechercher un etudiant du departement \n"<<
    "7-modifier un Etudiant\n8-suppression d'un Etudiant"<<endl;
    int choix=0;
    cout<<"choisir une des operation ci-dessus"<<endl;
    cin >> choix;
    cin.clear();
     switch(choix){
        case 1:
            cout<<"vous avez choisi l'insertion d'un etudiant"<<endl<<endl;
            do{
                cout<<"avant l'insertion de la classe"<<endl;
                displayStudent();
                insertStudent();
                cout<<"\napres l'insertion de la classe"<<endl;
                displayStudent();
                cout<<"souhaiter vous effectuer inserer un autre etudiant??"<<endl;
                cin>>dec;
                dec=toupper(dec);
            }while(dec!='N');
        break;
        case 2:
            cout <<"liste de tous les Etudiants du departement"<<endl;
            displayStudent();
        break;
        case 3:
            do{
                 cout<<"liste de etudiant d'une classe precise"<<endl;
                displayClassDepartement();
                StudentOfClass();
                cout<<"souhaiter vous afficher les etudiant d'une autre classe ???"<<endl;
               cin>>dec;
               dec=toupper(dec);
            }while(dec!='N');
        break;
        case 4:
            do{
                 cout<<"liste de etudiant d'une classe precise"<<endl;
                displayClassDepartement();
                MoyStudentOfClass();
                cout<<"souhaiter vous afficher les etudiant d'une autre classe ???"<<endl;
               cin>>dec;
               dec=toupper(dec);
            }while(dec!='N');
        break;
         case 5:
            do{
                noteAndMoyOfStudent();
               cout<<"souhaiter vous effectuer rechercher un autre etudiant???"<<endl;
               cout<<"souhaiter vous effectuer rechercher un autre etudiant???"<<endl;
               cin>>dec;
               dec=toupper(dec);
            }while(dec!='N');
        break;
        case 6:
            do{
                searchStudent();
               cout<<"souhaiter vous effectuer rechercher un autre etudiant???"<<endl;
               cin>>dec;
               dec=toupper(dec);
            }while(dec!='N');
        break;
        case 7:
            do{
               cout<<" recherche chercher une classe dans le departement"<<endl;
                setStudentInfo();
                cout<<"souhaiter vous effectuer la meme operation"<<endl;;
                cin>>dec;
                dec=toupper(dec);
            }while(dec!='N');
        break;
        case 8:
             do{
                cout<<" supprimer une classe du departement"<<endl;
                delStudent();
                cout<<"souhaiter vous effectuer la meme operation"<<endl;;
                cin>>dec;
                dec=toupper(dec);
            }while(dec!='N');
        break;
        default:
        cout<<"choix indisponible"<<endl;
        break;

    }
}
void Departement ::gestionMatiere(){
    char dec='N';
    cout <<"menu gestion des Matieres"<<endl;
    cout<<"1-inserer un Matiere\n2-afficher les toutes matiere\n"<<
    "3-afficher la liste des matiere d'une classe \n4-rechercher une du departement \n"<<
    "5-modifier une matiere \n6-suppression d'une matiere"<<endl;
    int choix=0;
    cout<<"choisir une des operation ci-dessus"<<endl;
    cin >> choix;
    cin.clear();
     switch(choix){
        case 1:
            cout<<"vous avez choisi l'insertion d'un etudiant"<<endl<<endl;
            do{
                cout<<"avant l'insertion de la classe"<<endl;
                displayMatiere();
                insertMatiere();
                cout<<"\napres l'insertion de la classe"<<endl;
                displayMatiere();
                cout<<"souhaiter vous effectuer inserer un autre etudiant??"<<endl;
                cin>>dec;
                dec=toupper(dec);
            }while(dec!='N');
        break;
        case 2:
            cout <<"liste de tous les Etudiants du departement"<<endl;
            displayMatiere();
        break;
        case 3:
            do{
                 cout<<"liste de etudiant d'une classe precise"<<endl;
                displayClassDepartement();
                subjectOfClass();
                cout<<"souhaiter vous afficher les etudiant d'une autre classe ???"<<endl;
               cin>>dec;
               dec=toupper(dec);
            }while(dec!='N');
        break;
        case 4:
            do{
               cout<<" Entrer le matricule de l'etudiant a rechercher dans le departement"<<endl;
                searchMat();
               cout<<"souhaiter vous effectuer rechercher un autre etudiant???"<<endl;
               cin>>dec;
               dec=toupper(dec);
            }while(dec!='N');
        break;
        case 5:
            do{
               cout<<" recherche chercher une classe dans le departement"<<endl;
                setMatInfo();
                cout<<"souhaiter vous effectuer la meme operation"<<endl;;
                cin>>dec;
                dec=toupper(dec);
            }while(dec!='N');
        break;
        case 6:
             do{
                cout<<" supprimer une classe du departement"<<endl;
                delMat();
                cout<<"souhaiter vous effectuer la meme operation"<<endl;;
                cin>>dec;
                dec=toupper(dec);
            }while(dec!='N');
        break;
        default:
        cout<<"choix indisponible"<<endl;
        break;

    }
}

void Departement::gestionNote(){

      char dec='N';
    cout <<"menu gestion des notes des Etudiants"<<endl;
    cout<<"1-inserer la note d'un Etudiant\n2-afficher les notes des Etudiants pour une matiere donné\n"<<
    "3-afficher toute les note d'un etudiant\n4-calcule de la moyenne des Etudiants\n"<<
    "-5-Liste des notes d'un etudiant et sa moyenne "<<endl;
    int choix=0;
    cout<<"choisir une des operation ci-dessus"<<endl;
    cin >> choix;
    cin.clear();
     switch(choix){
        case 1:
            cout<<"Saisit des notes d'un Etudiant"<<endl<<endl;
            do{
                cout<<"avant l'insertion de la classe"<<endl;
                displayStudent();
                insertNote();
                cout<<"\napres l'insertion de la classe"<<endl;
                displayStudent();
                cout<<"souhaiter vous effectuer inserer un autre etudiant??"<<endl;
                cin>>dec;
                dec=toupper(dec);
            }while(dec!='N');
        break;
        case 2:
            do{
                cout<<"note des etudiant pour une matiere"<<endl;
                displayClassDepartement();
                noteOfSubject();
                cout<<"souhaiter vous afficher les etudiants d'une autre classe ???"<<endl;
               cin>>dec;
               dec=toupper(dec);
            }while(dec!='N');
        break;
        case 3:
            do{
                cout<<"liste des note pour une matiere"<<endl;
                displayClassDepartement();
                noteOfStudent();
                cout<<"souhaiter vous afficher la liste des note pour un autre etudiant???"<<endl;
               cin>>dec;
               dec=toupper(dec);
            }while(dec!='N');
        break;
        case 4:
               cout<<" calclu de la moyenne des etudiants"<<endl;
                averageNote();
        break;
        default:
        cout<<"choix indisponible"<<endl;
        break;

    }

}

/****gestion des fichiers******/
void Departement::saveClasse(){
    ofstream monfichier("classe.txt");
    Classroom* current=tete;
    while(current!=0){
        monfichier<<current->val.dataClasse();
    }
}
void Departement::saveMat(){
    ofstream monfichier("matiere.txt");
    Subject* current=teteMatiere;
    while(current!=0){
        monfichier<<current->val.dataMat();
    }
}
void Departement::saveEtudiant(){
    ofstream  monfichier("etudiant.txt");
    Student* current=teteEtudiant;
    while(current!=0){
        monfichier<<current->val.dataEtudiant();
    }
}
void Departement::saveNote(){
    ofstream  monfichier("note.txt");
    Mark* current=teteNote;
    while(current!=0){
        monfichier<<current->val.dataNote();
    }
}
void Departement::loadClasse(){
    ifstream monfichier("classe.txt");
    vector<string> data;
    string line="";
    if(monfichier){
        while(getline(monfichier,line)){

            data=splitstr(line);
            readClasseFile(data[0],data[1]);
            data.clear();
        }
    }else{
        cout<<"erreur lors du chargement du fichier"<<endl;
    }
}
void Departement::loadMat(){
    ifstream monfichier("matiere.txt");
     vector<string> data;
      string line="";
    if(monfichier){
        while(getline(monfichier,line)){

            data=splitstr(line);
            readMatFile(data[0],data[1],data[2],string2float(data[3]));
            data.clear();
        }
    }else{
        cout<<"erreur lors du chargement du fichier"<<endl;
    }
}
void Departement::loadEtudiant(){
    ifstream monfichier("etudiant.txt");
    vector<string> data;
     string line="";
    if(monfichier){
        while(getline(monfichier,line)){

            data=splitstr(line);
            readStudentFile(data[0],data[1],data[2],data[3],data[4][0],data[5],string2float(data[6]));
            data.clear();
        }
    }else{
        cout<<"erreur lors du chargement du fichier"<<endl;
    }
}
void Departement::loadNote(){
    ifstream monfichier("note.txt");
   vector<string> data;
    string line="";
    if(monfichier){
        while(getline(monfichier,line)){


            data=splitstr(line);

            readNoteFile(data[0],data[1],string2float(data[2]));
            data.clear();
        }
    }else{
        cout<<"erreur lors du chargement du fichier"<<endl;
    }
}
/*****gestion des notes*****/
Mark* Departement::searchNoteDepart(string matricule,string codeMat){
    bool trouver=false;
    Mark* current=0;
    matricule=toupper(matricule);
    codeMat=toupper(codeMat);
    while(current!=0 && trouver!=true){
        if(matricule==current->val.getCodeEtudiant() && codeMat==current->val.getCodeMat()){
            trouver=true;
        }else{
            current=current->suivant;
        }
    }
    return current;
}

bool Departement::searchNote(string matricule,string codeMat){

        bool trouver=false;
        Mark* current=0;
        current=teteNote;
        matricule=toupper(matricule);
        codeMat=toupper(codeMat);
        while(current!=0 && trouver!=true){
            if((matricule==current->val.getCodeEtudiant()) && (codeMat==current->val.getCodeMat())){
                trouver=true;
            }else{
                current=current->suivant;
            }
        }
        return trouver;
  }

void Departement:: displayNote(){
    Mark* current=teteNote;
    if(current!=0){
        while(current!=0){
            current->val.displayNote();
            current=current->suivant;
        }
    }else{
        cout<<"aucune le matiere "<<endl;
    }
}

void Departement::noteOfSubject(){
     bool use;
    Mark* current=0;
    current=teteNote;
    string code;
     do{
            use=false;
            cout <<"entrer le code de la matiere dont on veut obtenir la liste des notes"<<endl;
            cin>>ws; //pour changer la valeur de l'espace blanc
            getline(cin, code);
            code=toupper(code);//on met le code en majuscule
            if(!searchMatDepartement(code)){
                cout<<"cette matiere n'existe pas dans le departement"<<endl;
                displayMatiere();
                use=true;
            }
        }while(use==true);
    while(current!=0){
        if(code==current->val.getCodeMat()){
            displayStudent(current->val.getCodeEtudiant());
            cout<<current->val.getNoteVal()<<endl;
        }
        current=current->suivant;
    }
}

void Departement:: noteOfStudent(){
    bool use;
    Mark* current=0;
    current=teteNote;
    string code;
     do{
            use=false;
            cout <<"entrer le matricule de l'etudiant dont on veut obtenir la liste des notes"<<endl;
            cin>>ws; //pour changer la valeur de l'espace blanc
            getline(cin, code);
            code=toupper(code);//on met le code en majuscule
            if(!searchStudent(code)){
                cout<<"la cet etudiant n'existe pas "<<endl;
                displayMatiere();
                use=true;
            }
        }while(use==true);
    while(current!=0){
        if(code==current->val.getCodeEtudiant()){
            current->val.displayNote();
        }
        current=current->suivant;
    }
}

void Departement::averageNote(){
    Student* current=teteEtudiant;
    Subject* mat;
    Mark* currentNote;
    float s,sCoef,moy,valnote;
    int coef;
        while(current!=0){
            sCoef=1;
            s=moy=0;
            currentNote=teteNote;
            while(currentNote!=0){
                if(currentNote->val.getCodeEtudiant()==current->val.getMatricule()){
                    mat=(searchMatDepart(currentNote->val.getCodeMat()));
                    if(mat!=0){
                        coef=mat->val.getCoef();
                        valnote=currentNote->val.getNoteVal();
                        s+=coef*valnote;
                        sCoef+=sCoef;
                    }
                }
                currentNote=currentNote->suivant;
            }
            moy=s/sCoef;
            current->val.setMoyenne(moy);
            current=current->suivant;
        }
}
void Departement::insertNote(){
    Mark* p=new Mark;
    bool use;
    string matricule,codeMat;
    int valnot;
    cout<<"entrer le code de la matiere"<<endl;
    cin>>ws;
    getline(cin,codeMat);
    cout<<"entrer la valeur de note a ajouter"<<endl;
    cin>>valnot;
     do{
        use=false;
        cout<<"entrer le matricule de l'etudiant"<<endl;
        cin>>ws;
        getline(cin,matricule);
        if(!searchStudent(matricule)){
            cout<<"cet n'est pas inscrit"<<endl;
            displayStudent();
            use=true;
        }
    }while(use==true);
    codeMat=toupper(codeMat);

    matricule=toupper(matricule);
     if(!searchStudent(matricule)&&!searchMatDepartement(codeMat)){
            if(!searchStudent(matricule)){
                cout<<"l'etudiant ayant le matricule"<<matricule<<" n'existe pas dans "<<endl;
            }
            if(!searchMatDepartement(codeMat)){
                cout<<"la matiere ayant le de code "<<codeMat<<" n'existe pas dans "<<endl;
            }
    }else{
        p->val.setAllNoteInfo(matricule,codeMat,valnot);
        if(!searchNote(matricule,codeMat)){
            if(teteNote==0){
                p->precedent=0;
                p->suivant=0;
                teteNote=p;
            }else{
                p->precedent=teteNote; // vue que l'elt est inserer en tête son precedent pointer vers rien
                teteNote->precedent=p;// le precedent de l'actuelle tete est la noubvelle tete que l'on souhaite inserer
                p->suivant=teteNote;//le suivant de la nouvelle tete pointe vers l'ancienne tete
                teteNote=p;//la tete pointe mtn sur mon element inserer;           }

            }
        }else{
            cout<<"la note pour cet etudiant est deja insere aller au menu modification pour la modifier"<<endl;
        }
    }
}
 void Departement::readNoteFile(std::string matricule,std:: string codeMat,float val){
      Mark* p=new Mark; // on cree une nouvelle classe
        matricule=toupper(matricule);
        codeMat=toupper(codeMat);
        p->val.setAllNoteInfo(matricule,codeMat,val);
    if(teteNote==0){
        p->precedent=0;
        p->suivant=0;
        teteNote=p;
    }else{
        p->precedent=0; // vue que l'elt est inserer en tête son precedent pointer vers rien
        teteNote->precedent=p;// le precedent de l'actuelle tete est la noubvelle tete que l'on souhaite inserer
        p->suivant=teteNote;//le suivant de la nouvelle tete pointe vers l'ancienne tete
        teteNote=p;//la tete pointe mtn sur mon element inserer;
    }
 }
void Departement::setNoteInfo(string matricule,string codeMat,float val){
    Mark* current=0;
    current=searchNoteDepart(matricule,codeMat);
    if(current!=0){
        current->val.setNoteVal(val);
    }else{
        cout<<"la note n'est pas encore defini"<<endl;
    }
 }
