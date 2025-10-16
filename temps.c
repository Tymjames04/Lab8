#include <stdio.h>
void convert(float temperature, char scale, char conversion){
    if(scale == 'F'){
        temperature = (temperature - 32) / 1.8;
    }
    else if(scale == 'K'){
        temperature = temperature - 273.15;
    }
    else if (scale == 'C'){
        temperature = temperature;
    }
    else{
        printf("You have attempted to put in an invalid temperature scale, please try again.");
        return;
    }
    
    if ((conversion != 'K') && (conversion != 'C') && (conversion != 'F')){
        printf("You have attempted to put in an invalid temperature conversion, please try again.");
        return;
    }

    switch(conversion){
        case 'F':
        printf("Converted temperature %f %c\n", ((temperature * 1.8) + 32), conversion);
        break;
            
        case 'C':
        printf("Converted temperature %f %c\n", temperature, conversion);
        break;
    
        case 'K':
        printf("Converted temperature %f %c\n", (temperature+273.15), conversion);
        break;
    }
    if (temperature < 0){
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Stay indoors and use a heater\n");
    }else if (temperature < 10){
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear warm layers\n");
    }else if (temperature < 25){
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: Enjoy the nice weather\n");
    }else if (temperature < 35){
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Drink plenty of water\n");
    }else{
        printf("Temperature category: Extreme heat\n");
        printf("Weather advisory: Stay indoors and use a fan or air conditioning\n");
    }
}
int main(){
    float temperature;
    char scale;
    char conversion;
    printf("Please input the temperature:\n");
    scanf("%f", &temperature);
    printf("What scale is this temp (F, C or K)?:\n");
    scanf(" %c", &scale);
    printf("What scale would you like to convert to (F, C or K)?:\n");
    scanf(" %c", &conversion);
    convert(temperature, scale, conversion);
}