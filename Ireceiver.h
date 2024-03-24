#ifndef I_RECEIVER_H
#define I_RECEIVER_H

#include "common_data.h"

class IReceiver
{
public:
	virtual ~IReceiver() = default;
	virtual void receiveContent(Scene scene) {};
	virtual void receiveContent(InputEvent event) {};
	virtual void receiveContent(sf::Event& event) {};
};
#endif //I_RECEIVER_H