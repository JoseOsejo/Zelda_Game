#include <SDL2/SDL.h>

class Input
{
	public:
		
		static Input* GetInstance()//get instance
		//verificamos si se creo una instancia de esta clase; si se dio pues se retorna la droga
		{
			return s_Instance = (s_Instance != nullptr) ? s_Instance : new Input();
		}
		
		void Listen();
		bool GetKeyDown(SDL_Scancode key);
		
		

	private:
		Input();
		void KeyUp();
		void KeyDown();


		const Uint8* m_KeyStates;//this array is gonna be storing the stage of the keyboard si se presiona la tecla el valor es 1 sino 0
		static Input* s_Instance;
		
};

