#ifndef NAME_H_INCLUDED
#define NAME_H_INCLUDED

#include <iostream>
#include <string>

class Name {
private:
	std::string last;
	std::string first;

public:
    Name();
    Name(const Name&);
    Name(std::string, std::string);
	std::string getLast();
	std::string getFirst();

	void setLast(const std::string&);
	void setFirst(const std::string&);

	bool operator == (const Name&);
	bool operator != (const Name&);
	bool operator < (const Name&);
	bool operator > (const Name&);
	bool operator <= (const Name&);
	bool operator >= (const Name&);

	friend std::ostream& operator << (std::ostream&, Name&);
    friend std::istream& operator >> (std::istream&, Name&);
};

#endif // NAME_H_INCLUDED
