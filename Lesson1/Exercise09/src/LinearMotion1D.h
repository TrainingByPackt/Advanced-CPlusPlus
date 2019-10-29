/*
 * LinearMotion1D.h
 *
 *  Created on: Aug 1, 2019
 *      Author: gazihan
 */

#ifndef SRC_LINEARMOTION1D_H_
#define SRC_LINEARMOTION1D_H_

class LinearMotion1D {
public:
	double position;
	double velocity;
	void advanceTimeBy(double dt);
	LinearMotion1D();
	virtual ~LinearMotion1D();
};

#endif /* SRC_LINEARMOTION1D_H_ */
