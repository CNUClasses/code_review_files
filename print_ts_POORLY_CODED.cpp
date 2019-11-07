#include "print_ts.h"
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
mutex m;

//TODO what happens if you dont have an endl?
//TODO what about those raw mutexes
void PRINT1(std::string &txt){
    m.lock();
    cout<<txt;
    m.unlock();
}
void PRINT2(std::string &txt, std::string &txt1){
    m.lock();
    cout<<txt + txt1;
    m.unlock();
}
void PRINT3(std::string &txt, std::string &txt1, std::string &txt2){
    m.lock();
    cout<<txt + txt1 + txt2;
    m.unlock();

}
void PRINT4(std::string &txt, std::string &txt1, std::string &txt2, std::string &txt3){
    m.lock();
    cout<<txt + txt1 + txt2 + txt3;
    m.unlock();

}
void PRINT5(std::string &txt, std::string &txt1, std::string &txt2, std::string &txt3, std::string &txt4){
    m.lock();
    cout<<txt +txt1 + txt2 + txt3 +txt4;
    m.unlock();
}