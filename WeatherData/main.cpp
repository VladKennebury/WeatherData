/*  ICT283 Assignment 2 - Data Structures and Abstractions
    Author: Vladislav Kennebury
    Date: 08/06/2020

    Class: Main
    Description:
    The program reads and stores weather data from a multiple CSV files via an index text file.
    Data is stored in a Vector of Binary Search Trees (Weather) of type (WeatherType).
    After splitting and storing appropriate data including the date, time, wind speed,
    air temperature and solar radiation, a menu is displayed and looped until the exit
    option is selected.

    Options include the display of average and standard deviation for speed, temperature
    and radiation for a given month and year, or every month of a specified year.
    Specified values are stored within a Statistics object in order to calculate the
    certain values such as average for a specific month. Furthermore, times associated with
    maximum solar radiation values for a given date can be displayed (Option 5).

    Option 4 allows the creation of a CSV file named WindTempSolar.csv, where all averages
    and deviations for the variables are printed. No data is displayed if a specified month
    or year contains no information. */

//Header and library declarations
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Time.h"
#include "Vector.h"
#include "Date.h"
#include "Statistics.h"
#include "BST.h"
#include "WeatherType.h"
using namespace std;

//Keeps track of index value for numberOfYears array
int index = 0;
//Size of numberOfYears array. Stores up to default of 10 years
const int maxY = 10;
//Stores all varying years found within the files
int numberOfYears[maxY];
//Maximum radiation value for option 5
float maxRad = 0;
//Index of maxRadTime array
int maxRadIndex = 0;
//Size of maxRadTime array. Stores up to 5 times
const int numMaxRad = 5;
//Array of times for option 5 (max radiation)
Time maxRadTime[numMaxRad];
//Stores date and time from files
string date, theTime;
//Keeps track of date values for menu options
int addYear, addMonth, addDay;

//Vector of Binary Search Trees of type WeatherType
Vector<BST<WeatherType>> Weather;
//Declaration of Statistics class object for wind speed
Statistics WindSpeed;
//Declaration of Statistics class object for air temperature
Statistics AmbientTemperature;
//Declaration of Statistics class object for solar radiation
Statistics SolarRadiation;

//Used as function pointer for retrieving speed values
void addSpeed(WeatherType& w);
//Used as function pointer for retrieving temperature values
void addTemperature(WeatherType& w);
//Used as function pointer for retrieving radiation values
void addRadiation(WeatherType& w);
//Used as function pointer for retrieving max radiation with associated times
void findHighTime(WeatherType& w);
//Calculates which BST to search for option 5
void getHighestRad(WeatherType& o);

//Reads index text file
int readingIndexFile();
//Checks for file existence and reads file into Weather
int readingFile(string passedFile);
//Splits date string to collect specific values
void splittingDate(WeatherType& anObj, int flag);
//Splits time string to collect specific values
void splittingTime(WeatherType& anObj);

//Maintains collection of functions for storing and output, based upon menu option entered
void searchPrompt(int passedMenu);
//Stores speed within specified parameters into the statistics object, WindSpeed
void storeSpeed(int passedYear, int passedMonth);
//Stores temperature within specified parameters into the statistics object, AmbientTemperature
void storeTemperature(int passedYear, int passedMonth);
//Stores radiation within specified parameters into the statistics object, SolarRadiation
void storeRadiation(int passedYear, int passedMonth);

//Displays specified year
void outputTheYear(int passedYear);
//Displays specified month/months
string outputTheMonth(int passedM);
//Displays average speed and standard deviation
void outputSpeed();
//Displays average temperature and standard deviation
void outputTemperature();
//Displays average radiation and standard deviation
void outputRadiation();
//Displays maximum radiation and associated times
void outputHighRadTime();
//Loops through menu options until user exits program
void menu();
// Writes CSV file containing the averages and standard deviation of speed, temperature and radiation for a specified year
void writingFile(int passedYear);

int main()
{
    if(readingIndexFile() != 0){
        //Runs menu if file exists
        menu();
    }

    return 0;
}

