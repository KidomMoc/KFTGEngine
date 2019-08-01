#include "EventManager.hpp"

namespace KFTG
{

void QuitGameListener::callback (void *param)
{
	setQuit ();
}

// EventManager

EventManager* EventManager::instance ()
{
	static EventManager _instance;
	return &_instance;
}

void EventManager::init ()
{
	for (u32 i = 0; i < EVENT_TYPE_NUM; ++i)
		_listenerCount[i] = 0;
}

void EventManager::exit ()
{
}

void EventManager::registerEvent (enum Event eventType, EventListener *listener)
{
	if (_listenerCount[eventType] < EVENT_NUM)
	{
		_listeners[eventType][_listenerCount[eventType]] = listener;
		++_listenerCount[eventType];
	}
}

void EventManager::unregisterEvent (enum Event eventType, EventListener *listener)
{
	for (u32 i = 0; i < _listenerCount[eventType]; ++i)
		if (_listeners[eventType][i] == listener)
		{
			_listeners[eventType][i] =
				_listeners[eventType][_listenerCount[eventType - 1]];
			--_listenerCount[eventType];
			return;
		}
}

void EventManager::fireEvent (enum Event eventType, void *param)
{
	for (EventListener *el : _listeners[eventType])
		el->callback (param);
}

}