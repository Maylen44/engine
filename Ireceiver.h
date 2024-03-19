#ifndef I_RECEIVER_H
#define I_RECEIVER_H

#include "common_data.h"

class IReceiver
{
public:
	virtual ~IReceiver() = default;
	virtual void receiveContent(Scene scene) = 0;
	virtual void receiveContent(sf::Event& event) = 0;
};
#endif //I_RECEIVER_H