int readingIndexFile(){
    ifstream indexFile("data/met_index.txt");
    if(!indexFile){
        //Returns 0 if file does not exist
        cout << "No file found" << endl;
        return 0;
    }

    string indexLine;
    while(getline(indexFile, indexLine)){
        //Reads each line with data folder directory added as "data/"
        string fileName = "data/";
        fileName += indexLine;
        //Reads CSV of fileName
        readingFile(fileName);
    }
    //Returns value indicating the file was read
    return 1;
}

int readingFile(string passedFile){
    //Declaration of Binary Search Tree of type WeatherType fro re-use
    BST<WeatherType> w;
    //Declaration of WeatherType object for re-use
    WeatherType WeatherTypeObject;

    //Declaration of variables found within files
    //S, SR and T are used, while others are not utilised unless required in future use
    string variableList, DP, Dta, Dts, EV, QFE, QFF, QNH;
    string RF, RH, S, SR, ST1, ST2, ST3, ST4, Sx, T;
    //Delimiters separating data values, can be changed if required
    string spaceDelimiter = " ";
    string commaDelimiter = ",";
    //Stores float values after string stream conversion
    float solarRadFloat, temperatureFloat, speedFloat;

    // Opens specified file within the folder data
    //Needs to be converted to array of chars .c_str()
    ifstream inputFile(passedFile.c_str());
    if(!inputFile){
        // Returns 0 if file does not exist
        cout << "No file found" << endl;
        return 0;
    }

    //Collects single line in file for reading
    string inputLine;
    //Collects and discards first line of file, containing variable names
    getline(inputFile, variableList);

    //Continues storing data while file has a line
    while(getline(inputFile, inputLine)){

        // Position within the inputLine string
        int position = 0;

        if(position = inputLine.find(spaceDelimiter)){
            //Stores date as a substring when a space is found
            //Erases the stored string to continue data collection
            date = inputLine.substr(0, position);
            inputLine.erase(0, position + spaceDelimiter.length());
        }

        //Stores variables separated by commas
        if(position = inputLine.find(commaDelimiter)){
            theTime = inputLine.substr(0, position);
            inputLine.erase(0, position + commaDelimiter.length());
            //Updates the position within the string after storing and erasing the substring for all variables
            position = inputLine.find(commaDelimiter);

            DP = inputLine.substr(0, position);
            inputLine.erase(0, position + commaDelimiter.length());
            position = inputLine.find(commaDelimiter);

            Dta = inputLine.substr(0, position);
            inputLine.erase(0, position + (commaDelimiter.length()));
            position = inputLine.find(commaDelimiter);

            Dts = inputLine.substr(0, position);
            inputLine.erase(0, position + commaDelimiter.length());
            position = inputLine.find(commaDelimiter);

            EV = inputLine.substr(0, position);
            inputLine.erase(0, position + commaDelimiter.length());
            position = inputLine.find(commaDelimiter);

            QFE = inputLine.substr(0, position);
            inputLine.erase(0, position + commaDelimiter.length());
            position = inputLine.find(commaDelimiter);

            QFF = inputLine.substr(0, position);
            inputLine.erase(0, position + commaDelimiter.length());
            position = inputLine.find(commaDelimiter);

            QNH = inputLine.substr(0, position);
            inputLine.erase(0, position + commaDelimiter.length());
            position = inputLine.find(commaDelimiter);

            RF = inputLine.substr(0, position);
            inputLine.erase(0, position + commaDelimiter.length());
            position = inputLine.find(commaDelimiter);

            RH = inputLine.substr(0, position);
            inputLine.erase(0, position + commaDelimiter.length());
            position = inputLine.find(commaDelimiter);

            S = inputLine.substr(0, position);
            inputLine.erase(0, position + commaDelimiter.length());
            position = inputLine.find(commaDelimiter);

            SR = inputLine.substr(0, position);
            inputLine.erase(0, position + commaDelimiter.length());
            position = inputLine.find(commaDelimiter);

            ST1 = inputLine.substr(0, position);
            inputLine.erase(0, position + commaDelimiter.length());
            position = inputLine.find(commaDelimiter);

            ST2 = inputLine.substr(0, position);
            inputLine.erase(0, position + commaDelimiter.length());
            position = inputLine.find(commaDelimiter);

            ST3 = inputLine.substr(0, position);
            inputLine.erase(0, position + commaDelimiter.length());
            position = inputLine.find(commaDelimiter);

            ST4 = inputLine.substr(0, position);
            inputLine.erase(0, position + commaDelimiter.length());
            position = inputLine.find(commaDelimiter);

            Sx = inputLine.substr(0, position);
            inputLine.erase(0, position + commaDelimiter.length());
            position = inputLine.find(commaDelimiter);

            T = inputLine.substr(0, position);
        }

            //Flag 1 = file input, 2 = Option 5 input
            //Calls method to separate values of date, passes the current WeatherTypeObject
            splittingDate(WeatherTypeObject, 1);
            //Calls method to separate values of time, passes the current WeatherTypeObject
            splittingTime(WeatherTypeObject);

            //Checks for NA in any field
            // Sets value to 0 if NA is detected
            if(SR == "NA" || SR == "na"){
                WeatherTypeObject.setRadiation(0);
            }
            else{
                //Converts string to float or integer if the field
                //Stores converted string value into appropriate variable
                stringstream solarRadConvo(SR);
                solarRadConvo >> solarRadFloat;
                WeatherTypeObject.setRadiation(solarRadFloat);
            }

            if(T == "NA"|| T == "na"){
                WeatherTypeObject.setTemperature(0);
            }
            else{
                stringstream temperatureConvo(T);
                temperatureConvo >> temperatureFloat;
                WeatherTypeObject.setTemperature(temperatureFloat);
            }

            if(S == "NA"|| S == "na"){
                WeatherTypeObject.setSpeed(0);
            }
            else{
                stringstream speedConvo(S);
                speedConvo >> speedFloat;
                //Doesn't store invalid values found within the files such as -999
                if(speedFloat >= 0){
                    WeatherTypeObject.setSpeed(speedFloat);
                }
            }

            //Loops through all years of numberOfYears array, adds a BST to specific index of...
            // month + (i * 12) in vector. Thus one BST exists for each detected month of each detected year...
            // separated by 12 elements within the vector. EG - June for 2nd detected year would be stored at...
            // index 6 + (1 * 12) = Weather[18].
            for(int i = 0; i < maxY; i++){
                if(numberOfYears[i] == WeatherTypeObject.getDateYear()){
                    if(Weather[(i * 12) + WeatherTypeObject.getDateMonth()].isEmpty()){
                        //Only adds BST to vector once per detection
                        Weather.add(w, (i * 12) + WeatherTypeObject.getDateMonth());
                    }
                    //Inserts WeatherTypeObject to specified node based on month/year
                    Weather[(i * 12) + WeatherTypeObject.getDateMonth()].nodeInsert(WeatherTypeObject);
                }
            }
    }
    //Closes file after reading data
    inputFile.close();

    //Returns value indicating a file was read
    return 1;
}

