#include "Alimento.h"
#include <sstream>

Alimento::Alimento(int calories, int caloriesfromfat, float totalfatg, int totalfatdv, int sodium, int sodiumdv, int potassiumg, int potassiumdv, int carbohydrateg, int carbohydratedv, int fiberg, int fiberdv, int sugarsg, int proteing, int vitadv, int vitcdv, int calciumdv, int irondv, float saturatedfatdv, int saturatedfatmg, int cholesteroldv, int cholesterolmg, std::string foodtype)
	: m_Cal(calories)
  , m_CalFromFat(caloriesfromfat)
  , m_TotalFatg(totalfatg)
  , m_TotalFatDv(totalfatdv)
  , m_SodiumG(sodium)
  , m_SodiumDv(sodiumdv)
  , m_Potassiumg(potassiumg)
  , m_PotassiumDv(potassiumdv)
  , m_Carbohydrateg(carbohydrateg)
  , m_CarbohydrateDv(carbohydratedv)
  , m_Fiberg(fiberg)
  , m_FiberDv(fiberdv)
  , m_Sugarsg(sugarsg)
  , m_Proteing(proteing)
  , m_VitADv(vitadv)
  , m_VitCDv(vitcdv)
  , m_CalciumDv(calciumdv)
  , m_IronDv(irondv)
  , m_SaturatedFatDv(saturatedfatdv)
  , m_SaturatedFatmg(saturatedfatmg)
  , m_CholesterolDv(cholesteroldv)
  , m_Cholesterolmg(cholesterolmg)
  , m_FoodType(foodtype)
{
}

Alimento::~Alimento()
{
}


std::string Alimento::PrintTabela() const{
  std::ostringstream oss;
  oss << "\nCalories: " << GetCal()
      << "\nCalories from fat: " << GetCalFromFat()
      << "\nTotal Fat (g): " << GetTotalFatg()
      << "\nTotal Fat (%DV): " << GetTotalFatDv()
      << "\nSodium (g): " << GetSodiumG()
      << "\nSodium (%DV): " << GetSodiumDv()
      << "\nPotassium (g): " << GetPotassiumG()
      << "\nPotassium (%DV): " << GetPotassiumDv()
      << "\nCarbohydrate (g): " << GetCarbohyrateg()
      << "\nCarbohydrate (%DV): " << GetCarbohyrateDv()
      << "\nFiber (g): " << GetFiberg()
      << "\nFiber (%DV): " << GetFiberDv()
      << "\nSugar (g): " << GetSugarsg()
      << "\nProtein (g): " << GetProteing()
      << "\nVitamin A (%DV): " << GetVitADv()
      << "\nVitamin C (%DV): " << GetVitCDv()
      << "\nCalcium (%DV): " << GetCalciumDv()
      << "\nIron (%DV): " << GetIronDv()
      << "\nSaturated (%DV): " << GetSaturatedFatDv()
      << "\nSaturated (mg): " << GetSaturatedFatmg()
      << "\nCholesterol (%DV):" << GetCholesterolDv()
      << "\nCholesterol (mg): " << GetCholesterolmg()
      << "\nFood Type: " << GetFoodType();
  return oss.str();
}

int Alimento::GetCal() const {
  return m_Cal;
}
void Alimento::SetCal(int cal){
  m_Cal = cal;
}

int Alimento::GetCalFromFat() const {
  return m_CalFromFat;
}
void Alimento::SetCalFromFat(int calFromFat){
  m_CalFromFat = calFromFat;
}

float Alimento::GetTotalFatg() const{
  return m_TotalFatg;
}
void Alimento::SetTotalFatg(float totalfatg){
  m_TotalFatg = totalfatg;
}

int Alimento::GetTotalFatDv() const{
  return m_TotalFatDv;
}
void Alimento::SetTotalFatDv(int totalfatdv){
  m_TotalFatDv = totalfatdv;
}

int Alimento::GetSodiumG() const{
  return m_SodiumG;
}
void Alimento::SetSodiumG(int sodium){
  m_SodiumG = sodium;
}

int Alimento::GetSodiumDv() const{
  return m_SodiumDv;
}
void Alimento::SetSodiumDv(int sodiumDv){
  m_SodiumDv = sodiumDv;
}

int Alimento::GetPotassiumG() const{
  return m_Potassiumg;
}
void Alimento::SetPotassiumG(int potassiumg){
  m_Potassiumg = potassiumg;
}

int Alimento::GetPotassiumDv() const{
  return m_PotassiumDv;
}
void Alimento::SetPotassiumDv(int potassiumDv){
  m_PotassiumDv = potassiumDv;
}

int Alimento::GetCarbohyrateg() const{
  return m_Carbohydrateg;
}
void Alimento::SetCarbohyrateg(int carbohydrateg){
  m_Carbohydrateg = carbohydrateg;
}

int Alimento::GetCarbohyrateDv() const{
  return m_CarbohydrateDv;
}
void Alimento::SetCarbohyrateDv(int carbohydrateDv){
  m_CarbohydrateDv=carbohydrateDv;
}

int Alimento::GetFiberg() const{
  return m_Fiberg;
}
void Alimento::SetFiberg(int Fiberg){
  m_Fiberg=Fiberg;
}

int Alimento::GetFiberDv() const{
  return m_FiberDv;
}
void Alimento::SetFiberDv(int FiberDv){
  m_FiberDv=FiberDv;
}

int Alimento::GetSugarsg() const{
  return m_Sugarsg;
}
void Alimento::SetSugarsg(int Sugarsg){
  m_Sugarsg=Sugarsg;
}

int Alimento::GetProteing() const{
  return m_Proteing;
}
void Alimento::SetProteing(int Proteing){
  m_Proteing=Proteing;
}

int Alimento::GetVitADv() const{
  return m_VitADv;
}
void Alimento::SetVitADv(int VitADv){
  m_VitADv = VitADv;
}

int Alimento::GetVitCDv() const{
  return m_VitCDv;
}
void Alimento::SetVitCDv(int VitCDv){
  m_VitCDv = VitCDv;
}

int Alimento::GetCalciumDv() const{
  return m_CalciumDv;
}
void Alimento::SetCalciumDv(int CalciumDv){
  m_CalciumDv = CalciumDv;
}

int Alimento::GetIronDv() const{
  return m_IronDv;
}
void Alimento::SetIronDv(int IronDv){
  m_IronDv = IronDv;
}

float Alimento::GetSaturatedFatDv() const{
  return m_SaturatedFatDv;
}
void Alimento::SetSaturatedFatDv(float SaturatedFatDv){
  m_SaturatedFatDv = SaturatedFatDv;
}

int Alimento::GetSaturatedFatmg() const{
  return m_SaturatedFatmg;
}
void Alimento::SetSaturatedFatmg(int SaturatedFatmg){
  m_SaturatedFatmg = SaturatedFatmg;
}

int Alimento::GetCholesterolDv() const{
  return m_CholesterolDv;
}
void Alimento::SetCholesterolDv(int CholesterolDv){
  m_CholesterolDv = CholesterolDv;
}

int  Alimento::GetCholesterolmg() const{
  return m_Cholesterolmg;
}
void Alimento::SetCholesterolmg(int Cholesterolmg){
  m_Cholesterolmg = Cholesterolmg;
}

std::string Alimento::GetFoodType() const{
  return m_FoodType;
}
void Alimento::SetFoodType(std::string FoodType){
  m_FoodType = FoodType;
}