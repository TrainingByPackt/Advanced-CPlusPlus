/*
 * LinearMotion1D.cpp
 *
 *  Created on: Aug 1, 2019
 *      Author: gazihan
 */

#include "LinearMotion1D.h"

void LinearMotion1D::advanceTimeBy(double dt) {
	position += velocity * dt;
}

LinearMotion1D::LinearMotion1D() {
	position = 0;
	velocity = 0;
}

LinearMotion1D::~LinearMotion1D() {
	// TODO Auto-generated destructor stub
}

