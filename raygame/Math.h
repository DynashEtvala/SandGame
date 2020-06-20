#pragma once


float Abs(float a) {
	return a < 0 ? a * -1 : a;
}

int Abs(int a) {
	return a < 0 ? a * -1 : a;
}

double Abs(double a) {
	return a < 0 ? a * -1 : a;
}