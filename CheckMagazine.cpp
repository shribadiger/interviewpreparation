#include<iostream>
#include<string>
#include<vector>

using namespace std;

void validateOutput(std::vector<string> input, std::vector<string> output) {
	int counter = 0 ;
	std::cout<<"\n Size of Input:"<<input.size();
	for(int i=0; i<output.size();i++){
		for(int j=0;j<input.size();j++) {
			std::cout<<"\n"<<output[i]<<"--"<<input[j];
			if(output[i]==input[j]){
				counter++;
				break;
			}
		}
	}
	if(counter == output.size()){
		std::cout<<"Yes";
	}
	else {
		std::cout<<"No";
	}
}


int main() {
	std::vector<std::string> input;
	input.push_back("give");
	input.push_back("me");
	input.push_back("valid");
	input.push_back("input");
	input.push_back("output");

	std::vector<std::string> output;
	output.push_back("give");
	output.push_back("me");
	output.push_back("output");

	validateOutput(input,output);

	return 0;
}



