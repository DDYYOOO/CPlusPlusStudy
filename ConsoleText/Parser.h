#pragma once
#include<string>



enum CommandType // � ������ Ŀ�ǵ����� �����ϴ� ������(enum)
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

	// �� �� ������Ʈ

};

// C++ stringŬ����
// TypeString string == "w" => CommandTypeNorth

class ConsoleTextCommand
{
private:

public:
	CommandType commandType;
	std::string Parameter;		// ���� �Է¹��� ���� ������ "w" => commandType�� commandTypeNorth

};

ConsoleTextCommand ParseCommand();