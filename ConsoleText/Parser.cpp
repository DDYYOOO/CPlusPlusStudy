#include "Parser.h"
#include<vector>    // �����迭(ũ�� ������ ������ �迭)


ConsoleTextCommand ParseCommand()
{
    ConsoleTextCommand command = {};
    command.commandType = CommandTypeNone;

    const unsigned int INPUTCHARLIMIT = 256; // ����� �ִ� ũ�� ����
    char inputstr[INPUTCHARLIMIT];

    char* inputValue = fgets(inputstr, INPUTCHARLIMIT, stdin); 

    // strtoken : ���ڿ��� seperator(������)
    std::vector<std::string> tokens;
    char* nextToken = nullptr;
    char* token = strtok_s(inputstr, "\t\n", &nextToken);

    while (token)
    {
        tokens.push_back(token);
        token = strtok_s(nullptr, "\t\n", &nextToken);
    }

    // north south

    if (tokens.size() >= 1) // �Է��� ���� ���
    {
        std::string parseData = tokens[0];

        // ���� -> ��ҹ���
        for (unsigned int i = 0; i < parseData.size(); i++)
        {
            parseData[i] = towlower(parseData[i]);
        }

        if (parseData == "w" || parseData == "north" || parseData == "up")
        {
            command.commandType = CommandTypeNorth;
        }

        if (parseData == "s" || parseData == "south" || parseData == "down")
        {
            command.commandType = CommandTypeSouth;
        }

        if (parseData == "a" || parseData == "east" || parseData == "left")
        {
            command.commandType = CommandTypeEast;      
        }

        if (parseData == "d" || parseData == "west" || parseData == "right")
        {
            command.commandType = CommandTypeWest; 
        }

    }



    return command;
}
