/* 
mainAVL.cpp

Eduardo Veit Ferrão - 32150180
Leonardo Biagiotti Beloti - 32160062
Lucas Damasceno de Cunha Lima - 32132611
Lucas Iudi Corregliano Gallinari - 32138628
Thiago Aidar Figueiredo - 32144547
*/

#include "AVL.h"
#include <clocale>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std;

void clear_screen() { //Usa CLS no console se o S.O é WIN, senão usa Clear.
  #ifdef _WIN32
	  system("cls");
  #else
  	system("clear");
  #endif
} 

void Insert(AVL *avl, std::string food, Alimento *data){
  for (char& c : food){  
      c = tolower(c);
  }
  NodeAVL *node = avl->Insert(food, *data);
  if (!node){
    std::cout << "*** ERROR! Couldn't insert node!\n";
  }
}

void SaveBackup(AVL *avl){
  ofstream fout("Backup.csv");
  string csv = avl->AVLtoCSV();
  fout << csv;
}

void LoadBackup(AVL *avl){
  avl->Clear();
  ifstream inFile;
  string line, args;
  std::vector<std::string> v;
  inFile.open("Backup.csv");
  while (getline(inFile, line)) {
    v.clear();
    std::stringstream str(line);
    for (int i = 0; i < 24; ++i){
      getline(str, args, ',');
      if (args != "")
        v.push_back(args);
      else
        v.push_back("0");
    }
    Alimento *data = new Alimento(
    stoi(v[1]), stoi(v[2]), stof(v[3]), stoi(v[4]), stoi(v[5]), stoi(v[6]), stoi(v[7]), stoi(v[8]), stoi(v[9]), stoi(v[10]), stoi(v[11]), stoi(v[12]), stoi(v[13]), stoi(v[14]), stoi(v[15]), stoi(v[16]), stoi(v[17]), stoi(v[18]), stof(v[19]),stoi(v[20]), stoi(v[21]), stoi(v[22]), v[23]);
    Insert(avl, v[0], data);
  }
  inFile.close();
}

void PrintNode(NodeAVL *node) {
  if (node == nullptr)
    return;

  std::cout << "Food: " << node->GetFood() << node->GetData().PrintTabela() << '\n';
}

void Read(AVL *avl) {
  ifstream inFile;
  string line, args;
  std::vector<std::string> v;
  inFile.open("NutritionalFacts_Fruit_Vegetables_Seafood.csv");
  while (getline(inFile, line)) {
    v.clear();
    std::stringstream str(line);
    
    for (int i = 0; i < 24; ++i){
      getline(str, args, ',');
      
      if (args != "")
        v.push_back(args);
      else
        v.push_back("0");
    }
    
    Alimento *data = new Alimento(
    stoi(v[1]), stoi(v[2]), stof(v[3]), stoi(v[4]), stoi(v[5]), stoi(v[6]), stoi(v[7]), stoi(v[8]), stoi(v[9]), stoi(v[10]), stoi(v[11]), stoi(v[12]), stoi(v[13]), stoi(v[14]), stoi(v[15]), stoi(v[16]), stoi(v[17]), stoi(v[18]), stof(v[19]),stoi(v[20]), stoi(v[21]), stoi(v[22]), v[23]);
    Insert(avl, v[0], data);
  }
  inFile.close();
}

void Remove(AVL* avl){
  std::string food;
  std::cout << "Remove food: ";
  cin.ignore();
  getline(std::cin, food, '\n');
  for(char& c : food){ 
    c = tolower(c);
  }
  avl->Remove(food);
}

void TraverseInOrder(AVL *avl) { std::cout << avl->TraverseInOrder() << '\n'; }

