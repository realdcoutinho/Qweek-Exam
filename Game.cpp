#include "pch.h"
#include "Game.h"
#include <iostream>
//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	PrintLetters();

}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here

	DrawEllipse();
}

void Update(float elapsedSec)
{

	UpdateElipse();



	/*
	if ((g_InitialRadius < g_Maxradius) && (isGrowing == false))  {
		++g_InitialRadius;
		isGrowing = true ;
		if (g_InitialRadius == g_Maxradius) {
			isGrowing = false;
		}
	}
	else if (!(isGrowing)) {
		std::cout << "Is equal" << '\n';
		g_InitialRadius = g_InitialRadius - 1;
		isGrowing = false ;
	}
	*/


	// process input, do physics 

	// e.g. Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
}

void End()
{
	// free game resources here
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{
	switch (key)
	{ 
	case SDLK_UP:
		SpeedUp();
		break;
	case SDLK_DOWN:
		SpeedDown();
		break;
	}
}

void OnKeyUpEvent(SDL_Keycode key)
{
	//switch (key)
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
	{
		//std::cout << "Left mouse button released\n";
		Point2f mousePos{ float(e.x), float(g_WindowHeight - e.y) };
		g_MouseX = e.x;
		g_MouseY = (int(g_WindowHeight) - e.y);
		IsGrowing = true;
		IsWaiting = true;
		GenerateEllipse();
		//if (!(IsVisible)) {
			//GenerateEllipse();
			//IsVisible = true;
		//}
		std::cout << "Growing State!" << '\n';
		break;
	}
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
void PrintLetters() {

	int charPerLines{};

	std::cout << "How many characters would you like per line? \n";
	std::cout << "Please enter an integer: ";
	while (!(std::cin >> charPerLines) || (!(charPerLines <= 25)) || (!(charPerLines >= 1)))
	{
		std::cout << "You have not provided a valid number. Please provide an integer:  ";
		std::cin.clear(); //
		std::cin.ignore(123, '\n');
	}

	int minAscii{ 96 };
	int intialChar{1};
	int maxAscii{ 122 };

	for (minAscii; minAscii < maxAscii; minAscii) {

		++minAscii;
		std::cout << char(minAscii);
	}

	std::cout << '\n';
	std::cout << '\n';
	std::cout << '\n';
}

void GenerateEllipse() {

	g_Maxradius = float(rand() % 100 + 50);
	g_InitialRadius = 0;

	g_Origin = Point2f(float(g_MouseX), float(g_MouseY));

	float red{ float(rand() % 255 + 1) / 255.0f };
	float green{ float(rand() % 255 + 1) / 255.0f };
	float blue{ float(rand() % 255 + 1) / 255.0f };

	g_ColorEllipse = Color4f(red, green, blue, 1);

	std::cout << "The maximum radius is: " << g_Maxradius << '\n';
}

void DrawEllipse(){



	SetColor(g_ColorEllipse);
	FillEllipse(g_Origin, g_InitialRadius, g_InitialRadius);
}


void UpdateElipse() {

	if ((g_InitialRadius < g_Maxradius) && (IsGrowing) && (IsWaiting)) {
		g_InitialRadius = g_InitialRadius + g_Speed;
		if (g_InitialRadius >= g_Maxradius) {
			IsGrowing = false;
			IsShrinking = true;
{
				std::cout << "Shrinking State!" << '\n';
			}
		}

	}
	if (!(IsGrowing) && (IsShrinking)) {
		g_InitialRadius = g_InitialRadius - g_Speed;
		if (g_InitialRadius <= 0) {
			g_InitialRadius = 0;
			IsWaiting = false;
			IsShrinking = false;

			//IsVisible = false;
		}

	}

	if ((g_MouseX - g_InitialRadius <= 0) && (IsGrowing)) {
		std::cout << "Ouch!" << '\n';
		std::cout << "Shrinking State!" << '\n';
		g_ColorEllipse = g_Warining;
		IsGrowing = false;
		IsShrinking = true;
		if (!(IsGrowing) && (IsShrinking)) {
			g_InitialRadius = g_InitialRadius - g_Speed;
			if (g_InitialRadius <= 0) {
				g_InitialRadius = 0;
				IsWaiting = false;
				IsShrinking = false;
			}
		}

	}
	if ((g_MouseX + g_InitialRadius >= g_WindowWidth) && (IsGrowing)) {
		std::cout << "Ouch!" << '\n';
		std::cout << "Shrinking State!" << '\n';
		g_ColorEllipse = g_Warining;
		IsGrowing = false;
		IsShrinking = true;
		if (!(IsGrowing) && (IsShrinking)) {
			g_InitialRadius = g_InitialRadius - g_Speed;
			if (g_InitialRadius <= 0) {
				g_InitialRadius = 0;
				IsWaiting = false;
				IsShrinking = false;
			}
		}
	}
	if ((g_MouseY - g_InitialRadius <= 0) && (IsGrowing)) {
		std::cout << "Ouch!" << '\n';
		std::cout << "Shrinking State!" << '\n';
		g_ColorEllipse = g_Warining;
		IsGrowing = false;
		IsShrinking = true;
		if (!(IsGrowing) && (IsShrinking)) {
			g_InitialRadius = g_InitialRadius - g_Speed;
			if (g_InitialRadius <= 0) {
				g_InitialRadius = 0;
				IsWaiting = false;
				IsShrinking = false;
			}
		}
	}
	if ((g_MouseY + g_InitialRadius >= g_WindowHeight) && (IsGrowing)) {
		std::cout << "Ouch!" << '\n';
		std::cout << "Shrinking State!" << '\n';
		g_ColorEllipse = g_Warining;
		IsGrowing = false;
		IsShrinking = true;
			if (!(IsGrowing) && (IsShrinking)) {
		g_InitialRadius = g_InitialRadius - g_Speed;
		if (g_InitialRadius <= 0) {
			g_InitialRadius = 0;
			IsWaiting = false;
			IsShrinking = false;
		}
	}
	}

}

void SpeedUp() {

	if (g_Speed <= 5) {
		g_Speed = g_Speed + 0.4f;
		std::cout << "g_speed = " << g_Speed << '\n';
	}

}

void SpeedDown() {

	if (g_Speed >= 0.2f) {
		g_Speed = g_Speed - 0.4f;
		std::cout << "g_speed = " << g_Speed << '\n';
	}

}

#pragma endregion ownDefinitions