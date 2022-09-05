//
// Created by Xiaodong Liu on 9/5/22.
//

#ifndef FINDKTHSMALLEST_CUSTOMPRIORITYQUEUE_H
#define FINDKTHSMALLEST_CUSTOMPRIORITYQUEUE_H
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
namespace ns{
    template<
        class T,
        class Container = std::vector<T>,
        class Compare = std::less<typename Container::value_type>
    >class priority_queue{
    private:
        Compare compare;
        Container container;
        size_t parent(size_t i){
            return (i-1)>>1;
        }
        size_t leftChild(size_t i){
            return 2*i+1;
        }
        size_t rightChild(size_t i){
            return 2*i+2;
        }
        void heapify(size_t i){
            size_t nextI = i, left = leftChild(i), right = rightChild(i);
            if(left < container.size() && compare(container[nextI], container[left])){
                nextI = left;
            }
            if(right < container.size() && compare(container[nextI], container[right])){
                nextI = right;
            }
            if(nextI != i){
                swap(container[nextI], container[i]);
                heapify(nextI);
            }
        }
    public:
        priority_queue(){}
        priority_queue(const Compare& _compare): compare(_compare){}
        //Time O(logN), Space O(1)
        void push(const T& val){
            container.emplace_back(val);
            size_t i = container.size()-1;
            while(i > 0 && compare(container[parent(i)], container[i])){
                swap(container[parent(i)], container[i]);
                i = parent(i);
            }
        }
        //Time O(logN), Space O(logN)
        void pop(){
            swap(container[0], container.back());
            container.pop_back();
            heapify(0);
        }
        //Time O(1), Space O(1)
        const T& top(){
            return container[0];
        }
        size_t size(){
            return container.size();
        }
    };
}
#endif //FINDKTHSMALLEST_CUSTOMPRIORITYQUEUE_H
