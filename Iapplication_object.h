#ifndef I_APPLICATION_OBJECT_H
#define I_APPLICATION_OBJECT_H

#include "common_data.h"

class IApplicationObject
{
public:
	virtual ~IApplicationObject() = default;
	virtual void update(const std::vector<InputEvent>& events) {};
	virtual void draw(sf::RenderWindow& window) {};
};

#endif //I_APPLICATION_OBJECT_H