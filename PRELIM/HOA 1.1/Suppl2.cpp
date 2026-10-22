//My Temperature Converter
#include <iostream>

//Convert Kelvin to Fahrenheit
double kelvinToFahrenheit(double kelvin) {
    return (kelvin - 273.15) * 9.0 / 5.0 + 32;
}

//Convert Fahrenheit to Kelvin
double fahrenheitToKelvin(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0 + 273.15;
}

//User's input menu
int main() {
    int choice;
    double temperature;

    while (true) {
        std::cout << "\n--- My Temperature Converter ---\n";
        std::cout << "1. Convert Kelvin to Fahrenheit\n";
        std::cout << "2. Convert Fahrenheit to Kelvin\n";
        std::cout << "3. Exit the Converter\n";
        std::cout << "Enter your choice (1/2/3): ";
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Enter temperature in Kelvin: ";
            std::cin >> temperature;
            std::cout << temperature << " K is " << kelvinToFahrenheit(temperature) << "°F\n";
        } else if (choice == 2) {
            std::cout << "Enter temperature in Fahrenheit: ";
            std::cin >> temperature;
            std::cout << temperature << "°F is " << fahrenheitToKelvin(temperature) << " K\n";
        } else if (choice == 3) {
            std::cout << "Pwede ka nang umalis! Thank you beri much.\n";
            break;
        } else {
            std::cout << "Invalid Boss. Please select 1, 2, or 3.\n";
        }
    }
    return 0;
}