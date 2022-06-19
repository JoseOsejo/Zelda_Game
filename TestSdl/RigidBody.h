
//ojo con la linea 51 esos parentesis en la suma no van pero los puse para evitar el error en la division
#include "Vector2D.h"

//Inicializar valores para nuestra clase por defecto se puede hacer asi:
#define UNI_Mass 1.0f
#define GRAVITY 9.8F

#define FORWARD 1
#define BACKWARD -1

#define UPWARD -1
#define DOWNWARD 1


//clase que servira para hacer las fisicas del juego y apicarselas a nuestro personaje como que se vea afectado por la gravedad
class RigidBody
{
	public:
		RigidBody() 
		{
			m_Mass = UNI_Mass;
			m_Gravity = GRAVITY;
		}
		//setter and getter 
		inline void SetMass(float mass) { m_Mass = mass; }//igualamos nuesta masa de fuera a esta
		inline void SetGravity(float gravity) { m_Gravity = gravity; }//igualamos la gravedad de fuera a esta

		
		//Force (funciones inline hacen nuestro codigo mas rapido a la hora de ejecutar)
		inline void ApplyForce(Vector2D F) { m_Force = F; }//aplicamos la fuerza a nuestro objeto
		
		//aply force on x and y
		inline void ApplyForceX(float Fx) { m_Force.X = Fx; }
		inline void ApplyForceY(float Fy) { m_Force.Y = Fy; }
		inline void UnsetForce() { m_Force = Vector2D(0, 0); }
		
		//Friction
		inline void ApplyFricction(Vector2D Fr) { m_Friction = Fr; }
		inline void UnsetFriction() { m_Friction = Vector2D(0, 0); }


		//Getters
		inline float GetMass() { return m_Mass; }
		inline Vector2D Position() { return m_Position; }
		inline Vector2D Velocity() { return m_Velocity; }
		inline Vector2D Acceleration() {return m_Acceleration; }
		
		

		
		//////////////////////////////////////////////////////////////////////////////////
		//Update method that help to calculate velocity and all that stuff
		void Update(float dt) 
		{
			//Aceleracion = fuerza por friccion por masa //F* Fr = m * a;
			m_Acceleration.X = (m_Force.X + m_Friction.X) / m_Mass;    ////aceleracion en x
			m_Acceleration.Y = m_Gravity + m_Force.Y/ m_Mass;  //aceleracion en y afectada por gravedad
			m_Velocity = m_Acceleration * dt; //velocidad = aceleracion * dt
			m_Position = m_Velocity * dt;
		}
			
	private:
		float m_Mass;//variables relacionadas a las fisicas del yogo
		float m_Gravity;

		Vector2D m_Force;//uso real de la clase vector para facilitar el proceso de las fisicas
		Vector2D m_Friction;//cuando camine en lodo va mas lento (ejeplo de friccion)
		
		Vector2D m_Position;
		Vector2D m_Velocity;
		Vector2D m_Acceleration;
};		


