// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <valarray>


/**
 *	@brief Noise Generator class.
 *	Inherit this class to add more noise algorithm to the list of available ones
 *	@note Does not require to be a UCLASS (for now), it will require to be explicitly and explicitly destroyed
 *	@todo : Add Precision and/or Seed to constructor
 */
class  UNoiseGenerator
{
public :

	/**
	 *	@brief deleted default constructor
	 *	The user MUST specify the size of its array.
	 */
	UNoiseGenerator() = delete;

	/**
	 *	@brief square constructor
	 */
	UNoiseGenerator(unsigned int SquareNoiseMapSize, unsigned char Seed = 0);

	/**
	 *	@brief rectangular constructor
	 */
	UNoiseGenerator(unsigned int XSize, unsigned int YSize, unsigned char Seed = 0);

	/**
	 *	@brief SetSeed : Set a Seed for the generator
	 *	@note Your generator is free to use the seed or not
	 */
	inline virtual void SetSeed(unsigned char Seed) { _Seed = Seed; };

	/**
	 *	@brief GenerateMap : Array of float representing the Noise Map
	 *	@note Will store information into the NoiseMap Property
	 */
	virtual void GenerateMap() = 0;

	/**
	 *	@brief IsSeamlessNoise : tells to know if wee need to make it seamless or not
	 *	@note you must implement it for the generation to work as intended
	 */
	virtual bool IsSeamlessNoise() = 0;
 

	/**
	 *	@brief GetGeneratedMap : Gets a copy of the generated map as a std::vector
	 */
	inline std::valarray<float> GetGeneratedMap() const { return NoiseMap; }


	inline unsigned int XMax() const { return _XSize; }
	inline unsigned int YMax() const { return _YSize; }

	//  subscript operators to get or modify content 
	float& operator() ( int x, int y);				/**	@brief : operator() subscript Reference Getter, @see At() */
	float  operator() ( int x, int y) const;		/**	@brief : operator() subscript Copy Getter, @see At() */

	float operator[](int pos) const;

protected:


	float& At ( int x,  int y);			/**	@brief : At() Reference Getter */
	float  At ( int x,  int y) const;	/**	@brief : At() Copy Getter */

protected :

	/** 
	 *	@brief NoisedMap : Array of float representing the Noise Map
	 *	@note We are using stl for better performance and if someone using another engine comes across this code
	 */
	std::valarray<float> NoiseMap;


	/**
	 *	@brief IsValidSize : adapts the size to something that feat the algorithm
	 */
	virtual bool IsValidSize(unsigned& xsize, unsigned& ysize);


	/**
	 *	@brief GetRand : Gets a random generated value between -1 and 1.
	 *	Generated with the generator default precision
	 */
	virtual float GetRand(float Scale = 1) const;

	/**
	 *	@brief GetSeed : return the seed used for the generator
	 *	allows you to use it where-ever you want;
	 */
	unsigned int GetSeed() const { return _Seed; }

	unsigned int &XSize() { return _XSize; }
	unsigned int &YSize() { return _XSize; }

private :

	unsigned int _XSize;
	unsigned int _YSize;

	unsigned int _bIsSquare : 1;

	

	unsigned char _Seed;
	unsigned long _Precision = 1e6;

public :
	virtual ~UNoiseGenerator();

};
