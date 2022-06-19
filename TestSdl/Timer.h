
//Esta clase gestiona los datos del tiempo por que existen muchas maneras de crear unas animaciones para un juego;
//existe una manera, las personas usan el frame rate que es cuantos frames tu computadora puede soportar por segundo;
//esto se le llama fps y es buena pero existen muchso problemas con eso por  que si yo agarro este progrtama por ejemplo que
//actualmente esta corriendo a 60 frames por segundo y se lo paso a alguien que tiene 30 frmaes por segundo el ratio no sera el mismo
//(el juego sera mas lento y asi) pero nosotros no queriamos eso, queriamos un programa que pudiera crrer de la misma forma donde sea
//ya sea 60 0 30 frames;osea que algo fuer mas estandar 

const int TARGET_FPS = 60;
const float  TARGET_DELTATIME = 1.5f;


class Timer
{
	public :
		void Tick();
		inline float GetDeltaTime() { return m_DeltaTime; }
		inline static Timer* GetInstance() { return s_Instance = (s_Instance != nullptr) ? s_Instance : new Timer(); }
		
	private:
		Timer() {}//lo hacemos privado por que no queremos hacer mas de dos instancias de esta clase por que solo queremos tener los datos del tiempo en una sola clase y que de ella vaya a todas las demas 
		static Timer* s_Instance;   //hacemos statica esta clase medienate una instancia 
		float m_DeltaTime;
		float m_LastTime;

};

