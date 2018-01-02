//
// Created by Ryan on 26/11/2017.
//

#ifndef CPP_PRIMER_SALES_DATA_H
#define CPP_PRIMER_SALES_DATA_H

#include <string>

struct Sales_data {
    friend class std::hash<Sales_data>;

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};


#endif //CPP_PRIMER_SALES_DATA_H
