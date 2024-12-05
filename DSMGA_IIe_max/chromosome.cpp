/***************************************************************************
 *   Copyright (C) 2015 by TEIL                                            *
 ***************************************************************************/

#include <cstdio>
#include <cstring>
#include "spin.h"
#include "chromosome.h"
#include "nk-wa.h"
#include "sat.h"
#include <iostream>
// #include <bits/algorithmfwd.h>
#include <algorithm>
#include <random>
#include <typeinfo>

using namespace std;

#define TRAP_K 4

// OneMax
// double Chromosome::oneMax (double fHigh4, double fLow4, double fHigh3, double fLow3) const {

//     double result = 0;

//     for (int i = 0; i < length; ++i)
//         result += getVal(i);

//     return result;
// }

// max(onemax, zeromax)
// double Chromosome::oneMax (double fHigh4, double fLow4, double fHigh3, double fLow3) const {

//     double result = 0;

//     for (int i = 0; i < length; ++i)
//         result += getVal(i);

//     return std::max(result, length-result);
// }

// ##########################################################################################################################################################################################
// ##########################################################################################################################################################################################
// ##########################################################################################################################################################################################
// BB 相同 ##########################################################################################################################################################################################
// double Chromosome::oneMax(double fHigh4, double fLow4, double fHigh3, double fLow3) const {
//     int DEBUG = 0;

//     if (DEBUG)
//     {
//         cout << "############################### DEBUG BB 相同 ###############################" << endl;
//     }
   
//     // int TRAP_M4 = length / 4;
//     int indices4_1[length]; // 初始化索引陣列
//     for (int i = 0; i < length; ++i) {
//         indices4_1[i] = i;
//     }    

//     // if (DEBUG)
//     // {
//     //     cout << "---indices4_1----" << endl;
//     //     for (int i = 0; i < length; ++i) {
//     //         std::cout << indices4_1[i] << " ";
//     //     }
//     //     std::cout << std::endl;
//     // }

//     int* chrom4_1 = new int[length];
//     for (int i = 0; i < length; i++)
//         chrom4_1[indices4_1[i]] = getVal(i);



//     double result4_1 = 0;
//     int u4_1;
//     for (int i = 0; i < length; i+=4)
//     {   
//         u4_1 = 0;
//         for (int j = i; j < i+4; j++)
//         {
//             u4_1 += chrom4_1[j];
//         }

//         if (u4_1 == 4)
//             result4_1 += 4;
//         else if (u4_1 == 0)
//             result4_1 += 3;
//         else if (u4_1 == 1)
//             result4_1 += 2;
//         else if (u4_1 == 2)
//             result4_1 += 1;
//         else if (u4_1 == 3)
//             result4_1 += 0;
//     }

//     if (DEBUG)
//     {
//         cout << "---chrom4_1----" << endl;
//         for (int i = 0; i < length; ++i) {
//             std::cout << chrom4_1[i] << " ";
//         }
//         cout << " fitness " << result4_1 << std::endl;
//     }  
    

//     //###########################################
 
//     // int TRAP_M4 = length / 4;
//     int indices4_0[length]; // 初始化索引陣列
//     for (int i = 0; i < length; ++i) {
//         indices4_0[i] = i;
//     }


//     // std::default_random_engine rng4(42); // 使用固定種子
//     // std::shuffle(indices4, indices4 + length, rng4); // 使用 std::shuffle
    

//     // if (DEBUG)
//     // {
//     //     cout << "---indices4_0----" << endl;
//     //     for (int i = 0; i < length; ++i) {
//     //         std::cout << indices4_0[i] << " ";
//     //     }
//     //     std::cout << std::endl;
//     // }



//     int* chrom4_0 = new int[length];
//     for (int i = 0; i < length; i++)
//         chrom4_0[indices4_0[i]] = getVal(i);
    


