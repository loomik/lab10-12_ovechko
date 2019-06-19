#ifndef LAB10_12_OVECHKO_STRUCT_H
#define LAB10_12_OVECHKO_STRUCT_H

typedef struct GameDev {
    int id;                     // Id
    char *name;                 // Name of Game
    char *chapter;              // Type of Chapter
    char *developer;            // Developer of Game
    int date[3];                // Release date
    float Publisherrate;       // Publisher rate of Game
    int Gamersrate;             // Gamers rate of Game
    float bothrate;            // Both rate of Game(gamers and Publishers)
    int Publisher1;             // First Publisher
    int Publisher2;             // Second Publisher
    struct GameDev *next;       // Link to next
    struct GameDev *prev;       // Link to prev
} GameDev;


typedef struct head {		//the header element
    int size;	            //the number of the list
    struct GameDev *first;	//first element
    struct GameDev *last;	//last element
}head;



#endif //LAB10_12_OVECHKO_STRUCT_H
