#include "Parser.h"
#include<vector>    // 가변배열(크기 변경이 가능한 배열)


ConsoleTextCommand ParseCommand()
{
    ConsoleTextCommand command = {};
    command.commandType = CommandTypeNone;

    const unsigned int INPUTCHARLIMIT = 256; // 상수로 최대 크기 제한
    char inputstr[INPUTCHARLIMIT];

    char* inputValue = fgets(inputstr, INPUTCHARLIMIT, stdin); 

    // strtoken : 문자열을 seperator(구분자)
    std::vector<std::string> tokens;
    char* nextToken = nullptr;
    char* token = strtok_s(inputstr, "\t\n", &nextToken);

    while (token)
    {
        tokens.push_back(token);
        token = strtok_s(nullptr, "\t\n", &nextToken);
    }

    // north south

    if (tokens.size() >= 1) // 입력을 받을 경우
    {
        std::string parseData = tokens[0];

        // 영어 -> 대소문자
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
