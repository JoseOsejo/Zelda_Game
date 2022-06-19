#ifndef IOBJECT_h
#define IOBJECT_h
class IObject
{
	virtual void Draw() = 0;
	virtual void Update(float dt) = 0;
	virtual void Clean()=0;


	
};
#endif
