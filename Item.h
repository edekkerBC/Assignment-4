//============================================================================
// Name        : BarcodBSTScanner.cpp
// Author      : Erik Dekker
// Description : Assignment 4: Item class to be used in Data Structures
//============================================================================

#ifndef ITEM_H_
#define ITEM_H_

//#include <iostream>
using namespace std;

class Item
{
private:
    string code; //UPC Barcode
    string desc; //Item description

public:
    Item(){ }
    Item(string _code){
    	code = _code;
    }
    Item(string _code, string _desc){
        code = _code;
        desc = _desc;
    }
    void setCode(string _code) {
        code = _code;
    }
    void setDesc(string _desc){
        desc = _desc;
    }
    string getCode() const{
        return code;
    }
    string getDesc() const{
        return desc;
    }
    void write(string &_code, string &_desc){
        code = _code;
        desc = _desc;
    }
    bool operator >(const Item& i){
    		return code > i.code;
	}
	bool operator <(const Item& i){
		return code < i.code;
	}
	bool operator ==(const Item& i){
		return code == i.code;
	}
    friend  ostream& operator<<(ostream& os, Item& c);

};

ostream& operator<<(ostream& os, Item& c){
    os<<c.code<<" "<<c.desc<<endl;
    return os;
}



#endif /* ITEM_H_ */
