# STL2UE
A simple library to use stl in UE4 project

# How to Use

The library is header based and offer static classes to make conversions.
You can either include individual headers or just STL2UE.h 

## Exemple

```
std::vector<float> randomNumbers{ 12.43, 3.14, 7.32 }; 
TArray<float> AsTArray = StdVectorToUE::ToArray(const std::vector<T> &arr);
// AsTArray now contains 12.43  3.14  7.32 
```
