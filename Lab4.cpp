/*
 * This C++ program uses the BankAccount and Employee classes
 * It will take input from salary.txt
 * and print employee info and bank acount balance into monthly_salary.txt
 * CECS 275 spring 2023
 * Instructor: Minhthong Nguyen
 * @author Jonathan Cerniaz
 * @author George Elassal
 * @version 1
 * Last updated 4/7/2023 
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include "Employee.h"
#include "BankAccount.h"

using namespace std;
// Prototypes
double strDouble(const string& s);


int main(){
    //create infile and outfile variables
    ifstream in;
    ofstream out;
    in.open("Salary.txt");
    out.open("monthly_salary.txt");
    vector <Employee> employees; //vector containing employees
    Employee* employee; //employee pointer
    BankAccount* bankAccount; //bankaccount pointer
    string id, name, firstN, lastN, s; //string for input
    double salary; //double for input
    // Checking if input file is real
    out << "Employee ID    Last Name      First Name  	 Annual Salary   	  Monthly Salary  	   Balance" << endl;
    if (!in){
    cout << "Invalid file" << endl; // for checking
    }else{
        string meow;
        getline(in, meow); //throw away variable to clear first line of input file
        while(in >> id >> firstN >> lastN >> s){ //input ifstream into a string variables and double salary
            salary = strDouble(s); //convert to a double from a string for calculating
            bankAccount = new BankAccount(); //create new bankaccount on heap
            bankAccount -> set_id (id); //set the id to employee id
            employee = new Employee(id, firstN, lastN, salary, bankAccount); // create new employee and put into vector
            employees.push_back(*employee);
        }
        for (int i = 0; i < employees.size(); ++i){
            employees.at(i).deposit_monthly_salary(); // for each employee in vector deposit monthly salary into balance
            employees.at(i).print(out); // print each employee's info into monthly.salary

        
        }
   
        delete employee;
        delete bankAccount; //delete used up memory
        in.close(); //close files
        out.close();
    }
    return 0; 
}

//convert from a string to a double
//by getting rid of . and , and then converting using stod()
double strDouble(const string& s){
    double result;
    string temp = "";
    for (int i = 0; i< s.length(); i++){
    if (s[i] != ',')
        temp += (s[i]);
    }
    return result = stod(temp);
}
