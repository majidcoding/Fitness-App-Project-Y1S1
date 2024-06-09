

#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <cstdlib>
using namespace std;
const int MAX = 100;

void homepage();
void close();
void receipt(string username[], int, string gender[], int age[], double height[], double weight[], double, string, string, string);
double calorieCalculator(string username[], int validator, string gender[], int age[], double height[], double weight[]);
void mealPlanner(double calorie, string& mealplan);
void workoutPlanner(string& workoutplan, string& workouttype);
void profileUpdater(double[], int[], double[], int);

int login();
int feature();
int authenticator(string, string, int, string[], string[]);
int registration(string[], string[], int, string[], int[], double[], double[]);

int main() {
    homepage();

    string username[MAX], password[MAX], gender[MAX], input_username, input_password, mealplan, workoutplan, workouttype;
    int age[MAX], option, menu, validator, print, no_users = 0;
    double weight[MAX], height[MAX], WEIGHTGOAL_CALORIECALCULATOR = 0;

    cout << endl << "Already have an account?" << endl;

    while (true) { //to make the program keep asking for input

        option = login();

        if (option == 0) { //user exit
            close(); //call to display exit page
            exit(0); //end program so tak proceed next loop menu
        }

        else if (option == 1) { //USER LOGIN
            cout << "Enter your username: ";
            cin >> input_username;
            cout << "Enter your password: ";
            cin >> input_password;

            validator = authenticator(input_username, input_password, no_users, username, password); //call check ada account or not, nak pass array ke UDF just guna nama array je sbgai argument

            if (validator != -1) {
            system("CLS");
                cout << endl << "Logging in..." << endl;
                system("pause");
                cout << endl << "Success!" << endl << endl;
                cout << "\t\t\t\t\t\t|||" << "Welcome back " << username[validator] << "!" << "|||" << endl;
                cout << "\t\t\t\t\t\tReady to conquer the world?" << endl;

                cout << endl << "You:-" << endl;
                cout << "Gender: " << gender[validator] << "|" << " Age: " << age[validator] << "|" << " Height: " << height[validator] << "cm" << "|" << " Weight: " << weight[validator] << "kg" << endl;

                cout << endl << "What do you want to do today?" << endl;

                //FEATURE UTK FITNESS APP
                while (true) {
                    menu = feature(); //menu, user pilih dia nak buat apa

                   if(menu == 1){ //call function calorie calculator
                    system("CLS");
                    cout << endl << "You:-" << endl;
                    cout << "Gender: " << gender[validator] << "|" << " Age: " << age[validator] << "|" << " Height: " << height[validator] << "cm" << "|" << " Weight: " << weight[validator] << "kg" << endl;
                        WEIGHTGOAL_CALORIECALCULATOR = calorieCalculator(username, validator, gender, age, height, weight);
                        cout << "To go back to menu..." << endl;
                        system("pause");
                        cout << endl;
                        system("CLS");
                        cout << endl << "You:-" << endl;
                cout << "Gender: " << gender[validator] << "|" << " Age: " << age[validator] << "|" << " Height: " << height[validator] << "cm" << "|" << " Weight: " << weight[validator] << "kg" << endl;
                        cout << "What do you want to do next? " << endl;
                    }

                    else if(menu == 2){ //call function workout planner
                    system("CLS");
                    cout << "Gender: " << gender[validator] << "|" << " Age: " << age[validator] << "|" << " Height: " << height[validator] << "cm" << "|" << " Weight: " << weight[validator] << "kg" << endl;
                    workoutPlanner(workoutplan, workouttype);
                    cout << workoutplan << endl;
                    cout << "To go back to menu..." << endl;
                        system("pause");
                        cout << endl;
                        system("CLS");
                        cout << endl << "You:-" << endl;
                cout << "Gender: " << gender[validator] << "|" << " Age: " << age[validator] << "|" << " Height: " << height[validator] << "cm" << "|" << " Weight: " << weight[validator] << "kg" << endl;
                        cout << "What do you want to do next? " << endl;
                    }

                    else if(menu == 3){ //call function meal planner
                    system("CLS");
                    cout << "Gender: " << gender[validator] << "|" << " Age: " << age[validator] << "|" << " Height: " << height[validator] << "cm" << "|" << " Weight: " << weight[validator] << "kg" << endl << endl;
                    mealPlanner(WEIGHTGOAL_CALORIECALCULATOR, mealplan);
                   
cout << mealplan << endl;
                        cout << "To go back to menu..." << endl;
                        system("pause");
                        cout << endl;
                        system("CLS");
                        cout << endl << "You:-" << endl;
                cout << "Gender: " << gender[validator] << "|" << " Age: " << age[validator] << "|" << " Height: " << height[validator] << "cm" << "|" << " Weight: " << weight[validator] << "kg" << endl;
                        cout << "What do you want to do next? " << endl;
                    }

                    else if(menu == 4){ //profile updater
profileUpdater(weight, age, height, validator);
cout << endl << "You:-" << endl;
                cout << "Gender: " << gender[validator] << "|" << " Age: " << age[validator] << "|" << " Height: " << height[validator] << "cm" << "|" << " Weight: " << weight[validator] << "kg" << endl;
                    }

                    else if(menu == 0){ //user logout
cout << "Print receipt? " << endl << "1-Yes" << endl << "0-No" << endl << "= "; //print receipt or naa
                        cin >> print;
                        if (print != 1){//tak print
                        cout << "Logging out..." << endl;
                        cout << endl;
                        system("CLS");
                        cout << "\t\t\t\t\tHello user! Already have an account?" << endl;
                            break;
                        }
                        else if(print == 1){//print
                            receipt(username, validator, gender, age, height, weight, WEIGHTGOAL_CALORIECALCULATOR, mealplan, workoutplan, workouttype); //print receipt
                            cout << "Success! Logging out..." << endl;
                            system("pause");
                            system("CLS");
                            cout << endl;
                            cout << "\t\t\t\t\t\tHello user! Already have an account?" << endl;
                            break;
                        }
                    }

                    else{
                        cout << "Invalid! Enter an available option!" << endl;
                    }
                }
            } else {
                cout << "Login failed. Invalid username or password." << endl << endl;
            }
        } else if (option == 2) { // user register
            no_users = registration(username, password, no_users, gender, age, height, weight); //call function utk register // (array username, array password, numberofuser
        } else {
            cout << "Invalid! Enter an available option!" << endl;
        }
    }
    return 0;
}