void nutrition_calculator(AVL* avl){
  int calories = 0, caloriesfromfat = 0, totalfatdv = 0, sodium = 0, sodiumdv = 0, potassiumg = 0, potassiumdv = 0, carbohydrateg = 0, carbohydratedv = 0, fiberg = 0,fiberdv = 0, sugarsg, proteing = 0, vitadv = 0, vitcdv = 0, calciumdv = 0, irondv = 0, saturatedfatmg = 0, cholesteroldv = 0, cholesterolmg = 0;
  float totalfatg = 0, saturatedfatdv = 0;
  string op = "0";
  std::vector<NodeAVL*> list;
  cin.ignore();
  while(true){
    cout << "\n\n  < Stop: -1 >\nEnter Food Name: "<< endl;
    getline(cin, op, '\n');
    if(op == "-1") break;
    else{
      for(char& c : op){ 
        c = tolower(c);
      }
      NodeAVL* node = avl->SearchInOrder(op);
      if(node){
        list.push_back(node);
        calories += node->GetData().GetCal();
        caloriesfromfat += node->GetData().GetCalFromFat();
        totalfatdv += node->GetData().GetTotalFatDv(); 
        sodium += node->GetData().GetSodiumG();
        sodiumdv += node->GetData().GetSodiumDv(); 
        potassiumg += node->GetData().GetPotassiumG();
        potassiumdv += node->GetData().GetPotassiumDv();
        carbohydrateg += node->GetData().GetCarbohyrateg();
        carbohydratedv += node->GetData().GetCarbohyrateDv();
        fiberg += node->GetData().GetFiberg();
        fiberdv += node->GetData().GetFiberDv();
        sugarsg += node->GetData().GetSugarsg();
        proteing += node->GetData().GetProteing();
        vitadv += node->GetData().GetVitADv();
        vitcdv += node->GetData().GetVitCDv();
        calciumdv += node->GetData().GetCalciumDv();
        irondv += node->GetData().GetIronDv();
        saturatedfatmg += node->GetData().GetSaturatedFatmg(); 
        cholesteroldv += node->GetData().GetCholesterolDv(); 
        cholesterolmg += node->GetData().GetCholesterolmg();
        totalfatg += node->GetData().GetTotalFatg();
        saturatedfatdv += node->GetData().GetSaturatedFatDv();
      }
      else cout << "Couldn't find food\n\n";
    }
  }
  cout<< "\nNutritional Values Table\n"
      << "\nCalories: " << calories
      << "\nCalories from fat: " << caloriesfromfat
      << "\nTotal Fat (g): " << totalfatg
      << "\nTotal Fat (%DV): " << totalfatdv
      << "\nSodium (g): " << sodium
      << "\nSodium (%DV): " << sodiumdv
      << "\nPotassium (g): " << potassiumg
      << "\nPotassium (%DV): " << potassiumdv
      << "\nCarbohydrate (g): " << carbohydrateg
      << "\nCarbohydrate (%DV): " << carbohydratedv
      << "\nFiber (g): " << fiberg
      << "\nFiber (%DV): " << fiberdv
      << "\nSugar (g): " << sugarsg
      << "\nProtein (g): " << proteing
      << "\nVitamin A (%DV): " << vitadv
      << "\nVitamin C (%DV): " << vitcdv
      << "\nCalcium (%DV): " << calciumdv
      << "\nIron (%DV): " << irondv
      << "\nSaturated (%DV): " << saturatedfatdv
      << "\nSaturated (mg): " <<  saturatedfatmg
      << "\nCholesterol (%DV):" << cholesteroldv
      << "\nCholesterol (mg): " << cholesterolmg<<endl<<endl;
  while(true){
    cout<< "\n < Your list >\n\n";
    for(int i = 0; i < list.size(); ++i){
      cout << i+1 << ": " << list[i]->GetFood() << endl;
    }
    cout << "\nType -1 to exit or a number to show\na specific food calories value: ";
    cin >> op;
    if (op == "-1") break;
    else if (stoi(op) <= list.size() && stoi(op) >= 1) cout << endl << list [stoi(op)-1]->GetFood() << " calories: " << list[stoi(op)-1]->GetData().GetCal() << endl;
    else cout << "\nWrong input, try again\n\n";
  }
}

int main() {
  AVL *avl = new AVL();
  char option = '0';
  do
  {
    std::cout << " Nutritional Database\n"
              << "[1] Read CSV\n"
              << "[2] Nutrition Table\n"
              << "[3] Remove Food\n"
              << "[4] Print DataBase Food\n"
              << "[5] Save Backup\n"
              << "[6] Load Backup\n"
              << "[0] Exit\nOption: ";
    std::cin >> option;
    std::cout << '\n';
    switch (option){
      case '1': Read(avl); clear_screen(); break;
      case '2': nutrition_calculator(avl); clear_screen(); break;
      case '3': Remove(avl); clear_screen(); break;
      case '4': clear_screen(); TraverseInOrder(avl); break;
      case '5': SaveBackup(avl); clear_screen(); break;
      case '6': LoadBackup(avl); clear_screen(); break;
      case '0': break; clear_screen();
      default: clear_screen(); cout << "Invalid option, try again\n"; break;
      }
      std::cout << '\n';
  } while (option != '0');

  delete avl;
  return 0;
}