//     double result4_0 = 0;
//     int u4_0;
//     for (int i = 0; i < length; i+=4)
//     {   
//         u4_0 = 0;
//         for (int j = i; j < i+4; j++)
//         {
//             u4_0 += chrom4_0[j];
//         }

//         if (u4_0 == 4)
//             result4_0 += 3;
//         else if (u4_0 == 0)
//             result4_0 += 4;
//         else if (u4_0 == 1)
//             result4_0 += 0;
//         else if (u4_0 == 2)
//             result4_0 += 1;
//         else if (u4_0 == 3)
//             result4_0 += 2;
//     }
    
//     if (DEBUG)
//     {
//         cout << "---chrom4_0----" << endl;
//         for (int i = 0; i < length; ++i) {
//             std::cout << chrom4_0[i] << " ";
//         }
       

//         cout << " fitness " << result4_0 << std::endl;
//     }

//     delete []chrom4_1;
//     delete []chrom4_0;
//     if (DEBUG)
//         std::cout << "Fitness = " << std::max(result4_1, result4_0) << std::endl;
//     return std::max(result4_1, result4_0);

// }
// ##########################################################################################################################################################################################
// ##########################################################################################################################################################################################
// ##########################################################################################################################################################################################





// ##########################################################################################################################################################################################
// ##########################################################################################################################################################################################
// ##########################################################################################################################################################################################
// BB 不同 step 1 ##########################################################################################################################################################################################
// double Chromosome::oneMax(double fHigh4, double fLow4, double fHigh3, double fLow3) const {
//     int DEBUG = 0;

//     if (DEBUG)
//     {
//         std::cout << "############################### DEBUG BB 不同 step 1 ###############################" << std::endl;
//     }
   
//     // int TRAP_M4 = length / 4;
//     int indices4_1[length]; // 初始化索引陣列
//     for (int i = 0; i < length; ++i) {
//         indices4_1[i] = i;
//     }    

//     // if (DEBUG)
//     // {
//     //     cout << "---indices4_1----" << endl;
//     //     for (int i = 0; i < length; ++i) {
//     //         std::cout << indices4_1[i] << " ";
//     //     }
//     //     std::cout << std::endl;
//     // }

//     int* chrom4_1 = new int[length];
//     for (int i = 0; i < length; i++)
//         chrom4_1[indices4_1[i]] = getVal(i);



//     double result4_1 = 0;
//     int u4_1;
//     for (int i = 0; i < length; i+=4)
//     {   
//         u4_1 = 0;
//         for (int j = i; j < i+4; j++)
//         {
//             u4_1 += chrom4_1[j];
//         }

//         if (u4_1 == 4)
//             result4_1 += 4;
//         else if (u4_1 == 0)
//             result4_1 += 3;
//         else if (u4_1 == 1)
//             result4_1 += 2;
//         else if (u4_1 == 2)
//             result4_1 += 1;
//         else if (u4_1 == 3)
//             result4_1 += 0;
//     }

//     if (DEBUG)
//     {
//         cout << "---chrom4_1----" << endl;
//         for (int i = 0; i < length; ++i) {
//             std::cout << chrom4_1[i] << " ";
//         }
//         cout << " fitness " << result4_1 << std::endl;
//     }  
    

//     //###########################################
 
//     // int TRAP_M4 = length / 4;
//     int indices4_0[length]; // 初始化索引陣列
//     for (int i = 0; i < length; ++i) {
//         indices4_0[i] = i;
//     }


//     // std::default_random_engine rng4(42); // 使用固定種子
//     // std::shuffle(indices4, indices4 + length, rng4); // 使用 std::shuffle
    

//     // if (DEBUG)
//     // {
//     //     cout << "---indices4_0----" << endl;
//     //     for (int i = 0; i < length; ++i) {
//     //         std::cout << indices4_0[i] << " ";
//     //     }
//     //     std::cout << std::endl;
//     // }



//     int* chrom4_0 = new int[length];
//     for (int i = 0; i < length; i++){
//         int step = 1;
//         int steped_index = (i+step)%length;
//         chrom4_0[indices4_0[i]] = getVal(steped_index);
//     }
    


