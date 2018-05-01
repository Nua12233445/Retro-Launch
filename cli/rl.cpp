//Copyright Asaad Noman Abbasi

/*

   To use this , i assume u have ur emu's added to ur PATH ..
   i have tested this on CITRA(3DS) , CEMU(WII U) , DOLPHIN(WII)

*/

#include <iostream>
#include <unistd.h>
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
            std::cout << "(" << lc << ")"<< " " << GAME_TITLES[lc] << std::endl;
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
               std::cout << "(" << lc << ")" << " " << GAME_TITLES[lc] << std::endl;
               lc += lc_e;
            }
         }
      } file.close();
   } else {
      std::cout << "Could not Open File";
   }
   
   std::cout << "\n Please Enter Game Code: ";
   std::cin >> CHOICE;
   std::cout << " ------------------------------------------- \n";
   std::cout << " Starting " << GAME_TITLES[CHOICE] << std::endl;
   std::cout << " ------------------------------------------- \n";
   usleep(5000000);
   system(GAME_COMMAND[CHOICE].c_str());
   return 0;
}