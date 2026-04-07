#pragma once
#include <iostream>
using namespace std;

class Entity {
public:
	float x, y;
	void Move(float dx, float dy) {
		x += dx;
		y += dy;
	}
	virtual void PrintName() {
		cout << "Entity" << endl;
	}
};
class Player : public Entity {
public:
	string name;

	void PrintName() override {
		cout << "Player";
	}
};
class Log {
public:
	enum Level { LevelError, LevelWarning, LevelInfo };
private:
	Level m_LogLevel = LevelInfo;
public:
	void SetLevel(Level level) {
		m_LogLevel = level;
	}
	void Info(const char* message) {
		if (m_LogLevel >= LevelInfo)
			cout << "[INFO]: " << message << endl;
	}
	void Warning(const char* message) {
		if (m_LogLevel >= LevelWarning)
			cout << "[WARNING]: " << message << endl;
	}
	void Error(const char* message) {
		if (m_LogLevel >= LevelError)
			cout << "[ERROR]: " << message << endl;
	}
};