void homepage() {
    cout << "\t\t\t\t\t\t--------------------------------" << endl;
    cout << "\t\t\t\t\t\t     WELCOME TO TRENFITNESS     " << endl;
    cout << "\t\t\t\t\t\t--------------------------------" << endl;
}

void close() {
    cout << "\t\t\t\t\t\t--------------exit--------------" << endl;
    cout << "\t\t\t\t\t\t     THANK YOU FOR VISITING     " << endl;
    cout << "\t\t\t\t\t\t    WORK HARD AND STAY FIT <3   " << endl;
    cout << "\t\t\t\t\t\t         SEE YOU LATER          " << endl;
    cout << "\t\t\t\t\t\t         |_o_(O__O)_o_|         " << endl;
    cout << "\t\t\t\t\t\t---------------tq---------------" << endl;
}

int login() {
    int choice;
    cout << "1-login" << endl << "2-register" << endl << "0-exit" << endl;
    cout << "= ";
    cin >> choice;
    cout << endl;
    return choice;
}

int authenticator(string input_username, string input_password, int no_users, string username[], string password[]) {
    // check username ada atau tak
    for (int i = 0; i < no_users; i++) {
        if (username[i] == input_username && password[i] == input_password) {
            return i;
        }
    }
    return -1;
}

int registration(string username[], string password[], int no_users, string gender[], int age[], double height[], double weight[]) {
    // nak register user dalam array
    string name, newpassword, genderuser; // declare variable utk buat nama and pw
    int ageuser, i = 0;
    double heightuser, weightuser;

    cout << "Create a username: ";
    cin >> name;

    // Check username available atau tak
    while(username[i] == name){
        cout << "Username already exists. Please choose a different one." << endl << endl;
        cout << "Create a username: ";
        cin >> name;
    }

    cout << "Enter a password: ";
    cin >> newpassword;

    cout << "Enter your gender (e.g., Male/Female): ";
    cin >> genderuser;
    while(genderuser != "Male" && genderuser != "male" && genderuser != "Female" && genderuser != "female"){
    cout << "Invalid! There are only 2 genders! " << endl;
    cout << "Enter your gender (Male/Female): ";
    cin >> genderuser;
}

    cout << "Enter your age: ";
    cin >> ageuser;
    while(ageuser < 0){
    cout << "Invalid! Must be positive values!" << endl;
    cout << "Enter your age: ";
    cin >> ageuser;
}

    cout << "Enter your height (in cm): ";
    cin >> heightuser;
    while(heightuser < 0.00){
    cout << "Invalid! Must be positive values!" << endl;
    cout << "Enter your height (in cm): ";
    cin >> heightuser;
}

    cout << "Enter your weight (in kg): ";
    cin >> weightuser;
    while(weightuser < 0.00){
    cout << "Invalid! Must be positive values!" << endl;
    cout << "Enter your weight (in kg): ";
    cin >> weightuser;
}

    // letak maklumat user dalam array
    username[no_users] = name;
    password[no_users] = newpassword;
    gender[no_users] = genderuser;
    age[no_users] = ageuser;
    height[no_users] = heightuser;
    weight[no_users] = weightuser;

    cout << endl << "Registration successful! Now you can login." << endl << endl;

    return ++no_users; // return no_user + 1 sbb no_user yg lama dah diisi dgn user yg baru register ni, update array kat main and go back to while(true) loop
}

