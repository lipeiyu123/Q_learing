#ifndef __QLEARING_H__
#define __QLEARING_H__

#include <Eigen/Dense>

#define     Y           0
#define     N           -1
#define     END     100

class Qlearing{

                public:
                                                                        Qlearing(double ga ,double lr ,double eps);
                                Eigen::MatrixXi         init_R();
                                Eigen::MatrixXd        init_Q();
                                Eigen::VectorXi         init_action();
                                double                          gamma;
                                double                          learing_rate;
                                double                          epsilon;
                                int                                   choose_state();
                                Eigen::VectorXi          take_action( Eigen::MatrixXi state_transfer , int state);
                                double                          maxQ(Eigen::MatrixXd Q , int state);
                                Eigen::MatrixXd         useQ(Eigen::MatrixXd Q , int state);
                                double                          learn(int state , int action ,  int state_ ,
                                                                                     Eigen::MatrixXd Q , 
                                                                                     Eigen::MatrixXi R      );
                                //Q(state , action_nextstete(0)) = Q(state , action_nextstete(0)) +  lr*(  R(state , action_nextstete(0)) + q.gamma * q.maxQ(Q , action_nextstete(1))  -  Q(state , action_nextstete(0)) );

};



#endif