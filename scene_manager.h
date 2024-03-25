#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "Isender.h"
#include "common_data.h"

class SceneManager : public ISender
{
public:
	SceneManager(Scene startScene);
	virtual ~SceneManager() {};

	//SR methods
	void attach(IReceiver* receiver) override { m_listReceivers.push_back(receiver); };
	void detach(IReceiver* receiver) override { m_listReceivers.remove(receiver); };
	void sendContent() override { for (auto& receiver : m_listReceivers) { receiver->receiveContent(m_currentScene); } };

	//Class methods
	bool getScene(Scene scene) const;
	void setScene(Scene scene) noexcept;

private:
	Scene m_currentScene;
	std::list<IReceiver*> m_listReceivers;

};
#endif //SCENE_MANAGER_H