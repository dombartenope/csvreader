#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {
    //Count for results display after search
    double count {0};

    // Open the input and output files
    std::ifstream input("input.csv");
    std::ofstream output("output.csv");

    // Read the first line from the input file (assumed to be the column names)
    std::string line;
    std::getline(input, line);

    // Write the "column name" line to the output file
    output << line << "\n";

    //Switch to true if your terminal supports ANSI Color Codes
    bool colorMode {true};
    //Vector to store all search queries
    std::vector<std::string> search_words;
    //Current search query
    std::string search;

    while(true) {
        //Prompt user to add search query in terminal
        std::cout << "\nString/s that you would like to find exact matches for (type " << (colorMode ? "\033[1;35m'!done'\033[0m" : "'!done'") << " to begin searching): ";
        //Collect full request including spaces
        std::getline(std::cin, search);
        std::cout << std::endl;
        if(search == "!done") {
            break;
        }
        //Push search query to vector
        search_words.push_back(search);
    }

    //Loop while there are lines are in input.csv (starts @ line 2)
    while(std::getline(input, line)){
        //For each index of the vector loop through 
        for(size_t i{}; i < search_words.size(); i++) {
            //if search matches the csv line
            if(line.find(search_words[i])!= std::string::npos) {
                //Add one to count and write the line to the output
                count++;
                output << line << "\n";
            }
        }
    }
    //Count shown to user to detail the results and new csv destination
    std::cout << (colorMode ? "\033[1;35mFound " : "Found") << count << (count != 1 ? " matches. Please see output.csv to view your updated CSV.\n" : " match. Please see output.csv to view your updated CSV.\n") << std::endl;

    // Close the files
    input.close();
    output.close();

    return 0;
}


