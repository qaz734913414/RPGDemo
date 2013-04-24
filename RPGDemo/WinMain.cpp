#include "stdafx.h"
#include <hge.h>
#include "control\GameControler.h"

#pragma comment(lib, "hge.lib")
#pragma comment(lib, "hgehelp.lib")

HGE* hge = NULL;
GameControler* game;

SceneEngine* SceneEngine_ = NULL;

bool Update()
{
    return game->Update();
}

bool Render()
{
    return game->Render();
}


int WINAPI WinMain(          HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow
)
{
    hge = hgeCreate(HGE_VERSION);
    
    hge->System_SetState(HGE_FRAMEFUNC, Update);
    hge->System_SetState(HGE_RENDERFUNC, Render);
    hge->System_SetState(HGE_FPS, 60);
    hge->System_SetState(HGE_TITLE, "RPG Demo");
    hge->System_SetState(HGE_SHOWSPLASH, false); //不显示HGE的LOGO
    hge->System_SetState(HGE_WINDOWED, true); 

    if (hge->System_Initiate())
    {
        game = GameControler::Instance();
        game->Start();
        hge->System_Start();
        hge->System_Shutdown();
    }
    else
    {
        MessageBox(NULL, "创建窗口失败", NULL, MB_OK);
    }

    return 0;
}