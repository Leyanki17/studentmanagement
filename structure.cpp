#include "preprocesseur.h"
#include <sstream>
using namespace std;
string toupper(string text){
    string val="";
    for(int i=0;i<text.size();i++){
        val+=toupper(text[i]);
    }
    return val;
}

string float2string(float f)
{
  ostringstream os;
  os << f;
  return os.str();
}
float string2float(string f){
    float numero=strtof((f).c_str(),0);
    return numero;
}

vector<string> splitstr(string data_file){
	vector<string> tab;
	string temp ="";
	for(int i=0;i<data_file.size();i++){
		if(data_file[i] == '#'){
			tab.push_back(temp);
			temp ="" ;
		}else{
			temp+=data_file[i];
		}
	}
		tab.push_back(temp);
		return tab;
}
