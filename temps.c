//include the standard input/output library
#include <stdio.h>
//create a void function that has no return type called convert. Takes in a float temperature, a charater scale, and a character conversion
//this function works by first converting all temps to celcius as it is easier to work with then. if any other are needed conversions are used.
void convert(float temperature, char scale, char conversion){
    //if the scale is F, set temperature equal to the correct celcius conversion farenheit.
    if(scale == 'F'){
        temperature = (temperature - 32) / 1.8;
    }
    //if the scale is K, set temperature equal to the correct celcius conversion for kelvin
    else if(scale == 'K'){
        temperature = temperature - 273.15;
    }
    //if the scale is C, ensure temperature is not changed.
    else if (scale == 'C'){
        temperature = temperature;
    }
    //if scale is non of these, print the following line and return out of the function. This means an impossible scale was passed in.
    else{
        printf("You have attempted to put in an invalid temperature scale, please try again.");
        return;
    }
    //if the conversion type is not K and not C and not F, then it is an impossible conversion type so print the message and return out of the function.
    if ((conversion != 'K') && (conversion != 'C') && (conversion != 'F')){
        printf("You have attempted to put in an invalid temperature conversion, please try again.");
        return;
    }
    //uses switch statement to consider the different possible cases for conversion
    switch(conversion){
        //if conversion is F, print the following message that contains the text followed by the converted temperature and the correct unit
        case 'F':
        printf("Converted temperature %f %c\n", ((temperature * 1.8) + 32), conversion);
        break;
        //if conversion is C, print the following message that contains the text followed by the converted temperature and the correct unit    
        case 'C':
        printf("Converted temperature %f %c\n", temperature, conversion);
        break;
        //if conversion is K, print the following message that contains the text followed by the converted temperature and the correct unit
        case 'K':
        printf("Converted temperature %f %c\n", (temperature+273.15), conversion);
        break;
    }
    //if the temperature is less than 0, print the following messages on their own lines
    if (temperature < 0){
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Stay indoors and use a heater\n");
    //if the temperature is less than 10, print the following messages on their own lines
    }else if (temperature < 10){
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear warm layers\n");
    //if the temperature is less than 25, print the following messages on their own lines
    }else if (temperature < 25){
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: Enjoy the nice weather\n");
    //if the temperature is less than 35, print the following messages on their own lines
    }else if (temperature < 35){
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Drink plenty of water\n");
    //if the temperature is greater than 35, print the following messages on their own lines
    }else{
        printf("Temperature category: Extreme heat\n");
        printf("Weather advisory: Stay indoors and use a fan or air conditioning\n");
    }
}
//creates main function
int main(){
    //defines the float var temperature and the char vars scale and conversion
    float temperature;
    char scale;
    char conversion;
    //prints the following string followed by a newline character.
    printf("Please input the temperature:\n");
    //scans the users input for a float type and stores it in the memory location of temperature
    scanf("%f", &temperature);
    //prints the following string followed by a newline character.
    printf("What scale is this temp (F, C or K)?:\n");
    //scans the users input for a character type and stores it in the memory location of scale
    scanf(" %c", &scale);
    //prints the following string followed by a newline character.
    printf("What scale would you like to convert to (F, C or K)?:\n");
    //scans the users input for a character type and stores it in the memory location of conversion
    scanf(" %c", &conversion);
    //calls the convert function and passes in temperature, scale, and conversion values
    convert(temperature, scale, conversion);
}