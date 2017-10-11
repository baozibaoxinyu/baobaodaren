/*
  Filename:Exec_1.cpp
  Date:09/10/2017
  Author:Chris Bao
  Overview:
  Using array<T,N> to create a BMI table
  BMI = weight/(height*height)
  weight is in kilometers,height is in meters
*/
#include <iostream>
#include <iomanip>
#include <array>
const unsigned int min_wt{ 40 };
const unsigned int max_wt{ 120 };
const unsigned int wt_step{ 5 };
const size_t wt_count{ 1 + (max_wt - min_wt) / wt_step };
const unsigned int min_ht{ 155 };
const unsigned int max_ht{ 200 };
const unsigned int ht_step{ 5 };
const size_t ht_count{ 1 + (max_ht - min_ht) / ht_step };

int main()
{
	std::array<unsigned int, wt_count>weight_kg;
	std::array<unsigned int, ht_count>height_m;
	for (size_t i{}, w{ min_wt }; i < wt_count; w += wt_step, ++i) {
		weight_kg[i] = w;
	}
	unsigned int h = min_ht;
	for (auto &ht : height_m) {
		ht = h;
		h += ht_step;
	}
	for (size_t i{ 0 }; i <= wt_count; ++i) {
		std::cout << "----------";
	}
	std::cout << std::endl;
	std::cout << " h/m|w/kg|";
	for (const auto &w : weight_kg) {
		std::cout << std::setw(6) << w << "   |";
	}
	std::cout << std::endl;
	for (size_t i{0}; i <= wt_count; ++i) {
		std::cout << "----------";
	}
	std::cout << std::endl;
	double bmi{};
	for (const auto& ht : height_m) {
		double h = ht / 100.0;
		std::cout << std::fixed << std::setprecision(2);
		std::cout << std::setw(6) << ht << "   |";
		for (const auto& wt : weight_kg) {
			bmi = wt / (h*h);
			std::cout << std::setw(7) << bmi << "  |";
		}
		std::cout << std::endl;
	}
	for (size_t i{ 0 }; i <= wt_count; ++i) {
		std::cout << "----------";
	}
	std::cout << std::endl;
	std::cout << "BMI from 18.5 to 24.9 is normal." << std::endl;
}