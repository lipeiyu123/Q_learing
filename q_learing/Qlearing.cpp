#include "Qlearing.h"
#include "../random/rand.h"

Qlearing::Qlearing(double ga = 0.8 , double lr = 0.9){
                
                gamma = ga;
                learing_rate = lr;
}



Eigen::MatrixXi      Qlearing::init_R(){

            Eigen::MatrixXi     R(6 , 6);
            R          <<      N , N , N , N , Y , N , 
                                    N , N , N , Y , N , END ,
                                    N , N , N , Y , N , N ,
                                    N , Y  , Y , N , Y ,  N ,
                                    Y ,  N , N , Y , N , END ,
                                    N ,  Y , N , N , Y , END;      
            return  R ;
}



Eigen::MatrixXd     Qlearing::init_Q(){

            Eigen::MatrixXd  Q = Eigen::MatrixXd::Zero(6,6);
            return Q;
}



Eigen::VectorXi     Qlearing::init_action(){

           Eigen::VectorXi action = Eigen::VectorXi::Zero(1,6);
           return action; 
}



int             Qlearing::choose_state(){

            return int_rand(0 , 5);
}


Eigen::VectorXi             Qlearing::take_action(const Eigen::MatrixXi state_transfer , int state){

            int action = 2;
            int action_num = 0;
            Eigen::VectorXi action_state = Eigen::VectorXi::Zero(2);
            Eigen::VectorXi all_action = Eigen::VectorXi::Zero(6);

            for(int i = 0 ; i < 6 ; i++){
                        action = state_transfer(state , i );
                        if ((action == Y) || (action == END)) {
                                    all_action(action_num) = i;
                                    action_num++;
                        }
            }
            action_state(0) = all_action( int_rand(0 , action_num) );
            action_state(1) = action_state(0);
            return action_state;
}



double          Qlearing::maxQ( const Eigen::MatrixXd Q , int state){

                double maxq = -65535.0;
                for(int i = 0 ; i  < 6 ; i++){
                            if (maxq < (Q(state,i) + double_rand(-5 , 5 ) ) ){
                                        maxq = Q(state,i);
                            }
                }
                return maxq;
}



Eigen::MatrixXd        Qlearing::useQ(const Eigen::MatrixXd Q , int state){

                Eigen::VectorXd nextstate_vale = Eigen::VectorXd::Zero(2);
                nextstate_vale(0) = 0;
                nextstate_vale(1) = -65535;
                for(int i = 0 ; i  < 6 ; i++){
                            if (nextstate_vale(1) < Q(state,i)){
                                        nextstate_vale(1) = Q(state,i);
                                        nextstate_vale(0) = i;
                            }
                }
                return nextstate_vale;               
}



double                         Qlearing::learn(int state , int action  , int state_ ,
                                                                        Eigen::MatrixXd Q , 
                                                                        Eigen::MatrixXi R      ){

                return      Q(state , action) +  learing_rate *(  R(state , action) + gamma * maxQ(Q , state_)  -  Q(state , action) );
}