void splittingDate(WeatherType& anObj, int flag){
    //Position within the string
    int position = 0;
    //Tracks frequency of a certain year to avoid storing duplicates
    int counting = 0;
    //Stores converted value for day, month and year
    int dayPass, monthPass, yearPass;
    //Stores day, month and year as substring
    string dayToken, monthToken, yearToken;
    //Delimiter separating data value, can be changed if required
    string dateDelimiter = "/";
    //Declaration of Date class for re-use
    Date someDate;

    if ((position = date.find(dateDelimiter))) {

        //Stores substring if the date delimiter is found, erases the substring and...
        // updates the position within the string
        dayToken = date.substr(0, position);
        date.erase(0, position + dateDelimiter.length());
        position = date.find(dateDelimiter);

        //Converts substring into float or int value
        //Stores the converted value into variable
        //Sets the day as the converted value
        stringstream dayConv(dayToken);
        dayConv >> dayPass;
        someDate.setDay(dayPass);
        //Same process of substring conversion and storing occurs for the month and year
        monthToken = date.substr(0, position);
        date.erase(0, position + dateDelimiter.length());
        position = date.find(dateDelimiter);

        stringstream monthConv(monthToken);
        monthConv >> monthPass;
        someDate.setMonth(monthPass);

        yearToken = date.substr(0, position);

        stringstream yearConv(yearToken);
        yearConv >> yearPass;
        someDate.setYear(yearPass);

        //Flag 1 = reading file. Allows code re-use for option 5 without...
        // affecting numberOfYears array
        //Avoids storing duplicates in numberOfYears. Only stores if no...
        // elements of the year exist.
        if(flag == 1){
            for(int i = 0; i < maxY; i++){
                if(numberOfYears[i] == yearPass){
                    counting++;
                }
            }
            if(counting < 1){
                numberOfYears[index] = yearPass;
                index++;
            }
        }
        //Resets counting for next call
        counting = 0;
        //Sets date values to passed WeatherType Object
        anObj.setDate(someDate);
    }
}

