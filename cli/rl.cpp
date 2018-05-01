//Copyright Asaad Noman Abbasi

#include <iostream>
#include <fstream>
#include <string>

int main() {
   
   std::cout << "\n-------------------------------------------- \n";
   std::cout << "      R E T R O    L A U N C H   ( CLI )\n";
   std::cout << "--------------------------------------------    \n\n";
 
   int CHOICE = 0;
   std::string GAME_TITLES[50];
   std::ifstream file("config.txt");
   std::string line;
   if(file.is_open()) {
      int line_counter = 0;
      while(std::getline(file,line)) {
         line_counter++;
         std::cout << line_counter << " : " << line << '\n';
         GAME_TITLES[line_counter] = line;
      } file.close();
   } else {
      std::cout << "Could not Open File";
   }
   
   std::cout << "\nSelect A Choice : ";
   std::cin >> CHOICE;
   if(GAME_TITLES[CHOICE] == "")
      std::cout << "Error: Game not Listed in config_names File\n";
   std::cout << GAME_TITLES[CHOICE];
}

