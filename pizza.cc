/**
 *   @file: pizza.cc
 * @author: Anthony DeLuca
 *   @date: 04/05/21
 *  @brief: pizza
 */


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <cctype>

using namespace std;

struct Pizza{
    string size;
    string type;
    int num;
}; 



void load(vector<Pizza> &pizzas);
void numPizzas(vector<Pizza> &pizzas, int &numLarge, int &numSmall);
void pricePizzas(vector<Pizza> &pizzas, double &totalPrice);
void printResults(int numLarge, int numSmall, double totalPrice);


///Constants, structures, classes, and function prototypes

int main(int argc, char const *argv[]) {
Pizza p;
vector <Pizza> pizzas;

int numLarge, numSmall;
double totalPrice;

load(pizzas);

numPizzas(pizzas, numLarge, numSmall);

pricePizzas(pizzas, totalPrice);

printResults(numLarge, numSmall, totalPrice);




    return 0;
} /// main

void load(vector<Pizza> &pizzas){
    ifstream inStream;
    string filename;

    cout << "Please enter the file you want to use: ";
    cin >> filename;

    inStream.open(filename);
    if (inStream.fail()){
        cout << "Error opening the file";
        exit(0);
    }
    string line;
    string size, type;
    int num;
    inStream >> size >> type >> num;
    while(!inStream.eof()){
    
    Pizza tempPizza = {.size=size, .type=type, .num = num};
    pizzas.push_back(tempPizza);
    inStream >> size >> type >> num;
    
    }

}


void numPizzas(vector<Pizza> &pizzas, int &numLarge, int &numSmall){
    numLarge = 0, numSmall = 0;
    for(unsigned int i = 0; i < pizzas.size(); i++){
        if(pizzas.at(i).size == "l" || pizzas.at(i).size == "L"){
            numLarge++;
        }
        else if(pizzas.at(i).size == "s" || pizzas.at(i).size == "S"){
            numSmall++;
        }
    }
}


void pricePizzas(vector<Pizza> &pizzas, double &totalPrice){
    totalPrice = 0;
    for(unsigned int i = 0; i < pizzas.size(); i++){
        if(pizzas.at(i).size == "l" || pizzas.at(i).size == "L"){
            totalPrice = totalPrice + 8.00;
            if(pizzas.at(i).type == "wheat"){
                totalPrice += 1.00;
            }
            totalPrice += pizzas.at(i).num * 2;

        }
        else if(pizzas.at(i).size == "s" || pizzas.at(i).size == "S"){
            totalPrice = totalPrice + 5.00;
            if(pizzas.at(i).type == "wheat" || pizzas.at(i).type == "Wheat"){
                totalPrice += 1.00;
            }
            totalPrice += pizzas.at(i).num;

        }
        
    }
}


void printResults(int numLarge, int numSmall, double totalPrice){
    cout << "Number of small pizzas = " << numSmall << endl;
    cout << "Number of large pizzas = " << numLarge << endl;
    cout << "Total number of pizzas = " << numSmall + numLarge << endl;
    cout << "Total price of pizzas = $" << setprecision(2) << fixed << totalPrice << endl;
}