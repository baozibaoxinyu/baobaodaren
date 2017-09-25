#include <iostream>
using namespace std;

int main()
{
	bool bulb[2016]{0};
	for(int i = 1;i<2016;++i){
		for(int j = i;j< 2016;++j){
			if(j%i == 0)
				bulb[j] = !bulb[j];
		}
	}
	int count = 0;
        for(int i = 1;i<2016;++i)
		if(bulb[i]== 1)
			++count;
	cout << "The light bulb number is "<< count << endl;	
}
