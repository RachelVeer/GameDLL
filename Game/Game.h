#pragma once

class SampleGame {
public:
    virtual void Init( void ) = 0;
};

extern SampleGame* game;

typedef struct {

	SampleGame* game;					// interface to run the game

} gameExport_t;

extern "C" {
    typedef gameExport_t* (*GetGameAPI_t)(void);
}