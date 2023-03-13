#include <stdio.h>

int f(int x) {
	static int g;
	g = 2 * x;
	return g;
}

int main() {
	int a = 0;

	a = f(2);
	a = f(9);
}
