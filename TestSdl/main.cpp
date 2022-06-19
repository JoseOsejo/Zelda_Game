#include "Engine.h"
#include "Timer.h"

//#include "_2Win.h"

using namespace std;

//make a main 
int main(int argc, char* args[])
{
	//start main loop :)
	Engine::GetInstance()->Init();
	
	while (Engine::GetInstance()->IsRunning())//as long as is running
	{
		Engine::GetInstance()->Events();
		Engine::GetInstance()->Update();//if at this moment of the game the player decides to run lets update that 
		Engine::GetInstance()->Render();//to show the game
		//Timer::GetInstance()->Tick();
	}
	Engine::GetInstance()->Clean();// if the player decies to get out of the game then we close the game


	//
	//return 0;

	////start main loop :)
	//_2Win::GetInstance()->Init();

	//while (_2Win::GetInstance()->IsRunning())//as long as is running
	//{
	//	_2Win::GetInstance()->Events();
	//	_2Win::GetInstance()->Update();//if at this moment of the game the player decides to run lets update that 
	//	_2Win::GetInstance()->Render();//to show the game
	//	//_2Win::GetInstance()->Tick();
	//}
	//_2Win::GetInstance()->Clean();// if the player decies to get out of the game then we close the game



	return 0;
}
