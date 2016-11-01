#ifndef PACIENTE_H_INCLUDED
#define PACIENTE_H_INCLUDED


#include <string>
#include "name.h"
#include "date.h"

class Paciente{
private:

    Name name;
    Date birthDay;
    Date startingDate;
    int age;
    char sex;
    std::string address;
    int phone;
    int cellphone;
    std::string occupation;
    std::string martialStatus;
    bool playsSports;
    bool smokes;
    bool drinks;
    float weight;
    float height;
    Date appointment;

public:

    Paciente();
    Paciente(const Paciente&);

    Name getName();
    Date getBirthDay();
    Date getstartingDate();
    int getAge();
    char getSex();
    std::string getAddress();
    int getPhone();
    int getCellphone();
    std::string getOccupation();
    std::string getMartialstatus();
    bool getPlaysSports();
    bool getSmokes();
    bool getDrinks();
    float getWeight();
    float getHeight();
    Date getAppointment();

    void setName(const Name&);
    void setBirthDay(const Date&);
    void setstartingDate(const Date&);
    void setAge(const int&);
    void setSex(const char&);
    void setAddress(const std::string);
    void setPhone(const int&);
    void setCellphone(const int&);
    void setOccupation(const std::string);
    void setMartialstatus(const std::string);
    void setPlaysSports();
    void setSmokes();
    void setDrinks();
    void setWeight(const float&);
    void setHeight(const float&);
    void setAppointment(const Date&);

    float calculateBMI(float&, float&);

    bool operator == (const Paciente&);
    bool operator != (const Paciente&);
    bool operator < (const Paciente&);
    bool operator > (const Paciente&);
    bool operator <= (const Paciente&);
    bool operator >= (const Paciente&);



    friend std::ostream& operator << (std::ostream& , Paciente&);
    friend std::istream& operator >> (std::istream&, Paciente&);


};

#endif // PACIENTE_H_INCLUDED
