#pragma once

class Ex {
	private: float x;
	public:
		Ex(float x) : x(x) {}
		float getText() const {
			return x;
		}
};

class Bar {
	public:
		float y;
		Bar() {
			y = 0;
		}

		void set(float a) {
			if ((y + a) > 100) {
				throw Ex(a * y);
			}
			this->y = a;
		}
};