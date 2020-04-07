#include "KeyboardEvent.h"

KeyboardEvent::KeyboardEvent() :
	type(EventType::INVALID),
	key(0u)
{
}

KeyboardEvent::KeyboardEvent(const EventType type, const unsigned char key) :
	type(type),
	key(key)
{
}

bool KeyboardEvent::IsPress() const
{
	return this->type == EventType::PRESS;
}

bool KeyboardEvent::IsRelease() const
{
	return this->type == EventType::RELEASE;
}

bool KeyboardEvent::IsValid() const
{
	return this->type != EventType::INVALID;
}

unsigned char KeyboardEvent::GetKeyCode() const
{
	return this->key;
}
