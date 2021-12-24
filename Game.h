#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Q42 - deMouraCoutinho, Diogo - 1DAE10E" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
int g_MouseX{};
int g_MouseY{};

float g_Maxradius{};
float g_InitialRadius{};

float g_Speed{ 0.2f };

Color4f g_ColorEllipse{};
Color4f g_Warining(1, 0, 0, 1);
Point2f g_Origin{};


bool IsGrowing{ false };
bool IsShrinking{ false };
bool IsWaiting{ true };

bool IsVisible{ false };

// Declare your own functions here
void PrintLetters();

void GenerateEllipse();
void DrawEllipse();
void SpeedUp();
void SpeedDown();

void UpdateElipse();
//void HitBorders();
#pragma endregion ownDeclarations

#pragma region gameFunctions											
void Start();
void Draw();
void Update(float elapsedSec);
void End();
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key);
void OnKeyUpEvent(SDL_Keycode key);
void OnMouseMotionEvent(const SDL_MouseMotionEvent& e);
void OnMouseDownEvent(const SDL_MouseButtonEvent& e);
void OnMouseUpEvent(const SDL_MouseButtonEvent& e);
#pragma endregion inputHandling
