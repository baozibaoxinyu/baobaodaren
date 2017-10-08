#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
class A {
private:
	int a{};
	int b{};
	int c{};
	std::string name;
public:
	A() {};
	A(int theA, int theB, int theC, char* theName) :a{ theA }, b{ theB }, c{ theC }, name{ theName } {}
	A(const A& theA) {
		a = theA.a;
		b = theA.b;
		c = theA.c;
		name = theA.name;
	}
	friend std::ostream& operator<<(std::ostream& out, A& theA);
	friend std::istream& operator >> (std::istream& in, A& theA);
	friend std::ofstream& write(std::ofstream& out, A& theA);
	friend std::ifstream& read(std::ifstream& in, A& theA);
};
inline std::ostream& operator<<(std::ostream& out, A& theA) {
	out << theA.a << ' ' << theA.b << ' ' << theA.c << ' ' << theA.name;
	return out;
}
inline std::istream& operator >> (std::istream& in, A& theA) {
	in >> theA.a >> theA.b >> theA.c >> theA.name;
	return in;
}
inline std::ofstream& write(std::ofstream& out, A& theA) {
	out.write(reinterpret_cast<char*>(&theA.a), sizeof(theA.a));
	out.write(reinterpret_cast<char*>(&theA.b), sizeof(theA.b));
	out.write(reinterpret_cast<char*>(&theA.c), sizeof(theA.c));
	out.write(reinterpret_cast<char*>(&theA.name), sizeof(theA.name));
	return out;
}
inline std::ifstream& read(std::ifstream& in, A& theA) {
	in.read(reinterpret_cast<char*>(&theA.a), sizeof(theA.a));
	in.read(reinterpret_cast<char*>(&theA.b), sizeof(theA.b));
	in.read(reinterpret_cast<char*>(&theA.c), sizeof(theA.c));
	in.read(reinterpret_cast<char*>(&theA.name), sizeof(theA.name));
	return in;
}
int main()
{
	A theA{ 1,2,3,"x"};
	A theB;
	std::string filename{ "E:\\LearnC++\\16-fileIO\\exercise\\Exercise_File\\binaryTest.txt" };
	std::string filename1{ "E:\\LearnC++\\16-fileIO\\exercise\\Exercise_File\\binaryTest1.txt" };
	std::ofstream outfile{ filename,std::ios::binary };
	if (!outfile.fail()) {
		//outfile << theA;
		write(outfile, theA);
		std::cout << "Success" << std::endl;
	}
	else {
		std::cout << "Failed" << std::endl;
	}
	outfile.close();
	std::ifstream infile{ filename };
	while (true) {
		//infile >> theB;
		read(infile, theB);
		if (infile.eof()) break;
	}
	std::cout << theB << std::endl;	
}