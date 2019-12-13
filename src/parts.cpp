#include <iostream>
using namespace std;
#include "parts.h"

NameContainer partContainer;

void Part::describe()
{

    cout<<"Part "<<name<<" subparts are:"<<endl;
    map<Part*, int>::iterator it;


    if(mapParts.empty())
    {
        cout<<"It has no subparts"<<endl;

    }
    for ( it = mapParts.begin(); it != mapParts.end(); it++ )
    {
        std::cout<<it->second<<" "<<it->first->name<<endl;
    }


}

int Part::count_howmany(Part const *p)
{

    int sum=0;
    map<Part*, int>::iterator it;


    for ( it = mapParts.begin(); it != mapParts.end(); it++ )
    {
        Part* subPart=it->first;

        if(subPart->name==p->name)
            return it->second;
        int subSum= (subPart->count_howmany(p));
        sum+=(it->second) *subSum;
    }


    return sum;
}


Part* NameContainer::lookup(string const &name)
{

    if(name_map[name])
    {
        return  name_map[name];
    }
    else
    {
        Part* part=(new Part(name));
        name_map[name]=part;
        return  name_map[name];
    }
}
void add_part(string const &x, int quantity, string const &y)
{
    partContainer.lookup(x)->mapParts[partContainer.lookup(y)]=quantity;


}

NameContainer::~NameContainer() {

}
