#include "../SampleLib/pch.h"
#include "Game_local.h"
#include <iostream>

static gameExport_t			gameExport;
MyGame gameLocal;
SampleGame* game = &gameLocal;

void MyGame::Init()
{
    printf("Hello World, from DLL!\n");
}

extern "C" gameExport_t * GetGameAPI()
{
    gameExport.game = game;
    return &gameExport;
}