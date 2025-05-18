// Copyright (c) 2024 Jayden Smith All rights reserved.
// Created By: Jayden Smith
// Date: May 16, 2025
// This code calculates the user's interest

#include <iostream>
#include <string>

int interest_calc(float p, float r, std::string t, float amt_of_t) {
    float interest;
    if (t == "years") {
        interest = p * r * amt_of_t * 0.01;
    } else if (t == "months") {
        interest = p * r * (amt_of_t / 12) * 0.01;
    } else {
        interest = p * r * (amt_of_t / 365) * 0.01;
    }
    return (interest);
}

int main() {
    // Define my variables
    std::string principal;
    std::string rate;
    std::string time;
    std::string timeSince;
    float principalFloat;
    float rateFloat;
    float timeSinceFloat;
    float interest;

    // Great user
    std::cout
        << "Welcome to Jayden's interest calculator! \n";

    // Make sure that if error in try catch it loops back
    while (true) {
        // Get user input
        std::cout << "What is your starting amount: ";
        std::cin >> principal;
        std::cout << "What is the rate (%): ";
        std::cin >> rate;
        std::cout << "Please enter the range of time (years, months, days): ";
        std::cin >> time;

        // Make sure that they gave a valid time range
        if (time == "years" || time == "months" || time == "days") {
            // Get how long its been since their deposit
            std::cout << "How long has it been since you made this deposit: ";
            std::cin >> timeSince;

            // Try catch and convert all the numerical data to floats
            try {
                principalFloat = stof(principal);
                try {
                    rateFloat = stof(rate);
                    try {
                        timeSinceFloat = stof(timeSince);
                        // Check if their are negatives
                        if (rateFloat <= 0) {
                            std::cout << " Your rate cannot be 0 or negative! \n ";
                        } else if (timeSinceFloat < 0) {
                            std::cout << "Your amount of time cannot be 0!\n";
                        } else {
                        // If everything is correct we break from the loop
                            break;
                        }
                        // If any of the data is erroneous (string) this happens
                    } catch (std::invalid_argument) {
                        std::cout << timeSince << "is not a float!";
                    }
                } catch (std::invalid_argument) {
                    std::cout << rate << "is not a float!";
                }
            } catch (std::invalid_argument) {
                std::cout << principal << "is not a float!";
            }
        } else {
            std::cout << "Please enter a valid time range \n";
        }
    }
    interest = interest_calc(principalFloat, rateFloat, time, timeSinceFloat);
    std::cout << "\n";
    std::cout << "From depositing " << principalFloat << "$"
              << " For " << timeSinceFloat << " " << time << " with a "
              << rateFloat
              << "% rate you have made "
              << interest << "$.\n";
    std::cout << "\n";
    std::cout << "Giving you a total " <<
    (interest + principalFloat) << "$! \n";
}
