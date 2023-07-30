// MS-3 Contributors: Long Duc , Amir Mullagaliev 
// Date: 2023/07/16
#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#define MAX_SIZE 36
#define MAX_WEIGHT 1000

struct BoxWeight {

    int m_weight[1000];    // Weight of the box (in kg)
};

struct Location {
    int m_row;       // row of the location (is an int)
    char m_column;   // column of the location (is a char)
};

struct BoxSize {
      
    double Size[144]; // the box size for the truck
     
};
struct Truck {
    struct BoxWeight m_weight;         // Weight of the item (in kilograms)
    struct BoxSize m_boxSize;    // Size of the box required for the item
    struct Location m_destination;   // Destination location for the item
    int numOfThingLoaded;
};

struct Route {
    struct Truck trucks[3];
};

// return the total size in this truck
double getTotalSize(const struct Truck* truck);
// initialize this truck to the default value, which is zero
void iniTruck(struct Truck* truck);
// load this truck by the cargo, which contain size and weight
void loadTruck(struct Truck* truck, double size, int weight);
// get the total weight of this truck
int getTotalWeight(const struct Truck* truck);
// decide weight or size exceed the limit for this truck
// return 1 if the weight will exceed first
// 0 if the size will exceed first
int decideLimit(const struct Truck* truck);
// set the destination for this truck to go
void setDestinatioon(struct Location* destination, int row, char column);
// validate if the passing destination is validate or not
// return 0 if not validate
// return 1 of validate
int validateDestination(int row, char column);
// decide which truck should be loaded by the cargo, based on their current state
void decideTruck(const struct Route* route, double size, int weight);
// validate if the truck can accept the cargo
// return 0 if it cannot
// return 1 if it can.
int validateTruck(const Truck* truck, double size, int weight);
#endif // DATA_STRUCTURES_H