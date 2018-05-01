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
   std::string GAME_COMMAND[50];
   std::ifstream file("config.txt");
   std::string line;
   if(file.is_open()) {
      
      //This basically extracts the data [Title and Path] in the given txt file format
      int lc = 0; //line counter
      int lc_o = 0; //line counter odd
      int lc_o_i = 0; //line counter odd inner
      int lc_e = 0; //line counter even
      while(std::getline(file,line)) {
         if(lc == 0) { //if first item
            lc_e++;
            GAME_TITLES[lc] = line;
            lc++;
         } else if(lc != 0) { //if not first item
            if(lc % 2 != 0) { //if AN odd item [GAME PATH]
               lc_o++;
               if(lc == 1) {  //if first ODD ITEM
                  lc = 0;
                  GAME_COMMAND[lc] = line;
                  lc += 2;
               } else {       
                  if(lc_o > 2) { //if line_counter_odd counter > 2 [Things Get Wonky]
                     lc_o_i++;   //Increment
                  } int t = lc; 
                    lc -= lc_o;
                    GAME_COMMAND[lc] = line;
                    lc = (t + (t - lc_o)) - lc_o_i; //Put the tracking pointer right on track
                  }  
            } else { //if its even item
               lc_e++;
               lc = (lc + 1) - lc_e;
               GAME_TITLES[lc] = line;
               lc += lc_e;
            }
         }
         
      } file.close();
   } else {
      std::cout << "Could not Open File";
   }
   
   std::cout << GAME_TITLES[3];
   std::cout << "\n" << GAME_COMMAND[3];
}