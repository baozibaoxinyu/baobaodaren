#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <typeinfo>
#include <iomanip>
#include "BaseLength.h"
using namespace std;
shared_ptr<BaseLength> readLength(){
    double value {};
    string units;
    while(1){
        cout<< "Enter a length:";
        cin >> skipws >> value;
        if(!value) return nullptr;
        
        getline(cin,units);
        size_t index{units.find_first_not_of(" ")};
        switch(toupper(units[index])){
	    case 'M':return make_shared<Meters>(value);
    	    case 'I':return make_shared<Inches>(value);
   	    case 'Y':return make_shared<Yards>(value);
            case 'P':return make_shared<Perches>(value);
            default:
    	        cout << "\nInvalid unit,re-enter length" <<endl;
                break;
       }
    }
}

int main()
{
    vector<shared_ptr<BaseLength>> pLengths;
    cout<<"you can enter lengths in inches,meters,yards,perches."
        <<"\n the first character following the number specified the units."
        <<"\nThis can be i,p,m,y for inches,perches,meters,yards."
        <<"\ne.g. '22 ins' means 22 inches,'1y' means 1 yard."
        << endl<<"please input a length followed by units or 0 to end:";
    while(1){
        auto p = readLength();
        if(!p) break;//if p = nullptr,break loop.
        pLengths.push_back(p);

        for(auto p : pLength){
            string units{"invalid type"};
            if(typeid(*p)== typeid(Inches))
   	        unit = "inches";
	    if(typeid(*p)== typeid(Meters))
    		unit = "meters";
	    if(typeid(*p)== typeid(Yards))
		unit = "yards";
	    if(typeid(*p)== typeid(Perches))
		unit = "perches";
	    cout<< "length is "<< fixed << setpercision(2) << p->length()
		<< units << " which is "<< static_cast<long>(p->BaseLength::length())
		<< " milimeters."<< endl;
        }
    }
    return 0;
}

