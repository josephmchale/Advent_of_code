#include "Day1.h"


std::vector<std::string> split_string_by_space(std::string string_to_split){
    std::istringstream iss(string_to_split);
    std::vector<std::string> split_string;
    std::string temporary_string;

    while (iss >> temporary_string)
    {
        split_string.push_back(temporary_string);
    }

    return split_string;    
}

int main() {
    // Get input text file
    std::ifstream input_file("input.txt");
    std::string file_line;

    // Store two lists gathered from input file
    std::vector<int> list1;
    std::vector<int> list2;

    while (std::getline(input_file, file_line))
    {
        
        std::vector<std::string> split_file_line = split_string_by_space(file_line);

        // Convert capture value to string and store in two input vectors
        list1.push_back(std::stoi(split_file_line[0]));
        list2.push_back(std::stoi(split_file_line[1]));
    }
    
    int total_difference = {0};
    
    // sort lists into accending order
    std::sort(list1.begin(), list1.end());
    std::sort(list2.begin(), list2.end());
    
    for (int i = 0; i < list1.size(); i++)
    {
        total_difference += std::abs(list1[i] - list2[i]);
    }
    std::cout << "total_difference: " << total_difference << std::endl;
    

    return 0;
}