//
//  main.cpp
//  KH_Chess
//
//  Created by Stuart Ward on 4/3/21.
//  Copyright © 2021 Stuart Ward. All rights reserved.
//j


//issues: Switch statment regardless of 1 or 2 only allows for one input before doing its own thing

#include <iostream>
#include "chess.hpp"
#include <unordered_map>

int main() {
    hash database;
    int number;
    //dataBase KH; gotta delete this useless ass class 
    
                 //(name, elo_rating, wins, losses)
    database.addData("Stuart Ward", 1250, 2, 1);
    database.addData("Casey Hnasko", 1120, 3, 6);
    database.addData("Luke Vu-Nyugen", 940, 1, 5);
    database.addData("Elijah Jenkins", 1300, 3, 1);
    database.addData("Dennis Mikaylov", 1410, 4, 2);
    database.addData("Lazar Agoev", 1430, 5, 1);
    database.addData("Kris Kertenis", 1010, 1, 2);
    database.addData("Elmar Ebrahim", 1325, 3, 1);
    
    
  do
    {
    
    std::cout<<"What do you want:"<<std::endl;
    std::cout<<"1) Insert New Player"<<std::endl;
    std::cout<<"2) Projected Elo "<<std::endl;
    std::cout<<"3) Display Stats"<<std::endl;
    std::cout<<"4) Predict Winner" <<std::endl;
    std::cout<<"0) Exit"<<std::endl;
    std::cin>>number;
    
    
switch(number){
    case 1:{
        std::string name;
        int elo_rating; //default elo = 1200
        int wins = 0; //default record is 0-0
        int losses = 0; //default record is 0-0
        
        std::cout<<"Name: "<<std::endl;
        std::getline(std::cin, name, '\n');
        std::cout<<"Elo Rating:"<<std::endl;
        std::cin>>elo_rating;
        std::cout<<"Wins:"<<std::endl;
        std::cin>>wins;
        std::cout<<"Losses: "<<std::endl;
        std::cin>>losses;
        database.addData(name, elo_rating, wins, losses);
    break;
    }
    case 2:{
        std::string playerA;
        std::string playerB;
        std::cout<<"Player A : "<<std::endl;
        std::cin>>playerA;
        std::cout<<"Player B : "<<std::endl;
        std::cin>>playerB;
        
        database.projectedElo(playerA, playerB);
    
    break;
    }
    case 3:{
        database.printTable();
    break;
    }
    default:
        std::cout<<"Program Exit"<<std::endl;
}
    }while(number!=0);
    
    return 0;
}
