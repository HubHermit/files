#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int num1 =0;
	int num2 =0;
	int num3 =0;
	int sum = 0; 
	int avg = 0;
	
	ifstream myfile{"data/file1", ios::binary};
	ofstream outFile{"data/file3",ios::binary};
	if (myfile)
	{
		
		while(!myfile.eof())
		{		
			myfile.read(reinterpret_cast<char*>(&num1), sizeof(num1));
			myfile.read(reinterpret_cast<char*>(&num2), sizeof(num2));
			myfile.read(reinterpret_cast<char*>(&num3), sizeof(num3));
			sum = num1 + num2 + num3;
			avg = sum/3;		
						
			if (avg < 75)
			{
				outFile<<"0 0 0"<<endl;
			}
			else if (avg > 150)
			{
				outFile<<"255 255 255"<<endl;
			}
			else 
			{
				outFile<<"100 100 100"<<endl;
			}			
		}
					
	}else
	{
		cout<<"Error opening data/file1"<<endl;
	}
	
}
