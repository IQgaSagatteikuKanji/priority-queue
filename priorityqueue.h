#pragma once
#include <vector>

template<class type>
class priority_queue{
    std::vector<type> array = {};
    void sink();
    void swap(size_t, size_t);
    void rise();
public:
    void push(const type&);
    type pop();
    const type& peek();
    bool empty();
};

template<class type>
void priority_queue<type>::rise(){
    size_t ind = array.size();
    while(ind != 1){
        if(array[ind - 1] > array[ind/2 - 1])
            swap(ind - 1, ind/2 - 1);
        ind = ind/2;
    }
}

template<class type> 
void priority_queue<type>::swap(size_t first, size_t second){
    type buffer = array[first];
    array[first] = array[second];
    array[second] = buffer;
}

template<class type>
void priority_queue<type>::sink(){
    if(array.size() <= 1) return;
    size_t ind = 1;
    bool swapped = true;
    while(swapped == true){
        swapped = false;
        if(array.size() > 2 * ind - 1){
            if(array[ind -1] < array[2*ind -1]){
                swap(ind -1, 2* ind -1);
                swapped = true;
                ind = 2*ind;
            }
        }
        else
            if(array.size() > 2 * ind)
                if(array[ind - 1] < array[2*ind]){
                    swap(ind-1, 2* ind);
                    swapped = true;
                    ind = 2* ind + 1;
                }
    }
}

template<class type>
void priority_queue<type>::push(const type& elem){
    array.push_back(elem);
    rise();
}

template<class type>
type priority_queue<type>::pop(){
    type retval = peek();
    if(array.size()>1){
        array[0] = array[array.size() - 1];
    }
    if(array.size() > 0)
        array.resize(array.size() - 1);
    sink();
    return retval;
}

template<class type>
const type& priority_queue<type>::peek(){
    return array[0];
}

template<class type>
bool priority_queue<type>::empty(){
    return array.empty();
}
