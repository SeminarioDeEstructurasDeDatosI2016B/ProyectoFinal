#include "paciente.h"

#include <string>

Paciente::Paciente(){

}

Paciente::Paciente(const Paciente&){

}

Name Paciente::getName(){

	return name;
}

Date Paciente::getBirthDay(){

	return birthDay;
}

int Paciente::getAge(){

	return age;
}

char Paciente::getSex(){

	return sex;
}

std::string Paciente::getAddress(){

	return address;
}

int Paciente::getPhone(){

	return phone;
}

int Paciente::getCellphone(){

	return cellphone;
}

std::string Paciente::getOccupation(){

	return occupation;
}

std::string Paciente::getMartialstatus(){

	return martialStatus;
}

bool Paciente::getPlaysSports(){


}

bool Paciente::getSmokes(){


}

bool Paciente::getDrinks(){


}

float Paciente::getWeight(){

	return weight;
}

float Paciente::getHeight(){

	return height;
}

Date Paciente::getstartingDate(){

	return startingDate;
}

Date Paciente::getAppointment(){

	return appointment;
}

void Paciente::setName(const Name& n){

	name = n;
}

void Paciente::setBirthDay(const Date& bd){

	birthDay = bd;
}

void Paciente::setstartingDate(const Date& sd){

	startingDate = sd;
}

void Paciente::setAge(const int& a){

	age = a;
}

void Paciente::setSex(const char& s){

	sex = s;
}

void Paciente::setAddress(const std::string adr){

	address = adr;
}

void Paciente::setPhone(const int& p){

	phone = p;
}

void Paciente::setCellphone(const int& cp){

	cellphone = cp;
}

void Paciente::setOccupation(const std::string o){

	occupation = o;
}

void Paciente::setMartialstatus(const std::string ms){

	martialStatus = ms;
}

void Paciente::setPlaysSports(){

}

void Paciente::setSmokes(){

}

void Paciente::setDrinks(){

}

void Paciente::setWeight(const float& w){

	weight = w;
}

void Paciente::setHeight(const float& h){

	height = h;
}


void Paciente::setAppointment(const Date& ap){

	appointment = ap;
}

float Paciente::calculateBMI(float& w,float& h){

	float bmi;
	float h2;

	if(w and h > 0){
		h *= h;
		bmi = h/w;
	}

	return bmi;
}

bool Paciente::operator==(const Paciente&){

}

bool Paciente::operator!=(const Paciente&){

}

bool Paciente::operator<(const Paciente&){

}

bool Paciente::operator>(const Paciente&){

}

bool Paciente::operator<=(const Paciente&){

}

bool Paciente::operator>=(const Paciente&){

}
