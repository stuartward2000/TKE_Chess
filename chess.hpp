//
//  chess.hpp
//  KH_Chess
//
//  Created by Stuart Ward on 4/3/21.
//  Copyright © 2021 Stuart Ward. All rights reserved...
//

#define chess_hpp
#include<iostream>

#include <stdio.h>

class Player{
public:
    std::string name;
    int elo_rating;
    double record;
    
Player(std::string new_name, int default_elo_rating = 1200, double new_record = 0.0);
    
};

class dataBase{
public:
    void calculateElo(int &eloRatingPlayerA, int &eloRatingPlayerB, int resultA, int resultB);
    int expectedOutcome(int ratingA, int ratingB);
  
   
};





class hash{
public:
    int Hash(std::string name);
    hash();
    void printTable();
    void addData(std::string name, int elo_rating, int wins, int losses);
    
    void projectedElo(std::string nameA, std::string nameB);
    int expectedOutcome(int ratingA, int ratingB); //needs fixing
    
    
private:
    static const int tableSize = 10;
    struct item{
        std::string name;
        int elo_rating;
        int wins;
        int losses;
        item* next;
    };
    
    item* HashTable[tableSize];
};

/*
class hash{
public:
    int Hash(std::string key);
    hash();
    void addItem(std::string name, std::string drink);
    int numberOfItemsInIndex(int index);
    void printTable();
    void findDrink(std::string name);
private:
    static const int tableSize = 10;
    struct item{
        std::string name;
        std::string drink;
        item* next;
    };
    
    item* HashTable[tableSize];
};

*/
