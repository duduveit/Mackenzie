#include "HashTable.h"
#include <sstream>

HashTable::HashTable()
	: HashTable(DEFAULT_SIZE)
{
}

HashTable::HashTable(int size)
	: m_Size(size)
{
	m_Table = new LinkedList[m_Size];
}

HashTable::~HashTable()
{
	delete[] m_Table;
	m_Table = nullptr;
}

std::string HashTable::Search(int key) const
{
	int hashKey = HashFunction(key);

	const Node* node = m_Table[hashKey].GetNode(key);
	if (node)
		return node->GetValue();

	return "";
}

HashTable::InsertResult HashTable::Insert(int key, const std::string& value)
{
	int hashKey = HashFunction(key);
	InsertResult result = m_Table[hashKey].IsEmpty() ? InsertResult::WithoutCollision : InsertResult::WithCollision;

	Node* node = m_Table[hashKey].GetNode(key);
	if (node)
	{
		node->SetValue(value);
		result = InsertResult::Updated;
	}
	else
	{
		m_Table[hashKey].Append(key, value);
	}

	return result;
}

bool HashTable::Remove(int key)
{
	int hashKey = HashFunction(key);

	Node* node = m_Table[hashKey].RemoveNode(key);
	if (node)
	{
		delete node;
		node = nullptr;

		return true;
	}

	return false;
}

bool HashTable::IsEmpty() const
{
	bool isEmpty = true;

	for (int i = 0; i < m_Size; ++i)
	{
		isEmpty &= m_Table[i].IsEmpty();
	}

	return isEmpty;
}

std::string HashTable::ToString() const
{
	std::ostringstream oss;

	for (int i = 0; i < m_Size; ++i)
		oss << "[" << i << "] " << m_Table[i].ToString() << '\n';

	return oss.str();
}

int HashTable::HashFunction(int key) const
{
  int Hashing=Extraction(key,0,0);
  Hashing=Hashing*Hashing;
  int  tam= Count(Hashing,1);
  return Quadratic(Hashing,0,0,tam)% m_Size;
}

int HashTable::Extraction(int x, int n, int  total) const{
  if(x >= 10)
       total= Extraction(x/10,n+1,total);
  int digit = x % 10;
  if(n==0||n==2||n==4){
    if(n==0) total=total+(digit*1);
    if(n==2) total=total+(digit*10);
    if(n==4) total=total+(digit*100);
  }
  return total;
}

int HashTable::Quadratic(long int x, int n, int total, int tam) const{
  if(x >= 10)
       total= Quadratic(x/10,n+1,total,tam);
  
  int digit = x % 10;
  if(tam%2==0){
    int metade=tam/2;
    if(n==metade-1||n==metade){
    if(n==metade-1) total=total+(digit*1);
    if(n==metade) total=total+(digit*10);
  }
  }
  else{
    int metade= (tam/2)-0.5;
    if(n==metade) total=total+(digit*1);
  }
  return total;
}

int HashTable::Count(long int x, int n) const{
  if(x >= 10)
       n= Count(x/10,n+1);

  return n;
}