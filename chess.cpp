//
//  chess.cpp
//  KH_Chess
//
//  Created by Stuart Ward on 4/3/21.
//  Copyright © 2021 Stuart Ward. All rights reserved...
///

#include "chess.hpp"

Player::Player(std::string new_name, int default_elo_rating, double new_record){
    name = new_name;
    elo_rating = default_elo_rating;
    record = new_record;
}

void dataBase::calculateElo(int &eloRatingPlayerA, int &eloRatingPlayerB, int resultA, int resultB){
    //Expected outcome of Player A = 1 / (1 + 10^((RatingB -RatingA)/400)
    //new rating = rating + 32(score - expected score)
     int new_elo;
    std::cout<<"EloA "<<eloRatingPlayerA<<std::endl;
    std::cout<<"EloB "<<eloRatingPlayerB<<std::endl;
    if(resultA == 1){
    new_elo = eloRatingPlayerA + 32*(resultA - expectedOutcome(eloRatingPlayerA, eloRatingPlayerB));
        std::cout<<"New Elo: " << new_elo<<std::endl;
        
    int difference = abs(eloRatingPlayerA - new_elo);
        std::cout<<"Difference : " << difference<<std::endl;
        
    eloRatingPlayerA = new_elo;
    eloRatingPlayerB -= difference;
    }
    
    else if(resultB==1){
        new_elo = eloRatingPlayerB + 32*(resultB - expectedOutcome(eloRatingPlayerB, eloRatingPlayerA));
        int difference = abs(eloRatingPlayerB - new_elo);
        eloRatingPlayerB = new_elo;
        eloRatingPlayerA -= difference;
    }
  
    //tie scenario
    
}

int dataBase::expectedOutcome(int ratingA, int ratingB){
    int projection;
    int differenceRating = ratingB - ratingA;
    projection = 1 / (1 + 10^(differenceRating/400));
    return projection;
}






hash::hash(){
    for(int i =0; i<tableSize; i++){
        HashTable[i] = new item;
        HashTable[i]->name = "empty";
        HashTable[i]->next = NULL;
    }
}



int hash::Hash(std::string name){
    int hash = 0;
    int index;
    
    for(int i = 0; i< name.length(); i++){
        hash = hash + (int)name[i];
       
    }
    index = hash%tableSize;
    return index;
}




void hash::addData(std::string name, int elo_rating, int wins, int losses){
    int index = Hash(name); //value of bucket index
    if(HashTable[index]->name == "empty"){
        HashTable[index]->name = name;
        HashTable[index]->elo_rating = elo_rating;
        HashTable[index]->wins = wins;
        HashTable[index]->losses = losses;
    }
    else{
        
        item* Ptr = HashTable[index];
        item* n = new item;
        n->name = name;
        n->elo_rating = elo_rating;
        n->wins = wins;
        n->losses = losses;
        n->next = NULL;
        
        while(Ptr->next != NULL){ //traversing thru index values until we get empty                             space
            Ptr = Ptr -> next;
        }
        Ptr->next = n;
    }
}


void hash::printTable(){
    
    for(int i =0; i<tableSize; i++){

        std::cout<<"-------"<<std::endl;
        std::cout<<"index: " << i<< std::endl;
        
        if(HashTable[i]->name == "empty"){
        std::cout<<HashTable[i]->name<<std::endl; //first name in bucket
        std::cout<<HashTable[i]->elo_rating<<std::endl; //first drink in bucket
        std::cout<<HashTable[i]->wins<<std::endl;
        std::cout<<HashTable[i]->losses<<std::endl;
        }
        else{
            item* Ptr = HashTable[i];
           
                while(Ptr != NULL){
                    std::cout<<"Name: "<<Ptr->name<<std::endl;
                    std::cout<<"EloRating: " << Ptr->elo_rating<<std::endl;
                    std::cout<<"Wins: "<<Ptr->wins <<std::endl;
                    std::cout<<"Losses: "<<Ptr->losses<<std::endl<<std::endl;
                
                    Ptr = Ptr->next;
            }
         
        }
        //std::cout<<"# of items "<<numberOfItemsInIndex(i)<<std::endl;
          std::cout<<"-------"<<std::endl;
    }
}


void hash::projectedElo(std::string nameA, std::string nameB){
    //Expected outcome of Player A = 1 / (1 + 10^((RatingB -RatingA)/400)
    //new rating = rating + 32(score - expected score)
    
    int new_elo;
    int indexA = Hash(nameA);//what if your hash index is linked??? Will lead to                             wrong output
    int indexB = Hash(nameB);
    
    std::cout<<"Elo Rating of "<<HashTable[indexA]->name<<" : " <<HashTable[indexA]->elo_rating<<std::endl;
     std::cout<<"Elo Rating of "<<HashTable[indexB]->name<<" : " <<HashTable[indexB]->elo_rating<<std::endl;
    
    std::cout<<"If " <<HashTable[indexA]->name << " wins ... " <<std::endl;
    new_elo = HashTable[indexA]->elo_rating + 32*(1 - expectedOutcome(HashTable[indexA]->elo_rating, HashTable[indexB]->elo_rating));
        std::cout<<"New Elo of : " << HashTable[indexA]->name<< " : "<< new_elo<<std::endl;
    
        
    int difference = abs(HashTable[indexA]->elo_rating - new_elo);
        std::cout<<"Difference : " << difference<<std::endl;
    
    int eloRatingLoser = HashTable[indexB]->elo_rating - difference;
    
    std::cout<<"New Elo of : " << HashTable[indexB]->name<< " : "<< eloRatingLoser<<std::endl;
    
  //  eloRatingPlayerA = new_elo;
 //   eloRatingPlayerB -= difference;
    
//If the other guy wins... outputing both possible scenarios
    
   std::cout<<"If " <<HashTable[indexB]->name << " wins ... " <<std::endl;
      new_elo = HashTable[indexB]->elo_rating + 32*(1 - expectedOutcome(HashTable[indexB]->elo_rating, HashTable[indexA]->elo_rating));
          std::cout<<"New Elo of : " << HashTable[indexB]->name<< " : "<< new_elo<<std::endl;
      
          
      difference = abs(HashTable[indexB]->elo_rating - new_elo);
          std::cout<<"Difference : " << difference<<std::endl;
      
      eloRatingLoser = HashTable[indexA]->elo_rating - difference;
      
      std::cout<<"New Elo of : " << HashTable[indexA]->name<< " : "<< eloRatingLoser<<std::endl;
  
    
    
}

int hash::expectedOutcome(int ratingA, int ratingB){
    int projection;
    int differenceRating = ratingB - ratingA;
    projection = 1 / (1 + 10^(differenceRating/400));
    return projection;
}
