

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>


#define ENTER '\n' // cf) std::endl

// ClauText
#define ARRAY_QUEUE std::deque // chk?
#define VECTOR std::vector
int log_result = 0;
#include <wiz/ClauText.h>
// ~ClauText

inline bool Check(const std::string& check_str, wiz::load_data::UserType* pClautextUT)
{
	if ("%int" == check_str) {

	}
	else if ("%float" == check_str) {

	}
	else if ("%string" == check_str) {

	}
	else if ("%id" == check_str) {

	}
	else if ("%any" == check_str) {

	}
	else if ("%optional" == check_str) {

	}
	else if (wiz::String::startsWith(check_str, "%event_")) {
		// std::string event_name = wiz::String::substring(check_str, 7);
	}
	// dateA,B,C ?
	
	std::cout << "it is not valid option?" << ENTER;
	return false;
}

bool Check(const wiz::load_data::UserType* schemaUT, wiz::load_data::UserType* pClautextUT)
{
	// GetName()?
}

inline bool _Validate(wiz::load_data::UserType& schemaUT, wiz::load_data::UserType& clautextUT)
{
	// 1. $로 시작하는 것들을 따로 분리해서 별도의 UserType에 저장한다.
		// 1-1. $Event -> 따로 뽑아낸 다음 Event로 rename?
		// 1-2. $변수들 -> 따로 뽑아낸 다음 변수들로 rename?
	// 2. $로 시작하지는 않는 것들은 data check 내용이다?
		// 2-1. %로 시작하는 것을 찾아서 각각 수행한다. 

	return true;
}

inline bool Validate(const std::string& schema, const std::string& clautext)
{
	wiz::load_data::UserType schemaUT;
	wiz::load_data::UserType clautextUT;

	// make LoadDataFromString2 ? - using Parallel Parsing?
	if (wiz::load_data::LoadData::LoadDataFromString(schema, schemaUT)) {
		//
	}
	else {
		std::cout << "schema is not valid!" << ENTER;
		return false;
	}
	if (wiz::load_data::LoadData::LoadDataFromString(clautext, clautextUT)) {
		//
	}
	else {
		std::cout << "clautext is not valid!" << ENTER;
		return false;
	}

	return _Validate(schemaUT, clautextUT);
}


// to do
std::pair<bool, std::string> MakeSchema(const std::string& clautext)
{
	// to do
}


std::pair<bool, std::string> LoadFile(const std::string& fileName)
{
	
}
bool SaveFile(const std::string& fileName, const std::string& data)
{

}


// todo - add file open, close.
int main(int argc, char* argv[])
{
	std::string option;
	std::string schema;
	std::string clautext;
	std::string fileName; // to save

	// -v : version?
	// -V : Validate.
	// -m : make schema.
	if (argc == 1 // default is -V, Validate!
		|| (argc == 4 && 0 == strcmp("-V", argv[1]))) {
		option = "-V";

		auto chk_schema = LoadFile(argv[2]);
		auto chk_clautext = LoadFile(argv[3]);
		
		if (chk_schema.first) {
			schema = chk_schema.second;
		}
		else {
			std::cout << "schema load fail" << ENTER;
			return 1;
		}
		if (chk_clautext.first) {
			clautext = chk_clautext.second;
		}
		else {
			std::cout << "clautext load fail" << ENTER;
			return 2;
		}
	}
	else if (argc == 4 && 0 == strcmp("-m", argv[1])) {
		option = "-m";

		auto chk_clautext = LoadFile(argv[2]);

		if (chk_clautext.first) {
			clautext = chk_clautext.second;
		}
		else {
			std::cout << "clautext load fail" << ENTER;
			return 3;
		}
		fileName = argv[3];
	}

	if (option == "-V") {
		auto chk = Validate(schema, clautext);
		if (chk) {
			std::cout << "success" << ENTER;;
		}
		else {
			std::cout << "fail" << ENTER;;
		}
	}
	else if (option == "-m") {
		auto chk = MakeSchema(clautext);
		if (chk.first) {
			schema = chk.second;

			if (SaveFile(fileName, schema)) {

			}
			else {
				std::cout << "save fail" << ENTER;
				return 4;
			}
			
			std::cout << "success" << ENTER;
		}
		else {
			std::cout << "fail" << ENTER;
		}
	}
	else {
		std::cout << "it is not valid option";
	}

	return 0;
}


