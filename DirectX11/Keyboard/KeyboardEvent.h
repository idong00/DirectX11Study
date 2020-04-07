#pragma once

// 키보드 이벤트
class KeyboardEvent {
public:
	enum EventType {
		PRESS,
		RELEASE,
		INVALID
	};

	KeyboardEvent();
	KeyboardEvent(const EventType type, const unsigned char key);
	bool IsPress() const;
	bool IsRelease() const;
	bool IsValid() const;
	unsigned char GetKeyCode() const;

private:
	EventType type;
	unsigned char key;
};