//     double result4_0 = 0;
//     int u4_0;
//     for (int i = 0; i < length; i+=4)
//     {   
//         u4_0 = 0;
//         for (int j = i; j < i+4; j++)
//         {
//             u4_0 += chrom4_0[j];
//         }

//         if (u4_0 == 4)
//             result4_0 += 3;
//         else if (u4_0 == 0)
//             result4_0 += 4;
//         else if (u4_0 == 1)
//             result4_0 += 0;
//         else if (u4_0 == 2)
//             result4_0 += 1;
//         else if (u4_0 == 3)
//             result4_0 += 2;
//     }
    
//     if (DEBUG)
//     {
//         cout << "---chrom4_0----" << endl;
//         for (int i = 0; i < length; ++i) {
//             std::cout << chrom4_0[i] << " ";
//         }
       

//         cout << " fitness " << result4_0 << std::endl;
//     }

//     delete []chrom4_1;
//     delete []chrom4_0;

//     if (DEBUG)
//         std::cout << "Fitness = " << std::max(result4_1, result4_0) << std::endl;
//     return std::max(result4_1, result4_0);

// }
// ##########################################################################################################################################################################################
// ##########################################################################################################################################################################################
// ##########################################################################################################################################################################################




// ##########################################################################################################################################################################################
// ##########################################################################################################################################################################################
// ##########################################################################################################################################################################################
// BB 不同 step 2 ##########################################################################################################################################################################################
// double Chromosome::oneMax(double fHigh4, double fLow4, double fHigh3, double fLow3) const {
//     int DEBUG = 0;

//     if (DEBUG)
//     {
//         cout << "############################### DEBUG BB 不同 step 2 ###############################" << endl;
//     }
   
//     // int TRAP_M4 = length / 4;
//     int indices4_1[length]; // 初始化索引陣列
//     for (int i = 0; i < length; ++i) {
//         indices4_1[i] = i;
//     }    

//     // if (DEBUG)
//     // {
//     //     cout << "---indices4_1----" << endl;
//     //     for (int i = 0; i < length; ++i) {
//     //         std::cout << indices4_1[i] << " ";
//     //     }
//     //     std::cout << std::endl;
//     // }

//     int* chrom4_1 = new int[length];
//     for (int i = 0; i < length; i++)
//         chrom4_1[indices4_1[i]] = getVal(i);



//     double result4_1 = 0;
//     int u4_1;
//     for (int i = 0; i < length; i+=4)
//     {   
//         u4_1 = 0;
//         for (int j = i; j < i+4; j++)
//         {
//             u4_1 += chrom4_1[j];
//         }

//         if (u4_1 == 4)
//             result4_1 += 4;
//         else if (u4_1 == 0)
//             result4_1 += 3;
//         else if (u4_1 == 1)
//             result4_1 += 2;
//         else if (u4_1 == 2)
//             result4_1 += 1;
//         else if (u4_1 == 3)
//             result4_1 += 0;
//     }

//     if (DEBUG)
//     {
//         cout << "---chrom4_1----" << endl;
//         for (int i = 0; i < length; ++i) {
//             std::cout << chrom4_1[i] << " ";
//         }
//         cout << " fitness " << result4_1 << std::endl;
//     }  
    

//     //###########################################
 
//     // int TRAP_M4 = length / 4;
//     int indices4_0[length]; // 初始化索引陣列
//     for (int i = 0; i < length; ++i) {
//         indices4_0[i] = i;
//     }


//     // std::default_random_engine rng4(42); // 使用固定種子
//     // std::shuffle(indices4, indices4 + length, rng4); // 使用 std::shuffle
    

//     // if (DEBUG)
//     // {
//     //     cout << "---indices4_0----" << endl;
//     //     for (int i = 0; i < length; ++i) {
//     //         std::cout << indices4_0[i] << " ";
//     //     }
//     //     std::cout << std::endl;
//     // }



