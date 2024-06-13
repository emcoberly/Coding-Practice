#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <iomanip>

#include "Math.h"
#include "Combination.cpp"
#include "Factorial.cpp"

int main(){

    srand(time(0));
    std::vector<int> trials(0);
    int trial_num = 0;

    while (trial_num < 100000) {
        bool first_try = false;
        long double expected_trial = 0;
        int measured_trial = 0;
        std::vector<int> my_vec(10);

        while (first_try == false) {
            my_vec = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
            int temp_trial = 0;

            int randex = 0;
            int success = 0;

            while (success < 10) {
                randex = rand() % 10;
                if (my_vec.at(randex) == 0) {
                    my_vec.at(randex) = randex + 1;
                    success++;
                }
                temp_trial++;
            }

            measured_trial++;

            if (temp_trial == 10) {
                first_try = true;
            }
        }

        double measured_prob = 1.0 / measured_trial;

        trial_num++;
        trials.push_back(measured_trial);
    }

    // for (int j = 0; j < my_vec.size(); j++) {
    //     std::cout << my_vec.at(j) << " ";
    // } std::cout << std::endl;
    // std::cout << "Expected trials:\t" << expected_trial << std::endl;
    // std::cout << "Number of trials:\t" << measured_trial << std::endl;
    // std::cout << "Expected prob:\t\t" << expected_prob << std::endl;
    // std::cout << "Measured prob:\t\t" << measured_prob << std::endl;

    int trial_sum = 0;
    double trial_average = 0.0;
    int first_try = 0, meets_2755 = 0, meets_2756 = 0;
    for (int i = 0; i < 100000; i++) {
        trial_sum += trials.at(i);
        if (trials.at(i) == 1) {
            first_try++;
        } else if (trials.at(i) == 2755) {
            meets_2755++;
        } else if (trials.at(i) == 2756) {
            meets_2756++;
        } else if (trials.at(i) >= 34943) {
            std::cout << trials.at(i) << std::endl;
        }
    }
    trial_average = trial_sum / 100000.0;

    std::cout << "First tries:      " << first_try << std::endl;
    std::cout << "Average down:     " << meets_2755 << std::endl;
    std::cout << "Average up:       " << meets_2756 << std::endl;
    std::cout << "Average trials:   " << std::fixed << std::setprecision(10) << trial_average << std::endl;

    return 0;

// SHORTER VERSION
    // srand(time(0));
    // std::vector<int> my_vec = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    // double success_prob = 1;
    // for (int i = 1; i <= 10; i++) {
    //     success_prob *= (1.0 / i);
    // }

    // int randex = 0;
    // int success = 0, measured_trial = 0;

    // while (success < 10) {
    //     randex = rand() % 10;
    //     if (my_vec.at(randex) == 0) {
    //         my_vec.at(randex) = randex + 1;
    //         success++;
    //     }
    //     trial++;
    // }

    // double measured_prob = static_cast<double>(success) / static_cast<double>(trial);

    // for (int j = 0; j < my_vec.size(); j++) {
    //     std::cout << my_vec.at(j) << " ";
    // } std::cout << std::endl;
    // std::cout << "Number of trials:\t" << measured_trial << std::endl;
    // std::cout << "Expected prob:\t\t" << success_prob << std::endl;
    // std::cout << "Measured prob:\t\t" << measured_prob << std::endl;

    // return 0;

}

// BEST:        1 (227)
// WORST:       34943

// HIGH ABOVE:  2803.2342
// BEST AVERAGE:2755.77
// LOW BELOW:   2702.53608

// 2755:        72
// 2756:        73

// SOLUTION:    10^10 / 10! = 2755.7319223985890652557319223985890652557319223985890652557319223 = 2756
