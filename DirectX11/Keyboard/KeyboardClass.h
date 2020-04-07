#pragma once

#include "KeyboardEvent.h"
#include <queue>

class KeyboardClass {
public:
	KeyboardClass();
	bool KeyIsPressed(const unsigned char keycode);
	bool KeyBufferIsEmpty();  // 체크
	bool CharBufferIsEmpty(); // 체크
	KeyboardEvent ReadKey();  // 읽기
	unsigned char ReadChar(); // 읽기
	void OnKeyPressed(const unsigned char key);
	void OnKeyReleased(const unsigned char key);
	void OnChar(const unsigned char key); // 큐
	void EnableAutoRepeatKeys();
	void DisableAutoRepeatKeys();
	void EnableAutoRepeatChars();
	void DisableAutoRepeatChars();
	bool IsKeysAutoRepeat();
	bool IsCharsAutoRepeat();

private:
	bool autoRepeatKeys = false;
	bool autoRepeatChars = false;
	bool keyStates[256];
	std::queue<KeyboardEvent> keyBuffer;
	std::queue<unsigned char> charBuffer;
};