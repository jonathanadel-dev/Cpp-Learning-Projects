#include <iostream>
#include <string>
using namespace std;

class Log {
public:
	enum Level{LevelError, LevelWarning, LevelInfo};
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
class Player {
public:
	Player() {
		cout << "Player created" << endl;
	}
	~Player() {
		cout << "Player destroyed" << endl;
	}
};

void test() {
	Player p;
}

int main()
{

	//Log log;
	//log.SetLevel(Log::LevelError);
	//log.Info("Some important information");
	//log.Warning("Some important information");
	//log.Error("Some important information");

	//test();

	for (int i = 0; i < 5; i++) {
		for (int j = 5; j > i; j--) {
			cout << 5 - j + 1 << " ";
		}
		cout << endl;
	}

}