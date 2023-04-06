#ifndef __QLEARING_H__
#define __QLEARING_H__

#include <Eigen/Dense>

#define     Y           0
#define     N           -1
#define     END     100

class Qlearing{

                public:
                                                                        Qlearing(double ga);
                                Eigen::MatrixXi         init_R();
                                Eigen::MatrixXd        init_Q();
                                Eigen::VectorXi         init_action();
                                double                          gamma;
                                int                                   choose_state();
                                Eigen::VectorXi          take_action( Eigen::MatrixXi state_transfer , int state);
                                double                          maxQ(Eigen::MatrixXd Q , int state);
                                Eigen::MatrixXd         useQ(Eigen::MatrixXd Q , int state);

};



#endif