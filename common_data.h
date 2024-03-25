#ifndef COMMON_DATA_H
#define COMMON_DATA_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

enum Scene
{
	Scene_Initialization,
	Scene_MainMenu,
	Scene_SettingsMenu,
	Scene_Game,
	Scene_MAX
};

enum InputEvent
{
	InputEvent_NoInput,
	InputEvent_W,
	InputEvent_Up,
	InputEvent_S,
	InputEvent_Down,
	InputEvent_A,
	InputEvent_Left,
	InputEvent_D,
	InputEvent_Right,
	InputEvent_ESC,
	InputEvent_CloseApplication,
	InputEvent_Restart,
	InputEvent_MouseLeft,
	InputEvent_MouseRight,
	InputEvent_MAX
};

#endif //COMMON_DATA_H