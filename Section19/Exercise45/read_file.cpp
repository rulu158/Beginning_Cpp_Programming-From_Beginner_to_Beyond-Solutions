#include <iostream>
#include <fstream>

void read_file(std::string file_name) {
    //---- YOU WRITE YOUR CODE BELOW THIS LINE----

   std::ifstream in_file;
   in_file.open(file_name);
   if (!in_file) {
       std::cerr << "Error opening file" << std::endl;
   }
   
   std::string word;
   while (in_file >> word) {
       std::cout << word << std::endl;
   }
   
    //---- YOU WRITE YOUR CODE ABOVE THIS LINE----
}
