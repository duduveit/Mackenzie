#ifndef __ALIMENTO_H__
#define __ALIMENTO_H__

#include <string>

class Alimento{
public:
  Alimento(int calories, int caloriesfromfat, float totalfatg, int totalfatdv, int sodium, int sodiumdv, int potassiumg, int potassiumdv, int carbohydrateg, int carbohydratedv, int fiberg, int fiberdv, int sugarsg, int proteing, int vitadv, int vitcdv, int calciumdv, int irondv, float saturatedfatdv, int saturatedfatmg, int cholesteroldv, int cholesterolmg, std::string foodtype);
  ~Alimento();

  std::string PrintTabela() const;

  int GetCal() const;
  void SetCal(int cal);

  int GetCalFromFat() const;
  void SetCalFromFat(int calFromFat);

  float GetTotalFatg() const;
  void SetTotalFatg(float totalFatg);

  int GetTotalFatDv() const;
  void SetTotalFatDv(int totalFatDv);

  int GetSodiumG() const;
  void SetSodiumG(int sodium);

  int GetSodiumDv() const;
  void SetSodiumDv(int sodiumDv);

  int GetPotassiumG() const;
  void SetPotassiumG(int potassiumMg);

  int GetPotassiumDv() const;
  void SetPotassiumDv(int potassiumDv);

  int GetCarbohyrateg() const;
  void SetCarbohyrateg(int carbohydrateg);

  int GetCarbohyrateDv() const;
  void SetCarbohyrateDv(int carbohydrateDv);

  int GetFiberg() const;
  void SetFiberg(int Fiberg);

  int GetFiberDv() const;
  void SetFiberDv(int FiberDv);

  int GetSugarsg() const;
  void SetSugarsg(int Sugarsg);

  int GetProteing() const;
  void SetProteing(int Proteing);

  int GetVitADv() const;
  void SetVitADv(int VitADv);

  int GetVitCDv() const;
  void SetVitCDv(int VitCDv);

  int GetCalciumDv() const;
  void SetCalciumDv(int CalciumDv);

  int GetIronDv() const;
  void SetIronDv(int IronDv);

  float GetSaturatedFatDv() const;
  void SetSaturatedFatDv(float SaturatedFatDv);

  int GetSaturatedFatmg() const;
  void SetSaturatedFatmg(int SaturatedFatmg);

  int GetCholesterolDv() const;
  void SetCholesterolDv(int CholesterolDv);

  int GetCholesterolmg() const;
  void SetCholesterolmg(int Cholesterolmg);

  std::string GetFoodType() const;
  void SetFoodType(std::string FoodType);

private:
  int m_Cal;
  int m_CalFromFat;
  float m_TotalFatg;
  int m_TotalFatDv;
  int m_SodiumG;
  int m_SodiumDv;
  int m_Potassiumg;
  int m_PotassiumDv;
  int m_Carbohydrateg;
  int m_CarbohydrateDv;
  int m_Fiberg;
  int m_FiberDv;
  int m_Sugarsg;
  int m_Proteing;
  int m_VitADv;
  int m_VitCDv;
  int m_CalciumDv;
  int m_IronDv;
  float m_SaturatedFatDv;
  int m_SaturatedFatmg;
  int m_CholesterolDv;
  int m_Cholesterolmg;
  std::string m_FoodType;
};

#endif