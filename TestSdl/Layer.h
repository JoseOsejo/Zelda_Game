#ifndef LAYER_H
#define LAYER_H

class Layer
{
	public:
		//a diferncia del proyecto de mohamend es que las iniciales son minisculas 
		virtual void Render() = 0;//THIS IS FOR RENDERING THE LAYER 
		virtual void Update() = 0;//THIS IS FOR UPDATING THE LAYER
		

};
#endif