void splittingTime(WeatherType& anObj){
    //Position within the string
    int position = 0;
    //Stores converted value for minutes and hours
    int hourPass, minutePass;
    //Stores minutes and hours as a substrings
    string hourToken, minuteToken;
    //Delimiter separating data value, can be changed if required
    string timeDelimiter = ":";
    //Declaration of Time class for re-use
    Time someTime;

    if ((position = theTime.find(timeDelimiter))) {
        //Stores substring if the time delimiter is found, Erases the substring and Updates the position within the string
        hourToken = theTime.substr(0, position);
        theTime.erase(0, position + timeDelimiter.length());
        position = theTime.find(timeDelimiter);

        //Converts substring into float or int value, Stores the converted value into variable
        stringstream hourConv(hourToken);
        hourConv >> hourPass;
        someTime.setHours(hourPass);
        //Same process of substring conversion and storing occurs for the minutes, seconds and type
        minuteToken = theTime.substr(0, position);// + time.substr(1, position);
        theTime.erase(0, position + timeDelimiter.length());

        stringstream minuteConv(minuteToken);
        minuteConv >> minutePass;
        someTime.setMinutes(minutePass);
        //Sets time values to passed WeatherType Object
        anObj.setTime(someTime);
    }
}

void searchPrompt(int passedMenu){ //Uses passed menu choice to determine routine
    //Used to store date in option 5, allows code re-use for splittingDate function
    WeatherType optionFive;
    //Stores input for month and year after conversion
    float monthSearch, yearSearch;
    //Stores month and year as string
    string monthInput, yearInput;

    if(passedMenu == 1){
        //Requests input for month and year
        cout << "Enter month and year in the form (mm yyyy): " << endl;
        cin >> monthInput >> yearInput;
        cout << "\n";

        //Converts string into integer value, Stores integer value in variable
        stringstream mInputConv(monthInput);
        mInputConv >> monthSearch;
    }
    else if(passedMenu == 5){
        //Requests date for input
        cout << "Enter a date in the form (d/m/yyyy): " << endl;
        cin >> date;
        cout << "\n";
    }
    else{ //Option 2, 3, 4
        //Only requests year if Menu option 1 or 5 is not selected
        //Requests input for year
        cout << "Enter year in the form (yyyy): " << endl;
        cin >> yearInput;
        cout << "\n";
    }
    //Converts string into integer value, Stores integer value in variable
    stringstream yInputConv(yearInput);
    yInputConv >> yearSearch;

    if(passedMenu == 1){
        //Stores speed in WindSpeed, based on parameters
        //Calculates and stores: sum, average, standard deviation
        storeSpeed(yearSearch, monthSearch);
        WindSpeed.setTotal();
        WindSpeed.setAverage();
        WindSpeed.setDeviation();
        //Displays month, year and speed
        cout << outputTheMonth(monthSearch);
        outputTheYear(yearSearch);
        outputSpeed();
        //Clears map for future input
        WindSpeed.clearMap();
    }
    else if(passedMenu == 2){
        //Loops through every month
        for(int m = 1; m < 13; m++){
            //Stores temperature in AmbientTemperature, based on parameters
            //Calculates and stores: sum, average, standard deviation
            storeTemperature(yearSearch, m);
            AmbientTemperature.setTotal();
            AmbientTemperature.setAverage();
            AmbientTemperature.setDeviation();
            if(m == 1){
                //Avoids year output for every month, only displaying at the beginning of the output
                outputTheYear(yearSearch);
                cout << '\n';
            }
            //Displays month and temperature
            cout << outputTheMonth(m);
            outputTemperature();
            //Clears map for future input
            AmbientTemperature.clearMap();
        }
    }
    else if(passedMenu == 3){
        //Loops through every month
        for(int m = 1; m < 13; m++){ //Loops through every month
            //Stores radiation in SolarRadiation, base on parameters
            //Calculates and stores: sum, average, standard deviation
            storeRadiation(yearSearch, m);
            SolarRadiation.setTotal();
            SolarRadiation.setAverage();
            if(m == 1){
                //Avoids year output for every month, only displaying at the beginning of the output
                outputTheYear(yearSearch);
                cout << '\n';
            }
            //Displays month and radiation
            cout << outputTheMonth(m);
            outputRadiation();
            //Clears map for future input
            SolarRadiation.clearMap();
        }
    }
    else if(passedMenu == 4){
        //Writes CSV file for speed, temperature and radiation based upon specified parameters
        writingFile(yearSearch);
    }
    else{
        //Splits date input with flag = 2 indicating option 5 in the function
        splittingDate(optionFive, 2);
        //Calculates appropriate BST to search through based upon input
        getHighestRad(optionFive);
        //Displays highest radiation and times for given date
        outputHighRadTime();
    }
}

