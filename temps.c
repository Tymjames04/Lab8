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
        printf("Temperature category: Freezing");
        printf("Weather advisory: Stay indoors and use a heater");
    }else if (temperature < 10){
        printf("Temperature category: Cold");
        printf("Weather advisory: Wear warm layers");
    }else if (temperature < 25){
        printf("Temperature category: Comfortable");
        printf("Weather advisory: Enjoy the nice weather");
    }else if (temperature < 35){
        printf("Temperature category: Hot");
        printf("Weather advisory: Drink plenty of water");
    }else{
        printf("Temperature category: Extreme heat");
        printf("Weather advisory: Stay indoors and use a fan or air conditioning");
    }
}
int main(){
    float temperature;
    char scale;
    char conversion;
    printf("Please input the temperature:\n");
    scanf("%f", temperature);
    printf("What scale is this temp (F, C or K)?:\n");
    scanf(" %c", scale);
    printf("What scale would you like to convert to (F, C or K)?:\n");
    scanf(" %c", conversion);
    convert(temperature, scale, conversion);
}