//     int* chrom4_0 = new int[length];
//     for (int i = 0; i < length; i++){
//         int step = 2;
//         int steped_index = (i+step)%length;
//         chrom4_0[indices4_0[i]] = getVal(steped_index);
//     }
    


//     double result4_0 = 0;
//     int u4_0;
//     for (int i = 0; i < length; i+=4)
//     {   
//         u4_0 = 0;
//         for (int j = i; j < i+4; j++)
//         {
//             u4_0 += chrom4_0[j];
//         }

//         if (u4_0 == 4)
//             result4_0 += 3;
//         else if (u4_0 == 0)
//             result4_0 += 4;
//         else if (u4_0 == 1)
//             result4_0 += 0;
//         else if (u4_0 == 2)
//             result4_0 += 1;
//         else if (u4_0 == 3)
//             result4_0 += 2;
//     }
    
//     if (DEBUG)
//     {
//         cout << "---chrom4_0----" << endl;
//         for (int i = 0; i < length; ++i) {
//             std::cout << chrom4_0[i] << " ";
//         }
       

//         cout << " fitness " << result4_0 << std::endl;
//     }

//     delete []chrom4_1;
//     delete []chrom4_0;
//     if (DEBUG)
//         std::cout << "Fitness = " << std::max(result4_1, result4_0) << std::endl;
//     return std::max(result4_1, result4_0);

// }
// ##########################################################################################################################################################################################
// ##########################################################################################################################################################################################
// ##########################################################################################################################################################################################





// ##########################################################################################################################################################################################
// ##########################################################################################################################################################################################
// ##########################################################################################################################################################################################
// // BB 不同 step 3 ##########################################################################################################################################################################################
// double Chromosome::oneMax(double fHigh4, double fLow4, double fHigh3, double fLow3) const {
//     int DEBUG = 0;

//     if (DEBUG)
//     {
//         cout << "############################### DEBUG BB 不同 step 3 ###############################" << endl;
//     }
   
//     // int TRAP_M4 = length / 4;
//     int indices4_1[length]; // 初始化索引陣列
//     for (int i = 0; i < length; ++i) {
//         indices4_1[i] = i;
//     }    

//     // if (DEBUG)
//     // {
//     //     cout << "---indices4_1----" << endl;
//     //     for (int i = 0; i < length; ++i) {
//     //         std::cout << indices4_1[i] << " ";
//     //     }
//     //     std::cout << std::endl;
//     // }

//     int* chrom4_1 = new int[length];
//     for (int i = 0; i < length; i++)
//         chrom4_1[indices4_1[i]] = getVal(i);



//     double result4_1 = 0;
//     int u4_1;
//     for (int i = 0; i < length; i+=4)
//     {   
//         u4_1 = 0;
//         for (int j = i; j < i+4; j++)
//         {
//             u4_1 += chrom4_1[j];
//         }

//         if (u4_1 == 4)
//             result4_1 += 4;
//         else if (u4_1 == 0)
//             result4_1 += 3;
//         else if (u4_1 == 1)
//             result4_1 += 2;
//         else if (u4_1 == 2)
//             result4_1 += 1;
//         else if (u4_1 == 3)
//             result4_1 += 0;
//     }

//     if (DEBUG)
//     {
//         cout << "---chrom4_1----" << endl;
//         for (int i = 0; i < length; ++i) {
//             std::cout << chrom4_1[i] << " ";
//         }
//         cout << " fitness " << result4_1 << std::endl;
//     }  
    

//     //###########################################
 
//     // int TRAP_M4 = length / 4;
//     int indices4_0[length]; // 初始化索引陣列
//     for (int i = 0; i < length; ++i) {
//         indices4_0[i] = i;
//     }


//     // std::default_random_engine rng4(42); // 使用固定種子
//     // std::shuffle(indices4, indices4 + length, rng4); // 使用 std::shuffle
    

