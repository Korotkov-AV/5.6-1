// 5.6-1.cpp 

#include <iostream>
#include <map>
#include <string>


std::multimap<int, char> sort(std::string s) {
	std::map<char, int> map{};
	for (int i = 0; i < s.size(); i++)
	{
		if (!map.count(s[i])) map[s[i]] = 1;
		else map[s[i]]++;
	}

	std::multimap<int, char> invert_map{};
	for (const auto& elem : map)
		invert_map.insert(std::make_pair(elem.second, elem.first));

	return invert_map;
}

int main() {
	std::string my_string;

	std::cout << "input word: ";
	getline (std::cin, my_string);

	std::multimap<int, char> my_map = sort(my_string);

	for (auto iter = my_map.rbegin(); iter != my_map.rend(); ++iter) {
		std::cout << iter->first << ": " << iter->second << std::endl;
	}
}


