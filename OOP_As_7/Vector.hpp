//
//  Vector.hpp
//  oop_7
//
//  Created by 张倬豪 on 2016/12/23.
//  Copyright © 2016年 Icarus. All rights reserved.
//

#ifndef Vector_hpp
#define Vector_hpp

#define SIZE_ONCE 100

#include <iostream>
#include <assert.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>

class VectorIndexError {
public:
    VectorIndexError(int v) : m_badValue(v) { }
    ~VectorIndexError() { }
    void diagnostic();
private:
    int m_badValue;
};

template<class T>
class Vector
{
public:
    Vector();
    Vector(int n);
    Vector(const Vector& r);
    virtual ~Vector();
    T& operator[](int index);
    int	size();
    T* inflate(int addsize);
    bool empty();
private:
    T* m_pElements;
    int	m_nSize;
    int	length;
};

#endif /* Vector_hpp */
