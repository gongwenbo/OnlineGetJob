#pragma once
#include "common.h"
class Sort
{
public:

	int QuickSortPart(std::vector<int>& data, int l, int r) {

		int i = l, j = r, k = data[l];
		while (i < j) {
		
			while (i < j && k < data[j])
				j--;
			if (i < j) {
			
				data[i] = data[j];
				i++;
			}

			while (i < j && k > data[i])
				i++;
			if (i < j) {

				data[j] = data[i];
				j--;
			}		
		}
		data[i] = k;
		return i;

	}
	
	
	void QuickMang(std::vector<int>& data, int l, int r){

		if (l < r) {

			int i = QuickSortPart(data, l, r);
			QuickMang(data, l, i - 1);
			QuickMang(data, i+1, r);
		}

	}

};

int test_Sort() {
	
	std::vector<int> info;
	std::string reci;
	std::stringstream str;
	std::getline(std::cin, reci);
	str << reci;
	int data;
	while (str >> data) {
	
		info.emplace_back(data);
	}

	auto ptr = std::make_shared<Sort>();
	ptr->QuickSortPart(info, 0, info.size()-1);
	for (auto& iter : info) {
	
		std::cout << iter << "\n";
	}
	return 0;

};























