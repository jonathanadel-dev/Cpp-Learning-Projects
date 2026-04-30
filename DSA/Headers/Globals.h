#pragma once
#include <string>
#include <vector>
#include <set>
using namespace std;


// Loops
void print7(int n);
void print8(int n);
void print9(int n);
void print10(int n);
void print11(int n);
void print12(int n);
void print13(int n);
void print14(int n);
void print17(int n);


// STL
void pairs();
void vectors();
void lists();
void deques();
void stacks();
void queues();
void pqs();
void sets();
void multisets();
void unorderedSets();
void maps();
void multimaps();
void unorderedmaps();


// Sorting algorithms
void sortingFunction();


// Basic Maths
int numberOfDigits(int n);
int numberOfDigits2(int n);
bool isArmstrong(int n);
void printDivisors(int n);
void printDivisors2(int n);
bool isPrime(int n);
bool isPrime2(int n);
int gcd(int n1, int n2);


// Recursion
void print(int i, int n);
void printAsc(int i, int n);
void printDesc(int n);
void printAsc2(int n);
void printDesc2(int i, int n);
int recursionSum(int n, int sum);
int recursionSum2(int n);
int recursionFactorial(int n);
void recursionArrayReverse(int arr[], int i, int size);
void recursionArrayReverse2(int arr[], int i, int size);
bool recursionCheckIfPalindrome(int i, const string& s);
int recursionFib(int n);


// Hashing
void hashingArray(int a[], int size);
void hashingCharacters(string s);
void hashingMap(int a[], int size);
void hashingCharacterMap(string s);


// Sorting
void selectionSort(int a[], int size);
void bubbleSort(int a[], int size);
void bubbleSort2(int a[], int size);
void insertionSort(int a[], int size);
void mergeSort(int a[], int left, int right);
void quickSort(int a[], int left, int right);


// Basic Arrays problems
int greatestElementInTheArray(int a[], int size);
vector<int> secondGreatestElementInTheArray(int a[], int size);
void removeDuplicates(int a[], int size);
void leftRotateAnArrayByOne(int a[], int size);
void leftRotateAnArrayByK(int a[], int size, int k);
void movingZerosToTheEnd(int a[], int size);
void unionOfTwoArrays(int a[], int size, int a1[], int a2[], int size1, int size2);
vector<int> intersectionOfTwoArrays(vector<int> v1, vector<int> v2);
int findMissingNumberInAnArray(vector<int>);
int findTheLongestConsecutiveOnes(vector<int> v);
int longestSubArrayWithLengthK(vector<int> v, int k);


// Medium array problems
vector <int> twoSum(vector <int> v, int target);
void sortArrayOfZerosOnesAndTwos(vector <int> v);
int majorityElement(vector <int> nums);
int maximumSubarray(vector<int> nums);