/* 
Utils.h

Eduardo Veit Ferrão - 32150180
Leonardo Biagiotti Beloti - 32160062
Lucas Damasceno de Cunha Lima - 32132611
Lucas Iudi Corregliano Gallinari - 32138628
Thiago Aidar Figueiredo - 32144547
*/

#ifndef __UTILS_H__
#define __UTILS_H__

namespace Utils
{
	template <typename T>
	static T Max(T l, T r)
	{
		return (l > r) ? l : r;
	}
}

#endif