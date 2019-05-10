//
// Created by utec on 10/05/19.
//

#ifndef UNTITLED7_FIGHT_H
#define UNTITLED7_FIGHT_H

#include <iostream>
#include <vector>
#include <string>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include <fstream>
using namespace std;


class Defense{
protected:
    int level;
public:
    int defense(){return level;}
};

class Elude: public Defense{
public:
    Elude(){this->level = 1;};
};

class Shield: public Defense{
public:
    Shield(){this->level = 4;};
};

class Armor: public Defense{
public:
    Armor(){this->level = 8;};
};

class Attack{
protected:
    int level;
public:
    int attack(){return level;}
};

class Punch: public Attack{
public:
    Punch(){this->level = 1;};
};

class Saber: public Attack{
public:
    Saber(){this->level = 5;};
};

class Firearm: public Attack{
public:
    Firearm(){this->level = 10;};
};

class Fighter{
    string name;
    vector<Defense*> def;
    vector<Attack*> att;
public:
    Fighter(string a, string d, string f){
        name = f;
        vector<string> temp;
        boost::split(temp, d, boost::is_any_of(", "));
        for (int i = 0; i<temp.size(); i++){
            if (temp[i]=="E"){def.push_back(new Elude);}
            if (temp[i]=="S"){def.push_back(new Shield);}
            if (temp[i]=="A"){def.push_back(new Armor);}
        }
        temp.clear();
        boost::split(temp, a, boost::is_any_of(", "));
        for (int i = 0; i<temp.size(); i++){
            if (temp[i]=="P"){att.push_back(new Punch);}
            if (temp[i]=="S"){att.push_back(new Saber);}
            if (temp[i]=="F"){att.push_back(new Firearm);}
        }
    }
    int defense(){
        int temp = 0;
        for (int i = 0; i<def.size(); i++){
            temp = temp + def[i]->defense();
        }
        return temp;
    }

    int attack(){
        int temp = 0;
        for (int i = 0; i<att.size(); i++){
            temp = temp + att[i]->attack();
        }
        return temp;
    }

    string get_name(){
        return name;
    }
};
class Fight {
    Fighter* a;
    Fighter* b;
    Fighter* winner = nullptr;
    int score_a;
    int score_b;
public:
    Fight(vector<string> temp, int n){

        a = new Fighter(temp[(n*6)+0], temp[(n*6)+1], temp[(n*6)+2]);
        b = new Fighter(temp[(n*6)+3], temp[(n*6)+4], temp[(n*6)+5]);
        score_a = a->defense() - b->attack();
        score_b = b->defense() - a->attack();
        if (score_a>score_b){
            winner = a;
        }else{
            if(score_b>score_a){
                winner = b;
            }
        }
    }
    string get_winner(){if (winner != nullptr) {return winner->get_name();} else{return "Empate";}}
};

class Arena{
vector<string>actions;
vector<Fight*>peleas;
int npeleas = 0;

public:
    Arena(string filename){
        fstream file(filename);
        string str;
        while (std::getline(file, str))
        {
            if(str. size() > 0)
                actions. push_back(str);
        }
        if (actions.size()>0){
            npeleas = (actions.size()/6);
        }

    }
    void Run(){
        for (int i = 0; i<npeleas; i++){
            peleas.push_back(new Fight(actions, i));
        }
    }
    int Actions_Size(){return actions.size();}
    int Peleas_Size(){ return peleas.size();}
    int Get_npeleas(){return npeleas;}
    string Get_Winner(int a){return peleas[a]->get_winner();}
};

#endif //UNTITLED7_FIGHT_H
