#include"Windows.h"
#include <iostream>
#include<consoleapi2.h>
#include<tchar.h>
#include<string>
#include<strsafe.h>
#include<conio.h>
#include<stdio.h>

#include"Parser.h"
#include"GameCore.h"


int main()
{
    // 콘솔 크기 설정
    TCHAR buf[256];     // 키보드 자판을 모두 대응하는 크기
    StringCchPrintf(buf, 256, TEXT("%s 콘솔 텍스트 게임 버전 %f"), _T("이동윤"), 1.00f);
    SetConsoleTitleW(buf);
    // 1. 메인 메뉴 : 게임 시작(데이터의 초기화 진행 : 맵 생성(크기), 맵 종류가 다양하다면(시작 맵))
    // 플레이어의 시작 : 위치, 아이템, 소지금, ....
    Playerstate player;
    WorldState world;
    InitializeGame(player, world);
    // namespace ConsoleText GamePlay 클래스 -> 플레이어의 입력을 변환해주는 클래스, 플레이 함수 구현하는 클래스



    while (1)
    {
        ParseCommand();     // 플레이어의 x, y좌표를 이동
        // 플레이어 입력
        // Rendering : 이미지(맵)를 그려주는 것
        // Update : 특정 위치에 도착하면 다음 맵으로 이동. 플레이어의 위치, 특정 장소의 위치 같은지 아닌지
         
        // Quit : 게임 종료 기능 함수. Bool Quit -> true -> break Exit(0);
    }

    // 데이터 기록

}

