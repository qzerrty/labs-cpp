#include <iostream>
#include <cmath>
#include <cstring>
#include "Triangle.hpp"

void help() {
	std::cout << "h - list of commands" << std::endl;
	std::cout << "p - print the values of fields" << std::endl;
	std::cout << "c - create new Triangle to compare with main object" << std::endl;
	std::cout << "g [1 / 2 / 3 / 4 / 5] - get [side / angle1 / angle2 / sides / bisectors]" << std::endl;
	std::cout << "s [1 / 2 / 3] - set [side / angle1 / angle2]" << std::endl;
	std::cout << "q - quit" << std::endl;
}

void clear() {
	while(std::cin.get() != '\n');
}

int main() {
	Triangle figure(3, 1.0472, 0.523599);
	Triangle figure2(1, 1, 1);
	Triangle::lines lines;

	char command;
	int arg;
	float value;
	while (true) {
		std::cout << "<< ";
		std::cin >> command;
		switch (command) {
			case 'h':
				clear();
				help();
				break;

			case 'p':
				clear();
				std::cout << "side: " << figure.getSide() << "; angle1: " << figure.getAngle1() << " radians; angle2: " << figure.getAngle2() << " radians;" << std::endl;
				break;

			case 'c':
				clear();
				std::cout << "Please, enter angles in radians" << std::endl;
				figure2.readUserInput();
				std::cout << "figure == figure2 is " << (figure == figure2 ? "true" : "false") << std::endl;
				break;

			case 'g':
				std::cin >> arg;
				switch (arg) {
					case 1:
						clear();
						std::cout << figure.getSide() << std::endl;
						break;

					case 2:
						clear();
						std::cout << figure.getAngle1() << std::endl;
						break;

					case 3:
						clear();
						std::cout << figure.getAngle2() << std::endl;
						break;

					case 4:
						clear();
						lines = figure.getSides();
						std::cout << "side1: " << lines.line1 << "; side2: " << lines.line2 << "; side3: " << lines.line3 << ";" << std::endl;
						break;
						
					case 5:
						clear();
						lines = figure.getBisectors();
						std::cout << "side1: " << lines.line1 << "; side2: " << lines.line2 << "; side3: " << lines.line3 << ";" << std::endl;
						break;

					default:
						clear();
						std::cout << "Incorrect argument" << std::endl;
				}
				break;

			case 's':
				std::cin >> arg;
				switch (arg) {
					case 1:
						clear();
						std::cout << "Enter length of side: ";
						std::cin >> value;
						if (!figure.setSide(value)) {
							std::cout << " >> Incorrect argument. Side value didn't change" << std::endl;
						}
						break;
					
					case 2:
						clear();
						std::cout << "Enter first angle: ";
						std::cin >> value;
						if (!figure.setAngle1(value)) {
							std::cout << " >> Incorrect argument. Angle1 value didn't change" << std::endl;
						}
						break;

					case 3:
						clear();
						std::cout << "Enter second angle: ";
						std::cin >> value;
						if (!figure.setAngle2(value)) {
							std::cout << " >> Incorrect argument. Angle2 value didn't change" << std::endl;
						}
						break;

					default:
						clear();
						std::cout << "Incorrect argument" << std::endl;
				}
				break;

			case 'q':
				return 0;
			
			default:
				clear();
				std::cout << "Unknown command" << std::endl;
		}
	}
}