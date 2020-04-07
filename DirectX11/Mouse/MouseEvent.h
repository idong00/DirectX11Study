#pragma once

struct MousePoint
{
	int x;
	int y;
};

class MouseEvent
{
public:
	enum EventType
	{
		LPRESS,
		LRELEASE,
		RPRESS,
		RRELEASE,
		MPRESS,
		MRELEASE,
		WHEELUP,
		WHEELDOWN,
		MOVE,
		RAW_MOVE,
		INVALID
	};

private:
	EventType type;
	int x;
	int y;

public:
	MouseEvent();
	MouseEvent(const EventType type, const int x, const int y);
	bool IsValid() const;
	EventType GetType() const;
	MousePoint GetPos() const;
	int GetPosX() const;
	int GetPosY() const;
};