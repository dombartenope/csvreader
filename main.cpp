#include <iostream>
#include <fstream>
#include <string>


int main() {

  // Open the input and output files
  std::ifstream input("file.csv");
  std::ofstream output("output.csv");

  // Read the first line from the input file (assumed to be the column names)
  std::string line;
  std::getline(input, line);

  // Write the "column name" line to the output file
  output << line << "\n";

  // Loop through the rest of the lines in the input file
  while (std::getline(input, line))
  {
      // SEARCH CONDITION:
      if (line.find("dom") != std::string::npos)
      {
          // Write the line to the output file
          output << line << "\n";
      }
  }

  // Close the files
  input.close();
  output.close();


  return 0;
}