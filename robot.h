#pragma once
#include <string>

using namespace std;
class RobotException {
	private:
		string exception;
		int x, y;
	public:
		RobotException(string text, int x, int y) : exception(text), x(x), y(y) {
		}
		string getEx() const {
			return exception + ", x=" + to_string(x) + ", y=" + to_string(y);
		}
};
class OffTheField : public RobotException {
	public:
		OffTheField(int x, int y) : RobotException("robot is off the field", x, y) {
		}
};

class IllegalCommand : public RobotException {
	public:
		IllegalCommand(int x, int y) : RobotException("Wrong vector", x, y) {
		}
};

class Robot {
	private:
		int x;
		int y;
	public:
		Robot() : x(1), y(1) {
		}
		void move(int xVector, int yVector) {
			if ((xVector > 1 || xVector < -1) || (yVector > 1 || yVector < -1)) {
				throw IllegalCommand(x, y);
			}
			if ((x + xVector) > 10 || ((x + xVector) < 0) || ((y + yVector) > 10) || ((y + yVector) < 0)) {
				throw OffTheField(x, y);
			}
			x += xVector;
			y += yVector;
		}
		int getX() const {
			return this->x;
		}
		int getY() const {
			return this->y;
		}
};