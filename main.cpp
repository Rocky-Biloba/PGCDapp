//
//  main.cpp
//  TP1_PGCD
//
//  Created by RLO on 2020-03-26.
//  Copyright © 2020 Bubble Father. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

/*Functions*/
//Case 1 : PGCD
int menuUno(){
    int num1;
    int num2;
    
    cout << BOLDYELLOW << "Entrez le numérateur: "; //get user input
    cin >> num1;
    cout << "Entrez le dénominateur: ";
    cin >> num2;
    
    int reponse = calculerPGCD(<#int a#>, <#int b#>);
    
    std::string solutionPGCD = "Le Plus Grand Diviseur Commun de " + //print out pgcd
    std::to_string(num1) + " et " +
    std::to_string(num2) + " est " +
    std::to_string(reponse);
    
}

int calculerPGCD(int a, int b) {
    return b == 0 ? a : calculerPGCD(b, a % b);
} //PGCD

//Case 2: Simplifier
void simplifier(){
    
} // simplifier

// Case 3 : simplifierPlus
void simplifierPlus(){
    
} //simplifierPlus

// Case 4: Quitter
void quitter(){
    cout << "\t\t\t  ***                Au revoir!           ***\t\t\t  " << endl;
    exit(0);
}



/*int pgcd(int a, int b) {
    return b == 0 ? a : pgcd(b, a % b);
} */      //DELETE?


int choix = 0;

int main() {
    
    cout << BOLDMAGENTA << "\t\t\t ****PGCD et simplification des fractions****\t\t\t " << endl;
    cout << "\t\t\t  ***                MENU           ***\t\t\t  " << endl;
    cout << std::left;
    cout << RESET << "Voulez-vous:\n" << std::left
    << std::setw(6) << "1. Trouver le plus grand diviseur commun de deux numéros?\n" << std::right
    << std::setw(6) << "2. Simplifier une fraction?\n" << std::right
    << std::setw(6) << "3. Simplifier plusieurs fractions?\n" << std::right
    << std::setw(6) << "4. Quitter?\n" << std::right << endl;
    
    
    cin >> choix;
    while (choix < 1 || choix > 4){
        cout << "Choix incorrect.\n Essaye de nouveau : " << endl;
    }
    
    switch(choix) {
        case 1:
            int solutionPGCD = 0;
            solutionPGCD = menuUno();
            std::cout << solutionPGCD;
            break;
        case 2:
            simplifier();
            break;
        case 3:
            simplifierPlus();
            break;
        case 4:
            quitter();
            break;
        
    } // switch
} //main

                  
