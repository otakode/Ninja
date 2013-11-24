#ifndef __CONTROLSMANAGER_H__
#define __CONTROLSMANAGER_H__

class ControlsManager;

#include "Manager.h"
#include <map>
#include "Controller.h"
#include <SDL/SDL.h>

class ControlsManager : public Manager
{
public:
	// TODO Custom Input handle
/*	enum Keyboard
	{
		KEYBOARD_UNKNOWN,
		ESCAPE, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, PRINT_SCREEN, SCROLL_LOCK, PAUSE,

		TILDE, EXCLAMATION, AT, HASH, DOLLAR, PERCENT, CARET, AMPERSAND, ASTERISK, LEFT_PARENTHESIS, RIGHT_PARENTHESIS, UNDERSCORE, PLUS,
		BACKQUOTE, NUM_0, NUM_1, NUM_2, NUM_3, NUM_4, NUM_5, NUM_6, NUM_7, NUM_8, NUM_9, MINUS, EQUAL, BACKSPACE,
		TAB, Q, W, E, R, T, Y, U, I, O, P, LEFT_BRACKET, LEFT_BRACE, RIGHT_BRACKET, RIGHT_BRACE, BACKSLASH, PIPE,
		CAPS_LOCK, A, S, D, F, G, H, J, K, L, SEMI_COLON, COLON, QUOTE, DOUBLE_QUOTE, RETURN, 
		LEFT_SHIFT, Z, X, C, V, B, N, M, COMMA, LESS, PERIOD, GREATER, SLASH, QUESTION, RIGHT_SHIFT,
		LEFT_CONTROL, LEFT_SUPER, ALT, SPACE, ALT_GR, RIGHT_SUPER, MENU, RIGHT_CONTROL,

		INSERT, HOME, PAGE_UP,
		DELETE, END, PAGE_DOWN,

		LEFT, UP, DOWN, RIGHT,

		NUMLOCK, PAD_SLASH, PAD_ASTERISK, PAD_MINUS,
		PAD_7, PAD_HOME, PAD_8, PAD_UP, PAD_9, PAD_PAGE_UP, PAD_PLUS,
		PAD_4, PAD_LEFT, PAD_5, PAD_CLEAR, PAD_6, PAD_RIGHT,
		PAD_1, PAD_END, PAD_2, PAD_DOWN, PAD_3, PAD_PAGE_DOWN, PAD_RETURN,
		PAD_0, PAD_INSERT, PAD_PERIOD, PAD_DELETE

	};
	enum Mouse
	{
		MOUSE_UNKNOWN,
		LEFT_BUTTON, WHEEL_LEFT, WHEEL_UP, WHEEL_BUTTON, WHEEL_DOWN, WHEEL_RIGHT, RIGHT_BUTTON,
		FORWARD, BACK
	};
	enum Joystick
	{
		JOYSTICK_UNKNOWN
	};*/

protected:
	std::multimap<SDLKey, Controller*> _registry;

public:
	ControlsManager();
	virtual ~ControlsManager();

	virtual bool Routine();

	void RegisterToKey(Controller* controller, SDLKey key);
	void UnRegisterToKey(Controller* controller, SDLKey key);
}; // ControlsManager

#endif // __CONTROLSMANAGER_H__