#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  
	 float py = 0.0;
    float px = 0.0;
    float vy = 0.0;
    float vx = 0.0;
    
	VectorXd rmse(4);
	rmse << 0,0,0,0;

    // check the validity of the following inputs:
	//  * the estimation vector size should not be zero
	if( estimations.size() == 0 ) {
	    cout << "Error: estimations are zero size" << endl;
	    return rmse;
	}    
	//  * the estimation vector size should equal ground truth vector size
	// ... your code here
	if( estimations.size() != ground_truth.size() ) {
	    cout << "Error: estimations and ground_truths matrices are not same dimensions" << endl;
	    return rmse;
	}    

	//accumulate squared residuals
	for(int i=0; i < estimations.size(); ++i){
        // ... your code here
        
        //cout << estimations.at(i) << endl;
        
        VectorXd xe = estimations.at(i);
        VectorXd xt = ground_truth.at(i);
        
        px = px + pow(xe(0) - xt(0),2);
        py = py + pow(xe(1) - xt(1),2);
        vx = vx + pow(xe(2) - xt(2),2);
        vy = vy + pow(xe(3) - xt(3),2);
	
	}

	//calculate the mean
	// ... your code here
	px = px / estimations.size();
	py = py / estimations.size();
	vx = vx / estimations.size();
	vy = vy / estimations.size();

	//calculate the squared root
	// ... your code here
	rmse(0) = sqrt(px);
	rmse(1) = sqrt(py);
	rmse(2) = sqrt(vx);
	rmse(3) = sqrt(vy);
	

	//return the result
	return rmse;
}