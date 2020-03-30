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
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
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
int calculerPGCD(int a, int b) {
    return b == 0 ? a : calculerPGCD(b, a % b);
} //calculerPGCD

int menuUno(){
    int num1;
    int num2;
    cout << BOLDYELLOW << "\t\t  ***          Calculer le PGDC          ***\t\t  " << endl;
    cout << YELLOW << "Entrez le numérateur: "; //get user input
    cin >> num1;
    cout << "Entrez le dénominateur: ";
    cin >> num2;
    
    int reponse = calculerPGCD(num1, num2);
    
    std::cout << '\n';
    std::string solutionPGCD = ("Le Plus Grand Diviseur Commun de " + //print out pgcd
                                std::to_string(num1) + " et " +
                                std::to_string(num2) + " est " +
                                std::to_string(reponse) + "\n");
    cout << solutionPGCD;
    return reponse;
}//menuUno

//Case 2: Simplifier
// simplifier
int menuDuo(){
    int num1;
    int num2;
    
    cout << BOLDGREEN << "\t\t  ***          Simplifier une fraction          ***\t\t  " << endl;
    cout << GREEN << "Entrez le numérateur: "; //get user input
    cin >> num1;
    cout << "Entrez le dénominateur: ";
    cin >> num2;
    
    int pgdc = calculerPGCD(num1, num2);
    
    int simp1 = num1 / pgdc;
    int simp2 = num2 / pgdc;
    
    std::cout << '\n';
    cout << "Votre fraction et sa forme simplifiée :" << endl;
    
    std::string solutionSimp = std::to_string(simp1) + " \\ " + //print out pgcd
    std::to_string(simp2)+ "\n";
    cout << solutionSimp;
    return 0;
}//menuDuo


// Case 3 : simplifierPlus
void menuTres(){
    int quantFrac = 0;
    int num;
    int denom;
    
    cout << BOLDCYAN << "\t\t  ***          Simplifier plusieurs fractions          ***\t\t  " << endl;
    cout << CYAN << "Entrez le nombre de fractions à simplifier: " << endl;
    
    cin >> quantFrac; //get user input
    if (quantFrac < 0){                 // detect 0 input
        quantFrac = 0;
    }
    
    int numerateurs[quantFrac];
    int denominateurs[quantFrac];
    
    for (int i= 0 ; i < quantFrac ; i++){
        std::cout << "Entrez les numérateurs: ";
        std::cin >> num;
        numerateurs[i] = num; // populate numerator table
    }
    
    for (int i= 0 ; i < quantFrac ; i++){
        std::cout << "Entrez les dénominateurs: ";
        std::cin >> denom;
        if (denom == 0){                       // detect 0 input
            cout << BOLDRED <<"\t Chiffre invalid. " << endl;
            return; // exit the function
        } else {
            denominateurs[i] = denom; // populate denominator table
        }
    }
    std::cout << '\n';
    cout << "Vos fractions et leurs formes simplifiées :" << endl;
    
    for (int i= 0 ; i < quantFrac ; i++){ // print out num / denoms
        num = numerateurs[i];
        denom = denominateurs[i];
        int pgdc = calculerPGCD(num, denom);
        
        int simp1 = num / pgdc;
        int simp2 = denom / pgdc;
        
        std::string solutionSimpPlus = (std::to_string(numerateurs[i]) + " \\ " +
                                        std::to_string(denominateurs[i])+ " >>> " +
                                        std::to_string(simp1) + " \\ " +
                                        std::to_string(simp2)+ "\n");
        cout << solutionSimpPlus;
    }
} //menuTres

int choix = 0;

int main() {
    bool run = true;
    while(run){
        std::cout << '\n';
        cout << BOLDMAGENTA << "\t\t ****PGCD et simplification des fractions****\b\t\t " << endl;
        cout << "\t\t  ***                MENU           ***\t\t  " << endl;
        cout << std::left;
        cout << MAGENTA << "Voulez-vous:\n" << std::left
        << std::setw(6) << "1. Trouver le plus grand diviseur commun de deux numéros?\n" << std::right
        << std::setw(6) << "2. Simplifier une fraction?\n" << std::right
        << std::setw(6) << "3. Simplifier plusieurs fractions?\n" << std::right
        << std::setw(6) << "4. Quitter?\n" << std::right << endl;
        
        cin>>choix;
        
        switch(choix) {
            case 1: {
                int solutionPGCD = menuUno();
                std::cout << solutionPGCD;
                break;
            }
            case 2: {
                int solutionSimp = menuDuo();
                std::cout << solutionSimp;
                break;
            }
            case 3: {
                menuTres();
                break;
            }
            case 4: {
                run = false;
                cout << BOLDMAGENTA << "\t\t ***        Au revoir!        ***\t\t" << endl;
                cout << RESET;
                exit(0);
                break;
            }
            default :
                cout << BOLDRED << "\t Choix non-valide. Essaie de nouveau : " << endl;
                
        } // switch
    } // while
} //main

