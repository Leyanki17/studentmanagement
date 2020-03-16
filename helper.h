#ifndef HELPER_H_INCLUDED
#define HELPER_H_INCLUDED
#include "Classe.h"
#include "Etudiant.h"
#include "Matiere.h"
#include "Notes.h"
#include <iostream>
#include <cstdlib>
#include <vector>
    struct Classroom {
        Classroom *precedent;
        Classe val;
        Classroom *suivant;
    };

     struct Student{
        Student *precedent;
        Etudiant val;
        Student *suivant;
    };

    struct Subject{
        Subject* precedent;
        Matiere val;
        Subject * suivant;
    };
    struct Mark{
        Mark* precedent;
        Note val;
        Mark* suivant;
    };
std::string toupper(std::string text);
std::vector<std::string> splitstr(std::string data_file);
std::string float2string(float f);
float string2float(std::string f);

#endif // HELPER_H_INCLUDED


