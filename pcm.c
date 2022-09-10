#include <stdio.h>
#include <string.h>
#include <math.h>

float para[8] = { 0, 1.0 / 128, 1.0 / 64, 1.0 / 32, 1.0 / 16, 1.0 / 8, 1.0 / 4, 1.0 / 2 };
char code[8] = "00000000";

void main() {
	int V;
	float mag, mag_n, mag_a;
	int para_num = 7;

	printf("Please input a integer as the V:");
	scanf_s("%d", &V);

	printf("Please input a float as the Mag:");
	scanf_s("%f", &mag);

	// ¹éÒ»»¯
	mag_n = mag / V;

	if (mag_n > 0) {
		code[0] = '1';
	}

	mag_a = fabs(mag_n);

	for (int i = 1; i <= 7; i++) {
		if (mag_a < para[i]) {
			para_num = i - 1;
			break;
		}
	}

	if (para_num / 4) code[1] = '1';
	if (para_num % 4 / 2) code[2] = '1';
	if (para_num % 4 % 2) code[3] = '1';
	
	float delta, mag_d;
	if (para_num == 7) {
		delta = 1.0 / 32;
		mag_d = mag_a - 0.5;
	}
	else {
		delta = (para[para_num+1] - para[para_num])/16.0;
		mag_d = mag_a - para[para_num];
	}

	int i = 0;
	for (; i <= 15; i++) {
		if (mag_d < delta * (i+1)) {
			break;
		}
	}

	if (i / 8) code[4] = '1';
	if (i % 8 / 4) code[5] = '1';
	if (i % 8 % 4 / 2) code[6] = '1';
	if (i % 8 % 4 % 2) code[7] = '1';

	printf("PCM:");
	puts(code);
}