//     // if (DEBUG)
//     // {
//     //     cout << "---indices4_0----" << endl;
//     //     for (int i = 0; i < length; ++i) {
//     //         std::cout << indices4_0[i] << " ";
//     //     }
//     //     std::cout << std::endl;
//     // }



//     int* chrom4_0 = new int[length];
//     for (int i = 0; i < length; i++){
//         int step = 3;
//         int steped_index = (i+step)%length;
//         chrom4_0[indices4_0[i]] = getVal(steped_index);
//     }
    


//     double result4_0 = 0;
//     int u4_0;
//     for (int i = 0; i < length; i+=4)
//     {   
//         u4_0 = 0;
//         for (int j = i; j < i+4; j++)
//         {
//             u4_0 += chrom4_0[j];
//         }

//         if (u4_0 == 4)
//             result4_0 += 3;
//         else if (u4_0 == 0)
//             result4_0 += 4;
//         else if (u4_0 == 1)
//             result4_0 += 0;
//         else if (u4_0 == 2)
//             result4_0 += 1;
//         else if (u4_0 == 3)
//             result4_0 += 2;
//     }
    
//     if (DEBUG)
//     {
//         cout << "---chrom4_0----" << endl;
//         for (int i = 0; i < length; ++i) {
//             std::cout << chrom4_0[i] << " ";
//         }
       

//         cout << " fitness " << result4_0 << std::endl;
//     }

//     delete []chrom4_1;
//     delete []chrom4_0;
//     if (DEBUG)
//         std::cout << "Fitness = " << std::max(result4_1, result4_0) << std::endl;
//     return std::max(result4_1, result4_0);

// }
// // ##########################################################################################################################################################################################
// // ##########################################################################################################################################################################################
// // ##########################################################################################################################################################################################





// ##########################################################################################################################################################################################
// ##########################################################################################################################################################################################
// ##########################################################################################################################################################################################
// single_mk(4, 3) ##########################################################################################################################################################################################
double Chromosome::oneMax(double fHigh4, double fLow4, double fHigh3, double fLow3) const {
    int DEBUG = 0;

    if (DEBUG)
    {
        cout << "############################### DEBUG single_mk(4, 3) ###############################" << endl;
    }
   
    // int TRAP_M4 = length / 4;
    int indices4_1[length]; // 初始化索引陣列
    for (int i = 0; i < length; ++i) {
        indices4_1[i] = i;
    }    

    // if (DEBUG)
    // {
    //     cout << "---indices4_1----" << endl;
    //     for (int i = 0; i < length; ++i) {
    //         std::cout << indices4_1[i] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    int* chrom4_1 = new int[length];
    for (int i = 0; i < length; i++)
        chrom4_1[indices4_1[i]] = getVal(i);



    double result4_1 = 0;
    int u4_1;
    for (int i = 0; i < length; i+=4)
    {   
        u4_1 = 0;
        for (int j = i; j < i+4; j++)
        {
            u4_1 += chrom4_1[j];
        }

        if (u4_1 == 4)
            result4_1 += 4;
        else if (u4_1 == 0)
            result4_1 += 3;
        else if (u4_1 == 1)
            result4_1 += 2;
        else if (u4_1 == 2)
            result4_1 += 1;
        else if (u4_1 == 3)
            result4_1 += 0;
    }

    if (DEBUG)
    {
        cout << "---chrom4_1----" << endl;
        for (int i = 0; i < length; ++i) {
            std::cout << chrom4_1[i] << " ";
        }
        cout << " fitness " << result4_1 << std::endl;
    }  
    

    //###########################################
 

   
    delete []chrom4_1;
    if (DEBUG)
        std::cout << "Fitness = " << result4_1<< std::endl;
    return result4_1;

}
// ##########################################################################################################################################################################################
// ##########################################################################################################################################################################################
// ##########################################################################################################################################################################################



Chromosome::Chromosome () {
    length = 0;
    lengthLong = 0;
    gene = NULL;
    evaluated = false;
}

