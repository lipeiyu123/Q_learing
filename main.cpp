#include <iostream>
#include "q_learing/Qlearing.h"
#include "config.h"


int main(){

            Qlearing        q(0.8);
            int eps = 0;
            int state = 0;
            int next_state = 0;

            Eigen::MatrixXi R = q.init_R();
            Eigen::MatrixXd Q = q.init_Q();
            Eigen::VectorXi action_nextstete = Eigen::VectorXi::Zero(2);
            Eigen::VectorXd nextstate_vale = Eigen::VectorXd::Zero(2);

#if     DEBUG
            std::cout << "R:\n"<< R << std::endl;
            std::cout << "Q:\n"<< Q << std::endl;
#endif

            while(eps < MAX_EPS){

                        state = q.choose_state();
                        while(state !=  5){

                                    action_nextstete = q.take_action(R , state);
                                    Q(state , action_nextstete(0)) = R(state , action_nextstete(0)) + q.gamma * q.maxQ(Q , action_nextstete(1));
                                    state = action_nextstete(1);
                        }
                        eps++;
            }


            std::cout <<"finish Q:\n" << Q << std::endl;


            eps = 0;
            while(eps < EVAL_EPS){
                        state = q.choose_state();
                        std::cout << "start 初始状态  "<< state << std::endl;
                        while(state != 5){
                                    std::cout << "当前状态  "<< state << std::endl;
                                    nextstate_vale = q.useQ(Q , state);
                                    state = nextstate_vale(0);
                                    std::cout << "下个状态  "<< state << std::endl;
                        }
                        eps++;

            }


            return 0;
}