void addSpeed(WeatherType& w)
{
    //Holds value after conversion form m/s to km/h
    float tempSpeed = 0;

    //Checks if the object date matches the input month/year
    if((w.getDateYear() == addYear) && (w.getDateMonth() == addMonth)){
        //Converts speed form m/s to km/h and stores in Map of floats
        tempSpeed = w.getSpeed() * 3.6;
        WindSpeed.add(tempSpeed);
    }
}

void addTemperature(WeatherType& w)
{
    //Checks if the object date matches the input month/year
    if(w.getDateYear() == addYear && w.getDateMonth() == addMonth){
        //Stores values in Map of floats
        AmbientTemperature.add(w.getTemperature());
    }
}

void addRadiation(WeatherType& w)
{
    //Stores and resets converted value for radiation
    float tempRadiation = 0;
    //Numerator and denominator for conversion fraction (1/6)
    float wattNumerator = 1;
    float wattDenominator = 6;
    //Stores fraction as a float value, changes if time difference between data is altered
    // 1/6 is needed as data is separated in 10 minute intervals, therefore to convert units from W/m^2 to kWh/m^2,
    // the value needs to be multiplied by 10/60 (For every 10min) then divided by 1000
    float wattPeriod;

    //Checks if the object date matches the input month/year
    if(w.getDateYear() == addYear && w.getDateMonth() == addMonth){
        // Checks if radiation is greater than or equal to 100 W/m^2
        if(w.getRadiation() >= 100){
            //Stores fraction value into float variable
            wattPeriod = wattNumerator / wattDenominator;
            //Converts W/m^2 into Wh/m^2
            tempRadiation = w.getRadiation() * wattPeriod;
            //Conversion from Wh/m^2 to kWh/m^2
            tempRadiation = tempRadiation / 1000;
            //Stores values in Map of floats
            SolarRadiation.add(tempRadiation);
        }
    }
}