void profileUpdater(double weight[], int age[], double height[], int validator){
    cout << "\nEnter your new weight (in kg): ";
    cin >> weight[validator];

    while (weight[validator] < 0.00) {
        cout << "Invalid! Must be a positive value!" << endl;
        cout << "Enter your new weight (in kg): ";
        cin >> weight[validator];
    }

    cout << "Enter your new age: ";
    cin >> age[validator];

    while (age[validator] < 0) {
        cout << "Invalid! Must be a positive value!" << endl;
        cout << "Enter your new age: ";
        cin >> age[validator];
}
    cout << "Enter your new height (in cm): ";
    cin >> height[validator];

    while (height[validator] < 0.00) {
        cout << "Invalid! Must be a positive value!" << endl;
        cout << "Enter your new height (in cm): ";
        cin >> height[validator];
    }
   
    cout << "Profile updated successfully!" << endl;
}

int feature() {
    int choice;
    cout << "1-Calorie Calculator" << endl << "2-Workout Planner" << endl << "3-Meal Planner" << endl << "4-Update your profile" << endl << "0-Logout" << endl;
    cout << "= ";
    cin >> choice;
    cout << endl;
    return choice;
}

void receipt(string username[], int validator, string gender[], int age[], double height[], double weight[], double goalweight, string mealplan, string workoutplan, string workouttype){//RECEIPTTTTTTTTTTTTTTTTT
    ofstream Outputfile;
    Outputfile.open("TrenReceipt.txt");

    Outputfile << "\t\t\t\t\t................................." << endl;
    Outputfile << "\t\t\t\t\t\t:--TREN FITNESS--:" << endl;
    Outputfile << "\t\t\t\t\t-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-" << endl;
    Outputfile << "Name: " << username[validator] << "\t\t\tAge: " << age[validator] << "\t\t\tsex: " << gender[validator] << "\t\t\tHeight(cm): " << height[validator] << endl << "\t\t\tCurrent Weight: " << weight[validator] << "kg" << "\t\t\tGoal: " << goalweight << "kg" << endl << endl;
   
    Outputfile << mealplan << endl;
   
    Outputfile << "Workout Plan" << endl;
    Outputfile << "-------------------------------------------------------------------------------------------------------------------" << endl << endl;
    Outputfile << workouttype << endl;
    Outputfile << workoutplan << endl;

    Outputfile.close();
}

