#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>

#include "list.h"
#include "paciente.h"
#include "name.h"
#include "date.h"

using namespace std;

//No recomendable, seria mejor utilizar una clase menu para mantener el main en un minimo

void inputp();
void inputc();
void psearch();
void csearch();
void pedit();
void pdisplayAll();
void cdisplayAll();
void exit();

int main() {



     bool menu = true; //lmao
     int choice;
     List<Paciente> myLista;
     List<Date> myOtherLista;
     string myString;
     Paciente myPaciente;
     Name myName;
     Date myDate;
     int myInt;
     float myFloat;
     char myChar;
     char op;
    while(menu){

     system("cls"); //system("cls") no sirve en linux, se tiene que utilizar "clear" ya que el shell es bash
     system("title: Nutriologa"); // funciona en windows
     system("color 0f"); // funciona en windows

     cout << "Por favor introduzca su eleccion" << endl;
     cout << "1.Introducir nuevo Paciente:  " << endl;
     cout << "2.Agendar nueva Cita: " << endl;
     cout << "3.Desplegar todos los Pacientes" << endl;
     cout << "4.Desplegar todas las Citas" << endl;
     cout << "5.Salir" << endl;

     cin >> choice;
     menu = false;
     switch (choice){

    case 1:
        do {
        //terrible
        cout << cin.ignore();
        cout << endl;

        cout << "Dame el apellido del paciente: ";
        getline(cin,myString);
        myName.setLast(myString);

        cout<< "Dame el nombre del paciente: ";
        getline(cin,myString);
        myName.setFirst(myString);

        myPaciente.setName(myName);

        cout << "Dame la edad del paciente:";
        cin>> myInt;
        myPaciente.setAge(myInt);

        cout <<"Dame el sexo del paciente: (M/F)";
        cin>>myChar;
        myPaciente.setSex(myChar);

        cout <<"Dame el peso del paciente: ";
        cin>> myFloat;
        myPaciente.setWeight(myFloat);

        cout <<"Dame la altura del paciente: ";
        cin>> myFloat;
        myPaciente.setHeight(myFloat);

        cout <<"Dame el dia de nacimiento: ";
        cin>> myInt;
        myDate.setDay(myInt);

        cout <<"Dame el mes de nacimiento: ";
        cin>> myInt;
        myDate.setMonth(myInt);

        cout <<"Dame el anio de nacimiento: ";
        cin>> myInt;
        myDate.setYear(myInt);

        myPaciente.setBirthDay(myDate);

        cout <<"Dame el dia de Ingreso: ";
        cin>> myInt;
        myDate.setDay(myInt);

        cout <<"Dame el mes de Ingreso: ";
        cin>> myInt;
        myDate.setMonth(myInt);

        cout <<"Dame el anio de Ingreso: ";
        cin>> myInt;
        myDate.setYear(myInt);

        myPaciente.setstartingDate(myDate);


        myLista.insertData(myLista.getLast(),myPaciente);
        do {
            cout << "Capturar otro? (s/n): ";
            cin>> op;
        cout << cin.ignore();
            op = toupper(op);
            }while(op != 'N' and op != 'S');

        cout << "\tContenido de la Lista: \n" << endl;
        myLista.print();
        }
    while(op == 'S');

    cout << endl << endl;
    menu = true;
    break;



    case 2:
        do {
        //terrible
        cout << cin.ignore();
        cout << endl;

        cout<< "Dame el nombre del paciente: ";
        getline(cin,myString);
        myName.setFirst(myString);

        myPaciente.setName(myName);

        cout <<"Dame el dia de Ingreso: ";
        cin>> myInt;
        myDate.setDay(myInt);

        cout <<"Dame el mes de Ingreso: ";
        cin>> myInt;
        myDate.setMonth(myInt);

        cout <<"Dame el anio de Ingreso: ";
        cin>> myInt;
        myDate.setYear(myInt);

        myPaciente.setstartingDate(myDate);


        myLista.insertData(myLista.getLast(),myPaciente);
        do {
            cout << "Capturar otro? (s/n): ";
            cin>> op;
        cout << cin.ignore();
            op = toupper(op);
            }while(op != 'N' and op != 'S');

        cout << "\tContenido de la Lista: \n" << endl;
        myLista.print();
        }
    while(op == 'S');

    cout << endl << endl;
    menu = true;
    break;

    case 3:
        break;

    case 4:
        myLista.print();
        break;


    case 5:
        return 0;
        break;

    default:
        menu = true;

    }
}


return 0;

}