void findHighTime(WeatherType& w)
{
    //Checks for matching day
    if(w.getDateDay() == addDay){
        if(w.getRadiation() > maxRad){
            //Stores radiation and time if new max is found
            maxRadIndex = 0;
            maxRad = w.getRadiation();
            maxRadTime[maxRadIndex].setHours(w.getTimeHours());
            maxRadTime[maxRadIndex].setMinutes(w.getTimeMinutes());

            //Resets all other elements within the array
            for(int i = 1; i < numMaxRad; i++){
                maxRadTime[i].setHours(0);
                maxRadTime[i].setMinutes(0);
            }
        }
        else if(w.getRadiation() == maxRad){
            //Adds new time as next element within the array
            maxRadIndex++;
            maxRad = w.getRadiation();
            maxRadTime[maxRadIndex].setHours(w.getTimeHours());
            maxRadTime[maxRadIndex].setMinutes(w.getTimeMinutes());
        }
    }
}

void getHighestRad(WeatherType& o)
{
    //Values used in function pointer
    addMonth = o.getDateMonth();
    addYear = o.getDateYear();
    addDay = o.getDateDay();

    //Loops through array to calculate the appropriate BST to search.
    //Correct BST will be in the location, month + (i * 12)
    for(int i = 0; i < maxY; i++){
        if(numberOfYears[i] == o.getDateYear()){
            Weather[o.getDateMonth() + (i * 12)].inOrderTraversal(findHighTime);
        }
    }
}

void storeSpeed(int passedYear, int passedMonth){ //Stores speed based on month and year input

    //Avoids out of bound errors if month input is large
    //Values used in function pointer
    if(passedMonth > 12){
        addMonth = 0;
        passedMonth = 0;
    }
    else{
        addMonth = passedMonth;
    }
    addYear = passedYear;

    //Loops through array to calculate the appropriate BST to search.
    //Correct BST will be in the location, month + (i * 12)
    for(int i = 0; i < maxY; i++){
        if(numberOfYears[i] == passedYear){
            Weather[passedMonth + (i * 12)].inOrderTraversal(addSpeed);
        }
    }
}

void storeTemperature(int passedYear, int passedMonth){ //Stores temperature based on month and year input

    //Values used in function pointer
    addMonth = passedMonth;
    addYear = passedYear;

    //Loops through array to calculate the appropriate BST to search.
    //Correct BST will be in the location, month + (i * 12)
    for(int i = 0; i < maxY; i++){
        if(numberOfYears[i] == passedYear){
            Weather[passedMonth + (i * 12)].inOrderTraversal(addTemperature);
        }
    }
}

void storeRadiation(int passedYear, int passedMonth){ //Stores radiation based on month and year input

    //Values used in function pointer
    addMonth = passedMonth;
    addYear = passedYear;

    //Loops through array to calculate the appropriate BST to search.
    //Correct BST will be in the location, month + (i * 12)
    for(int i = 0; i < maxY; i++){
        if(numberOfYears[i] == passedYear){
            Weather[passedMonth + (i * 12)].inOrderTraversal(addRadiation);
        }
    }
}

void outputHighRadTime(){

    //Needed as bug occurred which showed values such as 1.1e+003...
    // instead of presenting the value (eg. 1073) due to float issues.
    int intMaxRad = maxRad;
    //Displays date
    cout << "Date: " << addDay << "/" << addMonth << "/" << addYear << endl;

    //Displays radiation and times if input is collected from the BST
    if(intMaxRad != 0){
        cout << "Highest solar radiation for the day: " << intMaxRad << " W/m^2\n" << endl;
        cout << "Time:" << endl;
        for(int i = 0; i < numMaxRad; i++){
            if(maxRadTime[i].getHours() != 0 && maxRadTime[i].getMinutes() != 0){
                cout << maxRadTime[i].getHours() << ":" << maxRadTime[i].getMinutes() << endl;
            }
        }
    }
    else{
        cout << "No data" << endl;
    }

    //Resets values for future use
    maxRad = 0;
    for(int i = 0; i < numMaxRad; i++){
        maxRadTime[i].setHours(0);
        maxRadTime[i].setMinutes(0);
    }
}

void outputTheYear(int passedYear){
    //Displays entered year
    cout << " " << passedYear << " - ";
}

