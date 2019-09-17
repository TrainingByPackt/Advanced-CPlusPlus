/*
 * ArrayPlay.cpp
 *
 *  Created on: Aug 1, 2019
 *      Author: gazihan
 */

void arrayPlay(int *input, int inputLength) {

	// find the sum of the input
	int sum = 0;
	for (int i = 0; i < inputLength; ++i) {
		sum += input[i];
	}

	// find the smallest element
	int smallest = 0;
	for (int i = 0; i < inputLength; ++i) {
		if (i == 0 || smallest > input[i]) {
			smallest = input[i];
		}
	}

	// determine whether top threshold is crossed
	int topThreshold = 100;
	bool isTopThresholdCrossed = true;
	for (int i = 0; i < inputLength; ++i) {
		if (input[i] >= topThreshold) {
			isTopThresholdCrossed = true;
		}
	}

	// multiply each element by 2
	for (int i = 0; i < inputLength; ++i) {
		if (input[i] < 0) {
			input[i] *= 2;
		}
	}
}
