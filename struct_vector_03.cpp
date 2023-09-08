#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct Angajat{
    int age;
    double sallary;
    string name;
};

int Cauta_Elementul(string name, vector < Angajat > &db){

    int indexul_numelui {-1};

    for (int i = 0; i < db.size(); i++){
        if (db[i].name == name){
            indexul_numelui = i;
        }
    }
    return indexul_numelui;
}

//Prototipul
bool Adaugarea_Unui_Element_In_Database(int age, double sallary, string name, vector < Angajat > &db){
//Implementare
    Angajat variabila{age, sallary, name};
    size_t dimensiune_initiala {db.size()};

    int rezultatul_functiei = Cauta_Elementul(name, db);
    
    if(rezultatul_functiei == -1){
        db.push_back(variabila);
    }

   
    
    size_t dimensiune_finala{db.size()};

    bool status = (dimensiune_finala - dimensiune_initiala == 1);

    return status;

}
//La fiecare adaugare de element functia v-a printa un 1


void afisare_elemente(vector < Angajat > &db){

     for (int i = 0; i < db.size(); i++){//loop afisare
        
        cout << "Varsta angajatului: " << db[i].age << endl;
        cout << "Salariul angajatului: " << db[i].sallary << endl;
        cout << "Numele angajatului: " << db[i].name << endl;

    }
}


bool stergere_elemente(vector < Angajat > &db, string name){

     //Companie.erase(Companie.begin() + stergere_element);

    int indexul_numelui = Cauta_Elementul(name, db);

    bool status;

    if(indexul_numelui != -1){
        db.erase(db.begin() + indexul_numelui);
        status = true;
    }
    else{
        status = false;
    }

    return status;

 }


//2) Sa fac o functie care pe baza numelui poate modifica campurile age si sallary
bool modificare_dupa_nume(vector < Angajat > &db, string name , int age, double sallary){

    int indexul_numelui = Cauta_Elementul(name, db);
    bool status = false;

    if(indexul_numelui > -1){
        db[indexul_numelui].age = age;
        db[indexul_numelui].sallary = sallary; 
        status = true;
    }

    return status;
}          

int comma_count(string linie){
    
    int comma_count {0};
    string var_aux00 = linie;
    int var_aux00_bytes = sizeof(var_aux00);// char == 1 byte


    for (int i = 0 ; i < var_aux00_bytes ; i++){
        if (linie[i] == ','){
          
            comma_count++;

        }
    }
    
    cout << "Comma count: " << comma_count << endl;

    return comma_count;

}

Angajat Split_by_token( string linie ){

    Angajat return_value;

    stringstream pipeline(linie);

    string substring;
    
    // while (getline(pipeline , substring , ',')){

    //     cout << endl << substring << endl;

    // }
    
    int token_age{0};
    double token_sallary{0};
    string token_name;
    
    if(comma_count(linie) == 2){
        
        getline(pipeline , substring , ',');{
            token_age = stoi(substring);
            cout << token_age << endl;
            return_value.age = token_age;
        }

        getline(pipeline , substring , ',');{
            token_sallary = stod(substring);
            cout << token_sallary << endl;
            return_value.sallary = token_sallary;
        }

        getline(pipeline , token_name , ',');{
            cout << token_name << endl;
            return_value.name = token_name;
        }
    }

    else{
        cout << "Ati apelat functia cu argumente incorecte!" << endl;
    }

    return return_value;

    //1)Stochez cele 3 stringuri sparte in return value, fiecare pe campul corespunzator(age, sallary, name) - complete
    //Trebuie convertite datele
    //2)Sa gestionez situatiile extreme(linie mai mare sau mai mica de 3 valori,etc) - complete(cred)
}
       

int main() {

    vector < Angajat > Companie;

    cout << Adaugarea_Unui_Element_In_Database(20 , 2000 , "Marius" , Companie);

    //Functiile de afisare si stergere

    cout << Adaugarea_Unui_Element_In_Database(30 , 3000 , "Gabor" , Companie);
    
    afisare_elemente(Companie);
    
    cout << endl;

    //stergere_elemente(Companie, "Gabor");

    afisare_elemente(Companie);
    
    // modify_by_name(Companie);

    // cout << "Afisarea elementelor modificate: " << endl;

    // afisare_elemente(Companie);

    //modificare_dupa_nume(25, 5000 , "Ionut" , Companie);

    cout << endl <<"Verificare dupa nume: " << endl;
    modificare_dupa_nume(Companie , "Ionut" , 35 , 4500);

    cout << endl << "Functia Split_by_token: " << endl;
    Split_by_token("20,2000,Marius");

    //prototype
    vector <string> nume = {"Adrian" , "Andrei" , "Mihai" , "Ionut" , "Florin" , "Daniel" , "Marian" , "Cristian" , "Constantin" , "Bogdan" , "Vasile"};

}

//1)De citit despre size_t - complete
//2)De implementat functiile de afisare/stergere - complete
//3)De citit function overloading - complete
//4) Adaugarea unui nou element pe baza verificarii numelui - complete
//5) Sa fac o functie care pe baza numelui poate modifica campurile age si sallary - complete
//6) Sa introduc functia Cauta_Elementul in primul bool - complete
//7) Citeste valorile pe care le-am adaugat in db dintr-un csv - complete