string outputTheMonth(int passedM){
    //Stores string corresponding to a certain month
    string displayMonth;

    //Integer value associated with particular month (01 being January)
    if(passedM == 1){
        displayMonth = "January";
    }
    else if(passedM == 2){
        displayMonth = "February";
    }
    else if(passedM == 3){
        displayMonth = "March";
    }
    else if(passedM == 4){
        displayMonth = "April";
    }
    else if(passedM == 5){
        displayMonth = "May";
    }
    else if(passedM == 6){
        displayMonth = "June";
    }
    else if(passedM == 7){
        displayMonth = "July";
    }
    else if(passedM == 8){
        displayMonth = "August";
    }
    else if(passedM == 9){
        displayMonth = "September";
    }
    else if(passedM == 10){
        displayMonth = "October";
    }
    else if(passedM == 11){
        displayMonth = "November";
    }
    else if(passedM == 12){
        displayMonth = "December";
    }

    //Return string important for Writing CSV
    return displayMonth;
}

void outputSpeed(){
    //POTENTIAL BUG - If the average = 0, no data is displayed. However future iterations...
    // might require changing of this check. Certain values such as the temperature might allow...
    // rare instances of the average temperature to be exactly 0.
    if(WindSpeed.getAverage() == 0){
        cout << "No Data" << endl;
    }
    else{
        //Outputs average and standard deviation for given data
        //Setprecision controls number of decimal places
        cout << "\nAverage: " << setprecision(3) << WindSpeed.getAverage() << " km/h";
        cout << "\nStandard Deviation: " << setprecision(3) << WindSpeed.getDeviation() << endl;
    }
}

void outputTemperature(){
    //POTENTIAL BUG - If the average = 0, no data is displayed. However future iterations...
    // might require changing of this check. Certain values such as the temperature might allow...
    // rare instances of the average temperature to be exactly 0.
    if(AmbientTemperature.getAverage() == 0){
        cout << " No Data" << endl;
    }
    else{
        //Outputs average and standard deviation for given data
        //Setprecision controls number of decimal places
        cout << " Average: " << setprecision(3) << AmbientTemperature.getAverage() << " degrees C, ";
        cout << "Standard Deviation: " << setprecision(2) << AmbientTemperature.getDeviation() << endl;
    }
}

void outputRadiation(){
    //POTENTIAL BUG - If the average = 0, no data is displayed. However future iterations...
    // might require changing of this check. Certain values such as the temperature might allow...
    // rare instances of the average temperature to be exactly 0.
    if(SolarRadiation.getAverage() == 0){
        cout << " No Data" << endl;
    }
    else{
        //Outputs average for given data
        //Setprecision controls number of decimal places
        cout << " Average: " << setprecision(2) << SolarRadiation.getAverage() << " kWh/m^2" << endl;
    }
}

