#include "name.h"

using namespace std;

string Name::getLast() {
	return last;
}
string Name::getFirst() {
	return first;
}
void Name::setLast(const std::string& l){
	last = l;
}
void Name::setFirst(const std::string& f){
	first = f;
}

bool Name::operator==(const Name& n){
    return last+first == n.last + n.first;

}
bool Name::operator!=(const Name& n){
    return!(*this == n);

}
bool Name::operator<(const Name& n){
    return last + first < n.last + n.first;

}
bool Name::operator>(const Name& n){
    return last + first > n.last + n.first;

}
bool Name::operator<=(const Name& n){
    return last + first <= n.last + n.first;

}
bool Name::operator>=(const Name& n){
    return last + first >= n.last + n.first;

}

std::ostream& operator << (std::ostream& os, Name& n){ //convertir en flujo
    os << n.last << endl;
    os << n.first << endl;

    return os;
}
/*
REVISAR

std::istream& operator >> (std::istream& is, Name& n){
    getline(is >> n.last); //flujo de entrada
    getline(is >> n.first);

    return is;
}
*/
