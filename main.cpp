#include <iostream>
#include <fstream>
#include <string>


int main() {
  double count {0};

  // Open the input and output files
  std::ifstream input("file.csv");
  std::ofstream output("output.csv");

  // Read the first line from the input file (assumed to be the column names)
  std::string line;
  std::getline(input, line);

  // Write the "column name" line to the output file
  output << line << "\n";

  //Switch to true if your terminal supports ANSI Color Codes
  bool colorMode {true};
  
  
  //Request for the user to enter in a search term to look for in the csv file
  std::string search;
  std::cout << "\nEnter a string that you would like to find exact matches for: ";
  std::cin >> search;



  // Loop through the rest of the lines in the input file
  while (std::getline(input, line))
  {
      // SEARCH CONDITION (this currently does not support spaces and will only search for the first string input):
      if (line.find(search) != std::string::npos)
      {
          count++;
          // Write the line to the output file
          output << line << "\n";
      }
  }
  std::cout << (colorMode ? "\033[\n1;35mFound " : "\nFound") << count << " matches. Please see output.csv to view your updated CSV.\n"<< std::endl;

  // Close the files
  input.close();
  output.close();


  return 0;
}