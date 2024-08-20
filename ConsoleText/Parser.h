#pragma once
#include<string>



enum CommandType // 어떤 종류의 커맨드인지 구분하는 열거형(enum)
{
	CommandTypeNone,

	CommandTypeNorth, 
	CommandTypeSouth,
	CommandTypeWest,
	CommandTypeEast,

	CommandTypeQuit,
	CommnadTypeGet,
	CommandTypeInventory,
	CommandTypeHelp,
	CommandTypeInfo

	// 향 후 업데이트

};

// C++ string클래스
// TypeString string == "w" => CommandTypeNorth

class ConsoleTextCommand
{
private:

public:
	CommandType commandType;
	std::string Parameter;		// 직접 입력받을 문자 데이터 "w" => commandType의 commandTypeNorth

};

ConsoleTextCommand ParseCommand();