double calorieCalculator(string username[], int validator, string gender[], int age[], double height[], double weight[]){//CALORIE CALCULATORRRRRRRRRRRRRRRRRRRRR
    string goal;
    int activityLevel, days;
    double bmr, calories, weightgoal = 0, kg, gain;
   
    cout << "\n\t\t\t\t\tEnter your activity level (1-5)\n\n"
        << "\t\t\t\t1 - sedentary (little or no exercise)" << endl
        << "\t\t\t\t2 - lightly active (light exercise/sports 1-3 days/week " << endl
        << "\t\t\t\t3 - moderately active (moderate exercise/sports 3-5 days/week)" << endl
        << "\t\t\t\t4 - very active (hard exercise/sports 6-7 days a week)" << endl
        << "\t\t\t\t5 - extra active (very hard exercise/sports & physical job or 2x training)\n\n";
    cout << "\t\t\t\t\tActivity Level: ";
    cin >> activityLevel;

    //kira BMR
    if(gender[validator] == "Male" || gender[validator] == "male"){
        bmr = 10 * weight[validator] + 6.25 * height[validator] - 5 * age[validator] + 5;
    }
else{
        bmr = 10 * weight[validator] + 6.25 * height[validator] - 5 * age[validator] - 161;
    }

    //bmr ikut activity
    switch(activityLevel){
        case 1: calories = bmr * 1.2; break;
        case 2: calories = bmr * 1.375; break;
        case 3: calories = bmr * 1.55; break;
        case 4: calories = bmr * 1.725; break;
        case 5: calories = bmr * 1.9; break;
        default: cout << "\t\t\t\t\tInvalid activity level.\n" << endl;
cout << "\t\t\t\t\tEnter your activity level (1-5): ";
cin >> activityLevel;
    }

    //Ask for weight goal
    cout << "\n\t\t\t\t\tEnter your weight goal\n" << endl << "\t\t\t\t\tM - Maintain" << endl << "\t\t\t\t\tL - Lose" << endl << "\t\t\t\t\tG - Gain " << endl << "\n\t\t\t\t\tWeight Goal: "; //WIGHT GOAL CALORIE CALCCCCCCCCCCCC
    cin >> goal;
   
    while(goal != "M" && goal != "m" && goal != "L" && goal != "l" && goal != "G" && goal != "g"){
    cout << "\t\t\t\t\tInvalid! Enter an available option " << endl << "\t\t\t\t\tWeight Goal: ";
    cin >> goal;
}
   
    cout << "\n\t\tTo maintain your current weight, you need to consume approximately " << calories << " calories per day." << endl;

    //Adjust calories based on goal //kalau dari sudut kesihatan bagus +-0.5kg/week untuk selamat
    if(goal == "L" || goal == "l"){
    cout << "\n\t\t\t\t\tEnter your target weight (kg): ";
    cin >> weightgoal;
    while(weightgoal > weight[validator]){
    cout << "\n\t\t\t\t\tTarget weight must be less than your current weight!" << endl;
    cout << "\n\t\t\t\t\tEnter your target weight (kg): ";
    cin >> weightgoal;
}
    gain = weight[validator] - weightgoal; //to find total kg needed to lose
    days = static_cast<int> (gain * 7);//to find how many days will it take to achieve target weight (safely)
        calories -= 500;
        cout << "\n\tTo achieve your target weight of " << weightgoal << "kg, you need to consume approximately " << setprecision(2) << fixed << calories << " calories per day" << endl;
cout << "\n\t\t\tYou will achieve your target in " << setw(2) << days << " day(s). Goodluck! Go after it!" << endl << endl;
return weightgoal;
}
    else if(goal == "G" || goal == "g"){
    cout << "\n\t\t\t\t\tEnter your target weight (kg): ";
    cin >> weightgoal;
    while(weightgoal < weight[validator]){
    cout << "\n\t\t\t\t\tTarget weight must be more than your current weight!" << endl;
    cout << "\n\t\t\t\t\tEnter your target weight (kg): ";
    cin >> weightgoal;
}
    gain = weightgoal - weight[validator]; //to find total kg needed to gain
    days = static_cast<int> (gain * 7);//to find how many days will it take to achieve target weight (safely)
        calories += 500;
        cout << "\n\tTo achieve your target weight of " << weightgoal << "kg, you need to consume approximately " << setprecision(2) << fixed << calories << " calories per day" << endl;
cout << "\n\t\t\tYou will achieve your target in " << setw(2) << days << " day(s). Goodluck! Go after it!" << endl << endl;
return weightgoal;
    }
    else
    return weightgoal;
}

