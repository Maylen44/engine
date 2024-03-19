#ifndef I_SENDER_H
#define I_SENDER_H

#include "Ireceiver.h"
#include <list>

class ISender
{
public:
	virtual ~ISender() = default;
	virtual void attach(IReceiver* receiver) = 0;
	virtual void detach(IReceiver* receiver) = 0;
	virtual void sendContent() = 0;
};
#endif //I_SENDER_H