void writingFile(int passedYear){
    ofstream outputFile;
    //Creates, opens and writes comma separated values file, for wind speed, air temperature and solar radiation
    outputFile.open("WindTempSolar.csv");

    //Count value to check if a month has no data
    int emptyFlag = 0;
    //Loops through each month
    //Stores and sets averages/deviation for speed, temperature and radiation
    for(int m = 1; m < 13; m++){
            storeSpeed(passedYear, m);
            WindSpeed.setTotal();
            WindSpeed.setAverage();
            WindSpeed.setDeviation();

            storeTemperature(passedYear, m);
            AmbientTemperature.setTotal();
            AmbientTemperature.setAverage();
            AmbientTemperature.setDeviation();

            storeRadiation(passedYear, m);
            SolarRadiation.setTotal();
            SolarRadiation.setAverage();

            //Increments flag if every average for the month = 0
            if(WindSpeed.getAverage() == 0 && AmbientTemperature.getAverage() == 0 && SolarRadiation.getAverage() == 0){
                emptyFlag++;
            }

            //Clears each Map for new input
            WindSpeed.clearMap();
            AmbientTemperature.clearMap();
            SolarRadiation.clearMap();
    }

    //If any average contains data, output is printed to file.
    if(emptyFlag != 12){
        for(int m = 1; m < 13; m++){
            //Stores and sets averages/deviation for speed, temperature and radiation
            storeSpeed(passedYear, m);
            WindSpeed.setTotal();
            WindSpeed.setAverage();
            WindSpeed.setDeviation();

            storeTemperature(passedYear, m);
            AmbientTemperature.setTotal();
            AmbientTemperature.setAverage();
            AmbientTemperature.setDeviation();

            storeRadiation(passedYear, m);
            SolarRadiation.setTotal();
            SolarRadiation.setAverage();

            if(m == 1){
                //Avoids year output for every month, displaying only once
                outputFile << passedYear << '\n';
            }

            //Outputs month
            outputFile << outputTheMonth(m);
            //Prints no data if all averages = 0
            //Prints averages then deviation in brackets for an average which contains data
            if(WindSpeed.getAverage() == 0 && AmbientTemperature.getAverage() == 0 && SolarRadiation.getAverage() == 0){
                outputFile << "," << "No Data" << '\n';
            }
            else{
                if(WindSpeed.getAverage() != 0){
                outputFile << "," << setprecision(3) << WindSpeed.getAverage() << "(" << setprecision(3)
                << WindSpeed.getDeviation() << ")";
                }
                else{
                    outputFile << ",";
                }

                if(AmbientTemperature.getAverage() != 0){
                outputFile << "," << setprecision(3) << AmbientTemperature.getAverage() << "(" << setprecision(2)
                << AmbientTemperature.getDeviation() << ")";
                }
                else{
                    outputFile << ",";
                }

                if(SolarRadiation.getAverage() != 0){
                    outputFile << "," << setprecision(2) << SolarRadiation.getAverage();
                }
                //Ends line after output is printed for a month
                outputFile << '\n';
            }

            //Clears each Map for new input
            WindSpeed.clearMap();
            AmbientTemperature.clearMap();
            SolarRadiation.clearMap();
        }
    }
    else{
        //If all data is empty "No data" is printed after the specified year
        outputFile << passedYear << '\n' << "No Data";
    }
        //Displays message and closes output file
        cout << "File Written" << endl;
        outputFile.close();
}

void menu(){
    //Stores menu input as a string for conversion
    string menuInput;
    //Stores converted value from input
    int menuChoice = 0;
    //Display menu while exit is not selected
    do{
        cout << "\n------------------------------------------------------------------------------------------------------------\n"
            << "1 - Search for average wind speed and sample standard deviation by month and year\n"
            << "2 - Search for average ambient air temperature and sample standard deviation by year\n"
            << "3 - Search for total solar radiation by year\n"
            << "4 - Print averages for wind speed, ambient air temperature and total solar radiation by year, to csv file\n"
            << "5 - Search for highest solar radiation times by date\n"
            << "6 - Exit\n"
            << "------------------------------------------------------------------------------------------------------------\n" << endl;
        //Requests input
        cin >> menuInput;
        // Converts string to int value and //Stores value in menuChoice
        stringstream menuConv(menuInput);
        menuConv >> menuChoice;

        //Passes input to searchPrompt function, unless exit is selected
        switch(menuChoice){
            case 1:
                //Average and deviation of wind speed for given month and year
                searchPrompt(menuChoice);
                break;
            case 2:
                //Average and deviation of air temperature for all months of given year
                searchPrompt(menuChoice);
                break;
            case 3:
                //Average of solar radiation for all months of given year
                searchPrompt(menuChoice);
                break;
            case 4:
                //Writes average and deviation of speed, temperature and radiation for all months of given year
                searchPrompt(menuChoice);
                break;
            case 5:
                //Max radiation and associated times for specific date
                searchPrompt(menuChoice);
                break;
            case 6:
                //Exits program
                cout << "\nExiting Program" << endl;
                break;
            default:
                //Default option when invalid input is entered
                cout << "Invalid option, try again" << endl;
                break;
        }
        //Continues to loop though while loop, until option 5 (exit) is chosen
    } while(menuChoice != 6);
}
