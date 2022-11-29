// mainBST.cpp
#include "BST.h"
#include <clocale>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

void PrintNode(NodeBST *node) {
  if (node == nullptr)
    return;

  std::cout << "Food: " << node->GetFood() << node->GetData().PrintTabela() << '\n';
}

void Insert(BST *bst, std::string food, Alimento *data) {
  NodeBST *node = bst->Insert(food, *data);
  if (!node){
    std::cout << "*** ERROR! Couldn't insert node!\n";
  }
}

void Read(BST *bst) {

  ifstream inFile;

  string line, args;
  int calories, caloriesfromfat, totalfatdv, sodium, sodiumdv, potassiumg, potassiumdv, carbohydrateg, carbohydratedv, fiberg,fiberdv, sugarsg, proteing, vitadv, vitcdv, calciumdv, irondv, saturatedfatmg, cholesteroldv, cholesterolmg;
  float totalfatg, saturatedfatdv;
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
    calories = stoi(v[1]);
    caloriesfromfat = stoi(v[2]);
    totalfatg= stof(v[3]);
    totalfatdv = stoi(v[4]);
    sodium = stoi(v[5]);
    sodiumdv = stoi(v[6]);
    potassiumg = stoi(v[7]);
    potassiumdv = stoi(v[8]);
    carbohydrateg = stoi(v[9]);
    carbohydratedv = stoi(v[10]);
    fiberg= stoi(v[11]);
    fiberdv = stoi(v[12]);
    sugarsg = stoi(v[13]);
    proteing = stoi(v[14]);
    vitadv = stoi(v[15]);
    vitcdv = stoi(v[16]);
    calciumdv = stoi(v[17]);
    irondv = stoi(v[18]);
    saturatedfatdv = stof(v[19]);
    saturatedfatmg = stoi(v[20]);
    cholesteroldv = stoi(v[21]);
    cholesterolmg = stoi(v[22]);
    Alimento *data = new Alimento(
    calories, caloriesfromfat, totalfatg, totalfatdv, sodium, sodiumdv,
    potassiumg, potassiumdv, carbohydrateg, carbohydratedv, fiberg, fiberdv,
    sugarsg, proteing, vitadv, vitcdv, calciumdv, irondv, saturatedfatdv,
    saturatedfatmg, cholesteroldv, cholesterolmg, v[23]);

    Insert(bst, v[0], data);
  }
  inFile.close();
}

void Remove(BST* bst)
{
        std::string food;
        std::cout << "Remove food: ";
        std::cin >> food;
        bst->Remove(food);
}

void Search(BST* bst)
{
  string food;
  std::cout << "Search food name: ";
  std::cin >> food;
  NodeBST* node = bst->SearchInOrder(food);
  if (node){
    std::cout << "\n";
    PrintNode(node);
  }
  else{
    std::cout << "*** ERROR! Couldn't find food!\n";
  }
}

void TraverseInOrder(BST *bst) { std::cout << bst->TraverseInOrder() << '\n'; }

void TraversePreOrder(BST* bst)
{
        std::cout << bst->TraversePreOrder() << '\n';
}

void TraversePostOrder(BST* bst)
{
        std::cout << bst->TraversePostOrder() << '\n';
}
void nutrition_calculator(BST* bst)
{
  int calories = 0, caloriesfromfat = 0, totalfatdv = 0, sodium = 0, sodiumdv = 0, potassiumg = 0, potassiumdv = 0, carbohydrateg = 0, carbohydratedv = 0, fiberg = 0,fiberdv = 0, sugarsg, proteing = 0, vitadv = 0, vitcdv = 0, calciumdv = 0, irondv = 0, saturatedfatmg = 0, cholesteroldv = 0, cholesterolmg = 0;
  float totalfatg = 0, saturatedfatdv = 0;
  string op = "0";
  std::vector<NodeBST*> list;
  while(true){
    cout << "\n\n  < Stop: -1 >\nEnter Food Name: "<< endl;
    cin >> op;
    if(op == "-1") break;
    else{
      NodeBST* node = bst->SearchInOrder(op);
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
  cout<< "Nutritional Values Table\n"
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
  BST *bst = new BST();
  int option = 0;
  do
  {
    std::cout << "*** BST Tree ***\n"
              << "[1] Read\n"
              << "[2] Search\n"
              << "[3] Traverse in-order\n"
              << "[4] Traverse pre-order\n"
              << "[5] Traverse post-order\n"
              << "[6] Remove food\n"
              << "[7] Nutrition Calculator\n"
              << "[8] Clear\n"
              << "[0] Exit\nOption: ";
    std::cin >> option;
    std::cout << '\n';
    switch (option){
      case 1: Read(bst); break;
      case 2: Search(bst); break;
      case 3: TraverseInOrder(bst); break;
      case 4: TraversePreOrder(bst); break;
      case 5: TraversePostOrder(bst); break;
      case 6: Remove(bst); break;
      case 7: nutrition_calculator(bst); break;
      case 8: bst->Clear();break;
      case 0: break;
      default: cout<< "Invalid option, try again"; break;
      }
      std::cout << '\n';
  } while (option != 0);

  delete bst;
  return 0;
}