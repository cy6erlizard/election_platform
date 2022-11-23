
#ifndef HEAEDER_H_INCLUDED
#define HEAEDER_H_INCLUDED


typedef struct{
    int id;
    char type[15]
    ElectoralList electoral_list[15];
    Date date ;
    char municipality[15];
    char text[200];
}Claims;
typedef struct {
     int month;
     int day;
     int year;
}Date;

typedef struct{
    int id[4];

}ElectoralList;
#endif // HEAEDER_H_INCLUDED