Chromosome::Chromosome (int n_length) {
    gene = NULL;
    init (n_length);
}


Chromosome::~Chromosome () {
    if (gene != NULL) delete []gene;
}

void Chromosome::init (int _length) {
    length = _length;
    lengthLong = quotientLong(length)+1;

    if (gene != NULL)
        delete []gene;

    gene = new unsigned long [lengthLong];
    gene[lengthLong-1] = 0;

    evaluated = false;
}

void Chromosome::init0 (int _length) {
    length = _length;
    lengthLong = quotientLong(length)+1;

    if (gene != NULL)
        delete []gene;

    gene = new unsigned long [lengthLong];

    for (int i=0; i<lengthLong; ++i)
        gene[i] = 0;

    key = 0;
    evaluated = false;
}

void Chromosome::initR (int _length) {
    length = _length;
    lengthLong = quotientLong(length)+1;

    if (gene != NULL)
        delete []gene;

    gene = new unsigned long [lengthLong];
    gene[lengthLong-1] = 0;

    key = 0;
    for (int i=0; i<length; ++i) {

        int val = myRand.flip();
        setValF(i, val);
        if (val == 1)
            key ^= zKey[i];
    }

    evaluated = false;
}

double Chromosome::getFitness () {
    if (evaluated)
        return fitness;
    else {
        fitness = evaluate();
        if (!hit && fitness > getMaxFitness()) {
            hit = true;
            hitnfe = nfe+lsnfe;
        }
        return fitness;
    }
}

bool Chromosome::isEvaluated () const {
    return evaluated;
}

bool Chromosome::hasSeen() const {

    unordered_map<unsigned long, double>::iterator it = cache.find(key);
    if (it != cache.end())
        return true;
    return false;
}

double Chromosome::evaluate () {


    if (CACHE)
        if (hasSeen()) {
            evaluated = true;
            return cache[key];
        }

    ++nfe;
    evaluated = true;
    double accum = 0.0;

    switch (function) {
        case ONEMAX:
            accum = oneMax(4, 3, 3, 2);
            break;
        case MKTRAP:
            accum = mkTrap(1, 0.8);
            break;
        case CYCTRAP:
            accum = cycTrap(1, 0.8);
            break;
        case FTRAP:
            accum = fTrap();
            break;
        case SPINGLASS:
            accum = spinGlass();
            break;
        case NK:
            accum = nkFitness();
            break;
        case SAT:
            accum = satFitness();
            break;
        default:
            accum = mkTrap(1, 0.8);
            break;
    }

    if (CACHE)
        cache[key]=accum;

    return accum;

}



double
Chromosome::spinGlass () const {

    int *x = new int[length];
    double result;

    for (int i=0; i<length; i++)
        if (getVal(i) == 1)
            x[i] = 1;
        else
            x[i] = -1;

    result = evaluateSPIN(x, &mySpinGlassParams);

    delete []x;

    return result;
}

double Chromosome::nkFitness() const {
    char *x = new char[length];

    for ( int i = 0; i < length; ++i) {
        x[i] = (char) getVal(i);
    }

    double result = evaluateNKProblem(x, &nkwa);
    //double result = evaluateNKWAProblem(x, &nkwa);
    delete []x;
    return result;
}

// OneMax
// double Chromosome::oneMax () const {

//     double result = 0;

//     for (int i = 0; i < length; ++i)
//         result += getVal(i);

//     return result;
// }


bool Chromosome::operator== (const Chromosome& c) const {
    if (length != c.length)
        return false;

    for (int i=0; i<lengthLong; i++)
        if (gene[i] != c.gene[i])
            return false;

    return true;
}

Chromosome& Chromosome::operator= (const Chromosome& c) {

    if (length != c.length) {
        length = c.length;
        init (length);
    }

    evaluated = c.evaluated;
    fitness = c.fitness;
    lengthLong = c.lengthLong;
    key = c.key;

    memcpy(gene, c.gene, sizeof(long) * lengthLong);

    return *this;
}

