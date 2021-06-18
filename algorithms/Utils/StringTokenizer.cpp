/**
https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
**/
//Single char delimeter solution:
using namespace std;

string parsed,input="text to be parsed";
stringstream input_stringstream(input);
if (getline(input_stringstream,parsed,' ')) {
     // do some processing.
}

//string as delimeter : 
std::string s = "scott>=tiger>=mushroom";
std::string delimiter = ">=";

size_t pos = 0;
std::string token;
while ((pos = s.find(delimiter)) != std::string::npos) {
    token = s.substr(0, pos);
    std::cout << token << std::endl;
    s.erase(0, pos + delimiter.length());
}
std::cout << s << std::endl;
/**
O/P:
scott
tiger
mushroom
**/