void mealPlanner(double WEIGHTGOAL_CALORIECALCULATOR, string& mealplan){ //MEAL PLANNNEEEEERRRR
    ifstream file4("1000-1499.txt");//file calorie 1000-1499
    ifstream file5("1500-1999.txt");//file calorie  1500 - 1999
    ifstream file6("2000-2499.txt");//file calorie 2000 - 2499

    string L, M, G;
    double calorie;

    cout << "\t\t\t\t\t\tWelcome to Meal Plan" << endl;

    cout << "Your target calorie intake : "; // calorie from calorie calculator
    cin >> calorie;

    if(calorie > 1000 && calorie <= 1500){

        while (getline(file4, G))//baca file calorie 1000-1500
        {
            mealplan = mealplan + G + "\n";
        }
    }

    else if(calorie >= 1500 && calorie <= 2000){

        while(getline(file5, L))//baca file calorie 1500-2000
        {
            mealplan = mealplan + L + "\n";
        }
    }

    else if(calorie >= 2000 && calorie <= 100000){
        while(getline(file6, M)) //baca file calorie 2000-2500
        {
            mealplan = mealplan + M + "\n";
        }
    }
    else if(calorie <= 1000)
{
mealplan = "Consuming too low calories is unhealthy!\n ";
}
}

void workoutPlanner(string& workoutplan, string& workouttype){ //WORKOUT PLANNNNEEEERRRRR FREE PALESTINE MA BRUDDA
int prefer, days;

cout << "Where do you usually workout?" << endl
         << "(1) Home workout" << endl
         << "(2) Gym" << endl;
    cout << "= ";
cin >> prefer;

    ifstream file4("gym 1.txt");
    ifstream file5("gym 2.txt");
    ifstream file6("gym 3.txt");
    ifstream file7("gym 4.txt");
    ifstream file8("gym 5.txt");
    ifstream file9("gym 6.txt");
ifstream file10("gym 7.txt");

    string A, B, C, D, E, F, G, H;

while(prefer != 1 && prefer != 2){
    cout << "Invalid! Enter a valid option: " << endl;
    cin >> prefer;
}

    if(prefer == 1){
    workouttype = "For home workout:";
    cout << endl << workouttype << endl;
        while (getline(file10, H)){
        workoutplan = workoutplan + H + "\n";
        }
    }
    else if(prefer == 2){
    workouttype = "For gym workout:";
    cout << endl << workouttype << endl;
cout << "How many days do you workout in a week? (1-7): ";
        cin >> days;
       
        while(days < 1 || days > 7){
        cout << "Invalid! There is only 7 days in a week!" << endl;
        cout << "How many days do you workout in a week? (1-7): ";
        cin >> days;
}

        switch (days){
        case 1:
            cout << endl << "Full body workout split is the best for you." << endl << endl;
            system("pause");
            while (getline(file4, A)){
                workoutplan = workoutplan + A + "\n";
            }
            break;
        case 2:
            cout << endl << "Upper and lower body workout split is the best for you." << endl << endl;
            system("pause");
            while (getline(file5, B)){
                workoutplan = workoutplan + B + "\n";
        }
            break;
        case 3:
            cout << endl << "Push, Pull and Leg split workout split is the best for you." << endl << endl;
            system("pause");
            while (getline(file6, C)){
                workoutplan = workoutplan + C + "\n";
            }
            break;
        case 4:
            cout << endl << "Upper and lower body workout for twice repetition is the best for you." << endl << endl;
            system("pause");
            while (getline(file7, D)){
                workoutplan = workoutplan + D + "\n";
            }
            break;
        case 5:
            cout << endl << "Push, Pull, Leg then you continue to Push and Pull is the great split workout for you to use." << endl << endl;
            system("pause");
            while (getline(file8, E)){
                workoutplan = workoutplan + E + "\n";
            }
            break;
        case 6:
            cout << endl << "Push, Pull, and leg for twice repetition is the great exercise for you to build muscle." << endl << endl;
            system("pause");
            while (getline(file9, F)){
                workoutplan = workoutplan + F + "\n";
            }
            break;
        case 7:
            cout << endl << "You should not workout every day because your muscle needs to recover from heavy training." << endl << endl;
            system("pause");
            cout << "There is no workout plan for you because you need to recover from heavy training." << endl
                 << "\nThere is no calorie burned." << endl;
            break;
        }
    }

    file4.close();
    file5.close();
    file6.close();
    file7.close();
    file8.close();
    file9.close();
    file10.close();
}
