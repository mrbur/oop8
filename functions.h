#pragma once

using namespace std;

class DivisionByZero {
	private:
		string exceptionText;
	public:
		DivisionByZero(string text) : exceptionText(text) {}

		string getExceptionText() const {
			return exceptionText;
		}
};
template <typename N> N divNumbers(N divisor, N divident) {
	if (divident == 0) {
		throw DivisionByZero("divident is null");
	}
	return divisor / divident;
}