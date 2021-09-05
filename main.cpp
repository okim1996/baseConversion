#include <iostream>
#include <math.h>
using namespace std;
bool validate(string inp){
	string allowed = "0123456789ABCDEFabcdef";
	for(int i = 0 ; i < inp.size() ; i++){
		if( allowed.find(inp[i]) == -1)
			return false;
	}
	return true;
}

string findType(string inp){
	string hex = "ABCDEFabcdef";
	string dec_hex = "89";
	string oct_dec_hex = "234567";
	string type = "BinOctDecHex";
	for(int i = 0 ; i < inp.size() ; i++){
		
		if(oct_dec_hex.find(inp[i]) != -1){
			type = "OctDecHex";
		}
		if(dec_hex.find(inp[i]) != -1){
			type =  "DecHex";
		}
		if(hex.find(inp[i]) != -1){
			return "Hex";
		}
	}
	return type;
}

int char_int(char character){
	if(character == 'A' || character == 'a') return 10;
	if(character == 'B' || character == 'b') return 11;
	if(character == 'C' || character == 'c') return 12;
	if(character == 'D' || character == 'd') return 13;
	if(character == 'E' || character == 'e') return 14;
	if(character == 'F' || character == 'f') return 15;
	return 1;
} 

string int_hex(int to_hex){
	if(to_hex == 0) return "0" ;
	if(to_hex == 1) return "1" ;
	if(to_hex == 2) return "2" ;
	if(to_hex == 3) return "3" ;
	if(to_hex == 4) return "4" ;
	if(to_hex == 5) return "5" ;
	if(to_hex == 6) return "6" ;
	if(to_hex == 7) return "7" ;
	if(to_hex == 8) return "8" ;
	if(to_hex == 9) return "9" ;
	if(to_hex == 10) return "A" ;
	if(to_hex == 11) return "B" ;
	if(to_hex == 12) return "C" ;
	if(to_hex == 13) return "D" ;
	if(to_hex == 14) return "E" ;
	if(to_hex == 15) return "F" ;
	return "A";
}

string hex_bin(string hex){
	string nums = "1234567890";
	int current = 0;
	string reverse = "";
	string bin = "";
	for(int i = 0 ; i < hex.size();i++){
		if(nums.find(hex[i]) == -1){
			current = char_int(hex[i]);
		} else {
			current = hex[i] - 48;
		}		
		for(int c = 0 ; c < 4 ; c++){
			reverse +=  to_string(current%2);
			current /= 2;
		}

		for(int i = reverse.size()-1 ; i >= 0 ; i--){
			bin += reverse[i];
		}
		reverse = "";
	}
	return bin;
}

string dec_bin(string dec){
	int number = stoi(dec);
	string reverse = "";
	string bin = "";
	while(number/2 !=0){
		reverse += to_string(number % 2);
		number /= 2;
	}
	reverse += to_string(number % 2);
	for(int i = reverse.size() - 1 ; i >= 0 ; i --){
		bin += reverse[i];
	}
	return bin;
}

string oct_bin(string oct){
	int current = 0;
	string reverse = "";
	string bin = "";
	for(int i = 0 ; i < oct.size();i++){
		current = oct[i] - 48;
		for(int c = 0 ; c < 3 ; c++){
			reverse +=  to_string(current%2);
			current /= 2;
		}
		for(int i = reverse.size()-1 ; i >= 0 ; i--){
			bin += reverse[i];
		}
		reverse = "";
	}
	return bin;
}

string bin_hex(string bin){
	int start = 4 - (bin.size()%4);
	string starting_zeros = "";
	string hex = "";
	int value = 0;
	for(int i = 0 ; i < start ; i++){
		starting_zeros += "0";
	}
	bin = starting_zeros + bin;
	for(int i = 0 ; i < bin.size() ; i++){
		value = 0;
		if(bin[i] == '1'){
			value += 8;
		}
		i++;
		if(bin[i] == '1'){
			value += 4;
		}
		i++;
		if(bin[i] == '1'){
			value += 2;
		}
		i++;
		if(bin[i] == '1'){
			value += 1;
		}
		hex += int_hex(value);
	}
	return hex;
}

string bin_oct(string bin){
	int start = 3 - (bin.size()%3);
	string starting_zeros = "";
	string oct = "";
	int value = 0;
	for(int i = 0 ; i < start ; i++){
		starting_zeros += "0";
	}
	bin = starting_zeros + bin;
	for(int i = 0 ; i < bin.size() ; i++){
		value = 0;
		if(bin[i] == '1'){
			value += 4;
		}
		i++;
		if(bin[i] == '1'){
			value += 2;
		}
		i++;
		if(bin[i] == '1'){
			value += 1;
		}
		oct += to_string(value);
	}
	return oct;
}

int bin_dec(string bin){
	// long dec = 0;
	int dec = 0;
	for(int i = 0 ; i < bin.size() ; i++){
		if(bin[i] == '1'){
			dec += pow(2 , (bin.size() - 1 - i));
		}
	}
	return dec;
}

void printValues(string binary){
	cout<<"\n Binary : "<<binary;
	cout<<"\n Octal : "<<bin_oct(binary);
	cout<<"\n Base 10 : "<<bin_dec(binary);
	cout<<"\n Hexadecimal : "<<bin_hex(binary);
}

int main(){
	string inp;
	string binary = "";
	cout<<"Please enter any binary , octal , base 10 , or hexadecimal number!\n"<<
	"We do not accept signed values!\n";
	cout<<"Beware if you enter a value too large the base 10 conversion may overflow!\n";
	cin>>inp;
	if(validate(inp)){
		if(findType(inp) == "BinOctDecHex"){
			binary = hex_bin(inp);
			printValues(binary);
			cout<<"\n\n";
			binary = dec_bin(inp);
			printValues(binary);
			cout<<"\n\n";
			binary = oct_bin(inp);
			printValues(binary);
			cout<<"\n\n";
			printValues(inp);
			cout<<"\n\n";
		}
		if(findType(inp) == "OctDecHex"){
			binary = hex_bin(inp);
			printValues(binary);
			cout<<"\n\n";
			binary = dec_bin(inp);
			printValues(binary);
			cout<<"\n\n";
			binary = oct_bin(inp);
			printValues(binary);
			cout<<"\n\n";
		}
		if(findType(inp) == "DecHex"){
			binary = hex_bin(inp);
			printValues(binary);
			cout<<"\n\n";
			binary = dec_bin(inp);
			printValues(binary);
			cout<<"\n\n";
		}
		if(findType(inp) == "Hex"){
			binary = hex_bin(inp);
			printValues(binary);
			cout<<"\n\n";
		}
		
	} else{
		cout<<"\nERROR.You just entered an invalid or signed value! Good bye!";
	}
	cout<<endl;
	return 0;
}

