#include <iostream>
#include <sstream>
#include <fstream>
#include "string"
#include <map> 
#include <vector>
#include<iomanip>
using namespace std;
void strTrans(vector<string> str2, map<string,   float> my_Map);
float calculate();
vector<char> sign ; 
vector<float> num ; 
void main()
{
	map<string, float> my_Map;
	bool isReadMap = true;
	ifstream fin("input.txt", std::ios::in); 
	ofstream fout("output.txt");
	fout<<"tianlan521521@126.com"<<endl;
	fout<<endl;
	char line[1024]={0};
	vector<string> input, expression;
	string temp;
	while(fin.getline(line, sizeof(line)))
	{
		if(line[0] == '\0') {
			isReadMap = false;
			fin.getline(line, sizeof(line));			
			my_Map.insert(map<string,   float>::value_type("miles",my_Map["mile"])); 
			my_Map.insert(map<string,   float>::value_type("feet",my_Map["foot"])); 
			my_Map.insert(map<string,   float>::value_type("inches",my_Map["inch"]));
			my_Map.insert(map<string,   float>::value_type("faths",my_Map["fath"])); 
			my_Map.insert(map<string,   float>::value_type("fulongs",my_Map["fulong"]));
			my_Map.insert(map<string,   float>::value_type("yards",my_Map["yard"]));
		}
		if(isReadMap){
			std::stringstream word(line);
			word>>temp;
			while (temp != "")
			{
				input.push_back(temp);
				temp = "";
				word>>temp;
			}				
			my_Map.insert(map<string,   float>::value_type(input[1],(float)atof(input[3].c_str())));
			input.clear();
		}else{
			std::stringstream word(line);
			word>>temp;
			while (temp != "")
			{
				expression.push_back(temp);
				temp = "";
				word>>temp;
			}
			expression.push_back("");
			strTrans(expression, my_Map);
			float sum = 0;
			sum = calculate();
			expression.clear();
			num.clear();
			sign.clear();
			fout<<setiosflags(ios::fixed)<<setprecision(2)<<sum<<" m"<<endl;
		}
	}
	fout.close();
	fin.clear();
	fin.close();
}
void strTrans(vector<string> str2 , map<string, float> my_Map)
{
	int index = 0;
	float xishu = 0;
	float ratio = 0;	
	while(str2[index] != ""){
		if(str2[index][0] <= '9' && str2[index][0] >= '0')
		{
			xishu = (float)atof(str2[index].c_str());
		}else if( str2[index][0] <= 'z' && str2[index][0] >= 'A'){
			ratio = my_Map[str2[index]];
			num.push_back(xishu * ratio);
		}else if(str2[index] == "+" || str2[index] == "-"){
			sign.push_back(str2[index][0]);
		}		
		index++;
	};
}
float calculate()
{
	float sum = num[0]; 
	for (int i = 0; i < sign.size(); i++)
	{
		if(sign[i] == '+'){
			sum += num[i+1]; 
		}else{
			sum -= num[i+1];
		}
	}
	return sum;
}