double Chromosome::trap (int unitary, double fHigh, double fLow, int trapK) const {
    if (unitary > trapK)
        return 0;

    if (unitary == trapK)
        return fHigh;
    else
        return fLow - unitary * fLow / (trapK-1);
}


double Chromosome::fTrap() const {

    double result = 0.0;

    for (int i=0; i<length/6; ++i) {
        int u=0;
        for (int j=0; j<6; ++j)
            u += getVal(i*6+j);

        if (u==0)
            result += 1.0;
        else if (u==1)
            result += 0.0;
        else if (u==2)
            result += 0.4;
        else if (u==3)
            result += 0.8;
        else if (u==4)
            result += 0.4;
        else if (u==5)
            result += 0.0;
        else // u == 6
            result += 1.0;
    }

    return result;
}

double Chromosome::cycTrap(double fHigh, double fLow) const {
    int i, j;
    int u;
    int TRAP_M = length / (TRAP_K-1);
    if (length % (TRAP_K-1) != 0)
        outputErrMsg ("TRAP_k doesn't divide length for Cyclic Setting");
    double result = 0;
    for (i = 0; i < TRAP_M; i++) {
        u = 0;
        int idx = i * TRAP_K - i;
        for (j = 0; j < TRAP_K; j++) {
            int pos = idx + j;
            if (pos == length)
                pos = 0;
            else if (pos > length)
                outputErrMsg ("CYCLIC BUG");
            //
            u += getVal(pos);
        }
        result += trap (u, fHigh, fLow, TRAP_K);
    }
    return result;
}



double Chromosome::mkTrap (double fHigh, double fLow) const {
    int i, j;
    int u;

    int TRAP_M = length / TRAP_K;

    if (length % TRAP_K != 0)
        outputErrMsg ("TRAP_K doesn't divide length");

    double result = 0;

    for (i = 0; i < TRAP_M; i++) {
        u = 0;
        for (j = 0; j < TRAP_K; j++)
            u += getVal(i * TRAP_K + j);

        result += trap (u, fHigh, fLow, TRAP_K);
    }

    return result;
}


int Chromosome::getLength () const {
    return length;
}

double Chromosome::getMaxFitness () const {

    double maxF;

    switch (function) {
        case ONEMAX:
            maxF = length;
            break;
        case MKTRAP:
            maxF = length/TRAP_K;
            break;
        case FTRAP:
            maxF = length/6;
            break;
        case CYCTRAP:
            maxF =  length/(TRAP_K - 1);
            break;
        case SPINGLASS:
            maxF = mySpinGlassParams.opt;
            break;
        case NK:
            maxF = nkwa.maxF;
            break;
        case SAT:
            maxF = 0;
            break;
        default:
            // Never converge
            maxF = INF;
    }

    return maxF - EPSILON;

}

// contribute to lsnfe
bool Chromosome::tryFlipping(int index) {

    int oldNFE = nfe;

    double oldF = getFitness();
    flip(index);

    //2016-10-21
    if (getFitness() - EPSILON <= oldF) {
    //if (getFitness() <= oldF) {
        flip(index);
        evaluated = true;
        fitness = oldF;

        lsnfe += nfe - oldNFE;
        nfe = oldNFE;

        return false;
    } else {

        lsnfe += nfe - oldNFE;
        nfe = oldNFE;

        return true;
    }


}

bool Chromosome::GHC() {

    int* order = new int [length];
    myRand.uniformArray(order, length, 0, length-1);

    bool flag = false;
    for (int i=0; i<length; ++i) {
        if (tryFlipping(order[i])) flag = true;
    }

    delete []order;
    return flag;

}

double Chromosome::satFitness() const {
    int *x = new int[length];

    for ( int i = 0; i < length; ++i) {
        x[i] = getVal(i);
    }

    double result = evaluateSAT(x, &mySAT);
    delete []x;
    return result;
}
