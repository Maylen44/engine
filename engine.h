#ifndef ENGINE_H
#define ENGINE_H

#include "Iapplication_object.h"
#include <list>

#define ENGINE Engine::instanceEngine();

class Engine
{
public:
	static Engine* instance();

	void addApplicationObject(IApplicationObject* object) { m_objects.push_back(object); };
	void removeApplicationObject(IApplicationObject* object) { m_objects.remove(object); };

	void update();
	void draw();
	void logOutsideMsg(const char* msg);

private:
	Engine() {};
	std::list<IApplicationObject*> m_objects;

};

#endif //ENGINE_H