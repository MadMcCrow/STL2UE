//	Copyright 2019 Noé Perard-Gayot <noe.perard@gmail.com>
//	
//	Licensed under the Apache License, Version 2.0 (the "License");
//	you may not use this file except in compliance with the License.
//	You may obtain a copy of the License at
//	
//	http ://www.apache.org/licenses/LICENSE-2.0
//	
//	Unless required by applicable law or agreed to in writing, software
//	distributed under the License is distributed on an "AS IS" BASIS,
//	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//	See the License for the specific language governing permissions and
//	limitations under the License.

#pragma once

#include "CoreMinimal.h"
#include <valarray>

/**
 *	@brief StdVectorToUE class.
 *	Provide static functions to convert std::vector in TArray and back.
 */
class  StdValarrayToUE
{
public :
	template< typename T>
	static TArray<T> ToArray(const std::valarray<T> &arr);

	template< typename T>
	static std::valarray<T> ToVector(const TArray<T> &arr);

};

template<typename T>
inline TArray<T> StdVectorToUE::ToArray(const std::valarray<T> &arr);
{
	const auto size = arr.size();
	TArray<T> Out;
	Out.AddUninitialized(size);
	FMemory::Memcpy(Out.GetData(), *arr.begin(), size * sizeof(T)); // this only works if valarray is continuous, which I hope it is
	return Out;
}

template< typename T>
inline std::valarray<T> StdVectorToUE::ToVector(const TArray<T> &arr)
{
	const auto size = arr.Num();
	std::vector<T> Out;
	Out.resize(size);
	FMemory::Memcpy(*arr.begin(), arr.GetData(), size * sizeof(T)); // this only works if valarray is continuous, which I hope it is
	return Out;
}


