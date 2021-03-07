#include <Windows.h>
#include <iostream>
// have to include pch here 
#include "../SampleLib/pch.h"

SampleGame* game = NULL;

int main()
{
    HINSTANCE hinstLib;
    gameExport_t	gameExport;
    GetGameAPI_t	GetGameAPI;

    hinstLib = LoadLibrary(TEXT("Game.dll"));
    GetGameAPI = (GetGameAPI_t)GetProcAddress(hinstLib, "GetGameAPI");

    if (GetGameAPI == NULL)
    {
        printf("Error");
        return 1;
    }

    gameExport = *GetGameAPI();

    game = gameExport.game;

    game->Init();

    printf("Hello World from executable!");

    FreeLibrary(hinstLib);
    return 0;
}